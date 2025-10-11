## Two directories:
- frontend
- backend

![[Pasted image 20250706183526.png]]
## 🔷 `src/`

The main source folder of your React app. All your application code lives here.

---

## 📁 `assets/`

Holds **static assets** like:

- Images (logo, icons)
    
- Fonts
    
- SVGs
    

> Example: `logo.png`, `wallet-icon.svg`

---

## 📁 `components/`

Contains **reusable UI components** used across pages:

- `Header`, `Sidebar`, `Button`, `Card`, etc.
    
- These are presentational components (they don’t contain routing or complex logic).
    

---

## 📁 `context/`

This will store your **React Context Providers**, such as:

- Authentication context
    
- Theme context
    
- Global state provider
    

> Example: `AuthContext.js` to share login state across the app.

---

## 📁 `hooks/`

Stores **custom React hooks** you write.

> Example:

```js
useAuth(), useFetch(), useLocalStorage()
```

These help you encapsulate and reuse logic across components/pages.

---

## 📁 `pages/`

Holds top-level **page components**, grouped by feature (great structure).

### 📁 `Auth/`

Contains authentication pages:

- **`Login.js`**  
    UI + logic for user login. Likely includes form input, state, and submission to backend.
    
- **`SignUp.js`**  
    UI for new user registration. Similar to Login but with additional fields.
    

### 📁 `Dashboard/`

Contains pages that are visible after login:

- **`Home.js`**  
    The main dashboard screen. Displays an overview: balance, charts, shortcuts to income/expenses.
    
- **`Income.js`**  
    Page to add/view income records.
    
- **`Expense.js`**  
    Page to add/view expense records.
    

---

## 📁 `utils/`

Holds **utility/helper files** — functions that are reused across multiple parts of the app.

- **`apiPaths.js`**  
    Central place to define all API endpoints (like `/api/login`, `/api/income`, etc.)
    
    ```js
    export const LOGIN_API = "/api/login";
    export const EXPENSE_API = "/api/expense";
    ```
    
- **`data.js`**  
    Static or mock data used in development or testing.
    
    Example:
    
    ```js
    export const expenseCategories = ["Food", "Transport", "Utilities"];
    ```
    
- **`helper.js`**  
    Common utility functions like date formatting, currency formatting, percentage calculator, etc.
    
    ```js
    export function formatCurrency(amount) {
      return `$${amount.toFixed(2)}`;
    }
    ```
    

---

## 📄 `App.js`

- Your main component that defines **routing and app layout**.
    
- Wraps routes inside layout components like `Sidebar`, `Header`, etc.
    
- Likely contains:
    
    ```js
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/login" element={<Login />} />
    </Routes>
    ```
    

---

## 📄 `index.js`

- Entry point of your React app.
    
- Renders the `<App />` component into the DOM root.
    
- May wrap `App` in `<BrowserRouter>` and `<AuthProvider>`.
    

---

## 📄 `index.css`

- Global styles (base Tailwind setup or CSS resets).
    
- You can define app-wide fonts, transitions, or variables here.
    

---

## ✅ Summary Table

|File / Folder|Purpose|
|---|---|
|`assets/`|Images, icons, fonts|
|`components/`|Reusable UI components|
|`context/`|Global state/context providers|
|`hooks/`|Custom reusable hooks|
|`pages/Auth/`|Login and signup pages|
|`pages/Dashboard/`|Main app pages (home, income, expense)|
|`utils/`|API paths, mock data, helper functions|
|`App.js`|Root component and routing setup|
|`index.js`|React app entry point|
|`index.css`|Global CSS or Tailwind base styles|

---

Would you like help wiring up routes between these pages next? Or maybe implement login/signup functionality with dummy data or Firebase?