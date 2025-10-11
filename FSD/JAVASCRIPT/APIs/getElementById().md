

`getElementById()` is a JavaScript method used to **select a single HTML element** by its **`id` attribute**.

### ✅ Syntax:

```js
document.getElementById("id-name");
```

- `"id-name"` is the value of the `id` in your HTML element.
    

---

## 📦 Example HTML:

```html
    <div >
        <h1>Second div</h1>
        <p>I am <span id="username">Sofia</span></p>
    </div>

```

```js
const el = document.getElementById('username');
console.log(el.innerText);
el.remove();
```


### 🔍 Output in Console:

```html
Sofia
```

---

## 🖊️ Changing Content with it

```js
el.innerText = "Hello, Sofia!";
```

Now the text inside the `<h1>` changes on the webpage to:

```html
<h1 id="mainTitle">Hello, Sofia!</h1>
```

---

## 🔥 Key Facts

|Feature|`getElementById()`|
|---|---|
|Selector type|ID only|
|Returns|A **single element**|
|Fast?|✅ Yes, it's the **fastest** DOM selector|
|ID uniqueness required|✅ Yes, every ID should be unique|

---

## ❌ Common Mistakes

1. **Forgetting quotes:**
    
    ```js
    document.getElementById(mainTitle); // ❌ will give error
    ```
    
2. **ID doesn't exist:**
    
    ```js
    document.getElementById("wrongId"); // ❌ returns null
    ```
    

---

## ✅ Real-Life Example

### HTML:

```html
<p id="greet">Hello there!</p>
```

### JavaScript:

```js
const para = document.getElementById("greet");
para.style.color = "blue";
para.innerText = "Have a nice day!";
```

---

## 🆚 Compared to `querySelector()`

|Feature|`getElementById()`|`querySelector()`|
|---|---|---|
|Selector|Only by ID (`"myId"`)|Any CSS selector (`"#myId"`)|
|Returns|One element|First matching element|
|Performance|Slightly faster|Slightly slower|
|Simplicity|Very easy for IDs|More flexible for all types|

---

## ✅ `querySelector()` Can Be Used to Style Elements

### Example:

```html
<div class="card">Welcome!</div>
```

### JavaScript:

```js
const card = document.querySelector('.card');
card.style.color = "blue";           // change text color
card.style.backgroundColor = "pink"; // change background color
card.style.padding = "20px";         // add padding
```

This works exactly like `getElementById()`, except you use a **CSS selector** (like `.card`, `#main`, `div h1`, etc.).

---

## 🔥 Difference?

Both `getElementById()` and `querySelector()` return **DOM elements**, and once you have that element, you can modify **styles**, **text**, **attributes**, **HTML**, and more.

### So YES ✅:

You can inject CSS like this:

```js
document.querySelector(".btn").style.backgroundColor = "red";
```

---

## 🧠 Bonus: Add Entire Class (Optional)

Instead of styling line by line, you can apply a **CSS class**:

### CSS:

```html
<style>
  .highlight {
    background-color: yellow;
    color: red;
    font-weight: bold;
  }
</style>
```

### JS:

```js
document.querySelector("#username").classList.add("highlight");
```

---

## 📝 Summary

|Feature|`getElementById()`|`querySelector()`|
|---|---|---|
|Selects by|Only `id`|Any valid CSS selector|
|Can modify CSS?|✅ Yes|✅ Yes|
|Style usage|`element.style.prop`|`element.style.prop`|
|Apply class?|✅ Use `classList.add()`|✅ Use `classList.add()`|

---

## getElementByClassName()

```js
for (let index = 0; index < el.length; index++) {
    el[index].remove();
}

```
### `getElementsByClassName()` returns a **live HTMLCollection**:

- It **updates automatically** as elements are removed.
    
- So if you remove `el[0]`, the next element becomes the new `el[0]`.
    
- Your loop then **skips elements** or stops early.

### Correct way

```js
//task is to remove all elements with classname = "remove"

const el = document.getElementsByClassName("remove");
console.log(el)
for (let i = el.length - 1; i >= 0; i--) {
    el[i].remove(); 
}
```

- We remove from the **end to the start**, so the shifting doesn't affect the next item we want to delete.

### using querySelectorAll()
```js
document.querySelectorAll(".remove").forEach(el => el.remove());
```

This uses a **static NodeList**, so no shifting issues