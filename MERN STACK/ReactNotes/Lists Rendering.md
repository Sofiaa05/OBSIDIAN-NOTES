
- Lists are very useful when it comes to developing the Ul of any website.
- Lists are mainly used for displaying   **in a website**, Eg: list of products, list of names, list of courses etc.
- In React, you will render lists with some type of loop.
- The JavaScript **map() array method** is generally the preferred method.

## JavaScript map() array method :
- map() creates a **new array** from calling a function for every array element.
- map() calls a function **once** for each element in an array.
- map() does **not execute** the function for **empty elements.**
- map() **does not change** the **original array.**

#### Example 1 :
```js
import React from 'react';

function Lists() {
    const number =[1,2,3,4,5];
  return (
    <div>
      {number.map(num => <ul><li>{num}</li></ul>)}
    </div>
  )
}

export default Lists;
```

Or, to make JSX lightweight, we can define the map function above return:
```js

function Lists() {
    const number =[1,2,3,4,5];
    const result = number.map(num => <h1>{num}</h1>);

  return (
    <div>
        {result}
    </div>
  )
}
```

#### Example 2 :
```js
export function Garage() {
    const cars = ['Ford', 'BMW', 'Audi'];
    const result = cars.map((car) =>  <li>{car}</li>)
    return (
      <>
        <h1>Who lives in my garage?</h1>
        <ul>
          {result}
        </ul>
      </>
    );
  }

```

## List of objects :
```js
export function Object() {
    const objects = [
        {
            name: 'sofia',
            age: 22
        },
        {
            name: 'mukul',
            age: 23
        },
        {
            name: 'goby',
            age:7
        }
    ]
  return (
    <div>
      {objects.map(objects => <h2>Hi! I am {obj.name} and I am {obj.age} years old.</h2>)}
    </div>
  )
}

OUTPUTS:
Hi! I am sofia and I am 22 years old.
Hi! I am mukul and I am 23 years old.
Hi! I am goby and I am 7 years old.
```


- We can also do this in a separate component by passing the objects array as props to the new component.

```js
//Lists.js
  return (
    <div>
      {objects.map(obj => <ListsNew obj = {obj}/>  )}
    </div>

//ListsNew.js
function ListsNew({obj}) {
  return (
    <div>
      <h2>Hi! I am {obj.name} and I am {obj.age} years old. </h2>
    </div>
  )
}
```

---
---
# ~={purple} Keys :=~
### Lists without keys:
- When you run above code in your `create-react-app`, it will work but you will receive a warning that there is **no "key" provided** for the list items. You can check this error in console.
- Warning: 
		- Each child in a list should have a **unique "key"** prop.
- Without keys, React will have to rerender the entire lists instead of only the changes done..
### What is a key?
- Keys allow React to keep track of elements. If an item is updated or removed, only that item will be re-rendered instead of the entire list.

- Keys need to be **unique** to each sibling. But they can be duplicated globally.

- Generally, the key should be a unique ID assigned to each item. As a last resort, you can use the **array index as a key.** 
- A “key” is a **special string attribute** you need to include when creating lists of elements in React.

- We can also say that keys are used to give an **identity to the elements** in the lists.

- Keys help React identify which **items have changed, added or removed.**

- Help in **efficient update** of the user interface.
```js
function Car(props) {
    return <li>I am a { props.brand }</li>;
  }
  
export function Garage() {
    const cars = [
      {id: 1, brand: 'Ford'},
      {id: 2, brand: 'BMW'},
      {id: 3, brand: 'Audi'}
    ];
    return (
      <>
        <h1>Who lives in my garage?</h1>
        <ul>
          {cars.map((car) => <Car key={car.id} brand={car.brand} />)}
        </ul>
      </>
    );
  }


```