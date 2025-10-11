
- **Backend:** Implement `/signup` & `/login` with password hashing (bcrypt).
    
- **Frontend:** Create signup/login forms with validation.
    
- **Integration:** Store JWT token in localStorage after login.

### Backend

#### /authController.js
```js
const express = require('express');
const User = require("../models/User");

exports.signup = async (req, res) => {
    try{
        const { name, email, password } = req.body || {};

        if(!name || !email || !password){
            return res.status(400).json({message: "All fields are required"})
        }

        const existingUser = await User.findOne({ email }); //need to learn syntax
        if(existingUser){
            return res.status(400).json({error: "Email already exists"});
        }

        const newUser = await User.create({
            name,
            email,
            password,
        })
        
        res.status(201).json({message: "User successfully created", newUser})
    }catch (error){
        res.status(500).json({message: "Error adding user", error: error.message});
    }
}

//login
exports.login = async (req, res) => {
    try{
        const { email, password } = req.body || {};

        if( !email || !password ){
            return res.status(400).json({message: "All fields are required"})
        }

        //if email doesn't not found or password doesn't match
        const user = await User.findOne({ email });
        if(!user){
            return res.status(401).json({message: 'Invalid credentials'});
        }

        const isMatch = await user.comparePassword(password); //comparePassword takes one parameter password and is instance method
        if(!isMatch){
            return res.status(401).json({message: 'Invalid credentials'});
        }

        res.status(200).json({
            id: user._id,
            name: user.name,
            email: user.email
        })
        
    }catch (error){
        console.error("Login error:", error.message);
        res.status(500).json({ message: "Server error" });    
    }
}
```

#### /authRoutes.js
```js
const express = require("express");
// const jwt = require('jsonwebtoken');

const User = require("../models/User");
const router = express.Router();

const { signup,login } = require('../controllers/authcontroller');
// const login = require('../controllers/authcontroller')

router.post('/signup', signup);
router.post('/login', login);

module.exports = router;
```

#### hashing password (/models/User.js)
```js
const mongoose = require ("mongoose");
const bcrypt = require('bcrypt');

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

// Hash password automatically *only* when it’s created/changed
userSchema.pre("save", async function (next){
    if(!this.isModified("password")){
        return next();
    }
    this.password = await bcrypt.hash(this.password, 10);
    next()
})

// Instance method to compare passwords
userSchema.methods.comparePassword = function (plain){
    return bcrypt.compare(plain, this.password);
}

//model
const User = mongoose.model("User", userSchema);
module.exports = User;

```
#### Explanation:
```javascript
userSchema.pre("save", async function (next){
    if(!this.isModified("password")){
        return next;
    }
    this.password = await bcrypt.hash(this.password, 10);
    next()
})
```

---

##### 1. `userSchema.pre("save", async function (next) { ... })`

- **`userSchema`**:  
    This is the Mongoose schema for your user collection. It defines the structure of user documents (fields like name, email, password, etc.).
    
- **`.pre()`**:  
    This is a Mongoose **middleware** function. Pre middleware runs **before** a certain operation occurs. In this case, it runs **before saving** (`"save"`) a document to the database.
    
- **`"save"`**:  
    This tells Mongoose to run this middleware **before the `save` operation**. The `save` operation happens when you call `user.save()` or create a new document.
    
- **`async function (next)`**:  
    This is the callback function that will execute before saving.
    
    - **`async`**: Allows us to use `await` inside the function for asynchronous operations (like hashing the password).
        
    - **`function`**: A standard JavaScript function. Using a **normal function** instead of an arrow function is crucial here because `this` must refer to the **current document**. Arrow functions would not have the correct `this`.
        
    - **`next`**: A callback provided by Mongoose. Calling `next()` tells Mongoose to proceed to the next middleware or finish the save operation. If you forget to call `next()`, the save operation will **hang**.
        

---

##### 2. `if(!this.isModified("password")) { return next; }`

- **`this`**:  
    Refers to the **current document being saved**. For example, if you’re creating or updating a user, `this` is that user object.
    
- **`.isModified("password")`**:  
    This is a Mongoose document method that checks if a particular field has been **modified** since it was loaded from the database.
    
    - If the password has **not changed**, we don’t need to hash it again.
        
    - If it **has changed**, we need to hash the new password.
        
- **`!this.isModified("password")`**:  
    The `!` negates the result. So this checks:
    
    > "If the password field was **not modified**, then..."
    

##### 3. `this.password = await bcrypt.hash(this.password, 10);`

- **`this.password`**:  
    Refers to the password of the current user document.
    
- **`await`**:  
    Waits for the **Promise** returned by `bcrypt.hash` to resolve. This is necessary because hashing is an asynchronous operation.
    
