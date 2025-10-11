```js
import React from 'react'
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './pages/Dashboard/Home';
import Login from './pages/Auth/Login';

const App = () => {
  return (
    <Router>
      <Routes> 
        <Route path="/" element={<Home />} />
        <Route path="login" element={<Login/>} />
      </Routes>
    </Router>
  )
}

export default App

```

### `<Router>...</Router>`

- Wraps your whole app with **routing capability**.
    
- It listens to URL changes in the browser and tells React which component to render.
    

---

### ✅ `<Routes>...</Routes>`

- This is like a **switch** statement.
    
- It holds all your routes and only matches the **first matching route**.
    

---

### ✅ `<Route path="/" element={<Home />} />`

- If the URL is exactly `/` → render the `Home` component.
    
- Example: Visiting `http://localhost:3000/` will show the **Home** page.
    

---

### ✅ `<Route path="login" element={<Login />} />`

- If the URL is `/login` → render the `Login` component.
    
- Example: Visiting `http://localhost:3000/login` shows the **Login** page.
    

> 🔔 Note: This is a **relative path**. You could also write `path="/login"` — it works the same here.

### Fallback route:

A **fallback route** (also called a **catch-all route** or **404 route**) is a route that matches **any path that doesn’t match your defined routes** — like when a user visits a wrong or non-existent URL.

---

## After code

```js
const root = () => {
  const isAuthenticated = !!localStorage.getItem('token');
  return isAuthenticated ? (
    <Navigate to="/dashboard" />
  ) : (
    <Navigate to="/login" />
  );
};
```



#### ✅ `const root = () => { ... }`

- You're declaring a **new function component** called `root`.
    


#### ✅ `const isAuthenticated = !!localStorage.getItem('token');`

- `localStorage.getItem('token')` → Tries to get the JWT token (from login).
    
- `!!` → Converts it to a **true/false** value:
    
    - If token exists → `true`
        
    - If token is missing → `false`
        

So `isAuthenticated` tells whether the user is logged in.

---

#### ✅ This line:

```js
return isAuthenticated ? (
  <Navigate to="/dashboard" />
) : (
  <Navigate to="/login" />
);
```

- This is a **conditional (ternary) expression**.
    
- If user is authenticated, go to **dashboard**.
    
- Otherwise, go to **login**.
    

> `Navigate` is a special React Router component that **redirects** the user.


---

## 🧠 Summary

|Code|Meaning|
|---|---|
|`export default App`|Main app that is rendered on the page|
|`const root = () => {}`|A component (but not used unless you call it)|
|`!!localStorage.getItem()`|Checks if token exists (user logged in)|
|`<Navigate to="/something" />`|Redirects the user to a route|
