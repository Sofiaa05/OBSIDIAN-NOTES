### **Day 3 — MongoDB Intro**

- **Backend:** Connect to MongoDB, create `users` collection, implement GET/POST.
    
- **Frontend:** Fetch and display users in a table.
    
- **Integration:** Store form data in MongoDB, then show updated list.


### Backend

1. connect to mongodb
```js
//configDB.js
const mongoose = require('mongoose');

async function connectDB(){
    try{
        await mongoose.connect("mongodb://localhost:27017/");
        console.log("Mongo DB connected successfully");
    }catch(error){
        console.error("MongoDB connection failed", error);
        process.exit(1); // crash early so we notice misconfigurations
    }
}

module.exports = connectDB;
```

2. creating user collection
```js
const mongoose = require ("mongoose");

//schema and model
const userSchema = new mongoose.Schema({
    name: {
        type: String, 
        required: true,
        trim: true
    },
    email: {
        type: String,
        required: true,
        lowercase: true,
        unique: true
    },
    password: {
        type: String,
        required: true,
        minlength: 6,
    }
}, {timestamps: true});

const User = mongoose.model("User", userSchema);
module.exports = User; 

//or just simply: 
module.exports = mongoose.model("User", userSchema);
//then import in other files as:
const User = require("filepath");
```

3. get
```js
app.get("/api/users", async (req, res) => {
    try{
        const users = await User.find();
        res.json(users); //automatically JSON.stringify whatever data is being sent 
    }catch(error){
        res.status(500).json({message: "server error"})
    }
})
```

4. post
```js
 app.post("/api/users", async (req, res) => {
    try{
        const { name, email } = req.body || {}; // object destructing to extract data

        if( !name || !email ){
            return res.status(400).json({ error: "Name and email are required" });
        }

        //model is like class so to add data we haev to create an instance of model
        /* const newUser = await new User ({ name, email });
        await newUser.save(); //save to mongodb */
        
	    //above two locs can also be done in a single step as:
        const newUser = await User.create({
            name,
            email
        });

        res.status(201).json(newUser);     
    }catch(error){
        res.status(500).json({message: "Error adding user", error})
    }
 });

```

|Use case|Recommended|
|---|---|
|Clean one-shot insertion|`User.create()`|
|Need to tweak/update data before saving|`new User() + save()`|
|Using instance methods / hooks|`new User()` style|
### Frontend
```js
import { useState, useEffect } from 'react';
import axios from 'axios';

export default function Details() {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [users, setUsers] = useState([]);
  const [error, setError] = useState("");

  
   // Fetch all users on page load
  useEffect( () => {
    fetchUsers();
  }, []);

  //fetch users
  const fetchUsers = async () => {
    try{
        const res = await axios.get("http://localhost:5001/api/users")
        console.log("API Response:", res.data); 
        setUsers(res.data)
    }catch(error){
        setError("Error fetching user");
        console.error(error.message);
    }
  }

  const addUsers = async (e) => {
    e.preventDefault();

    try{
        await axios.post("http://localhost:5001/api/users" , { name, email });
        setName("");
        setEmail("");
        setError("");
        fetchUsers()
    }catch (error){
        console.log("Error adding user", error);
    }
  };

  return (
    <div>
      <form onSubmit={addUsers}>
        <div>
          <label>
            Full Name:
            <input
              type="text"
              placeholder="Enter your name"
              value={name}
              onChange={(e) => setName(e.target.value)}
              required
            />
          </label>
        </div>
        <div>
          <label>
            Email:
            <input
              type="email"
              placeholder="Enter your email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
            />
          </label>
        </div>
        <button type="submit">Submit</button>
      </form>

      {error && <p style={{ color: "red" }}>{error}</p>} {/* finds first falsy value. If all true return last truthy value*/}
      
      <h2>Users List</h2>
      <table border="1" cellPadding="5">
        <thead>
          <tr>
            <th>Name</th>
            <th>Email</th>
          </tr>
        </thead>
        
        <tbody>
            {users.length > 0 ? (
                users.map(user => (
                    <tr key={user._id}> {/* mongodb objectid*/}
                        <td>{user.name}</td>
                        <td>{user.email}</td>
                    </tr>
                ))
            ) : (
                <tr>
                    <td colSpan="2">No users found</td>
                </tr>            
            )}
        </tbody>
      </table>
    </div>
  );
}

```