- **`bcrypt.hash(this.password, 10)`**:  
    This hashes the password using the **bcrypt algorithm**.
    
    - **`this.password`**: The plain-text password entered by the user.
        
    - **`10`**: The **salt rounds**. More rounds = more security, but slower hashing. 10 is a standard safe number.
        
    - `bcrypt.hash` generates a hashed version of the password that is **safe to store in the database**.
        
- **`this.password = ...`**:  
    The original plain-text password is replaced with the hashed password before saving.
    

---

##### 4. `next()`

- After the password is hashed, we **call `next()`** to tell Mongoose:
    
    > "I’m done with this middleware. You can now proceed to save the document."
    
- If you forget this, Mongoose will **hang** indefinitely because it’s waiting for the middleware to finish.
    

Absolutely! Let’s go **line by line, word by word**, and deeply explain your Mongoose **instance method** for comparing passwords. Here’s your code:

```javascript
// Instance method to compare passwords
userSchema.methods.comparePassword = function (plain) {
    return bcrypt.compare(plain, this.password);
}
```

---
#### Explanation:
```js
// Instance method to compare passwords
userSchema.methods.comparePassword = function (plain){
    return bcrypt.compare(plain, this.password);
}
```
##### 1. `userSchema.methods.comparePassword = function (plain) { ... }`

#### **a) `userSchema`**

* This is the **Mongoose schema** object for your user collection.
* It defines the structure of a user document (fields like `name`, `email`, `password`, etc.) and also allows attaching **methods** or middleware.

---

#### **b) `.methods`**

* `.methods` is a special Mongoose property where you can define **instance methods**.
* **Instance methods** are methods available on **individual documents** (not the model itself).

  * Example:

    ```javascript
    const user = await User.findById(id);
    user.comparePassword("123456"); // instance method
    ```
* Unlike **static methods** (`userSchema.statics`), instance methods are called **on the document**, not on the model.

---

#### **c) `.comparePassword`**

* This is the **name of the method** you are defining.
* You can call it whatever you want, e.g., `checkPassword`, `verifyPassword`, etc.
* After defining it, every user document will have a `comparePassword` method.

---

#### **d) `= function (plain) { ... }`**

* You are assigning a **regular function** (not an arrow function) to the method.

**Why a regular function?**

* Because we need `this` to refer to the **current document**.
* Arrow functions **do not have their own `this`**, so `this.password` would be undefined if you used an arrow function.

**`plain`**

* This is a **parameter** representing the **plain-text password** the user is trying to log in with.
* Example: user enters `"123456"` on login, `plain = "123456"`.

---

##### 2. `return bcrypt.compare(plain, this.password);`

#### **a) `return`**

* Sends back the result of `bcrypt.compare`.
* Important: `bcrypt.compare` returns a **Promise**, so you usually need `await` when calling it if you want the resolved value.

---

#### **b) `bcrypt.compare(plain, this.password)`**

* **`bcrypt`**: The bcrypt library used for password hashing and comparison.

* **`.compare()`**:

  * A bcrypt function that **checks if a plain-text password matches a hashed password**.
  * Syntax:

    ```javascript
    bcrypt.compare(plainPassword, hashedPassword)
    ```
  * Returns a **Promise** that resolves to:

    * `true` → passwords match
    * `false` → passwords do not match

* **`plain`**:

  * The plain-text password the user entered (first argument).

* **`this.password`**:

  * The hashed password stored in the database (from the current document).
  * `this` refers to the document because we used a normal function.

So this line effectively **checks if the entered password matches the hashed password**.

---

### **Key Points**

1. This is an **instance method**, not a static method.

   * Use: `user.comparePassword("123456")`
   * Not: `User.comparePassword(...)`

2. Always use **regular functions** for `this` to work correctly.

3. Returns a **Promise**, so in async code, you should use:

   ```javascript
   const isMatch = await user.comparePassword("123456");
   ```

4. This method allows **secure password verification** without ever storing plain-text passwords.

---

#### server.js
```js
const authRoutes = require("./routes/authRoutes")
app.use('/api/v1/auth', authRoutes);
```
---
### frontend

