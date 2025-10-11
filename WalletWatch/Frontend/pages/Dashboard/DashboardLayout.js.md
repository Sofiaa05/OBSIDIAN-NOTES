```js
import React, { useContext} from 'react';
import { UserContext } from '../../context/userContext';
import Navbar from './Navbar';
import SideMenu from './SideMenu';

const DashboardLayout = ({children, activeMenu}) => {
    const {user} = useContext(UserContext);
  return (
    <div className=''>
        <Navbar activeMenu={activeMenu} />
        {user && (
            <div className=''>
                <div className=''>
                    <SideMenu activeMenu={activeMenu} />
                </div>

                <div className=''>{children}</div>
            </div>
        )}
    </div>  
  )
}

export default DashboardLayout

```

```js
import React, { useContext } from 'react';
```

- `React` is needed to build your UI.
    
- `useContext` is a special tool to **get global user data** from `UserContext`.
    

---

```js
import { UserContext } from '../../context/userContext';
```

- You’re importing the **UserContext** where user login data (like name, email, etc.) is stored globally.
    

---

```js
import Navbar from './Navbar';
```

- Brings in your top navigation bar component.
    

---

```js
import SideMenu from './SideMenu';
```

- Brings in the **left sidebar** menu (with options like dashboard, profile, logout, etc.).
    

---

```js
const DashboardLayout = ({ children, activeMenu }) => {
```

- You’re creating a new **React component** called `DashboardLayout`.
    
- `children`: any inner content (like the actual dashboard, income screen, etc.).
    
- `activeMenu`: tells which menu item should be highlighted in the sidebar.
    

---

```js
  const { user } = useContext(UserContext);
```

- Using `useContext` to **get the logged-in user** from `UserContext`.
    
- `user` will contain info like: `{ name: "Sofia", email: "sofia@gmail.com" }`
    
- If no user is logged in → it will be `null`.
    

---

```js
  return (
    <div className=''>
```

- Starts rendering the layout.
    
- First outer `<div>` wraps the entire dashboard page.
    

---

```js
      <Navbar activeMenu={activeMenu} />
```

- Shows the top `Navbar`.
    
- Passes the `activeMenu` so Navbar can highlight current page (optional).
    

---

```js
      {user && (
```

- This means: **"Only show this next part if a user is logged in."**
    
- If `user` is not null, the dashboard layout (side menu + content) will be shown.
    

---

```js
        <div className=''>
```

- Starts a container to hold sidebar + main content.
    

---

```js
          <div className=''>
            <SideMenu activeMenu={activeMenu} />
          </div>
```

- Renders the left `SideMenu` component.
    
- Passes `activeMenu` so it knows which item is currently selected.
    

---

```js
          <div className=''>
            {children}
          </div>
```

- This area displays the main page content (like Dashboard, Income, Expense).
    
- `{children}` is what gets injected **inside** `DashboardLayout` when used like:
    
    ```jsx
    <DashboardLayout>
      <h1>This is content</h1>
    </DashboardLayout>
    ```
    

---

```js
        </div>
      )}
    </div>  
  )
```

- Ends the layout, wraps everything, and closes the conditional block.
    

---

```js
export default DashboardLayout;
```

- Makes this component usable in other files like `Home.js`.
    

---

## 🔁 Summary

|Word/Piece|Meaning|
|---|---|
|`useContext()`|Read global data (like user)|
|`UserContext`|Shared storage of user info|
|`Navbar`|Top bar UI|
|`SideMenu`|Sidebar UI|
|`children`|The page that’s inside layout|
|`activeMenu`|Current tab to highlight|
|`{user && (...)}`|Only show content if user is logged in|

---
