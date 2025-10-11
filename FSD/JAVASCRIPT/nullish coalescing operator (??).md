- a value is “defined” when it’s neither `null` nor `undefined`.
```js
result = (a !== null && a !== undefined) ? a : b;
```
can also be written as:

```js
result = a ?? b;
```

The common use case for `??` is to provide a default value.

---
The important difference between `||` and `??` is that:

- `||` returns the first _truthy_ value.
- `??` returns the first _defined_ value.
```js
let height = 0;

alert(height || 100); // 100
alert(height ?? 100); // 0
```
---
- The nullish coalescing operator `??` provides a short way to choose the first “defined” value from a list.
    
    It’s used to assign default values to variables:
    
    ```javascript
    // set height=100, if height is null or undefined
    height = height ?? 100;
    ```
    
- The operator `??` has a very low precedence, only a bit higher than `?` and `=`, so consider adding parentheses when using it in an expression.
    
- It’s forbidden to use it with `||` or `&&` without explicit parentheses.
    
----
#### You can also 'modify in place' with the nullish coalescing operator:

```js
let num = null  
console.log(num??=10)   //10
```

If you console.log(num) again, you get 10.  
```js
console.log(num) //10
```
So the value of num has been modified in place.

```js
let int = 1  
console.log(int??=10)  //1
```

Here the value of int is not modified, it remains 1, because it’s neither null nor undefined.

```js

```