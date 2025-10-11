![[Screenshot 2025-02-28 at 2.24.09 PM.png]]
- Node JS has a built-in module called **HTTP**, which allows Node.js to **transfer data** over the Hyper Text Transfer Protocol (HTTP).

- This HTTP module provides **utilities for creating HTTP servers and clients.**

- It’s a **fundamental part** of Node JS, enabling the **handling of HTTP requests and responses**

## Node.js as a Web Server



Use the `createServer()` method to create an HTTP server:

```js
var http = require("http");
http.createServer((req,res) => {
    // res.setHeader('content-type','text/plain');
    res.writeHead(200, {'Content-Type': 'text/html'}); //200 means all is OK
    res.write("response from server..");
    res.end(); 
}).listen(3000,() => { //function or method chaining
    console.log("server running at http://localHost:3000");
})
```

##### Explanation :

```js
var http = require("http");
```

The HTTP module can create an HTTP server that listens to server ports and gives a response back to the client.

---


```js
http.createServer((req, res) => {
```

- `http.createServer()` **creates a server.**
- It takes a **callback function** with two parameters:
    - **`req` (request):** Represents the incoming request from the client (e.g., browser, Postman, API call).
    - **`res` (response)**: Represents the response that the server sends back
- The function passed into the `http.createServer()` method, will be executed **when someone tries to access the computer on port 3000.**
---

```js
 res.write("response from server..");
```
- `res.write()` sends the response body.
- The response contains **plain text**, but since we set `Content-Type: text/html`, the browser will still display it
---

```js
res.end(); 
```
**Ends the response**, signaling that no more data will be sent.

---


```js
}).listen(3000, () => {     console.log("server running at http://localHost:3000"); 
});
```
- `.listen(3000, () => {...})` starts the server on **port 3000**.
- The callback `() => { console.log(...) }` runs once the server starts successfully.