#### 1. login
```js
import React, { useState } from 'react'
import authPath from '../axiosInstance';

const Login = () => {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState(null);
 
 //handleLogin
  const handleLogin = async (e) => {
    e.preventDefault();

    try{
      if( !email || !password){
        setError("All fields are required");
        return;
      }

		if(password.length < 8){
	        setError("Password must be atleast 8 digits long");
	        return
	    }

      setError(""); //clear any previous error encountered

      await authPath.post('/login', {
        email,
        password,
      });

      setEmail("")
      setPassword("")
      setError("")
    }catch(error){
      setError(error.response?.data?.message || "Something went wrong. Please try again.")
    }
 }
 
  return (
    <div>
      <form onSubmit={handleLogin}>
        <label>
            Email: 
            <input
                type="email"
                placeholder='john@gmail.com'
                value={email}
                onChange={(e) => setEmail(e.target.value)}
                required
            />
        </label>
        <label>
            Password:
            <input
                type="text"
                placeholder='Enter password'
                value={password}
                onChange={(e) => setPassword(e.target.value)}
                required
            />
        </label>
        <button type='submit'>Login</button>
      </form>
        {error && <p style={{color: 'red'}}>{error}</p>}
    </div>
  )
}

export default Login
```

#### 2. Signup
```js
import React, { useState }from 'react'
import authPath from '../axiosInstance';

const SignUp = () => {
    const[name, setName] = useState("");
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");
    const [error, setError] = useState(null);

    const handleSignup = async (e) => {
        e.preventDefault();
        try{
            if(!name || !email || !password){
                setError("All fields are required");
                return;
            }

            setError(""); //defualt value

            await authPath.post('/signup', {
                name,
                email,
                password
            })
		// set default value
            setName("");
            setEmail("");
            setPassword("");
            setError("");
        }catch (error){
            setError(error.response?.data?.message || "Something went wrong. Please try again")
        }
    }

  return (
    <div>
      <form onSubmit={handleSignup}>
        <label>
            Name:
            <input 
                type="text"
                placeholder='John'
                value={name}
                onChange={(e) => setName(e.target.value)}
                required
            />
        </label>
        <label>
            Email:
            <input 
                type="email"
                placeholder='john@gmail.com'
                value={email}
                onChange={(e) => setEmail(e.target.value)}
                required
            />
        </label>
        <label>
            Password:
            <input 
                type="password"
                value={password}
                onChange={(e) => setPassword(e.target.value)}
                required
            />
        </label>
        <button type="submit">SignUp</button>
      </form>
      {error && <p style={{color: "red"}}>{error}</p>}
    </div>
  )
}

export default SignUp
```

#### 3. App.js
```js
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Ping from './ping';
import Details  from './Details'
import Login from './Pages/Login';
import SignUp from './Pages/SignUp';
function App() {
  return (
    <Router>
      <Routes>
        <Route path='/ping' element={<Ping />} />
        <Route path='/details' element={<Details />} />
        <Route path='/login' element={<Login />} />
        <Route path='/signup' element={<SignUp />} />
      </Routes>
    </Router>
  );
}

export default App;
```

#### axiosInstance.js
```js
import axios from 'axios';

const authPath = axios.create({
    baseURL: "http://localhost:5001/api/v1/auth",
    'Content-Type': 'Application/json',
    'Accept': 'application/json',
})

export default authPath;
```

### Integration

#### generate token

```js
function generateToken(userId) {
  return jwt.sign({ id: userId }, SECRET_KEY, { expiresIn: "1h" });
}
```

|Part|Meaning|
|---|---|
|`function generateToken(userId)`|This defines a normal JavaScript function named **generateToken** which expects **userId** as an input parameter (argument). When you call this function you must pass the user’s unique ID.|
|`return`|Sends back the value that this function produces. In this case, it is returning **the JWT token string**.|
|`jwt`|The object imported from the **jsonwebtoken** package you installed. It gives us methods to work with JWT.|
|`.sign()`|A method provided by jsonwebtoken library to **create (sign)** a new token.|
|`{ id: userId }`|This is the **payload** of the token — data you want to store **inside** the JWT. Here, we are storing a simple object with the user's id. Later, when verifying, you can read `decoded.id`.|
|`SECRET_KEY`|A string known only to your server. Used to **digitally sign** the token. Without this secret, no one can generate a valid token. (In real apps, store it in `.env` file and never hard-code it.)|
|`{ expiresIn: "1h" }`|Options object. `expiresIn` sets the **validity time** of the token. Here token will automatically expire in **1 hour**. You can change to `"5m"`, `"30d"` etc.|

---

### ▶️ In spoken English:

> “Create a JWT whose payload is `{ id: userId }`, sign it using SECRET_KEY, set it to expire in one hour, and then return that token.”

---

#### store token in localstorage

[[MERN STACK/JWT|JWT]]

```js
import axios from 'axios';

const authPath = axios.create({
    baseURL: "http://localhost:5001/api/v1/auth",
    'Content-Type': 'Application/json',
    'Accept': 'application/json',
})

// Request Interceptor – Add Auth Token Automatically
authPath.interceptors.request.use((config) => {
    const token = localStorage.getItem('token');
    if(token){
        config.headers.Authorization = `Bearer ${token}`;
    }
    return config;
})

export default authPath;
```

