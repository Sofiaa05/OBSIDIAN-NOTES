The `map` method is a powerful and widely used function in JavaScript that operates on arrays. 
- It is designed to create a new array by applying a given function to each element of the original array.
- This method does not modify the original array but instead returns a new array containing the results of the function applied to each element.


```js
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map((num) => num * 2);
console.log(numbers); // [1, 2, 3, 4, 5]
console.log(doubled); // [2, 4, 6, 8, 10]
```

To create a new array where each number is doubled, we are using the `map` method. **The `map` method accepts a callback function where the function is called on every single element in the array.**


#### The callback function can accept up to three arguments.

1. The first argument is the current element being processed.

```js
const numbers = [3, 4, 5, 6, 7].map((element) => {
  console.log("Element:", element);
  return element * 2;
});
```

2. The second argument is the index of the current element being processed.

```js
const numbers = [3, 4, 5, 6, 7].map((element, index) => {
  console.log("Element:", element);
  console.log("Index:", index);
  return element * 2;
});
```

3. The third argument is the array where `map` is being called on.

```js
const numbers = [3, 4, 5, 6, 7].map((element, index, array) => {
  console.log("Element:", element);
  console.log("Index:", index);
  console.log("Array:", array);
  return element * 2;
});
```

---
```java
const products = ["Book", "Laptop", "Phone"];

const productObjects = products.map(item => ({ name: item })); //() to return obj

//is same as
const productObjects = products.map(function(item) {
    return { name: item };
});


console.log(productObjects);
// Output: [{ name: "Book" }, { name: "Laptop" }, { name: "Phone" }]

```

--- 
# Filter()
The `filter` method is used to create a new array with elements that pass a specified test, making it useful for selectively extracting items based on criteria.

### syntax
```js
array.filter(function(element, index, array) {
  // return true to keep the element
});

//with arrow function
array.filter(element => condition);
```

In this example, we are using the `filter` method, to create a new array of only even numbers:

```js
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const evenNumbers = numbers.filter((num) => num % 2 === 0);

console.log(evenNumbers); // [2, 4, 6, 8, 10]
```


If the number is even, **the function returns `true`, and that number is included in the new array. If it's odd, the function returns `false`, and that number is excluded.**

Just like the `map` method, the callback function for the `filter` method accepts the same three arguments: the current element being processed, the index, and the array.

It's important to note that **if no elements pass the test, the `filter` method returns an empty** array.

```js
const numbers = [2, 4, 6, 8].filter((num) => num > 10);

console.log(numbers); // []
```

- You can use it to remove `null` or `undefined` values from an array, to filter objects based on their properties, or to implement search functionality.


```javascript
const developers = [
  { name: "Alice", age: 25 },
  { name: "Bob", age: 30 },
  { name: "Charlie", age: 35 },
  { name: "David", age: 25 }
];

const youngPeople = developers.filter((person) => person.age < 30);
console.log(youngPeople);

// [{ name: "Alice", age: 25 }, { name: "David", age: 25 }]
```

---
# Reduce
- Allows you to process an array and condense it into a single value. This single value can be a number, a string, an object, or even another array.
- It's called `reduce` because it reduces an array to a single output. 

At its core, `reduce` works by applying a function to each element in the array, in order, passing the result of each calculation on to the next. This function is often called the reducer function.

**The reducer function takes two main parameters: an accumulator and the current value.** The accumulator is where you store the running result of your operations, and the current value is the array element being processed.

```js
const numbers = [1, 2, 3, 4, 5];
const sum = numbers.reduce(
  (accumulator, currentValue) => accumulator + currentValue,
  0
);

console.log(sum); // 15
```


The reducer function takes the accumulator (which starts at `0`, as specified by the second argument to `reduce`) and adds each number to it.

The result of each addition becomes the new accumulator for the next iteration.

The `reduce` method can also take an initial value as its second argument. This is the value that the accumulator starts with. In the example above, we set it to `0`.

**If you don't provide an initial value, `reduce` will use the first element of the array as the initial accumulator** and start the process from the second element.