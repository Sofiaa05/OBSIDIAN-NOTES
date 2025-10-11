A Higher-Order Function (HOF) is a function that either:

- Takes one or more functions as arguments, or

- Returns a function as its result, or both.


### Why Are Higher-Order Functions Useful?

- **Abstract logic** — You can write general code and pass specific behavior later.
    
- **Reusability** — Same function can do different things based on input functions.
    
- **Functional programming** — Encourages writing **clean, modular** code.
#### HOF taking function as an argument
```java
function greet(name, callback){ //greet() is a HOF
    console.log("hi" + name);
    callback();
}

function sayBye(){
    console.log("bbye bye");
}

greet("sofia", sayBye);
```

#### HOF returning another function
```java
function multiplyBy(factor) {
  return function(number) {
    return number * factor;
  }
}

let double = multiplyBy(2);
let triple = multiplyBy(3);

console.log(double(5)); // Outputs: 10
console.log(triple(5)); // Outputs: 15
```

In this case, `multiplyBy` is a higher order function that returns a new function. This new function is specialized based on the factor passed to `multiplyBy`. This allows us to create custom multiplication functions with ease.

----

#### Easiest Example
```js
// HOF - Higher Order Function
// A function that takes another function as an argument or returns a function as its result
// Example of a HOF: taking a function as an argument and returning a function as a result
function sub(a, b, cb) {
    let res = a - b;
    cb();
    return () => {console.log(res)};
}

let fun = sub(10, 5, () => {
    console.log("subtraction done");
});
fun();
```