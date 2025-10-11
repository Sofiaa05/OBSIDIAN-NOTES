![[Screenshot 2025-02-18 at 8.59.11 PM.png]]

- Props are **arguments** passed into React components.
- Props are passed to components **via HTML attributes.**
- `props` stands for **properties.**
- React Props are like function arguments in JavaScript _and_ attributes in HTML.
- To send props into a component, use the same syntax as HTML attributes.
- React Props are **read-only! (Immutable)** You will get an error if you try to change their value.

### Example: 
```js
//HelloMsg.js
import React from "react";

function HelloMsg(props){
    return (
        <>
        <h1>Hello world! I am {props.name}</h1>
        <h1>I am {props.age} years old.</h1>
        </>
    );
}
export default HelloMsg;

//index.js
import HelloMsg from './components/HelloMsg';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <HelloMsg name="sofia" age="22"/>
    <HelloMsg name="mukul" age="23"/> {/* reusing component */}
    <App/>
  </React.StrictMode>
);


OUTPUT:
 Hello world! I am sofia

 I am 22 years old.

 Hello world! I am mukul

 I am 23 years old.
```

If you have a variable to send, and not a string as in the example above, you just put the variable name inside curly brackets:

## Children Prop:
```js
//index.js
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <HelloMsg name="sofia" age="22">
      <p>This is child prop 1.</p>
    </HelloMsg>
    <HelloMsg name="mukul" age="23"> 
      <button >click</button>
    </HelloMsg> {/* reusing component */}
    <HelloMsg name={name} age="45">
      <h1>This is child prop 3</h1>
    </HelloMsg>
    <App/>
  </React.StrictMode>
);

//HelloMsg.js
function HelloMsg(props){
    return (
        <>
        <h1>Hello world! I am {props.name}</h1>
        <h1>I am {props.age} years old.</h1>
        {props.children}
        </>
    );
}

```

## Pass Data

Props are also how you pass data from one component to another, as parameters.

```js
export default House;

//Person.js
import React from "react";
function Person(props){
    return(
        <h1>{props.name} lives here</h1>
    );
}
export default Person;

//House.js
import React from "react";
import Person from './Person'
function House(){
    return (
        <Person name="toby"/>
    );
}

//index.js
root.render()
	<House/>
);

```

```jsx
function Car(props) {
  return <h2>I am a { props.brand }!</h2>;
}

function Garage() {
  return (
    <>
      <h1>Who lives in my garage?</h1>
      <Car brand="Ford" />
    </>
  );
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Garage />);
```