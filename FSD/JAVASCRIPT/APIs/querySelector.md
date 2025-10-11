- Used to **select the first element** that matches a **CSS selector** from the DOM (Document Object Model).

#### Syntax:
```js
document.querySelector(selector)
```

- `selector`: A string representing a valid CSS selector.
    
- Returns the **first matching element**, or `null` if no match is found.
    

---

### 🔹 Examples

#### 1. Select an element by **ID**

```javascript
//query selector using id
const username =document.querySelector("#username");
username.innerText = "john doe";
```

#### 2. Select an element by **class**

```javascript
//query selector using class
const el = document.querySelector(".block");
console.log(el.innerHTML);
console.log(el.children);
```

#### 3. Select an element by **tag name**

```js
//changes the first div element found in DOM. All other divs remains same.
const div = document.querySelector("div");
div.innerHTML = "<div>'changed using query selector'</div>";

```


#### 4. Select an element using **attribute**

```javascript
const input = document.querySelector('input[type="email"]');
```

#### 5. Select **nested** elements

```javascript
const nestedSpan = document.querySelector('div.container span.highlight');
```

---

### 🔹 What if you want **multiple** elements?

Use:

```javascript
document.querySelectorAll(selector)
```

Returns a **NodeList** of **all matching elements**.

Example:

```javascript
//querySelectorAll
const divAll = document.querySelectorAll(".block");
console.log("all div elements" ,divAll);
divAll.forEach(
    (el) => {
        console.log("all elements inside div", el);
        console.log(el.innerHTML);
        console.log(el.innerText)
    }
);

//output
all div elements NodeList(2) [nav.block, h2.block]
all elements inside div <nav class=​"block">​…​</nav>​<h3>​QUERY SELECTOR USING CLASS​</h3>​</nav>​
<h3>QUERY SELECTOR USING CLASS</h3>
QUERY SELECTOR USING CLASS
all elements inside div <h2 class=​"block">​This is heading 2​</h2>​
This is heading 2
This is heading 2
```

---

### ✅ Practical Tip

Always check for `null` to avoid errors:

```javascript
const heading = document.querySelector('h1');
if (heading) {
  heading.textContent = 'Hello World!';
}
```

---

Would you like to see examples inside an HTML page, or see how `querySelector()` compares to `getElementById()` or jQuery?

```js
document.querySelectorAll(selectors);
```

Call it on the `document` object and pass a string with the CSS selectors as an argument. The argument must be a valid CSS selector string. Otherwise, a `SyntaxError` exception will be thrown.

`querySelectorAll()` returns a `NodeList` object, a collection of nodes that match the specified CSS selector.

The list will contain one `Element` object for each element that matches the CSS selectors. **If no matches are found, the list will be empty.**

The elements will be in the order in which they appear in the HTML document. 

```js
document.querySelectorAll("div");
```

All elements with a specific class:

```js
document.querySelectorAll(".rounded");
```

All elements with a specific ID:

```js
document.querySelectorAll("#logo");
```

Or all elements with a specific attribute, like all links that take users to a specific URL:

```js
document.querySelectorAll("a[href='https://www.freecodecamp.org/']");
```

You can also use more complex CSS selectors, like this one, which matches all list items within an unordered list element with the class `ingredients`:

```js
document.querySelectorAll("ul.ingredients li");
```

Since the method will return a collection of nodes, you can assign this collection to a variable and use it in your programs to work with the individual elements, like you can see in this example with the general syntax:

```js
const matches = document.querySelectorAll(selectors); 
```

For example, if you have this unordered list with three list items:

```html
<ul class="ingredients">
  <li>Flour</li>
  <li>Cheese</li>
  <li>Water</li>
</ul>
```

You can call the `querySelectorAll()` method to match all list items within the unordered list with the class `ingredients` and assign the return value to the `matches` constant:

```js
const matches = document.querySelectorAll("ul.ingredients li");
```

This will return a collection of three nodes. Each node represents a list item element:

```js
// NodeList(3)
{
  0: `<li>Flour</li>`,
  1: `<li>Cheese</li>`,
  2: `<li>Water</li>`,
  length: 3,
}
```

You can work with this collection exactly like you would work with any other JavaScript array.

For example, you can show it in the console with `console.log()`:

```js
console.log(matches);
```

You can also check the length of the collection with the `length` property:

```js
console.log(matches.length);
```

The output will be an integer representing the number of nodes in the collection:

```md
3
```

You can also access the individual elements of the collection with their corresponding indices. The first element will be at index `0`:

```js
console.log(matches[0]);
console.log(matches[1]);
console.log(matches[2]);
```

This is the output:

```html
<li>Flour</li>
<li>Cheese</li>
<li>Water</li>
```

The elements are printed one by one on the console.

You can also iterate over the elements with a `for` loop:

```js
for (let i = 0; i < matches.length; i++) {
  console.log(matches[i]);    
}
```

The output will be exactly the same in this case. But this can be very powerful for working with all the elements of the collection.