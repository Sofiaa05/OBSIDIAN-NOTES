1. 
```js
let x = "5" + 2 + 3;
```

```plaintext
output: 523
```

##### Explanation: 
- String concatenation,If you put a number in quotes, the rest of the numbers will be treated as strings, and concatenated.
---
2. 
```js
let exampleVariable = null;
console.log(typeof exampleVariable); // "object"
```


This is widely considered a bug in JavaScript, dating back to its early days. The reason for this behavior is rooted in the way JavaScript was originally designed.

When the language was first implemented, values like `null` were represented as a special type of object, leading to this unexpected result. part of language, confusing so be aware.

---
3. 
![[Pasted image 20250621171601.png]]
 4. 
 ![[Pasted image 20250621171646.png]]
5. 
```js
let x = "100";  
let y = "10";  
let z = x / y;
```

JavaScript will try to convert strings to numbers in all numeric operations:

```plaintext
switch statements excel at handling multiple possible values
for a single variable, while if/else if chains offer more
flexibility for complex conditions. 
```

---
- In Javascript Math.max() is lesser than Math.min() because Math.max() returns -Infinity and Math.min() returns Infinity.
---

- The parseInt() method converts a string to an integer if it is possible. If the string starts with a number, it will convert that numeric part and return it. Else, it will return NaN.
```js
print(parseInt("123Hello"));
print(parseInt("Hello123"));

//123 
//NaN
```

---
```js
print(NaN === NaN);
//false
```

---
- functions are treated as objects in js i.e you can use . operator with functions
---
- The **Temporal Dead Zone (TDZ)** is the time **between** the hoisting of a variable declared with `let` or `const` **and** its actual declaration in the code — during which you **cannot access** the variable.
---
- `let` allows reassignment but not redeclaration; `const` allows neither. But for objects, `const` prevents reassignment of the reference, not mutation of the data.
--- 
```js
let $ = 1; // declared a variable with the name "$"
let _ = 2; // and now a variable with the name "_"

alert($ + _); // 3
```

---
```js
alert( 1 / 0 ); // Infinity
```

---
```js
alert( "not a number" / 2 ); // NaN, such division is erroneous
```

---
```js
alert( NaN + 1 ); // NaN
alert( 3 * NaN ); // NaN
alert( "not a number" / 2 - 1 ); // NaN
NaN ** 0 // 1
```
---
```js
alert( "6" / "2" ); // 3, strings are converted to numbers
```

---
```js 
let age = Number("an arbitrary string instead of a number");

alert(age); // NaN, conversion failed
```

---
```js
let result = alert("literally anything you pass here. be it number or string or empty");
console.log(result); //gives undefined always
```