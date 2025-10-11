### **Day 2 — Simple CRUD**

- **Backend:** Build `/api/users` route (GET, POST) with in-memory storage.
    
- **Frontend:** Create a form to add a new user (name, email) and a table to list users.
    
- **Integration:** Form submission → POST to backend → refresh list.

### Backend

```js
//server.js

//creating user route
app.use(express.json());

//"In-memory" storage
let users = [];

app.get("/api/users", (req, res) => {
    res.json(users); //automatically JSON.stringify whatever data is being sent 
})

app.post("/api/users", (req, res) => {
    const user = req.body;
    users.push(user);
    res.status(200).json(user); //set Content-Type: application/json.
})
```

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

  function fetchUsers(){
    axios.get("http://localhost:5001/api/users")
    .then(res => setUsers(res.data))
    .catch(err => { 
        setError("Error fetching users");
        console.log(err.message);
    })
  }

  function handleSubmit(e) {
    e.preventDefault(); // Prevent page reload
    console.log("Form submitted:");
    console.log("Name:", name);
    console.log("Email:", email);

    const newUser = { name, email };

    axios.post("http://localhost:5001/api/users", newUser)
    .then(res =>{
        setName("");
        setEmail("");
        setError("");
        fetchUsers();
    })
    .catch(err => {
        setError(err.response?.data?.error || "Error adding user"); 
    } )
  }

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <div>
          <label>
            Full Name:
            <input
              type="text"
              placeholder="Enter your name"
              value={name}
              onChange={(e) => setName(e.target.value)}
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
            />
          </label>
        </div>
        <button type="submit">Submit</button>
      </form>

      {error && <p style={{ color: "red" }}>{error}</p>}
      
      <h2>Users List</h2>
      <table border="1" cellPadding="5">
        <thead>
          <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Email</th>
          </tr>
        </thead>
        
        <tbody>
          {users.map(user => (
            <tr key={user.id}>
              <td>{user.id}</td>
              <td>{user.name}</td>
              <td>{user.email}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

```

#### What is `key={user.id}`

In React, when you render lists, you must give each element a **unique `key`** so React can track them.

- Here, we use `user.id` because IDs are unique.
    
- Without `key`, React will warn you and may update the DOM inefficiently.
- req object;
- axios async await 
- useState() : passing null parameters for different data types.
- optional chaning, if else, ternary, js shorthand
