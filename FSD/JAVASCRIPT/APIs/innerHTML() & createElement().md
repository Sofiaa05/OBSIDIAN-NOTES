- `innerHTML` is a property of `Element` objects that you can use to set their HTML markup.  
- With `innerHTML`, you can set the HTML structure of an existing element with a string, creating all the necessary nodes.

This is an example. We have an empty `div` and we'll add some elements within it using the `innerHTML` property:

```html
<div id="container">
  <!-- Add new elements here -->
</div>
```

First, we need to select the element by its ID:

```js
const container = document.getElementById("container");
```

Then, we set the `innerHTML` property of the container to a string. This string has to have all the markup necessary to represent the nodes and the structure that you want to create. You can think of it as writing HTML within a string.

```js
container.innerHTML = "<ul><li>Cheese</li><li>Tomato</li></ul>";
```

We will set the `innerHTML` of this element to an unordered list of pizza ingredients (cheese and tomato).


```html
<div id="container">
  <ul>
    <li>Cheese</li>
    <li>Tomato</li>
  </ul>
</div>
```

The new nodes were created and added dynamically to the DOM after the string was parsed.

#### Security risks
However, it does have some security risks that you should be familiar with. You shouldn't use it if you won't have full control over the string.

For example, if the **string will be entered by the user,** you shouldn't use `innerHTML` because the user **might insert malicious content into your website.** Because of this, it’s usually recommended to **use `textContent` instead, to insert plain text.**

### createElement()
- With this new method, you can create a new element by specifying its tag name.

For example, if you want to create an image element, you would pass the `img` tag as a string when calling this method:

```js
document.createElement("img");
```

And you can assign this new object to a variable:

```js
const img = document.createElement("img");
```

The `createElement()` method returns a new `HTMLElement` object if the document is an `HTMLDocument`. Else, it returns an `Element` object.

Once you have this new element ready, you can add it to the DOM as a child of another existing element using the `appendChild()` method, or you can insert it at a specific location using other methods. Choose the one that best fits your needs.