The `addEventListener()` method attaches an event handler to the specified element.

The `addEventListener()` method attaches an event handler to an element without overwriting existing event handlers.

You can add many event handlers to one element.

## Syntax

```js
_element_.addEventListener(_event, function, useCapture_);
```

The first parameter is the type of the event (like "`click`" or "`mousedown`" or any other [HTML DOM Event](https://www.w3schools.com/jsref/dom_obj_event.asp).)

The second parameter is the function we want to call when the event occurs.

The third parameter is a boolean value specifying whether to use event bubbling or event capturing. This parameter is optional.

##### Example:
```js
element.addEventListener("click", function(){ alert("Hello World!"); });
```

### Event Bubbling or Event Capturing?

There are two ways of event propagation in the HTML DOM, **bubbling and capturing.**

Event propagation is a way of defining the element order when an event occurs. If you have a <\p> element inside a <\div> element, and the user clicks on the <\p> element, which element's "click" event should be handled first?

1. **In bubbling** the inner most element's event is handled first and then the outer: the <\p> element's click event is handled first, then the <\div> element's click event.

2. In **capturing** the outer most element's event is handled first and then the inner: the <\div> element's click event will be handled first, then the <\p> element's click event.

With the addEventListener() method you can specify the propagation type by using the "useCapture" parameter:

```js
addEventListener(event, function, useCapture);
```
The default value is false, which will use the bubbling propagation, when the value is set to true, the event uses the capturing propagation.