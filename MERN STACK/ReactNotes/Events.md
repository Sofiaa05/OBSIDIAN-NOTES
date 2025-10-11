Just like HTML DOM events, React can perform actions based on user events.

React has the same events as HTML: **click, change, mouseover etc.**

---

## Adding Events

React events are written in **camelCase** syntax:

**`onClick`** instead of **`onclick`.**

React event handlers are written inside curly braces:

**`onClick={shoot}`**  instead of `onclick="shoot()"`.



![[Screenshot 2025-02-21 at 2.47.59 PM 1.png]]


```js
//functional component
import React from 'react';

const ClickFunction = () =>{

    const show = () =>{
        alert("You have implemented this using events.");
    }

    return(
        <>
        //dont put () after the function calling.
        <button onClick={show}>Click me for an event</button> 
        </>
    );
}

export default ClickFunction; 
```

```js
//Class component events
export class ClickClassComp  extends Component{

    show2=()=>{
        alert("You have implemented this using class component events.");
    }
    render(){
        return(
            <>
            <button onClick={this.show2}>Click me for class component event</button>
            </>    
        )
    }
}
```

## Passing Arguments & Props

To pass an argument to an event handler, use an arrow function.

```js
import React from 'react'

export default function PassingArgs(props) {
    //always use arrow function for passing arguments to an event handler
    const show = (a) => {
        alert(`Hello ${a}`);
    }

  return (
    <div>
      <button onClick={() => show("Arguments are passed here")}> FunComp Event.          using Args</button>
      
      <button onClick={() => show("Arguments are passed here using " + 
      props.name )}>FunComp Event using props</button> 
      
    </div>
  )
}
```

---------------------------------important stuff ends here--------------------------------------


```js
//class component event using props
    show1 = (props) => {
        alert(`Example usage of  ${props}  passed to class component events`);
    }

    render(){
        return(
            <>  
            //binding events     
            <button onClick={() => this.show1(this.props.propName)}>Btn1</button>
            </>    
        )
    }
}
```




## What is binding event handlers in React?

- Event Binding tells the browser that **this** function should be called whenever this event is triggered.
  
- Bind creates a new function that will have **this** set to the first parameter passed to **bind().**

### Binding Event Handlers

- In ReactJS, we need to bind events so that the **this** keyword would not return an "undefined".
### 1. Binding Event Handler using Arrow Function

- This is probably the best way to bind the events and still pass in parameters to the event handlers easily.
  
- By using this way you don’t need to bind **“this”** keyword.

### 2. Binding Event Handler in Render Method

- We can bind the handler when it is called in the render method using **bind()** method
```js
<button onClick={this.clickHandler.bind(this)}>Click</button>
```

### 3. Binding Event Handler in the Constructor

- Bind the event handler inside the constructor. This approach is also mentioned in ReactJS documentation.
    
- This has performance benefits as the events aren’t binding every time the method is called and binding starts as soon as constructor starts.
```js
constructor(){
super();
	this.<EventName> = this.<EventName>.bind(this);
}
```