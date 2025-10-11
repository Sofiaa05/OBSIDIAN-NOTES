##### Specifically for checkbox input field.

```js
function OtherInputs() {
    const[data,setData] = useState({});
    const handleChange = (e) => {
        const {name,value,checked}=e.target;

        setData((prevState) => {
            return{
                ...prevState, 
                [name]: (name === 'checkbox' ? checked : value)
            }
        })       
    }
    
  return (
    <div>
        <form >
	        <label style={{verticalAlign: 'top'}} htmlFor=''>Comment: &nbsp;</label>
            <textarea 
            value={data.textarea || ""} rows='10' cols='40' 
            name='textarea' 
            onChange={handleChange}/>
            <br></br>
            
            <label>Select Country: &nbsp;</label>
            <select 
            value={data.select || ""} 
            name='select' 
            onChange={handleChange}>
                <option value="canada" >canada</option >
                <option value="usa" >usa</option >
            </select>           
            <br></br>
            
            <label> Yes i love cars &nbsp;</label>
            <input 
            type='checkbox' 
            checked={data.checkbox || false} 
            name='checkbox' 
            onChange={handleChange}/>
            
            <input type='submit' value='submit'/>
        </form>
    </div>
  )
}
```

### Multiple CheckBoxes :
```js

function MultipleCheckbox() {
    const [data,setData] = useState({});

    const [fruitsArray, setFruitsArray] = useState([]);

    const handleSubmit=(e)=>{
      e.preventDefault();
      console.log(fruitsArray)
    }
    const handleChange = (e) => {
        const{name,checked}= e.target;
        console.log(name,checked)
        setData((prevState)=>{
            return{
                ...prevState,
                [name]: checked
            }
        })
        if(checked){
          setFruitsArray([...fruitsArray,name]);
        }
        else{
          setFruitsArray(fruitsArray.filter((i) => (i!==name)));
        }
    }
   
  return (
    <div>
        <h1>MultipleCheckbox</h1>
      <form onSubmit={handleSubmit}>
        <label htmlFor=''>Select Fruits:</label>
        <br></br>
        <label>apple</label>
        <input type='checkbox'  name='apple' checked={data.apple || false} onChange={handleChange} />
        <br></br>
        <label>banana</label>
        <input type='checkbox'  name='banana' checked={data.banana ||false} onChange={handleChange}/>
        <br></br>
        <label>grapes</label>
        <input type='checkbox'  name='grapes' checked={data.grapes || false} onChange={handleChange} />
        <br></br>
        <input type='submit'/>
      </form>
    </div>
  )
}
```

#### Explanation:

1. `if (checked)` → Checkbox is Checked ✅ (Add Item)

```js
setFruitsArray([...fruitsArray, name]);
```

- `checked` is `true`, meaning the checkbox was selected.
- `setFruitsArray([...fruitsArray, name])`:
    - `...fruitsArray` spreads the current array (preserves existing items).
    - `name` is added at the end.
    - This creates a **new array with the added item**
##### Example:
```js
// Initial state:
fruitsArray = ["apple", "banana"];

// Checkbox "grapes" is checked:
setFruitsArray([...fruitsArray, "grapes"]);

// New state:
fruitsArray = ["apple", "banana", "grapes"];

```

1. **`else`** → Checkbox is Unchecked ❌ (Remove Item)


```js
setFruitsArray(fruitsArray.filter((i) => i !== name));
```

- `checked` is `false`, meaning the checkbox was deselected.
- `.filter((i) => i !== name)`:
    - Iterates through `fruitsArray`.
    - **Keeps** all elements **except** the one that matches `name`.
    - Returns a new array **without** the unchecked item.

##### Example : 

```js
// Initial state: 
fruitsArray = ["apple", "banana", "grapes"];  

// Checkbox "banana" is unchecked: 
setFruitsArray(fruitsArray.filter((i) => i !== "banana"));  

// New state: 
fruitsArray = ["apple", "grapes"];`
```


| Usage                                   | Meaning                                                                            |
| --------------------------------------- | ---------------------------------------------------------------------------------- |
| **`e`** in `handleChange(e)`            | Event object from the event listener (contains `target`, `name`, `checked`, etc.). |
| **`i`** in `.filter((i) => i !== name)` | Each element of `fruitsArray` while iterating through it.                          |

Let me know if you need further clarification! 🚀

---

### **Why This Works Well**
✅ Preserves Previous State:
- Spreading **`(...fruitsArray)`** ensures we don’t mutate the existing array.

✅ Efficient Addition & Removal:
- **`.filter()`** removes the unchecked item while keeping others unchanged.

