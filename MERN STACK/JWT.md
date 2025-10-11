1. create generateToken function, generate token using this function in login and signup
2. send it to the client (frontend) — so that the browser/app can save it and start using it for authentication.

```js
const token = generateToken(user._id);   // step 1: generate

return res.status(200).json({            // step 2: send back to client
  message: "Login successful",
  token: token,
  user: {
    id: user._id,
    username: user.username
  }
});
```

4. After sending: On the **frontend**:

- You **receive this token** from your API response 
- Save it in **localStorage**, **sessionStorage**, or **cookie**
- Send it with every future request to protected routes
---
### The interceptor file

```javascript
// axiosInstance.js
import axios from "axios";

const api = axios.create({
  baseURL: "http://localhost:5000",
});

api.interceptors.request.use((config) => {
  const token = localStorage.getItem("token");
  if (token) {
    config.headers.Authorization = `Bearer ${token}`;
  }
  return config;
});

export default api;
```

---

### `import axios from "axios";`

- `import` → keyword used to _bring code_ from another file/module.
    
- `axios` → HTTP library we installed for making API calls.
    
- Meaning: “Bring the axios library so we can use it here.”
    

---

### `const api = axios.create({ baseURL: "http://localhost:5000", });`

- `const` → create a constant variable.
    
- `api` → the name we give to this variable. You can name it anything (like `client`, `axiosInstance`, etc).
    
- `axios.create()` → This makes a **custom instance** of axios (a copy) with your own settings.
    
- `{ baseURL: "http://localhost:5000" }` → Default base URL to be used in all requests.  
    ⮕ e.g., when we call `api.get("/users")`, it automatically becomes `http://localhost:5000/users`.
    

**📌 Use in other projects:**  
When your backend is running somewhere else (e.g., `https://api.mysite.com`), just change the `baseURL`. Everything else stays the same.

---

### `api.interceptors.request.use((config) => {`

- `api` → The instance we created above.
    
- `.interceptors` → A feature of axios that lets you run some code **before** every request automatically.
    
- `.request` → We are intercepting _outgoing requests_.
    
- `.use()` → Used to add your custom function.
    
- `(config) => { ... }` → A function that gets the original **request configuration** as `config`.
    
---
### `const token = localStorage.getItem("token");`

- `localStorage` → Browser's storage to save small data (persists even after refresh).
    
- `.getItem("token")` → Gets the token string you saved during signup/login.
    
- `token` → variable that will store the value.
    

---

### `if (token) {`

- Checks if token exists (i.e., user is logged in).
    
- If yes → then we attach this token in the request header.
    
---
### ``config.headers.Authorization = `Bearer ${token}`;``

- `config.headers` → The headers object of this request.
    
- `.Authorization` → Name of the header we are setting (standard for JWT tokens).
    
- `` `Bearer ${token}` `` → Template string.  
    Will become like: `"Bearer eyJhbcde....."`  
    (“Bearer” is just a keyword used in JWT systems)
    

So this line means →  
✅ “Attach the token in the Authorization header for this request so backend knows who is making the request”.

---

### `return config;`

- Must return the edited config back to Axios.
    
- Otherwise Axios won’t know what to send.
    

---

### `export default api;`

- `export default` → Makes this file usable in another file.
    
- `api` → The axios instance we created.
    
- So now when someone imports it, they’ll get an axios instance that _already_ attaches the JWT token automatically.
    

---

## 🚀 How to use it in other projects (Ex: React or Next.js)

### React example

```jsx
import api from "./axiosInstance";

async function getData(){
  const res = await api.get("/dashboard");
  console.log(res.data);
}
```

### Next.js example

1. Put `axiosInstance.js` inside `/utils`
    
2. Use like:
    

```ts
import api from "@/utils/axiosInstance";

export default async function handler(req, res) {
  const response = await api.get("/dashboard");
  res.json(response.data);
}
```

**You don’t have to write that interceptor code again —  
just copy this file into any project and only change `baseURL`.**

---

## ✅ Final Summary (for remembering)

- Create a separate `axiosInstance`
    
- Interceptor adds token automatically before each request
    
- Saves you from repeating headers `{ Authorization: ... }` everywhere
    
- Reusable in **all future projects** like React, Next.js, Vue — only change baseURL
    

---

Would you like me to create a **diagram flow** or a **learn-with-analogy** explanation of this so you can remember it super easily?