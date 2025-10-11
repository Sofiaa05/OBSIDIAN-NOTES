o![[Screenshot 2025-02-25 at 12.00.19 PM.png]]
- It enables the **navigation among various components** in a React Application.
- React Router is a **fully-featured client and server-side routing library** for React.
- React Router runs anywhere React runs; on the web, on the server with node.js, and on React Native 

- Create React App doesn't include page routing by default. React Router is the most popular solution.

- It provides **unique URLs for different components** in the app and makes Ul easily shareable with other Users.

## Add React Router
```js
npm i -D react-router-dom
```

If you are upgrading from **v5**, you will need to use the @latest flag:

```js
npm i -D react-router-dom@latest
```

```js
  <React.StrictMode>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  </React.StrictMode>

```

##### Explanation :
### `<React.StrictMode>`

- Wraps the application to help identify potential problems in the code.
- Enables additional checks and warnings during development (e.g., detecting side effects, deprecated APIs).
- **It does not affect production builds**—only helps in development.
### `<BrowserRouter>`

- Comes from `react-router-dom`, allowing **client-side navigation without full page reloads.**
- Wraps the **`<App />`** component, enabling **routing throughout the application.**
- Uses the browser's history API (`pushState`) to handle navigation.

###  `<App />`

- This is your root component where all other **components and routes are rendered.**
---
## Configuring Routes >
### 1st Step:
1. Import **BrowserRouter** Component from **‘react-router-dom’** inside Index.js File in our React App.
2. Wrap App component <App/> with BrowserRouter Component.
```js
  <React.StrictMode>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  </React.StrictMode>
```

### 2nd Step:

Create a folder called **‘components’** in our SRC folder and add your components in it.

### 3rd Step:

1. Import **Routes and Route Component** from ‘react-router-dom’ in App.js File.

2. Use **path prop to define URL.** 
3. Use **element prop** to define the corresponding **component.**

4. Don't forget to i**mport components** you are using inside App.js 
```js
import { Routes, Route } from 'react-router-dom';

import Home from './Components/Home';
import About from './Components/About';

function App() {
  return (
    <Routes>
      <Route path='/' element={<Home/>}/> 
      <Route path='/about' element={<About/>}/>
    </Routes>
  );
}
```

This means when the URL is **`/about`**, the **`About`** component will render.