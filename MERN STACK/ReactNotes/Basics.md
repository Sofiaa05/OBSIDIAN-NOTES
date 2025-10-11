### What is React?

- **JavaScript library** for building **user interfaces.** Developed by facebook.
- Used to build **single-page applications.**
- Allows us to create **reusable UI components.**
- Free and open source library.
- React is a **declarative, efficient, and flexible** JavaScript library for building user interfaces. It lets you compose complex UIs from small and isolated pieces of code called “components”.
- React community also provides advanced concepts like state management, routing, etc. on top of the react library.
- Facebook, Netflix, Instagram, Reddit are based on react.

### How does React Work?

- React creates a VIRTUAL DOM in memory.
- Instead of manipulating the browser's DOM directly, React creates a virtual DOM in memory, where it does all the necessary manipulating, before making the changes in the browser DOM.
- React only changes what needs to be changed!
### Why should we use React?

- Large community on github.
- Component based architecture.
- Virtual DOM
- Declarative Approach
### Declarative Approach:

- Similar to **Abstraction** in OOPs.
- You tell the browser what to do, instead of telling it what you need. The react declarative approach abstracts that for us.
- with declarative code, we tell JS what we want to be done, and let JS take care of performing the steps.

### What is Babel in React?

- JS compiler
- when we create an app using "create-react-app" then babel compiler gets included in our app automatically.
- `create-react-app` includes built tools such as webpack, Babel, and ESLint.


---




## **1. What is a React Element?**

A **React Element** is the smallest building block of a React app. It is a simple **JavaScript object** that describes what you want to display on the screen. it represents the building block of a component. 

🔹 A React Element is **immutable** (it cannot be changed after creation).  
🔹 It represents the **UI structure** but does not interact with the real DOM directly.

---

### **Creating a React Element (Without JSX)**

```js
const element = React.createElement('h1', null, 'Hello, Sofia!');
```

✅ This creates an `<h1>` element with the text `"Hello, Sofia!"`.

---

### **Using JSX (Recommended)**

JSX makes writing React elements easier:

```jsx
const element = <h1>Hello, Sofia!</h1>;
```

✅ This is the same as `React.createElement`, but shorter and easier to read.

---

## **2. What is ReactDOM?**

🔹 **ReactDOM** is a library that takes React Elements and renders them into the **real DOM** (the browser).  
🔹 It connects the **React Virtual DOM** to the **browser's actual DOM**.

### **Rendering an Element using ReactDOM**

```jsx
import React from 'react';
import ReactDOM from 'react-dom';

const element = <h1>Hello, React!</h1>;

ReactDOM.render(element, document.getElementById('root'));
```

✅ **ReactDOM.render()** places the element inside the `<div id="root">`.

---

## **3. Updating the DOM with React**

Unlike traditional JavaScript (`document.getElementById`), React updates the DOM efficiently using the **Virtual DOM**.

🔹 If we update an element in vanilla JavaScript:

```js
document.getElementById('root').innerHTML = "<h1>Hello, World!</h1>";
```

🔹 In React, we **re-render** instead:

```jsx
const newElement = <h1>Hello, World!</h1>;
ReactDOM.render(newElement, document.getElementById('root'));
```

✅ **React only updates the changed part**, not the whole page!

---

## **4. Difference Between React Elements and React Components**

| **Feature** | **React Element**                                     | **React Component**                               |
| ----------- | ----------------------------------------------------- | ------------------------------------------------- |
| Definition  | Smallest UI building block                            | Reusable function/class that returns elements     |
| Syntax      | `React.createElement()` or JSX                        | `function Component() { return <h1>Hello</h1>; }` |
| Mutability  | Immutable (cannot be changed)                         | Can hold state & logic                            |
| Usage       | Defines what should be rendered                       | Encapsulates UI & behavior                        |
|             | Elements are light, stateless and hence it is faster. | slower than elements                              |

---

## **Summary**

✔ **React Element** is a simple object that represents UI.  
✔ **ReactDOM** renders elements to the browser.  
✔ **JSX** makes React elements easier to write.  
✔ **React updates the DOM efficiently using Virtual DOM.**

