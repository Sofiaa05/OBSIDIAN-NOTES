# 1. Navigation on Button Click :
- **`useNavigate()`** is a React Router hook that allows navigation **without using `<Link>` or `<NavLink>`**.
- `navigate` is a function that lets us change pages programmatically.

## Full code:
```js
function App() {
  const navigate =useNavigate();
  return (
    <>
    <Navbar/> {/*Renders the Navbar component so users can click links to navigate. */}
    <Routes>
      <Route path='/' element={<Home/>}/> 
      <Route path='/about' element={<About/>}/>
      <Route path='/contact' element={<Contact/>}/>
    </Routes>
    <button onClick={() => navigate('/about')}>About</button>
    <br></br>
    <button onClick={() => navigate('/contact')}>Contact</button>
    </>
  );
}
```

##### Explanation :
```js
import { Routes, Route, useNavigate } from 'react-router-dom';
```

```js
<button onClick={() => navigate('/about')}>About</button> <br></br> <button onClick={() => navigate('/contact')}>Contact</button>
```

- These buttons **navigate to different pages** when clicked.
- `navigate('/about')` changes the URL to `/about`, triggering React Router to load the `About` component.
- `navigate('/contact')` changes the URL to `/contact`, loading the `Contact` component.
- This is useful when you want navigation **without clicking links** (e.g., **after form submission or authentication).** Enables navigate **after an event.**
---
# 2. Navigation inside event handler :
```js
function App() {
  const navigate =useNavigate();

//creating an events
  const NavigateToAbout = () => {
    navigate('/about');
  }
    const NavigateToContact = () => {
    navigate('/contact');
  }

return(
<button onClick={() => NavigateToAbout()}>About</button>
<button onClick={() => NavigateToContact()}>Contact</button>
)
```
---

# 3. Navigating to Multiple Pages with Single Event Handler 

```js
  const navigate =useNavigate();
  
//single event handler
  const NavigateTo = (url) => {
    navigate(url);
  }
  
return (
    <button onClick={()=>NavigateTo('/about')}>About</button>
    <button onClick={() => NavigateTo('/contact')}>Contact</button>
)

```

Note: 
```js
<button onClick={NavigateTo('/contact')}>Contact</button> 
```
🚨 Error: Calls `NavigateTo('/contact')` immediately on render.

```js
<button onClick={() => NavigateTo('/contact')}>Contact</button>
```
 Fix: Uses an arrow function to execute only when clicked.

---
# 4. Condition based Navigation :
```js
   const NavigateToWhere = (name) => {
    if (name === 'goby') {
      navigate('/about');
    } else {
      navigate('/contact');
    }
  };

return(
      <button onClick={() => NavigateToWhere('sofia')} >Click me</button>
);

//navigates to contact page
```
---
# 5. Go back
```js
//App.js
    <button onClick={() => navigate(-1)}>Go back</button>   
    <br></br>
    <button onClick={() => navigate(1)}>Go Forward</button>   

```

##### Explanation :
- This button is used for **navigating back to the previous page** in React Router.
- `navigate(-1)` tells React Router to **go back one step in history**, just like pressing the **back button** in a browser.
- `navigate(1)` tells React Router to **go forward one step**
- Example:

	1. You start on **Home (`/`)**.
	2. Click a link to go to **About (`/about`)**.
	3. Click **"Go back"** → It takes you **back to Home (`/`)**.