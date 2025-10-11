```js
const jwt = require("jsonwebtoken");
const User = require("../models/User");

// Middleware to protect routes
exports.protect = async(req, res, next) => {
    let token = req.headers.authorization?.split(" ")[1];
    if(!token) {
        return res.status(401).json({message: "Not authorized, no token"});
    }
    try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        req.user = await user.findById(decoded.id).select("-password");
        next();
    }catch (error) {
        console.error("Error in authMiddleware:", error);
        res.status(401).json({message: "Not authorized, token failed"});
    } 
};
```



### 🔐 File: `authMiddleware.js`

```js
const jwt = require("jsonwebtoken");
```

- ✅ Loads the `jsonwebtoken` library so you can **verify JWT tokens**.
    

```js
const User = require("../models/User");
```

- ✅ Loads your `User` model so you can **fetch user details from MongoDB** using the decoded token.
    

---

### Middleware Function

```js
exports.protect = async (req, res, next) => {
```

- ✅ This is an Express **middleware function**.
    
- It will be used to **protect routes** (like `/api/v1/auth/user`), so only users with a valid JWT token can access them.
    

---

```js
let token = req.headers.authorization?.split(" ")[1];
```

- ✅ This tries to get the token from the `Authorization` header:
    
    - The header should look like:
        
        ```
        Authorization: Bearer <your-token-here>
        ```
        
    - `split(" ")` splits it into `["Bearer", "<token>"]`
        
    - `[1]` gets the token part
        
- The `?.` (optional chaining) prevents errors if `authorization` is undefined.
    

---

```js
if (!token) {
  return res.status(401).json({ message: "Not authorized, no token" });
}
```

- ❌ If no token is found, respond with a `401 Unauthorized` error and **stop further processing**.
    
- `return` is important so it doesn’t continue executing.
    

---

```js
try {
```

- ✅ Try block to **attempt token verification and user fetching** safely.
    

---

```js
  const decoded = jwt.verify(token, process.env.JWT_SECRET);
```

- ✅ Verifies the token using your JWT secret from `.env`.
    
- If valid, it **decodes** the payload (e.g. `{ id: "userId" }`)
    

---


```js
  req.user = await User.findById(decoded.id).select("-password");
```

- ✅ This fetches the user from MongoDB using the decoded ID.
    
- `.select("-password")` excludes the password from the result for security.
    
- Then attaches the user to the `req` object as `req.user` so the next route handler can use it.
    

---

```js
  next();
```

- ✅ Moves to the **next middleware or route handler** since everything is valid.
    

---

```js
} catch (error) {
  console.error("Error in authMiddleware:", error);
  res.status(401).json({ message: "Not authorized, token failed" });
}
```

- ❌ If token verification fails (invalid, expired, or tampered), the server logs the error and returns a `401 Unauthorized` response.
    
