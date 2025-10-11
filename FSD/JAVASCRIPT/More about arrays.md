It's possible to have arrays with empty slots. Empty slots are defined as slots with nothing in them. This is different than an array with the value of `undefined`. These types of arrays are known as sparse arrays. Here is an example:

```js
const sparseArray = [1, , , 4];
console.log(sparseArray.length); // 4
```


### Constructing array of fixed length:
1. `Array()` constructor with a numeric argument. The `Array()` constructor can be used with the `new` keyword to create a new array. 

```js
const emptyArray = new Array(5);
console.log(emptyArray.length); // 5
console.log(emptyArray); // [,,,,]
```



2. `Array.from()` method with a length argument. This method creates an array of the specified length with all elements initialized to `undefined`:

```js
const fixedLengthArray = Array.from({ length: 5 });
console.log(fixedLengthArray.length); // 5

// [undefined, undefined, undefined, undefined, undefined]
console.log(fixedLengthArray);
```

3. If you want to create an array of specific length and fill it with a default value, you can use the `Array.fill()` method:

```js
const filledArray = new Array(3).fill(0);
console.log(filledArray); // [0, 0, 0]
```

