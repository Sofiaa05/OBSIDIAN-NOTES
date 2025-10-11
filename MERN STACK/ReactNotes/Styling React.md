

---

## 1. Inline Styling

- To style an element with the inline style attribute, the **value must be a JavaScript object:**

- **Note:** In JSX, JavaScript expressions are written inside curly braces, and since JavaScript objects also use curly braces, the styling in the example above is written inside two sets of curly braces `{{}}`.

- camelCased Property Names

#### Example:

Use `backgroundColor` instead of `background-color`:

```jsx
const Header = () => {
  return (
    <>
      <h1 style={{backgroundColor: "lightblue"}}>Hello Style!</h1>
      <p>Add a little style!</p>
    </>
  );
}
```

[Run Example »](https://www.w3schools.com/REACT/showreact.asp?filename=demo2_react_css_camelcase)

---
### 1. using JavaScript Object:
You can also create an object with styling information, and refer to it in the style attribute:

#### Example:

Create a style object named `myStyle`:

```jsx
const Header = () => {
  const myStyle = {
    color: "white",
    backgroundColor: "DodgerBlue",
    padding: "10px",
    fontFamily: "Sans-Serif"
  };
  return (
    <>
      <h1 style={myStyle}>Hello Style!</h1>
      <p>Add a little style!</p>
    </>
  );
}
```

[Run Example »](https://www.w3schools.com/REACT/showreact.asp?filename=demo2_react_css_inline_object)

### 2. Using Spread Operator

```js
const Styling = () => {
  const style1 = {
    color: "white",
    backgroundColor: "DodgerBlue",
    padding: "10px",
    fontFamily: "Sans-Serif"
  };
  const style2 = {
	  fontSize: "50px",
	  fontFamily: "cooper"
  }
  return (
    <>
      <h1 style={{...style1,...style2}}>Hello Style!</h1>
      <p>Add a little style!</p>
    </>
  );
}
```
---
---
# CSS Modules In React :

- Another way of adding styles to your application is to use CSS Modules.
- CSS Modules are convenient for components that are placed in separate files.
- The CSS inside a module is available only for the component that imported it, and you do not have to worry about **name conflicts.**
- CSS **Modules** are **locally scoped.**
- CSS **Stylesheets** (External Style) are **globally scoped.**
- CSS Module converted in different format in browser:
	 Filename_classname_hashcode
- CSS Modules feature is available with **react-scripts@2.0.0** and higher. 