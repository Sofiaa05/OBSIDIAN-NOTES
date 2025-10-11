Here’s the extracted text:

**What is JSX?**  
- JSX stands for JavaScript XML.  
- JSX is an extension of JavaScript Language.  
- JSX allows us to write HTML in React.  
- JSX makes it easier to write and add HTML in React.

### With JS:

```JS
function App() {
  return (
    <div className="App">
      <h1>Learning react!</h1>
    </div>
  );
}
```

### Without using JSX only JS:

```js
function App() {
  return ("div", {
    className: "App",
    children:("h1", {
      children: "Learning react!"
    })
  });
}
```

- JSX allows us to write HTML elements in JavaScript and place them in the DOM without any `createElement()`  and/or `appendChild()` methods.
- JSX converts HTML tags into react elements.
- You are not required to use JSX, but JSX makes it easier to write React applications.

### Expressions in JSX

With JSX you can write expressions inside curly braces `{ }`.

The expression can be a **React variable**, or **property**, or any other valid JavaScript **expression**. JSX will execute the expression and return the result
```js
let name = "sofia"
function App() {
  return (
    <div className="App">
      <h1>Learning react!</h1>
      <h1>hi my name is {name}. my age is {11+11}</h1>
    </div>
  );
}


Output:
hi my name is sofia. my age is 22
```

### One Top Level Element

- The HTML code must be wrapped in _ONE_ top level element.
- So if you like to write _two_ headings, you must put them inside a parent element, like a `div` element. (see above code)
- JSX will throw an error if the HTML is not correct, or if the HTML misses a parent element.
- Alternatively, you can use a **"fragment"** to wrap multiple lines.
- A fragment looks like an empty HTML tag: **`<></>`.**

```js
function App() {
  return (
    <>
    <h2>fragment example</h2>
    <div className="App">
      <h1>Learning react!</h1>
      <h1>hi my name is {name}. my age is {11+11}</h1>
    </div>
    </>
  );
}
```

### Elements Must be Closed:
- JSX follows XML rules, and therefore HTML elements must be **properly closed**.
- Close empty elements with **`/>`**
- JSX will throw an error if the HTML is not properly closed.

### Attribute class = className:

The **`class`** attribute is a much used attribute in HTML, but since JSX is rendered as JavaScript, and the `class` keyword is a reserved word in JavaScript, you are not allowed to use it in JSX.

Use attribute **`className`** instead. When JSX is rendered, it translates `className` attributes into `class` attributes.

### Conditions - if statements

React supports **`if`** statements, but not _inside_ JSX.

To be able to use conditional statements in JSX, you should put the `if` statements **outside of the JSX**, or you could use a **ternary expression instead**:

#### Option 1: 
Write `if` statements outside of the JSX code:

```js
let val = 10;
let msg=" "
if (val>20){
  msg="hello";
}
else{
  msg="Bye";
}

function App() {
  return (
    
    <div className="App">
     <h1> {msg} </h1>
    </div>

  );
}

output: Bye
```

#### Option 2:
Use ternary expressions instead to write if statement inside JSX code: 

```js
let val = 10;

function App() {
  return (
    
    <div className="App">
      <h1>{(val>20) ? msg="Hello" : msg="Bye"}</h1>
    </div>
  );
}

output: Bye
```