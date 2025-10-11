- React Class components have a **built-in `state` object.**
- The `state` object is where you store property values that belongs to the component.
- When the `state` object changes, the component **re-renders.**
- The change in state can happen as a response to user action or system-generated events, and these changes determine the behavior of the component and how it will render.
- Constructor is used to initialize the object's state.

---

 ### Creating the state Object

- The state object is initialized in the constructor
- It can store multiple states.


---
 ### Using the `state` Object

- Refer to the `state` object anywhere in the component by using the **`this.state._propertyname_`** 

---


 ### Changing the `state` Object

- To change a value in the state object, use the **`this.setState()`** method.
- State can be updated in response to event handlers, server responses, or props changes.
- Enqueues all of the updates made to the component state and insttucts React to re-render the component and its children with the updated state.
- Always use the setState() method to change the state object, since it will ensure that the component knows it’s been updated and calls the render() method.

---

```js
import React, { Component } from 'react';

export default class State extends Component {
    constructor(props) {
        super(props);
        
        //Creating state object
        this.state = {
            //initialising intiial states
            text: "This is before changing state",
            count: 0 
        };
    }

    // to change text 
    changeText = () => { 
    
	    //Changing the state object
        this.setState({
            text: "This is after changing state", 
        });
    };

    ////will increment count value on clicking button
    changeNumber = () => {
        this.setState({
            count: this.state.count+1 
        })
    };

    render() {
        return (
            <>
	            //using the state onject
                <h1>{this.state.text}</h1>
                <h1>{this.state.count}</h1>
                <input type='button' value="Click to change text" onClick={this.changeText} />
                <button type='button' onClick={this.changeNumber}>click to change number</button>
            </>
        );
    }
}

```

with Function Components: [[UseState]]  (Scroll till end)