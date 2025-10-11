

## 🧠 What is Hoisting in JavaScript?

> **Hoisting** is JavaScript's default behavior of **moving declarations to the top** of the current **scope** (global or function scope) **during the compilation phase**, before any code is executed.

But it only hoists **declarations**, not **initializations**.

---

## 💡 How to Explain It Simply:

> "In JavaScript, variable and function declarations are processed before any code is run. This means you can use them before you declare them in code — because JavaScript moves their declarations to the top internally. This behavior is called hoisting."

---

## 🧪 Example 1: Hoisting with `var`

```js
console.log(name); // 👉 undefined (NOT error)
var name = "Sofia";
```

### What happens internally (hoisting):

```js
var name;
console.log(name); // undefined
name = "Sofia";
```

### ✅ Explanation:

- The **declaration** `var name;` is hoisted
    
- The **initialization** `= "Sofia"` is **NOT**
    
- So when you log it before assigning — you get `undefined`
    

---

## ❌ Example 2: `let` and `const` are NOT hoisted like `var`

```js
console.log(city); // ❌ ReferenceError: Cannot access 'city' before initialization
let city = "Delhi";
```

### ✅ Explanation:

- `let` and `const` are **hoisted**, but kept in a **"temporal dead zone (TDZ)"**
    
- So they exist, but you **can’t use them before declaration**
    
- This helps prevent bugs that `var` allows
    

---

## 🧪 Example 3: Hoisting with Functions (function declarations)

```js
sayHello(); // ✅ Works!

function sayHello() {
  console.log("Hello, Sofia!");
}
```

### ✅ Explanation:

- Function **declarations** are **fully hoisted** (name + body)
    
- That’s why you can call it before it's written
    

---

## ❌ Example 4: Function expressions are NOT hoisted

```js
greet(); // ❌ TypeError: greet is not a function

var greet = function () {
  console.log("Hi!");
};
```

### What happens:

```js
var greet; // hoisted only the variable declaration
greet();   // greet is still undefined → calling undefined()
greet = function () { ... };
```

### ✅ Explanation:

- Variable `greet` is hoisted as `undefined`
    
- The function is assigned later
    
- So calling `greet()` too early → TypeError
    

---

## 🧠 Summary Table: What gets hoisted?

|Item|Hoisted?|Can be used before declaration?|
|---|---|---|
|`var`|✅ Yes|✅ Yes (but `undefined`)|
|`let`, `const`|✅ Yes (TDZ)|❌ No (ReferenceError)|
|`function declaration`|✅ Yes|✅ Yes|
|`function expression`|❌ Partially|❌ No (TypeError or undefined)|
|`arrow function (var/let)`|❌ Partially|❌ No (TypeError)|

---

## 🎯 What to Say in an Interview

> “Hoisting is JavaScript’s default behavior of moving **declarations to the top of their scope** during compilation. `var` declarations and `function` declarations are hoisted, but only the declaration — not the value assignment. However, `let` and `const` are hoisted into a 'temporal dead zone' and cannot be used until they are defined. Function expressions and arrow functions behave like variables and are not hoisted fully.”
