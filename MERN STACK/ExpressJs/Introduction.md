- ## What is Express JS ? 

	* Minimal and flexible Node.js web application **framework**.
	
	* It simplifies the process of **building web servers** and **APIs** by providing a set of tools and **middleware** to handle various tasks such as **routing, request handling, and response management.**
---


- ## Key Features of Express JS
	1. **Middle ware Support :** Middleware functions are executed **before** the final request handler. Express.js uses middleware functions to handle HTTP requests, **authentication, logging, request parsing, error handling** etc.

	2. **Routing :** Allows you to define routes for different HTTP methods (GET, POST, PUT, DELETE) easily.
	3. **Templating Engine Support :** Supports templating engines like **EJS, Pug, and Handlebars** for dynamic HTML rendering.
	4. **Error Handling :** Provides a centralized way to handle errors.
	5. **Static File Serving :** Can serve static files like **HTML, CSS, JS, and images**.
	6. **RESTful API Development :** Makes it easy to build RESTful APIs for frontend-backend communication.

## Installation :
```js
npm install express

//or

npm install express@latest
```

---
### Creating a simple Express Server

```js
var express = require('express'); // Import Express
var app = express(); // Create an Express app

// Define a route
app.get('/' , (req,res) => {
    res.send('Hello Toby');
});

// Start the server
app.listen(3000);
```

##### Explanation : 

```js
var app = express(); 
```

* `app` is now an **instance of Express** that we use to define routes, middleware, and server behavior.
* Like creating an object of a class. Where, class = "express()" class and object = app
#### - app.get(route, callback)
```js
app.get('/' , (req,res) => {
    res.send('Hello Toby');
});
```
This app.get() function tells **what to do** when a get request at the given route is called.

#### -res.send()
This function takes an **object as input**, sends this to the requesting client. 

#### - app.listen() 
This function binds and listens for connections on the specified host and port.

---
### How to render JSON and HTML elements in ExpressJS :
```js
app.get('/' , (req,res) => {
    res.send(`<h1>Hello, This is Home page.</h2>
        <a href='/about'>About us<a/>`);
});

app.get('/about' , (req,res) => {
//array of objects
    res.send([
            {name: 'sofia',
                age: 69
            },
            {
                name: 'mukul',
                age: 70
            }
        ]);
});

```

https://www.geeksforgeeks.org/explain-the-use-of-req-and-res-objects-in-express-js/

---
### **Cookies Management in Express.js** 🍪


- Cookies are **small pieces of data** stored in the browser to maintain **user sessions, authentication, and preferences.** 
- Express.js makes it easy to handle cookies using the **`cookie-parser`** middleware.

---
## Serving static files 

```js
var express = require('express'); // Import Express
var app = express(); // Create an Express app
var path = require('path');

var public = path.join(__dirname , 'public'); 
app.use(express.static(public))
app.listen(3000);
```

##### Explanation :
#### 1. express.static() : 
- middleware that **serves static files** from a specified directory.
- achieves this by **mapping URLs directly to files** in the specified directory.

![[Screenshot 2025-03-01 at 6.15.46 PM.png]]

#### 2. app.use() :

* To define middleware that **executes on every request,** regardless of the HTTP method (GET, POST, PUT, DELETE, etc.)
---
## How to remove file extension from URL in ExpressJS :
```js
var public = path.join(__dirname , 'public'); 
app.use(express.static(public))

app.get('/',(req,res) => {
    res.sendFile(`${public}/index.html`);
});

app.get('/about',(req,res) => {
res.sendFile (`${public}/about.html`)  
})

app.listen(3000);
```

