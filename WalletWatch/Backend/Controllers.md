```js
const ExpenseModel = require("../models/ExpenseModel"); //importing your Mongoose model that defines what an "income" looks like in the database.

//controller function that will handle the logic when someone calls the POST /add-income route.
exports.addExpense = async (req,res) => {
    const {title, amount, category, description, date} = req.body; //creates a new income object
    const income = ExpenseModel({ //This line creates a new document, but it’s not saved to the database yet. creates new income object
        title,
        amount, 
        category,
        description,
        date
    });
    
    try{
        if(!title || !category || !description || !date){
            return res.status(400).json({message: 'All fields are required!.'});
        }
        if(amount <= 0 || typeof amount !== 'number'){
            return res.status(400).json({message: 'Amount must be a positive number.'});
        }
        await income.save();
        res.status(200).json({message: "expense added successfully."});
    }catch(error){
        console.error("Error:", error);
        res.status(500).json({message: "something went wrong."})
    }
    console.log(income);
}

//get-income
exports.getExpense = async(req,res) => {
    try {
        const incomes = await ExpenseModel.find().sort({createdAt: -1})
        res.status(200).json(incomes);
    } catch (error) {
        console.error("Error fetching incomes:", error);
        res.send(500).json({message: "server error"});
    }
};

// Delete income
exports.deleteExpense = async (req, res) => {
  const { id } = req.params;
  console.log(id)

  try {
    await ExpenseModel.findByIdAndDelete(id);
    res.status(200).json({ message: "Expense deleted successfully" });
  } catch (error) {
    console.error("Error deleting expense:", error);
    res.status(500).json({ message: "Server error" });
  }
};
```

### Explanation


```js
const { title, amount, category, description, date } = req.body;
```
- object destructuring in JS

When you send data from your **frontend** (like a form) to your **backend** using a POST request, you usually send something like this:

```json
{
  "title": "Grocery",
  "amount": 500,
  "category": "Food",
  "description": "Bought vegetables",
  "date": "2025-06-29"
}

```

All of this comes to the backend and lives inside `req.body`. 

So `req.body` looks like this:

```js
{
  title: 'Grocery',
  amount: 500,
  category: 'Food',
  description: 'Bought vegetables',
  date: '2025-06-29'
}

```

It **pulls out (extracts)** each value from `req.body` into its own variable:

| Variable      | Value                 |
| ------------- | --------------------- |
| `title`       | `'Grocery'`           |
| `amount`      | `500`                 |
| `category`    | `'Food'`              |
| `description` | `'Bought vegetables'` |
| `date`        | `'2025-06-29'`        |
So now, instead of writing:
```js
req.body.title
req.body.amount
req.body.category
```

you can just write
```js
title
amount
category
```

---
You should use async and await in:

✅ **1. Controller functions:**

- You are saving, fetching, or deleting data from MongoDB using Mongoose

- All these Mongoose methods (save(), find(), findById(), deleteOne() etc.) are asynchronous

**✅ 2. Database connection (db folder)**

- mongoose.connect() returns a promise

- So you must await it to make sure the connection is complete before the app starts

