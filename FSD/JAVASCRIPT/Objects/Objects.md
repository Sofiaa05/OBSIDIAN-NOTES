### Object Destructuring
- Allows you to extract values from objects and assign them to variables in a more concise and readable way.
- It's part of the ES6 (ECMAScript 2015) specification and has become an essential tool for many JavaScript developers.

Destructuring can simplify your code, especially when working with complex objects or when you need to extract multiple values at once.

Instead of accessing object properties one by one, you can extract multiple properties in a single statement. This can make your code cleaner and more efficient.


```js
const person = { name: "Alice", age: 30, city: "New York" };

const { name, age } = person;

console.log(name); // Alice
console.log(age);  // 30
```


- One of the powerful aspects of object destructuring is that you can assign the extracted values to variables with different names. This is particularly useful **when you're working with objects that have property names that might conflict with existing variables** or when you want to use a different name:

```js
let person = { name: "Alice", age: 30, city: "New York" };

let { name: personName, age: personAge } = person;

console.log(personName); // Alice
console.log(personAge); //  30
```

- Object destructuring also allows you to set default values. If a property doesn't exist in the object you're destructuring, you can specify a fallback value:

```js
let person = { name: "Alice", age: 30, city: "New York" };
let { name, age, country = "Unknown" } = person;

console.log(country); // Unknown
```

Here, since `country` doesn't exist in our `person` object, it gets the default value `Unknown`.

#### Short Hand Notation:
- When you're creating objects, especially when the property names match variable names, you can use a shorthand syntax:

```js
let name = "Bob";
let age = 25;

let person = { name, age };

console.log(person); // { name: "Bob", age: 25 }
```

The code above takes the properties with the same name as our variables and assigns them the values of those variables.

- This shorthand notation is particularly **useful when you're returning objects from functions** or creating objects with multiple properties:

```js
function createPerson(name, age) {
  return { name, age };
}

let person = createPerson("Charlie", 35);
console.log(person); // { name: "Charlie", age: 35 }
```
 - makes code more concise and easy to read.
- They're especially useful when working with complex data structures, or when you need to pass multiple parameters to functions.
---
### Deleting Properties
1. when you use `delete`, it removes the selected property from the object. 

```js
const person = {
  name: "Alice",
  age: 30,
  job: "Engineer"
};

delete person.job;

console.log(person.job); // undefined
```

2. **Destructuring with rest parameters**: This approach doesn't actually delete the property, but it creates a new object without the specified properties:

```js
const person = {
  name: "Bob",
  age: 25,
  job: "Designer",
  city: "New York"
};

const { job, city, ...remainingProperties } = person;

// { name: "Bob", age: 25 }
console.log(remainingProperties);
```
---
### How to check if an object has a property?
1. hasOwnProperty():
```js
const person = {
	name: "sofia",
	age: 23
}

console.log(hasOwnProperty("name")) //returns true
```

2. `in` operator:
```js
console.log("name" in person); //returns true
```

---
### Accessing nested objects and arrays in objects
```js
const person = {
  name: "Alice",
  age: 30,
  contact: {
    email: "alice@example.com",
    phone: {
      home: "123-456-7890",
      work: "098-765-4321"
    }
  }
};
```

1. **dot notation**
```js
clg(person.contact.phone.work); 
```

2. **using bracket notation:** 
	- allows accessing property names with spaces and special characters
```js
clg(person['contact']['phone']['work']);
```

#### Accesssing nested array in objects
```js
const person = {
  name: "Alice",
  age: 30,
  addresses: [
    { type: "home", street: "123 Main St", city: "Anytown" },
    { type: "work", street: "456 Market St", city: "Workville" }
  ]
};

clg(person.addresses[1].city); //workville
```

---
### Primitive and Non-Primitive Data Types
- Primitive data types are the simplest form of data in JavaScript. They include numbers, strings, booleans, `null`, `undefined`, and symbols. These types are called "primitive" because they represent single values and are not objects.

When you work with primitive data types, you're dealing directly with their values. For example, when you create a variable with a primitive value, that value is stored directly in the variable.

Primitive values are immutable, which means once they are created, their value cannot be changed. However, you can reassign a new value to the variable. 

```js
let num1 = 5;
let num2 = num1;
num1 = 10;

console.log(num2); // 5 (remains unaffected)
```

- Non-primitive data types, on the other hand, are more complex. In JavaScript, these are objects, which include regular objects, arrays, and functions. Unlike primitives, non-primitive types can hold multiple values as properties or elements.

When you create a variable with a non-primitive value, what's stored in the variable is actually a reference to the location in memory where the object is stored, not the object itself. This leads to some important differences in behavior. 

```js
const originalPerson = { name: "John", age: 30 };
const copiedPerson = originalPerson;

originalPerson.age = 31;

console.log(copiedPerson.age); // 31
```


But why is that happening? This occurs because both `originalPerson` and `copiedPerson` are referencing the same object in memory.

In JavaScript, when you assign an object to another variable, you're copying the reference to the object, not the object itself. This is known as shallow copying by reference. As a result, any changes made to the object through one reference are reflected in all references to that object.

--- 
### Functions vs Methods
- functions are reusable blocks of code that perform a specific task:

```js
function greet(name) {
    return "Hello, " + name + "!";
}
console.log(greet("Alice")); // "Hello, Alice!"
```

- Object methods, on the other hand, are functions that are associated with an object. They are defined as properties of an object and can access and manipulate the object's data. 

```js
const person = {
    name: "Bob",
    age: 30,
    sayHello: function() {
        return "Hello, my name is " + this.name;
    }
};

console.log(person.sayHello()); // "Hello, my name is Bob"
```


- A difference between functions and methods is **how they are invoked.** **Functions are called by their name**, while **methods are called using dot notation** on the object they belong to. For example, we call the `greet` function as `greet("Alice")`, but we call the `sayHello` method as `person.sayHello()`.

- Another important difference is the context in which they operate. **Regular functions have their own scope**, but they don't have a built-in reference to any particular object. **Methods, however, are bound to their objec**t and can access its properties and other methods using the `this` keyword.

- A key point to note is that, methods help in organizing code into logical objects, while functions are used for more general, reusable code.
---
### Optional Chaining operator
- lets you safely access object properties or call methods without worrying whether they exist. It's like a safety net for working with objects that might have missing parts.

```js
const person = {
  name: "Alice",
  age: 30
};

console.log(person.name); // "Alice"
console.log(person.job); // undefined
```

Now, let's say we want to access a property of an object that might not exist:

```js
const person = {
  name: "Alice",
  age: 30
};

console.log(person.address.street); // This will throw an error!
```

This example will throw an `Uncaught TypeError`. Since `person.address` is `undefined`, we are not able to access the `street` property. This is where the optional chaining operator comes in handy. Here is an example of using the optional chaining operator:

```js
const user = {
  name: "John",
  profile: {
    email: "john@example.com",
    address: {
      street: "123 Main St",
      city: "Somewhere"
    }
  }
};

console.log(user.profile?.address?.street); // "123 Main St"
console.log(user.profile?.phone?.number);   // undefined
```

By using the optional chaining operator, we are telling JavaScript to only continue with the operation if the object (or the value before the `?.`) exists and is not `null` or `undefined`.

If the value before the `?.` is `null` or `undefined`, JavaScript returns `undefined` rather than attempting to proceed with the operation and throwing an error.