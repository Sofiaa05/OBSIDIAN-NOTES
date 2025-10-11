## What is the DOM?

- html document in terms of browser we call it DOM.
- Html elements in terms of DOM are called DOM elements. Using JS, we can create, update and delete these DOM elements and also add interactivity.

The DOM is a W3C (World Wide Web Consortium) standard.

The DOM defines a standard for accessing documents:

_"The W3C Document Object Model (DOM) is a platform and language-neutral interface that allows programs and scripts to dynamically access and update the content, structure, and style of a document."_

The W3C DOM standard is separated into 3 different parts:

- Core DOM - standard model for all document types
- XML DOM - standard model for XML documents
- HTML DOM - standard model for HTML documents
## What is the HTML DOM?

The HTML DOM is a standard **object** model and **programming interface** for HTML. It defines:

- The HTML elements as **objects**
- The **properties** of all HTML elements
- The **methods** to access all HTML elements
- The **events** for all HTML elements

In other words: **The HTML DOM is a standard for how to get, change, add, or delete HTML elements.**

 - DOM stands for **Document Object Model.** It's a **programming interface that lets us interact with HTML documents.**
 - When a web page is loaded, the browser creates a **D**ocument **O**bject **M**odel of the page.

- With the DOM, you can **add, modify, or delete elements on a webpage**. You can even make your **website interactive by making elements listen to and respond to events.**

In the DOM, an **HTML document is represented as a tree of nodes**. Each node represents an HTML element from the HTML document:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>DOM Example</title>
  </head>
  <body>
    <h1>What is the DOM?</h1>
    <h2>Let's learn about the DOM</h2>
  </body>
</html>
```

This is a diagram representing the basic DOM structure of our example:

```md
Document
========

HTML
-----

- Head
  - Title
- Body
  - H1
  - H2 
```


- The **HTML document is the root node** in the DOM hierarchy. It has one child node, the html element. This is the root element of the HTML document, since all other nodes descend from it.
- The **html element has two children: `head and body.`**
- The head element contains metadata about the document. It provides essential information about the webpage.
- The body element contains the visible content of the webpage.
- You can access these elements with JavaScript, work with them in your code, and even modify them dynamically

---
### The HTML DOM Tree of Objects

![DOM HTML tree](https://www.w3schools.com/js/pic_htmltree.gif)

With the object model, JavaScript gets all the power it needs to create dynamic HTML:

- JavaScript can change all the HTML elements in the page
- JavaScript can change all the HTML attributes in the page
- JavaScript can change all the CSS styles in the page
- JavaScript can remove existing HTML elements and attributes
- JavaScript can add new HTML elements and attributes
- JavaScript can react to all existing HTML events in the page
- JavaScript can create new HTML events in the page

---


- To access these elements in JavaScript, you can use **`getElementById() and querySelector()`** methods. 
- These methods are web APIs because **they provide standardized ways to interact with the DOM using JavaScript.**
#### getElementById() method: 
- With getElementById(), you can get an object that represents the HTML element with the specified id. Remember that ids must be unique in every HTML document, so this method will only return one Element object. 
```JS
const container = document.getElementById("container");
```

This line of JavaScript code gets an element with the id value of container and assigns that object to a JavaScript constant. You must pass the id within quotation marks as an argument. If you log this object to the console, you will see it in the output:
```JS
 Codeconsole.log(container); // <div id="container">...</div>
```

#### querySelector()
- it is broader than getElementById(). With querySelector(), you can get the first element in the HTML document that matches the CSS selector passed as argument. In this example, you will get the first element with the class section and assign it to a variable:
```js
const section = document.querySelector(".section");
```
