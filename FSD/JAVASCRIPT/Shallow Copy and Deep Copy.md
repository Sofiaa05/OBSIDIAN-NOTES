Two values are **structurally equivalent** if they have the **same structure and same values** inside them — even if they are **different instances**.
### Shallow Copy
A shallow copy creates a new object or array and inserts references to the original elements found in the source. In other words, it duplicates the structure at the top level, but the nested elements inside the new copy still reference the same objects as the original.

```js
//shallow of objects
// Shallow copy means that the top-level properties are copied, but nested objects or arrays are not deeply copied. 
// If you modify a nested object or array in the copied object, it will also modify the original object or array, because they both reference the same nested object or array.
let person = {
    name: "leo",
    age: 30,
    hobbies: {
        sports: "football",
        music: "rock"
    }
}

let person2 = {...person};

person2.name = "sofia";
person2.hobbies.sports = "basketball"; // This will change the original object as well, because it's a shallow copy

console.log(person2); 
/* {
  name: 'sofia',
  age: 30,
  hobbies: { sports: 'basketball', music: 'rock' }
} */

console.log(person);
/*
{
  name: 'leo',
  age: 30,
  hobbies: { sports: 'basketball', music: 'rock' }
}
*/
---------------------------------------------------------------------------------

//shallow copy of arrays
const arr1 = [1,2,[3,4]];
const arr2 = [...arr1];

arr2[0] = 69;
arr1[0] = 96;

arr2[2][0] = 89;
arr1[2][1] = 99;

console.log(arr1); //[ 96, 2, [ 89, 99 ] ]
console.log(arr2); //[ 69, 2, [ 89, 99 ] ]
```

- in a nutshell, shallow copy means changes get reflected in other copies.
- deep copy means changes doesn't get reflected in other copies.
--- Great question, Sofia 👍 — **Shallow Copy vs Deep Copy** is a very common interview topic in **JavaScript** (and other languages too). Let’s break it down clearly:

---

## 🟦 **Shallow Copy**

- Copies only the **first level** of the object/array.
    
- **Nested objects/arrays are still referenced** (not copied).
    
- Changing nested objects will affect both copies.
    

🔹 Example:

```js
let original = { name: "Sofia", address: { city: "Delhi" } };

// Shallow copy using spread operator
let shallowCopy = { ...original };

shallowCopy.address.city = "Mumbai";

console.log(original.address.city); // "Mumbai" (changed in both!)
```

✅ Here only top-level properties are copied. `address` is still a reference.

---

## 🟩 **Deep Copy**

- Creates a **full independent clone** of the object/array.
    
- **Nested objects are also copied** (not referenced).
    
- Changes in one object do not affect the other.
    

🔹 Example:

```js
let original = { name: "Sofia", address: { city: "Delhi" } };

// Deep copy using JSON
let deepCopy = JSON.parse(JSON.stringify(original));

deepCopy.address.city = "Mumbai";

console.log(original.address.city); // "Delhi" (unchanged ✅)
```

✅ Here nested objects are also copied separately.

---

## 🆚 **Shallow Copy vs Deep Copy (Summary)**

|Feature|Shallow Copy 🟦|Deep Copy 🟩|
|---|---|---|
|Copy level|First level only|All levels|
|Nested objects|Referenced (shared)|Fully cloned (independent)|
|Performance|Faster|Slower (more processing)|
|Example|Spread `...`, `Object.assign()`|`JSON.parse(JSON.stringify())`, `structuredClone()`, libraries like Lodash|

---

⚡ **In interviews you can say:**

- _"A shallow copy only duplicates the first level of an object, keeping nested objects as references, while a deep copy creates a complete clone with no shared references."_
    