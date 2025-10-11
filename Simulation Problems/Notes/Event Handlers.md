
An event handler is just a function that **runs when something happens** (an *event*).
* A click on a button → `"click"` event
* Typing in an input → `"change"` event
* Submitting a form → `"submit"` event

Think of it like **React saying:**  “When X happens, run this function.”

---
#### Example Without React

If you were using plain HTML/JS:

```html
<button onclick="alert('Clicked!')">Click Me</button>
```

or in JavaScript:

```js
document.querySelector("button").addEventListener("click", () => {
  alert("Clicked!");
});
```

#### Example in React

```jsx
function App() {
  function handleClick() {
    alert("Clicked!");
  }

  return <button onClick={handleClick}>Click Me</button>;
}
```
* `onClick` is the **event name**
* `handleClick` is the **event handler function**

---

### Input Change Event

For forms, the most common event is `onChange`.

```jsx
function App() {
  function handleChange(event) {
    console.log(event.target.value);
  }

  return <input onChange={handleChange} />;
}
```

* `event` is the special object React gives you with info about the event.
* `event.target` is the element (like the input box).
* `event.target.value` is what’s typed.

#### using arrow functions to define event handlers 
```js
return <input onChange={(event) => console.log(event.target.value)} />;
```

---

### Form Submit Event**

```jsx
function App() {
  function handleSubmit(event) {
    event.preventDefault(); // stops page reload
    console.log("Form submitted");
  }

  return (
    <form onSubmit={handleSubmit}>
      <button type="submit">Submit</button>
    </form>
  );
}
```

---

**Key point:** In React, an event handler is just a normal function that you tell React to run when something happens. The difference from plain JS is you use `onClick`, `onChange`, `onSubmit`, etc. as **props**.
