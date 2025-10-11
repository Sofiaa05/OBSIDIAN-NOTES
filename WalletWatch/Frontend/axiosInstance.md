
```js
import axios from 'axios';
import { BASE_URL } from './utils/apiPaths';

const axiosInstance = axios.create({
  baseURL: BASE_URL,
  headers: {
    'Content-Type': 'application/json',
    Accept: 'application/json',
  },
});

// Request Interceptor – Add Auth Token Automatically
axiosInstance.interceptors.request.use(
  (config) => {
    const accessToken = localStorage.getItem('token'); // get token from localStorage
    if (accessToken) {
      config.headers.Authorization = `Bearer ${accessToken}`; // add token to headers
    }
    return config;
  },
  (error) => {
    return Promise.reject(error);
  }
);

//Response Interceptor – Handle 401 Errors Globally
axiosInstance.interceptors.response.use(
  (response) => {
    return response;
  },
  (error) => {
    if (error.response && error.response.status === 401) {
      console.warn('Unauthorized! Redirecting to login...');
      // Optional: redirect to login page
      window.location.href = '/login';
    }else if(error.response.status === 500){
        console.error("server error, please try again later")
    }else if(error.code === 'ECONNABORTED'){
  console.error("Request timeout, please try again.");
}

    return Promise.reject(error);
  }
);

export default axiosInstance;

```
### 🔹 `import axios from 'axios';`

- `import` → A JavaScript keyword to bring in code from another file or library.
    
- `axios` → The default export of the Axios library.
    
- `'axios'` → This is the name of the installed npm package. When you install Axios via `npm install axios`, this is how you import it.
    

> 📌 This line allows you to use all of Axios’s features in this file.

---

### 🔹 `import { BASE_URL } from './utils/apiPaths';`

- `{ BASE_URL }` → You are importing a **named export** called `BASE_URL` from another file.
    
- `'./utils/apiPaths'` → Path to the file that contains your API base URL.
    

> 📌 This gives you the base part of all your API endpoints like: `http://localhost:5001`

---

### 🔹 `const axiosInstance = axios.create({ ... });`

- `const` → Declares a **constant variable** that cannot be reassigned.
    
- `axiosInstance` → Your custom, reusable Axios object.
    
- `axios.create({...})` → Axios’s method to create an **instance** with custom default settings.
    

> 📌 This line creates a reusable Axios client with pre-configured behavior.

---

### 🔹 Inside `.create()`:

```js
baseURL: BASE_URL,
```

- `baseURL` → Tells Axios what the root URL should be for all requests made using this instance.
    
- `BASE_URL` → This is the variable you imported earlier (e.g., `'http://localhost:5001'`)
    

```js
headers: {
  'Content-Type': 'application/json',
  Accept: 'application/json',
}
```

- `headers` → HTTP headers to be sent with every request by default.
    
- `'Content-Type': 'application/json'` → Tells the server you are sending JSON data in the body of your request.
    
- `Accept: 'application/json'` → Tells the server you want the response to be in JSON format.
    

> 📌 These headers are set automatically for every request sent using this instance.

---

## ✅ Request Interceptor

```js
axiosInstance.interceptors.request.use(
```

- `interceptors.request.use()` → Axios method to **add a request interceptor**.
    
- It runs **before every request leaves your app**.
    

---

### 🔹 Function:

```js
(config) => {
```

- `config` → This is the Axios request configuration object.
    
    - Contains URL, method, headers, data, etc.
        
- Arrow function: `(config) => {}` is the logic that runs before every request is sent.
    

---

### 🔹 Token Logic:

```js
const accessToken = localStorage.getItem('token');
```

- `localStorage.getItem()` → Reads a value from the browser’s local storage.
    
- `'token'` → The key you used to store the token after user login.
    
- `accessToken` → Now contains that token string, or null if not found.
    

```js
if (accessToken) {
  config.headers.Authorization = `Bearer ${accessToken}`;
}
```

- `if (accessToken)` → Only runs this if a token exists.
    
- `config.headers.Authorization` → Modifies the request to add an `Authorization` header.
    
- `` `Bearer ${accessToken}` `` → Follows standard JWT format: `Bearer <token>`
    

---

### 🔹 Return Config:

```js
return config;
```

- You **must return** the modified config object so Axios can use it for the actual request.
    

---

### 🔹 Error Handling:

```js
(error) => {
  return Promise.reject(error);
}
```

- If something goes wrong while modifying the request (rare), this handles it.
    
- `Promise.reject(error)` → Forwards the error so it can be caught by `.catch()` in your code.
    

---

## ✅ Response Interceptor

```js
axiosInstance.interceptors.response.use(
```

- Adds a **response interceptor** — runs **after** a response is received.
    

---

### 🔹 Success Case:

```js
(response) => {
  return response;
}
```

- This is called when the response is successful (`status 200`, `201`, etc.)
    
- Just returns the response so it can be used in your app.
    

---

### 🔹 Error Case:

```js
(error) => {
```

- Called when an error occurs (e.g., 401, 500)
    

---

### 🔹 Handle 401:

```js
if (error.response && error.response.status === 401) {
```

- `error.response` → The HTTP response that contains the error.
    
- `.status === 401` → Means the user is **unauthorized** (likely missing or invalid token)
    

```js
console.warn('Unauthorized! Redirecting to login...');
window.location.href = '/login';
```

- Logs a warning in console
    
- Redirects the user to the login page using the browser.
    

---

### 🔹 Handle 500:

```js
}else if(error.response.status === 500){
  console.error("server error, please try again later")
}
```

- Checks if server gave an internal error (common when backend crashes).
    
- Logs a user-friendly error.
    

---

### 🔹 Handle Timeout (Incorrect Check):

```js
}else if(error.response.status === 'ECONNABORTED'){
  console.error("Request timeout, please try again.");
}
```

🚫⚠️ This check is **incorrect** because `'ECONNABORTED'` is **not** a status code. It’s an **error code**, and it's found in `error.code`, not `error.response.status`.

✅ **Fix:**

```js
}else if(error.code === 'ECONNABORTED'){
  console.error("Request timeout, please try again.");
}
```

---

### 🔹 Final Error Return

```js
return Promise.reject(error);
```

- Sends the error to the component that made the request.
    
- Without this, the component wouldn’t be able to catch the error.
    

---

## ✅ `export default axiosInstance;`

- `export default` → Makes `axiosInstance` available to import in other files.
    
- Now you can use it like:
    

```js
import axiosInstance from './axiosInstance';
axiosInstance.get('/api/v1/dashboard');
```

---

## 🧠 Summary

|Concept|Purpose|
|---|---|
|`axios.create`|Makes a reusable instance of Axios with default settings|
|`request interceptor`|Runs before every request: adds token, headers|
|`response interceptor`|Runs after a response: handles errors, redirects, messages|
|`localStorage.getItem`|Gets your JWT token saved after login|
|`window.location.href`|Redirects the browser to another page (like login)|
