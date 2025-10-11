
- In **HTML**, form elements typically maintain their **own state** and update it according to the user input.
- In HTML, form data is usually handled by the **DOM**. In React, form data is usually handled by the **components.**
- In the **controlled component**, the input form element is **handled by the component** rather than the DOM.
- You can control changes by adding event handlers in the **`onChange`** attribute. We can use the **`useState`** Hook to keep track of each inputs value
- Here, the **mutable state is kept in the state** and will be **updated only with useState(**) hook inside functional component. 
- Controlled components have functions that govern the data passing info them on every **onChange** event, rather than grabbing the data only once, e.g., when you click a submit button. 
- This data is then **saved to state variable** and **updated with useState(**) Hook. This makes component have better control over the form elements and data.

#### Submitting Forms

You can control the submit action by adding an **event handler** in the **`onSubmit`** attribute for the `<form>`
```js
import React, { useState } from 'react'

function ControlledFunction() {
    const [data, setData]=useState("");    
    
    const handleSubmission =(e) =>{
        e.preventDefault();
        alert(`The name you entered was ${data}`);
    }
  return (
    <div>
      <form onSubmit={handleSubmission}>
       <label htmlFor=''>Enter name:</label> 
       <input type='text' value={data} onChange={(e)=> setData(e.target.value)}></input>
       <br></br>
       <input type="submit" />
       
      </form>
    </div>
  )
}

export default ControlledFunction

```

##### Explanation: 
`e.preventDefault()` is a method used in JavaScript to **prevent the default behavior** of an event. In the case of a **form submission**, the default behavior is to **reload the page.**

- **e** : event name: onChange/ onSubmit
- **target** : type
- **value** : value entered 
---
---

### Multiple Input Fields :
- You can control the values of more than one input field by adding a **name attribute** to each element.

- We will initialize our state with an **empty object.**

- To access the fields in the event handler use the **event.target.name** and **event.target.value** syntax.

- To update the state, use square brackets \[bracket notation] around the property name.

```js
import React, { useState } from 'react'

function ControlledFunction() {
    const [data, setData]=useState({
        name: "",
        email: ""
    });  
    
    const handleChange = (e)  => {
        // const name = e.target.name;
        // const value  = e.target.value;
        //we can perform above two steps in one single line as well:
        const {name, value}=e.target //destructuring 
        const emailVal = (name==="email" ? value.toLowerCase() : value)

        console.log(name,value);

        setData((prevState) => {
            return{
                ...prevState,
                [name]: emailVal
            }
        })
    }
        
    const handleSubmission =(e) =>{
        e.preventDefault();
        alert(`The name you entered was ${data.name} and email was ${data.email}`);
    }
  return (
    <div>
      <form onSubmit={handleSubmission}>
      
       <label htmlFor=''>Enter name:</label> 
       <input type='text' name="name" value={data.name}  placeholder='enter your name' onChange={handleChange}></input>
       <br></br>
       
       <label >Enter Email:</label>
       <input type="email" name="email" value={data.email} placeholder='enter your email' onChange={handleChange}></input>
       <br></br>
       
       <input type="submit" />
       
      </form>
    </div>
  )
}

export default ControlledFunction
```