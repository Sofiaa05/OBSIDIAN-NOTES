### 1. for-loop
### 2. for...of loop
- like for-each in java
A `for...of` loop is used when you need to loop over values from an iterable. Examples of iterables would be arrays, and strings.


```js
for (variable of iterable) {
  // code block to be executed
}
```

```js
const numbers = [1, 2, 3, 4, 5];

for (const num of numbers) {
  console.log(num);
}
```

### 3. for...in loop
- A `for...in` loop is best used when you need to loop over the properties of an object. This loop will iterate over all enumerable properties of an object, including inherited properties and non-numeric properties
```js
for (variable in object) {
  // code block to be executed
}
```

#### EXAMPLE 1
```js
const fruit = {
  name: 'apple',
  color: 'red',
  price: 0.99
};

for (const prop in fruit) {
  console.log(fruit[prop]);
}

//output
`apple`, `red`, and `0.99`.
```

#### EXAMPLE 2
```js
const person = {
  name: 'John',
  age: 30,
  address: {
    street: '123 Main St',
    city: 'Anytown',
    state: 'CA'
  }
};

for (const prop in person) {
  console.log(person[prop]);
}
```

```md
OUTPUT:
John
30
{ street: '123 Main St', city: 'Anytown', state: 'CA' }
```

if you want to loop over the properties of the `address` object, you can nest another `for...in` loop inside the first one.

```js
function isObject(obj) {
  return typeof obj === 'object' && !Array.isArray(obj) && obj !== null;
}

for (const prop in person) {
  if (isObject(person[prop])) {
    for (const nestedProp in person[prop]) {
      console.log(person[prop][nestedProp]);
    }
  } else {
    console.log(person[prop]);
  }
}
```

In this example have a custom function `isObject` that checks if the value is an object.

The `Array.isArray` method is used to check if the value is an array. By placing the logical NOT operator (`!`) in front of the method, we are checking if the value is not an array.

The reason why we can't just use `typeof` equals `'object'` is because arrays are also considered objects in JavaScript. We want to exclude arrays from the check.

Also, due to a historical bug in JavaScript, `typeof null` returns `'object'`. So we want to also exclude `null` values from the check.

If the condition is true, we nest another `for...in` loop that will loop over the properties of the nested object and log the value to the console.

The `nestedProp` variable represents the current property of the nested object.

Here is what the modified result will look like in the console:

```md
"John"
30
"123 Main St"
"Anytown"
"CA"
```

A `for...in` loop is useful when you need to loop over the properties of an object.

It is not recommended to use a `for...in` loop to loop over the elements of an array. Instead, use a `for...of` loop or other array methods like `forEach`, `map`, `filter`, and `reduce`, which you will learn about in future lessons.