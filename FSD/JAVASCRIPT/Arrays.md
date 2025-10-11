- An array in JavaScript is an ordered collection of values, each identified by a numeric index. 
- The values in a JavaScript array can be of different data types, including numbers, strings, booleans, objects, and even other arrays.
-  It is a common practice to declare arrays with the const keyword.
- Dynamic
- A JavaScript **array** is a special variable that can hold **multiple values** in a single variable. It's an **object type**, and elements are ordered by index (starting from 0).
### creating an array:
1. using array literal (commonly used)
```js
const fruits = ["apple", "banana", "orange"];
console.log(fruits[0]); // "apple"
console.log(fruits[2]); // "orange"
```


2. using new keyword (not used)
```js
const cars = new Array("Saab", "Volvo", "BMW");
```

### accessing and updating elements in an array
```js
const fruits = ["apple", "banana", "cherry"];

console.log(fruits[1]); // "banana"
console.log(fruits[3]); // undefined

fruits[1] = "blueberry"; //update
console.log(fruits); // ["apple", "blueberry", "cherry"]

const fruits = ["apple", "banana", "cherry"];
fruits[3] = "date"; //dynamic increasing array size
console.log(fruits); // Outputs: ["apple", "blueberry", "cherry", "date"]

```

You might have noticed that we are using `const` when declaring the `fruits` array. But why is it possible to add more elements to this `fruits` array when `fruits` is a constant? This is possible because **declaring an array with the `const` keyword creates a reference to the array. While the array itself is mutable and can be modified, you cannot reassign a new value to the `fruits`** constant, like this:

```js
const fruits = ["apple", "banana"];
fruits = ["This", "will", "not", "work"];
console.log(fruits); // Uncaught TypeError: Assignment to constant variable.
```
### Array methods:
| method                                                                                  | Description                                             |
| --------------------------------------------------------------------------------------- | ------------------------------------------------------- |
| [Array length](https://www.w3schools.com/js/js_array_methods.asp#mark_length)           | Returns the length (size) of an array                   |
| [Array toString](https://www.w3schools.com/js/js_array_methods.asp#mark_tostring)()     | Converts an array to a comma separated string of values |
| [Array at()](https://www.w3schools.com/js/js_array_methods.asp#mark_at)                 | Returns an indexed element from an array                |
| [Array join()](https://www.w3schools.com/js/js_array_methods.asp#mark_join)             | Joins all array elements into a string                  |
| [Array pop()](https://www.w3schools.com/js/js_array_methods.asp#mark_pop)               | Removes the last element from an array                  |
| [Array push()](https://www.w3schools.com/js/js_array_methods.asp#mark_push)             | Adds a new element to an array                          |
| [Array shift()](https://www.w3schools.com/js/js_array_methods.asp#mark_shift)           | Removes the first array element                         |
| [Array unshift()](https://www.w3schools.com/js/js_array_methods.asp#mark_unshift)       | Adds a new element at the beginning of an array         |
| [Array delete()](https://www.w3schools.com/js/js_array_methods.asp#mark_delete)         | Creates undefined holes in the array                    |
| [Array concat()](https://www.w3schools.com/js/js_array_methods.asp#mark_concat)         | Creates a new array by merging existing arrays          |
| [Array copyWithin()](https://www.w3schools.com/js/js_array_methods.asp#mark_copywithin) | Copies array elements to another position in the array  |
| [Array flat()](https://www.w3schools.com/js/js_array_methods.asp#mark_flat)             | Creates a new array from sub-array elements             |
| [Array slice()](https://www.w3schools.com/js/js_array_methods.asp#mark_slice)           | Slices out a part of an array                           |
| [Array splice()](https://www.w3schools.com/js/js_array_methods.asp#mark_splice)         | Adds new items to an array                              |
| [Array toSpliced()](https://www.w3schools.com/js/js_array_methods.asp#mark_tospliced)   | Adds new items to an array in a new array               |

### Array Destructuring

- Allows you to extract values from arrays and assign them to variables in a more concise and readable way. 
- It provides a convenient syntax for unpacking array elements into distinct variables.

This technique is particularly useful when working with arrays and functions that return multiple values. 

```js
let fruits = ["apple", "banana", "orange"];

let [first, second, third] = fruits;

console.log(first);  // "apple"
console.log(second); // "banana"
console.log(third);  // "orange"
```

In this example, we have an array called `fruits` with three elements. Using array destructuring, we assign the first element to the variable `first`, the second element to `second`, and the third element to `third`. This allows us to easily access individual elements of the array without using index notation.

Here is what it would look like if you accessed each of those elements by their index instead of using array destructuring:

```js
const fruits = ["apple", "banana", "orange"];

const first = fruits[0];
const second = fruits[1];
const third = fruits[2];

console.log(first); // "apple"
console.log(second); // "banana"
console.log(third); // "orange"
```

Array destructuring also allows you to skip elements you're not interested in by using commas. For instance:

```js
let colors = ["red", "green", "blue", "yellow"];
let [firstColor, , thirdColor] = colors;

console.log(firstColor); // Output: "red"
console.log(thirdColor); // Output: "blue"
```

Another powerful feature of array destructuring is the ability to use default values. If the array has fewer elements than the variables you're trying to assign, you can provide default values:

```js
let numbers = [1, 2];
let [a, b, c = 3] = numbers;

console.log(a); // 1
console.log(b); // 2
console.log(c); // 3
```

Here, we assign default value `3` to `c` because the `numbers` array doesn't have a third element.

Now, let's discuss the rest syntax, denoted by three dots (`...`). It allows you to capture the remaining elements of an array that haven’t been destructured into a new array. Here's how it works:

```js
let fruits = ["apple", "banana", "orange", "mango", "kiwi"];
let [first, second, ...rest] = fruits;

console.log(first);  // "apple"
console.log(second); // "banana"
console.log(rest);   // ["orange", "mango", "kiwi"]
```

In this example, `first` and `second` capture the first two elements of the `fruits` array, and `rest` captures all remaining elements as a new array. The rest syntax must be the last element in the destructuring pattern.

- Array destructuring is a powerful feature that can make your code more concise and easier to read. 
- It's especially useful when working with arrays, and when you need to extract specific elements from an array.
### split() , reverse(), join()
#### Split():
- The `split()` method divides a string into an array of substrings and specifies where each split should happen based on a given separator. If no separator is provided, the method returns an array containing the original string as a single element.
#### reverse():
- The `reverse()` method is an array method that reverses an array in place. This means it modifies the original array rather than creating a new one.
#### join():
- The `join()` method creates and returns a new string by concatenating all of the elements in an array, separated by a specified separator string.
```js
let str = "coding";
let reversed = str.split("").reverse().join("");
console.log(reversed); //gnidoc
```

```js
let word = "hello";
let chars = word.split("");
chars.reverse();
console.log(chars.join("-")); //o-l-l-e-h
```

---
### indexOf()
- index of an element
### splice()
- add or remove elements from middle
### includes()
- returns a boolean value
----
### Shallow copy of an array
- A shallow copy of an array is a new array that contains references to the same elements as the original array.
```java
const originalArray = [1, 2, 3];
const copyArray = [].concat(originalArray); //using concat()
const copyArray = originalArray.slice(); //using slice()
const copyArray = [...originalArray]; //using spread operator

console.log(copyArray === originalArray); // false

```