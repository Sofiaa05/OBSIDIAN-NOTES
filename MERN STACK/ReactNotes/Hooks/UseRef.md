
## 1.  Accessing DOM Elements
In React, we can add a **`ref`** attribute to an element to access it directly in the DOM without using state.
```js
function HookuseRef() {
    const fname=useRef();
    const lname=useRef();

    useEffect(()=> {
        console.log(fname); //{current: input}
        console.log(lname); //{current: input}
        fname.current.focus(); //to place cursor after submitting form.
    } )

    const handleSubmit =(e) => {
        e.preventDefault();
        alert(`First name = ${fname.current.value} and last name is ${lname.current.value}`)
    }
    
  return (
    <div>
      <h1>Use Ref</h1>
      <form onSubmit={handleSubmit}>
      
        <label>First name</label>
        <input 
        type='text' 
        ref={fname} 
        placeholder='Enter first name'/>
        <br></br>
        
        <label>Last name</label>
        <input 
        type='text' 
        ref={lname} 
        placeholder='Enter last name'/>
        <br></br>
        
        <input type='submit'/>
      </form>
    </div>
  )
}
```

## 2. Does Not Cause Re-renders

- If we tried to count how many times our application renders using the `useState` Hook, we would be caught in an **infinite loop** since this **useState Hook itself causes a re-render.** To avoid this we use **useRef**

- It can be used to **store a mutable value** that **does not cause a re-render** when updated.
#### Example : Counting rendering using useState() 

```js
function RefRerender() {
    const [count,setCount]=useState(0);

    useEffect(()=>{
        setCount(count+1);
    })

  return (
    <div>
      <h1>Use State vs Use ref</h1>
      <input type='text' placeholder='enter name'/>
      <h2>Render count: {count}</h2>
    </div>
  )
}

console: Maximum update depth exceeded. This can happen when a component calls setState inside useEffect, but useEffect either doesn't have a dependency array, or one of the dependencies changes on every render.

```

##### Explanation: 
1. Component Renders for the First Time

- `count` is initialized as `0` (`useState(0)`).
- `useEffect` runs **after the initial render** & calls `setCount(count + 1)`, setting `count` to `1`.
- Since `setCount` **updates state**, React **triggers a re-render**.
2. This Cycle Repeats Infinitely

- Since `useEffect` **has no dependency array (`[]`)**, it runs **on every render**.
- Each time, `setCount(count + 1)` updates the state, **causing an infinite loop**.

#### Example: using useRef() 
using useRef() to track renders.

```js
function RefRerender() {
    const [input, setInput]=useState(""); // for inputting data in form

    const count= useRef(0);
    useEffect(()=>{
        count.current = count.current + 1;
    });

  return (
    <div>
      <h1>Use State vs Use ref</h1>
      <input type='text' 
      value={input} 
      placeholder='enter name'
      onChange={(e)=>setInput(e.target.value)}/>
      
      <h2 >Render count: {count.current}</h2> 
      
      <h3> data: {input}</h3> 
    </div>
  )
}
```

##### Explanations :
- **Controlled input**: The value is linked to `input` state.
- **Typing updates `input`**, which triggers **re-renders**.
1. 
```js
h2>Render count: {count.current}</h2>
```


- Displays **render count** using `count.current`, which **persists across renders** but **does not trigger re-renders**.
2. 
```js
<h3>Data: {input}</h3>
```
- Displays the input value (`input`).
- **Re-renders every time `input` changes** because `useState` triggers renders.

##### In a nutshell:
 `useState` triggers re-renders.  
`useRef` persists values without causing re-renders.  
 `useEffect` updates `count.current` after each render.

---

- The useRef Hook allows you to **persist values between renders.**

- It returns a **mutable ref** object whose **`.current` property** is initialized with the **passed argument** (initialValue).

```js
const count= useRef(0); 
// mutable reference object = count
// .current = 0
```

- The returned object will persist for the **full lifetime** of the component.

- `useRef()` only **returns an Object called `current`**.

- When we initialize `useRef` we set the initial value: `useRef(0)`.

- It's like doing this: `const count = {current: 0}`. We can access the count by using `count.current`.
```js
    useEffect(()=>{
        count.current = count.current + 1; //incrementing count = 0 to 1 to...n
    });

```