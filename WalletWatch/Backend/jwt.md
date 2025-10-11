
```js
const jwt = require('jsonwebtoken');
```

- ✅ **Meaning**: This imports the `jsonwebtoken` library, which allows you to create and verify JWTs (JSON Web Tokens).
    

---

```js
const generateToken = (userId) => {
  return jwt.sign({ id: userId }, process.env.JWT_SECRET, {
    expiresIn: '7d', // valid for 7 days
  });
};
```

### 🔍 Line-by-line Explanation:

|Line|Meaning|
|---|---|
|`const generateToken = (userId) => {`|Defines a function that takes a `userId` and returns a JWT.|
|`jwt.sign({ id: userId }, process.env.JWT_SECRET, ...)`|Creates a signed token using the user ID as payload and your secret key.|
|`{ id: userId }`|This is the **payload**: what you store inside the token — here, the user's ID.|
|`process.env.JWT_SECRET`|This is the **secret key** used to sign the token. It should be kept private (stored in `.env`).|
|`expiresIn: '7d'`|The token will **expire in 7 days** — after that, it won't be valid.|
|`return`|Returns the signed token string.|

---

```js
//register user. This function should create a new user in the database and return a JWT token.
exports.registerUser = async (req, res) => {};
```

### 🔍 Meaning:

- This is a **placeholder function**.
    
- You're exporting a controller function called `registerUser` that will:
    
    1. Take user info from the request (`req.body`).
        
    2. Create a new user in the database.
        
    3. Return a JWT using `generateToken()`.
        

---

```js
//login user. this function should verify the user's credentials and return a JWT token if valid.
exports.loginUser = async (req, res) => {};
```

### 🔍 Meaning:

- Another **placeholder function**.
    
- Will:
    
    1. Check if user exists and password matches.
        
    2. Return a JWT token if credentials are valid.
        

---

```js
//get user info
//This function should verify the JWT token from the request headers and return user information if valid.
exports.getUserInfo = async (req, res) => {};
```

### 🔍 Meaning:

- This function will:
    
    1. Extract the token from request headers.
        
    2. Verify it using `jwt.verify()`.
        
    3. If valid, return the user’s data.
        

---

Let me know when you're ready to implement these, and I’ll walk you through the logic you need — only what you ask for.