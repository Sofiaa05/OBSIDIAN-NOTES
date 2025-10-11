### What is an HTTP POST Request?

- A POST request is used to send data to the server, usually to create something (like a new user, a comment, a form submission).

- It carries data in the body of the request — not in the URL like GET.

![[Pasted image 20250628181649.png]]

---
### Body Parser

Body-parser is a middleware used to parse incoming request bodies before your route handlers get them.

It helps you get data from req.body in a structured way — like JSON or form data.

```js
name=sofia&email=sofia@gmail.com
```
That’s what your server gets from a form when someone submits it. It's a **raw string**.

### Before Parsing:

- The data comes in as a **long string** in the body of the HTTP request.
    
- You **can’t access it directly** like `req.body.name` — because it’s just raw text.
```js
{
  name: 'sofia',
  email: 'sofia@gmail.com'
}

```

---

### 🔹 After Parsing:

**body-parser** reads that raw string and converts it into:
```js
{
  name: 'sofia',
  email: 'sofia@gmail.com'
}
```

---

#### installing body-parser
```js
npm install body-parser
```

#### Example:
```js
const express = require('express');
const bodyParser = require('body-parser');
const app = express();

// 🔧 Middleware to parse JSON and form data
app.use(bodyParser.json()); // for JSON data
app.use(bodyParser.urlencoded({ extended: true })); // for HTML form data

// 🔥 POST route
app.post('/register', (req, res) => {
  const { username, email } = req.body;

  console.log('Received:', username, email);

  res.status(201).json({
    message: 'User registered successfully',
    user: { username, email }
  });
});

app.listen(3000, () => {
  console.log('Server running at http://localhost:3000');
});

```

#### Explanation
### `const bodyParser = require('body-parser');`

- This loads the body-parser module.
    
- It gives you tools to extract data from the body of a POST request.
    

---

### `app.use(bodyParser.json());`

- This tells Express:
    

> “If someone sends **JSON** data (e.g., via Postman), parse it and put it inside `req.body`.”

---

### `app.use(bodyParser.urlencoded({ extended: true }));`

- This tells Express:
    

> “If someone submits a **form** (HTML form), parse it and put it in `req.body`.”

- `extended: true` allows nested objects, like:

```js
{ user: { name: "Sofia", age: 21 } }
```

---

### POST Route:

```js
app.post('/register', (req, res) => {
  const { username, email } = req.body;

```

- When someone sends a POST request to `/register`:
    
    - Express parses the body
        
    - Extracts `username` and `email` from `req.body`
        

---

### Interview Questions:

Q1: When do you use POST instead of GET?
When sending data to the server (creating a resource) — unlike GET which only retrieves.

Q2: How do you handle POST data in Express?
Use express.json() for JSON, express.urlencoded() for form data. Then access it via req.body.

Q3: What is req.body in Express?
It’s an object that holds data sent in the body of the request (works only if middleware is used).

Q4: What if req.body is undefined?
Most likely, the required middleware (express.json() or urlencoded()) is missing.

Q5: Which status code do you send after successful POST?
201 Created

Q6: Can we send files using POST?
Yes. Use the POST method with file upload middleware like multer.

Q7: What is body-parser in Express?
body-parser is middleware that parses the incoming request body so you can access it using req.body. It supports JSON, form-data, and more.

Q8: Is body-parser still required in Express?
No, since Express 4.16+, the most used features (json() and urlencoded()) are built-in. But for older apps or in legacy codebases, it’s still common.

Q9: What does extended: true mean?
It allows urlencoded data to use rich objects (e.g. nested key-value pairs). Set to false for simpler parsing.