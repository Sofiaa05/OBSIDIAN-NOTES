### Frontend:
#### React: 
- “React is a tool that helps you build the **frontend** (what the user sees) of a web app using components.”
- It helps you build **fast, interactive, and reusable** web pages.

|   |   |
|---|---|
|📦 **Component-Based**|You break the UI into small reusable parts|

|   |   |
|---|---|
|⚡ **Fast Updates**|It changes only the parts of the page that need updating|

|   |   |
|---|---|
|🎯 **One-Way Data Flow**|Data flows clearly from parent to child|

|   |   |
|---|---|
|💻 **Virtual DOM**|React uses a smart copy of the webpage to update only what's needed|

|   |   |
|---|---|
|🔁 **Reusable Code**|Write once, use many times|
#### Axios:
- **What is Axios?**
    
    > “Axios is a library to send HTTP requests from frontend to backend.”
    
- **Why use Axios instead of fetch()?**
    
    > “Axios is easier to use, supports older browsers, and handles JSON and errors better.”
    
- **What does Axios do in my project?**
    
    > “It sends the user’s search query to the backend and gets back a matching URL.
---
---

### Backend:

#### API:
- "An API works like a middleman between the frontend and the backend. It receives a request, the backend processes it, and the API returns the response to the frontend."
- We use REST APIs (REpresentational State Transfer - Application Programming Interface) when frontend and backend communicate over HTTP.(GET, POST, PUT, DELETE.")
- API as a waiter, server as kitchen, user as frontend, menu as routes
- interface/communication channel between two softwares applications
----

#### Express:
- Express is a Node.js **framework** that makes it easier to create backend APIs and servers. It helps me handle routing, requests, and responses in a clean and simple way. Without Express, I’d have to write a lot more code to do the same things.

| **Without Express (Pure Node.js)**            | **With Express.js**                            |
| --------------------------------------------- | ---------------------------------------------- |
| Long and repetitive code to handle routes     | Clean and short route definitions              |
| You handle HTTP requests manually             | Express handles it for you                     |
| No built-in routing system                    | Comes with powerful routing (like `app.get()`) |
| Hard to scale as app grows                    | Easy to build big apps with routes/controllers |
| No middleware support (must write everything) |  Built-in middleware system (like `app.use()`) |

---
#### NodeJS:
- Normally:

	- JavaScript runs **only in browsers** (like Chrome, Firefox).
	    
	- You use it for things like buttons, animations, or forms in the frontend.
    

###  But with Node.js:

- You can use JavaScript to write **backend code** — like handling APIs, connecting to databases, and sending data
---

#### Mongoose: 
- You **don’t interact with the schema directly** — instead, you interact with the **model** that Mongoose builds **from the schema**.
- **Mongoose** is a **library for Node.js** that helps you **interact with MongoDB** .
- **translator** between your **JavaScript code** and your **MongoDB database**.
- cleaner, readable code
##### NEED:
MongoDB is **schema-less** by default — you could accidentally insert inconsistent or broken data.

```JS
// With native MongoDB:
db.users.insert({ name: "Sofia" }); // Okay
db.users.insert({ name: 5 });       // Also okay 😬

```

> ❌ No consistency = potential bugs

 **With Mongoose**, you define a schema:
 ```JS
 const userSchema = new mongoose.Schema({
  name: { type: String, required: true }
});
```

---
#### CORS (cross origin resource sharing)
- “API is how frontend talks to backend. CORS decides **if** that talk is allowed across different origins.”
    
- **Why do we need CORS?**
     “To let frontend and backend talk when they’re on different ports or domains. Otherwise, browser blocks it.”
    
-  **Why did I use CORS in my project?**
     “Because my React frontend runs on port 3000 and backend on 5001. CORS allows them to share data. Browsers follow **Same-Origin Policy** by default, which means:  
**Frontend can only call backend on the same origin** unless allowed. cors allow it

- even if they’re on the same machine, but different **port**, it’s a **different origin**.  
Or even if they're on different machines — still different origins
- Yes, CORS is still needed if the **frontend and backend are on different origins**, even if they’re on different machines, because browsers block such requests unless allowed.


---
---

### Database:
#### MongoDB:
"MongoDB is a NoSQL database that stores data in documents like JavaScript objects.  
I used it in my MSN Clone project because it fits perfectly with JavaScript-based tech like React and Node.  
Since my app has dynamic content — like links, search results, and categories — MongoDB gave me the flexibility and speed I needed without worrying about strict table designs."

---

| **File/Folder** | **Use**                                                            |
| --------------- | ------------------------------------------------------------------ |
| `server.js`     | Starts your backend and connects everything (server + DB + routes) |
| `models/`       | Defines what your data should look like using Mongoose schemas     |
| `routes/`       | Tells what URL should do what                                      |
| `controllers/`  | Holds the logic that runs when someone hits a URL                  |

