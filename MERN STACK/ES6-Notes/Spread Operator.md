Used during **function calling**.
### Example1: Used to expand or spread an iterable or array

```javascript
let arr=[1,435,654,743,48]

const display1=document.getElementById("heading1").innerHTML=`Spreading ${[...arr]}`;  

OUTPUT: Spreading 1,435,654,743,48

const display2=document.getElementById("heading2").innerHTML=`Spreading ${[...arr].join(", ")}`;

OUTPUT: Spreading 1, 435, 654, 743, 48
```

### Example2: Destructuring an array

```javascript
let arr=[1,435,654,743,48]
const [a,b,c,d]=[...arr]

console.log(a)
console.log(b)
console.log(c)
console.log(d)

OUTPUT:
1
435
654 
743
```

### Example3: Copy array to another array
```javascript
const arr1= [12,34,56]

const arr2 =["sofia", 45, "abbasi"]

const mergedArr = [...arr1,...arr2] 

// const mergedArr = arr1.concat(arr2)  earlier we used to do this

console.log(mergedArr)

OUTPUT: [12, 34, 56, 'sofia', 45, 'abbasi']
```

### Example4: Clone array using spread operator (extension to Example3):

- In Javascript, objects are assigned by **reference** and not by value. 
- This means when you copy a value of a object1 to object2, the **memory address** of object1 gets copied to object2. 
- Changes made in object 1 will also be reflected in object2

- **Example:**
```js
let arrr1 =[12,32,56]
let arrr2 = arrr1 //passing memory address
console.log(arrr1) // [12,32,56]
console.log(arrr2) //[12,32,56]

arrr1.push(69)

console.log(arrr1) //[12,32,56,69]
console.log(arrr2) //[12,32,56,69]
```

when using spread operator, we pass the **values** in obj1 to obj2 and not the memory address.
Example: 
```js
let arrr1 =[12,32,56]
let arrr2 = [...arrr1] //passing values 
console.log(arrr1) // [12,32,56]
console.log(arrr2) //[12,32,56]

arrr1.push(69)

console.log(arrr1) //[12,32,56,69]
console.log(arrr2) //[12,32,56]
```

### Example5: Copy multiple objects into one object

```js
const myVehicle = {
brand: "Ford",
model: "Mustang",
color: "red"
}

const updateMyVehicle = {
type: "car",
year: 2021,
color: "yellow"
}

const myUpdatedVehicle = {...myVehicle, ...updateMyVehicle}
console.log(myUpdatedVehicle)

OUTPUTS: 
{brand: 'Ford', model: 'Mustang', color: 'yellow', type: 'car', year: 2021}
```

### Example6: Copy all or part of an existing array (Extension to Example2)
```js
let arr = [1, 2, 3, 4, 5, 6];  

const [one, two, ...remaining] = arr;  

console.log(one);  
console.log(two);  
console.log(remaining);

OUTPUT:
1
2
[3,4,5,6]
```