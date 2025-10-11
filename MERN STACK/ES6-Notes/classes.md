
ES6 introduced classes.

A class is a type of function, but instead of using the keyword `function` to initiate it, we use the keyword `class`, and the properties are assigned inside a `constructor()` method.

### Example

A simple class constructor:

```jsx
class Car {
  constructor(name) {
    this.brand = name;
  }
}
```