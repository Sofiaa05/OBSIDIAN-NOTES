
- Independent and reusable bits of code.
- Like functions but work in isolation that return HTML elements.
- Two types: Class components and Function components (suggested to use. along with hooks)
- They are **JavaScript functions** that **return React elements.**

### Example: Creating Header component.

```js
import React from 'react';

function Header(){
    return (
            <header>
                <h1>This is header</h1>
            </header>
    );
}

export default Header;
```

#### Points to remember:

1. 
```js
import React from 'react'; 
```
to execute JSX code, without this JSX wont run. **'react'** module provides the mechanism to understand JSX code.

1. You cant put round brackets in next line after return. These round brackets are used immediately next to return. 
	 - No brackets needed for returning a single tag. 

```js
	 return (
```


### How to render the Header Component created above? Two ways.
#### First:  
Importing **"Header.js"** in **"index.js"** and then render it.

```js
import Header from './components/header';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <>
  <Header/>
  </>
);
```
#### Second:  
1. Importing "Header.js" and ,"Slider.js" & "Footer.js" (other components) in "App.js" then,
2. importing App.js in "index.js". 
This makes "index.js" lightweight.

```js
// App.js
import Header from './components/Header';
import Footer from './components/Footer';
function App() {
  return (
    <>
    <Header/>
    <Footer/>
    </>
  );
}

export default App;
```

```js
//index.js
import App from './App';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <App/>
  </React.StrictMode>
);

```

### Rendering a Component

To use component in your application, use similar syntax as normal HTML: example `<Car />`

### Example

Display the `Car` component in the "root" element:

```jsx
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Car />);
```
