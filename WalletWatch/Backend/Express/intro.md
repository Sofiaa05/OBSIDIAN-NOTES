**Express.js** is a **minimal and flexible web application framework** for **Node.js** that provides a robust set of features to build **single-page, multi-page, and RESTful web applications** and **APIs**. It simplifies the process of handling **HTTP requests**, **routing**, **middleware**, and **server-side logic**, allowing developers to build web apps efficiently.

## Features
| Feature                 | Description                                                            |
| ----------------------- | ---------------------------------------------------------------------- |
| ⚡ Fast & Lightweight    | Built on Node.js core HTTP module, but faster to develop with          |
| 🧩 Middleware Support   | Use functions to modify request/response objects and control the flow  |
| 🛣️ Powerful Routing    | Define URL routes using HTTP verbs like GET, POST, etc.                |
| 🧱 Modular Structure    | Split app into routes/controllers/middleware easily                    |
| 🛡️ Error Handling      | Built-in and custom error handling capabilities                        |
| 🎭 Template Engines     | Supports Pug, EJS, Handlebars etc. for dynamic HTML                    |
| 🔐 Integration Friendly | Works well with databases, auth, third-party APIs, logging tools, etc. |
| 🔄 REST API Ready       | Designed to easily create RESTful APIs                                 |

```js
// 1. Import the Express module
const express = require('express');

// 2. Create an Express application
const app = express();

// 3. Define a route (URL endpoint) for GET requests to the root ('/')
app.get('/', (req, res) => {
  res.send('Hello Sofia, welcome to Express!');
});

// 4. Start the server and listen on port 3000
app.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});

```

#### `const express = require('express');`

- Loads the **Express module** using CommonJS `require`.
    
- Without this line, you can’t use Express functions like `app.get()`, `app.listen()`.
    

#### 2️⃣ `const app = express();`

- Calls the function returned by `express`, which creates an **Express application object**.
    
- This `app` is like your main restaurant controller — it can set up routes, middleware, start server, etc.
    

#### 3️⃣ `app.get('/', (req, res) => { ... });`

- This defines a **route**:
    
    - `'/'` is the **URL path**.
        
    - `'GET'` is the **HTTP method** (user typing URL in browser triggers GET).
        
    - `(req, res)` is a **callback function** that runs when someone visits `'/'`.
        
        - `req`: contains request data (e.g., headers, URL, params).
            
        - `res`: lets you **send a response** back to the client.
            
- Inside, `res.send()` sends a plain text message as the response.
    

#### 4️⃣ `app.listen(3000, () => { ... });`

- Starts the server.
    
- Tells the app to **listen on port 3000** (standard port for local dev).
    
- The callback inside logs a message to let you know the server is running.