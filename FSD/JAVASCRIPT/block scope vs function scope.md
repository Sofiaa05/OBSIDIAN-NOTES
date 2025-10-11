

### 1. **Function Scope** (Used by `var`)

> A variable is accessible **only inside the function** in which it is declared.

```javascript
function test() {
  var x = 10;
  console.log(x); // ✅ 10
}
console.log(x); // ❌ Error: x is not defined
```

### 🔸 `var` is function-scoped:

```javascript
function example() {
  if (true) {
    var a = 5;
  }
  console.log(a); // ✅ 5 — still accessible, because it's in the same function
}
```

Even though `a` was declared **inside the `if` block**, it's accessible in the whole **function** — because `var` doesn't care about `{}` blocks — only functions.

---

### ✅ 2. **Block Scope** (Used by `let` and `const`)

> A variable is accessible **only within the `{}` block** it was declared in.

```javascript
{
  let y = 20;
  console.log(y); // ✅ 20
}
console.log(y); // ❌ Error: y is not defined
```

### 🔸 `let` and `const` are block-scoped:

```javascript
function example() {
  if (true) {
    let b = 10;
  }
  console.log(b); // ❌ Error: b is not defined
}
```

So here, `b` is **not accessible** outside the `if` block.


---


### 💬 Interview One-Liner:

> "`var` is function-scoped, meaning it's accessible anywhere inside a function. `let` and `const` are block-scoped, meaning they're accessible only within the `{}` they are declared in."

