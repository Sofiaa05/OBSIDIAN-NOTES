

User Context is a way to store and share the logged-in user's data (like token, name, email) across your entire app, without passing it manually through every component.

---


## ✅ Why Is User Context Needed?

Let’s say your app has this structure:

```
<App>
  <Navbar>
    <UserAvatar />
  </Navbar>
  <Dashboard />
  <Settings />
</App>
```

You want to:

- Show the user's name in `Navbar`
    
- Show user data in `Dashboard`
    
- Use the token to make requests in `Settings`
    

✅ Instead of passing `user` and `token` through props like this:

```js
<Navbar user={user} />
<Dashboard user={user} />
<Settings token={token} />
```

You use **User Context** so every component can access it directly.

---

## ✅ How Do You Create a User Context?

I’ll show you the simple version first.

### 🔹 1. Create the Context File (`UserContext.js`)

```js
import { createContext, useContext, useState } from 'react';

const UserContext = createContext();

export const UserProvider = ({ children }) => {
  const [user, setUser] = useState(null); // holds user info
  const [token, setToken] = useState(null); // holds auth token

  const login = (userData, authToken) => {
    setUser(userData);
    setToken(authToken);
    localStorage.setItem('token', authToken);
  };

  const logout = () => {
    setUser(null);
    setToken(null);
    localStorage.removeItem('token');
  };

  return (
    <UserContext.Provider value={{ user, token, login, logout }}>
      {children}
    </UserContext.Provider>
  );
};

// Custom hook to use this context easily
export const useUser = () => useContext(UserContext);
```

---

### 🔹 2. Wrap Your App with `UserProvider` in `main.jsx`

```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import { UserProvider } from './contexts/UserContext'; // path as needed

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <UserProvider>
      <App />
    </UserProvider>
  </React.StrictMode>
);
```

---

### 🔹 3. Use Context Anywhere

#### ✅ In Navbar:

```js
import { useUser } from '../contexts/UserContext';

const Navbar = () => {
  const { user } = useUser();
  return <div>Welcome, {user?.fullname}</div>;
};
```

#### ✅ In Login:

```js
import { useUser } from '../contexts/UserContext';

const Login = () => {
  const { login } = useUser();

  const handleLogin = async () => {
    const res = await loginUser(email, password);
    login(res.user, res.token); // update context
  };
};
```

#### ✅ In Protected API Call:

```js
const { token } = useUser();
axiosInstance.get('/api/v1/dashboard', {
  headers: {
    Authorization: `Bearer ${token}`
  }
});
```

---

## ✅ What Does Context Store?

You can store anything:

- Logged-in user’s data (`user`)
    
- Token (`token`)
    
- Login / Logout functions
    
- User preferences
    
- Theme (`dark/light`)
    
- Language
    

---

## 🧠 Summary

|Concept|Meaning|
|---|---|
|`createContext()`|Creates a context object for global sharing|
|`UserProvider`|Wraps your app and holds the shared state|
|`useUser()`|Custom hook to access context easily|
|`login()`|Updates the context with user + token|
|`logout()`|Clears the context and token from localStorage|

--- 
## Code explanation


```js
import React, { createContext, useState } from 'react';
export const UserContext = createContext();

export const UserProvider = ({ children }) => {
    const [user, setUser] = useState(null);

    const updateUser = (userData) => {
        setUser(userData);
    }

    const clearUser = () => {
        setUser(null);
    }

    return (
        <UserContext.Provider 
            value={{ 
                user, 
                updateUser, 
                clearUser 
            }}
        >   
            {children}
        </UserContext.Provider>
    );
}

export default UserProvider;
```

---


### 🔹 `import React, { createContext, useState } from 'react';`

- `import React` → You must import React to write any component.
    
- `createContext` → React function to **create a context** (a shared state).
    
- `useState` → React hook to **store and update state** (like user info).
    

---

### 🔹 `export const UserContext = createContext();`

- You're creating a **context object** called `UserContext`.
    
- This object lets your components:
    
    - **Provide** user info
        
    - **Consume** user info (from anywhere in the app)
        

> Think of `UserContext` as a **global container** for storing your logged-in user's info.

---

### 🔹 `export const UserProvider = ({ children }) => {`

- You're creating a **Provider component** called `UserProvider`.
    
- `{ children }` → This means whatever you wrap inside `<UserProvider>` will be passed here.
    

Example usage:

```jsx
<UserProvider>
  <App />
</UserProvider>
```

So `{ children }` here is `<App />`.

---

### 🔹 `const [user, setUser] = useState(null);`

- You are creating a **state variable** called `user`.
    
- `setUser` is the function to **change** that user value.
    
- `null` means the user is not logged in yet.
    

> After login, you’ll store something like `{ name: 'Sofia', email: 'sofia@email.com' }`

---

### 🔹 `const updateUser = (userData) => { setUser(userData); }`

- This is a function that **updates the user data**.
    
- You’ll call it after the user logs in or updates their profile.
    

---

### 🔹 `const clearUser = () => { setUser(null); }`

- This function **removes the user info** from the state.
    
- You’ll call this when the user logs out.
    

---

### 🔹 `return (...)`

This part gives your components access to the user state.

```js
<UserContext.Provider value={...}>
  {children}
</UserContext.Provider>
```

- `UserContext.Provider` is a **wrapper** that shares the state with any nested component.
    
- `value={{ user, updateUser, clearUser }}` means:
    
    - Any component can now:
        
        - **Read** the current user
            
        - **Update** the user
            
        - **Clear** the user
            

---

### 🔹 `export default UserProvider;`

- This lets other files import and use the `UserProvider` component.
    

---

## 💡 So What Does This All Do?

You’re building a **central brain for user data**.

Once setup:

### ✅ You can update user after login:

```js
const { updateUser } = useContext(UserContext);
updateUser({ name: 'Sofia', email: 'sofia@example.com' });
```

### ✅ You can read the user anywhere:

```js
const { user } = useContext(UserContext);
console.log(user?.name); // Sofia
```

### ✅ You can logout:

```js
const { clearUser } = useContext(UserContext);
clearUser();
```

---

## 🧠 Summary (Super Simple):

|Line / Term|Meaning|
|---|---|
|`createContext()`|Makes a shared space to store your user info|
|`UserProvider`|A wrapper to make user info available to your app|
|`useState(null)`|Stores user info (starts empty)|
|`updateUser()`|Login or update user info|
|`clearUser()`|Logout the user|
|`{children}`|Whatever is inside `<UserProvider>` — like your whole app|
|`value={{...}}`|What’s being shared globally — user info & functions|
