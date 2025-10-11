- The word **effect** refers to a **functional programming term** called a **"side effect".**
- The useEffect Hook allows you to **perform side effects** in your functional component.
- Sometimes, we want to run some **additional code after React has updated the DOM**. **Network requests, manual DOM mutations,** and **logging** are common examples of effects.
- The render method itself shouldn't cause side effects. It would be too early.
- You can compare useEffect Hook as **componentDidMount, componentDidUpdate** and **componentWillUnmount** phases of Component Life cycle in Class Components.
## Common side effects include:
- Making a request to an API for data from a backend server. 
- To interact with browser APIs (that is, to use document or Window directly)
- Using unpredictable timing functions like setTimeout or SetInterval
## How To Use useEffect Hook
- First you have to import it from React.
	 **Import {useEffect} from ‘react’**
- When we place useEffect() hook inside the function component, then we have the access of props and state easily. 
- useEffect runs after first render and also after every render update.

## How it Works:
- useEffect accepts two arguments. The second argument is optional.
useEffect(\<function >, \<dependency>)) 
- The function inside useEffect() will **run after every render** is committed.
- **Second argument** of useEffect is the **array of values** which depends on effects.
- Important Note: you can call useEffect hook **as many times** as you need. 

```js
import React from 'react';
import {useEffect, useState} from 'react';

export function USEffect(){
    const [count, setCount]=useState(0);
    useEffect(()=>{
        setTimeout(()=> {
            setCount(count+1);
        }, 1000);
    }, []);
    return(
        <>
        <h1>I've rendered {count} times</h1>
        </>
    );
}
```
#### Explanation:
- It keeps counting even though it should only count once!
- useEffect runs on **every render.** That means that when the count changes, a render happens, which then triggers another effect.
---

We should always include the second parameter which accepts an array.
1. An empty array:

```jsx
useEffect(() => {
  //Runs only on the first render
}, []);
```
2. Props or state values:

```jsx
useEffect(() => {
  //Runs on the first render
  //And any time any dependency value changes
}, [prop, state]);
```

---
---
### Conditionally run useEffect
```js
export function UseEffectEx(){
    const [count, setCount]=useState(0);
    const [name, setName]=useState('sofia');
    useEffect(() => {
        console.log(`Hello i am effect = ${count}`)
        },[count] )
    return(
        <>
        <h1>{count}</h1>
        <h1>{name}</h1>
        <button onClick={() => setCount(count+1)}>Count</button>
        <button onClick={() => setName('toby')}>Name</button>
        </>
    );
}
```

#### Explanation:
useEffect function only works when **Count** button is clicked and not when **Name** button is clicked.