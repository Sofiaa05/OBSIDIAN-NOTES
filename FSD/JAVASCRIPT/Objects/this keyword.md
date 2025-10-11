- The value of `this` is the object “before dot”, the one used to call the method.
```js
let user = {
  name: "John",
  age: 30,

  sayHi() {
    // "this" is the "current object"
    alert(this.name);
  }

};

user.sayHi(); // John
```

#### without `this`

```js
let user = {
  name: "John",
  age: 30,

  sayHi() {
    alert(user.name);  // ❌ this is the problem
  }
};

let admin = user;
user = null;

admin.sayHi(); // ❌ TypeError
```

---

###  Step 1:

```js
let user = {
  name: "John",
  age: 30,
  sayHi() {
    alert(user.name); // hardcoded reference to 'user'
  }
};
```

This creates an object and assigns it to `user`.  
Inside `sayHi()`, you're referencing `user.name` **explicitly** (hardcoded).

---

### Step 2:

```js
let admin = user;
```

You now have **two variables pointing to the same object** in memory.

```
user  ─┬──────────────┐
       │              │
admin ─┘       { name: "John", sayHi() { alert(user.name) } }
```

So far, both `user` and `admin` point to the same object.

---

###  Step 3:

```js
user = null;
```

This **breaks the link** between the variable `user` and the object.  
Now `admin` is the only variable still pointing to that object.

```
user → null
admin → { name: "John", sayHi() { alert(user.name) } }
```

But **inside `sayHi()`, you are still trying to access `user.name`**, and now `user === null`, so:

```js
alert(user.name); // ❌ error, because user is null now
```

---

## ✅ How to Fix It: Use `this` Instead

```js
let user = {
  name: "John",
  sayHi() {
    alert(this.name);  // ✅ now 'this' refers to the calling object
  }
};

let admin = user;
user = null;

admin.sayHi(); // ✅ works, alerts "John"
```

### Why?

Because `this` refers to **the object that called the method**, in this case `admin`.

So `this.name` is like:

```js
admin.sayHi()  → this === admin
this.name === admin.name → "John"
```

- The value of `this` is evaluated during the run-time, depending on the context.
