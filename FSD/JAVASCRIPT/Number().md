The `Number()` constructor is used to create a number object. The number object contains a few helpful properties and methods like the `isNaN` and the `toFix` method. Here's an example using the `Number()` constructor with the `new` keyword:

Example Code

```js
const myNum = new Number("34");
console.log(typeof myNum); // "object" 
```


When the Number() constructor is called as a function without the new keyword, then the return value will be the primitive number type. Most of the time you will be using the Number() constructor to convert other data types to the number data type.

```js
const myNum = Number("100");
console.log(myNum); // 100
console.log(typeof myNum); // number
```

This is helpful when you are getting input from the user and you need to convert that string input to a number so you can perform mathematical calculations.

- If you try to call the Number() constructor through an empty string then the result will be the number 0:
```js
const num = Number("");
console.log(num); // 0
```


- if you try to pass in a string with random characters then the result will be NaN or "Not a Number".
```js
const num = Number("random");
console.log(num); // NaN
```

- **Working with Booleans**
```js
const boolTrue = Number(true);
const boolFalse = Number(false);

console.log(boolTrue); // 1
console.log(boolFalse); // 0
```

- **passing null and undefined**
```js
const undefinedNum = Number(undefined);
const nullNum = Number(null);

console.log(undefinedNum); // NaN
console.log(nullNum); // 0
```


- **Working with Arrays**
```js
const emptyArr = Number([]);
const arrOneNum = Number([7]);
const arrMultiNum = Number([7, 36, 12]);
const arrStr = Number(["str1"]);
const arrMultiStr = Number(["str1", "str2"]);

console.log(emptyArr); // 0
console.log(arrOneNum); // 7
console.log(arrMultiNum); // NaN
console.log(arrStr); // NaN
console.log(arrMultiStr); // NaN
```

- **When working with objects**, the result is always NaN.
```js
const obj1 = Number({});
const obj2 = Number({2: 2});
const obj3 = Number({key: "val"});
const obj4 = Number({key: true});

console.log(obj1); // NaN
console.log(obj2); // NaN
console.log(obj3); // NaN
console.log(obj4); // NaN
```

In conclusion, you'll mostly use the Number() constructor for type conversion more than creating a number or a number object.

| Value            | Becomes…                                                                                                                                                                                                                     |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `undefined`      | `NaN`                                                                                                                                                                                                                        |
| `null`           | `0`                                                                                                                                                                                                                          |
| `true and false` | `1` and `0`                                                                                                                                                                                                                  |
| `string`         | Whitespaces (includes spaces, tabs `\t`, newlines `\n` etc.) from the start and end are removed. If the remaining string is empty, the result is `0`. Otherwise, the number is “read” from the string. An error gives `NaN`. |

## Numeric conversion, unary +

The plus `+` exists in two forms: the binary form that we used to perform addition and string concatenation.

The unary plus or, in other words, the plus operator `+` applied to a single value, doesn’t do anything to numbers. But if the operand is not a number, the unary plus converts it into a number.

```js
// No effect on numbers
let x = 1;
alert( +x ); // 1

let y = -2;
alert( +y ); // -2

// Converts non-numbers
alert( +true ); // 1
alert( +"" );   // 0
```

```js
let apples = "2";
let oranges = "3";

// both values converted to numbers before the binary plus
alert( +apples + +oranges ); // 5

// the longer variant
// alert( Number(apples) + Number(oranges) ); // 5
```