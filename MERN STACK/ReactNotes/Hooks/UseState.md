- Hook state is the new way of **declaring a state** in React app.
- Hook uses **useState()** functional component for **setting and retrieving state.**
- The React `useState` Hook allows us to **track state in a function component.**
- State generally refers to data or properties that need to be tracking in an application.

![[Screenshot 2025-02-22 at 3.38.45 PM.png]]

## Import `useState`

To use the `useState` Hook, we first need to `import` it into our component.

```jsx
import { useState } from "react";
```

Notice that we are **destructuring `useState`** from `react` as it is a named export.

## Initialize `useState`

`useState` accepts an initial state and returns two values:
- **The current state.**
- **A function that updates the state.**
#### Example :

```js
import { useState } from "react";

export default function FavoriteAnimal(){
    const [type, setType]=useState("Cats");

    return(
    <>
        <h1>My favorite animal is {type}</h1> //reading state
        <button onClick={() => setType("cars")}> update </button> //updatingstate
    </>
    );
}
```

**NOTE:** 
we are destructuring the returned values from `useState`.

The first value, **`type`**, is our current state.

The second value, **`setType`**, is the function that is used to update our state.

## What Can State Hold?

- The `useState` Hook can be used to keep track of **strings, numbers, booleans, arrays, objects,** and any combination of these!
- We could create multiple state Hooks to track individual values.

```js
export function UsObj(){
    const [person, setPerson] = useState({ name: "sofia", age: 22, isCar: true
    });
    
    return(
        <>
        <h1>Hi i am {person.name}. My age is {person.age}. Am I a car? {person.isCar.toString()}</h1>
        </>
    );
}
```
###  Updating  (Updates all objects)
```js
    const changeDetails = () => {
        setPerson({ name: "goby", age: 7, isCar: true
        });
        
return(
	<button onClick={changeDetails}>Click me to change person</button>
);
```

## Updating particular value of an object : 
- When state is updated, the entire state gets overwritten.

- What if we only want to update the color of our car? If we only called `setPerson({age: 23})` this would remove the `name` and `isCar` from our state.

### 1. Without using spread operator (Not recommended)
```js
    const changeDetails = () => {
        setPerson({ ...person, age: 23});
    }
```
#### Explanation:

- The `setUser` function replaces the entire object.
- `{ ...user, name: "Bob" }` spreads the existing properties of `user` and updates only the `name` field.
- This works fine for independent updates but may cause issues in asynchronous updates where multiple state updates rely on the previous state.
### 2. Updating particular value of an object (Using spread operator) (Recommended) :
```js
    const changeDetails = () =>{
        setPerson(previousState => {
            return{
                ...previousState,
                isCar: false, 
                age: 23
            }
        })
    }
```

#### Explanation :  
- If your update depends on the previous state, this method is safer to use.

- Because we need the current value of state, we pass a function into our setPerson function. This function receives the previous value.

- We then return an object, spreading the previousState and overwriting only the `age` and `isCar` values.
---
---
## useState with Arrays :
```js
export function UsArr(){
    const array= [69,96,645,342,0];
    const [arr, setArr] = useState(array);

    const changeList = () => {
        setArr([12,23,43,7,0]);
    }
    return(
        <>
        <h1>
            <ul>My list is {arr.map((a,i) => <li key={i}>{a}</li>)}</ul>
        </h1>
        <button onClick={changeList}>click to update list</button>
        </>
    );
}
```

### Adding items in Array (Using Spread Operator)
```js
    const addItems = () => {
        setArr(previousState => {
            return[
                ...previousState,
                69 //Math.floor(Math.random()*50):to add random values in list
            ]
        })
    }
```

### Increment & Decrement function:
```js
export function Increment(){
    const [count,setCount]= useState(0);

    return(
        <>
        <h1>{count}</h1>
        <button onClick={() => setCount(count+1)} >Increment</button>
        <button onClick={() => setCount(count-1)}>Decrement</button>
        </>
    );
}
```

```js
import React, {useState} from 'react';

export function Counter(){
	const[count, setCount] = useState(0);
	
	return(
		<div>
			<h1>count: {count} </h1>
			<button onClick = {() => setCount(count + 1)}>Increment</button>
			<button onClick = {() => setCount(count-1)}> Decrement </button>
		</div>
	)
}
```

same using class component
```js
import React , {Component} from 'react';

export class Counter extends Component{
	constructor(props){
		super(props);
		this.state = {
			count: 0
		};
	}

	increment = () => {
		this.setState({count: this.state.count +1});
	}

	decrement = () => {
		this.setState({count: this.state.count - 1});
	}
	
	render(){
		return(
			<div>
			<h1> count : {this.state.count} </h1>
			<button onClick = {this.increment}>Increment</button>
			<button onClick = {this.decrement}>Decrement</button>
			</div>
		);
	}
}
```