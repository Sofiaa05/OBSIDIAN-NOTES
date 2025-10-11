- In JavaScript, a callback function is a **function that is passed as an argument to another function and is executed after the main function has finished its execution.** 
- It's a way to ensure that certain code doesn't execute until a previous operation has been completed.


Imagine you have a function that performs a task, and you want to do something after that task is complete. Instead of writing all the code in one big function, you can pass a second function (the callback) to be executed when the first function is done. This allows for more flexible and modular code.

### forEach
- `forEach` is a built-in method for arrays in JavaScript. It allows you to iterate over each element in an array and perform an operation on each element. 
- The operation you want to perform is defined in a callback function that you provide to `forEach`.


```js
let numbers = [1, 2, 3, 4, 5];

numbers.forEach(function(number) {
  console.log(number * 2);
});
```


This callback function takes one parameter, which represents each element in the array. The `forEach` method will **call this callback function once for each element in the array.**

```md
2
4
6
8
10
```

It's important to understand that the callback function is called once for each element in the array, in order. **`forEach` takes care of the looping for you, so you don't have to write a `for` loop yourself.**

- You can also use an arrow function as the callback, which can make your code even more concise:

```js
let numbers = [1, 2, 3, 4, 5];
numbers.forEach(number => console.log(number * 2));
```


- The callback function in `forEach` can actually take up to three arguments: the current element, the index of the current element, and the array that `forEach` was called upon.


```js
let numbers = [1, 2, 3, 4, 5];
numbers.forEach((number, index, array) => {
  console.log(`Element ${number} is at index ${index} in array ${array}`);
});
```

---
