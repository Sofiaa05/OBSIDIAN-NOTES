- JavaScript Object Notation. It is a lightweight, text-based data format that is commonly used to exchange data between a server and a web application.
- One of the reasons why JSON is so popular in web development is because it is both machine-parseable and human-readable.
- Since JSON is language-independent, you can easily send JSON data from a Java application to a Python application, or from a JavaScript application to a C# application.

JSON supports many data types including objects, arrays, strings, booleans, null, and numbers.

```js
{
  "name": "Alice",
  "age": 30,
  "isStudent": false,
  "list of courses": ["Mathematics", "Physics", "Computer Science"]
}
```

As you can see, JSON uses key-value pairs to store information and each pair is separated by a comma. Each key must be wrapped in double quotes, otherwise you will get an error.

To access data from a JSON object, you can either use dot or bracket notation.

```js
import data from "./example.json" assert { type: "json" };

console.log(data.age); 
clg(data["age"])
```


In summary, JSON is a versatile format that can store many data types, including arrays and nested objects. By using dot notation or bracket notation, you can easily access the values stored within a JSON object.

---
### JSON.parse() & JSON.stringify()

1. **JSON.stringify()**
- To convert a JavaScript object into a JSON string. This is useful when you want to store or transmit data in a format that can be easily shared or transferred between systems.

```js
const user = {
  name: "John",
  age: 30,
  isAdmin: true
};

const jsonString = JSON.stringify(user);
console.log(jsonString);
```

In the example, the JavaScript object `user` is converted into a JSON string that looks like this:

```js
'{"name":"John","age":30,"isAdmin":true}'
```

- The `JSON.stringify()` method also accepts an optional parameter called a replacer, which can be a function or an array. Here is an example of using an array for the optional replacer parameter:

```js
const developerObj = {
  firstName: "Jessica",
  isAwesome: true,
  isMusician: true,
  country: "USA",
};

// result: {"firstName":"Jessica","country":"USA"}
console.log(JSON.stringify(developerObj, ["firstName", "country"]));
```

In this example, we have a `developerObj` with four properties. When we use the `JSON.stringify()` method, we can pass in an array for the second parameter and specify which properties we want stringified. The result will be a stringified object containing only the `firstName` and `country` properties.

2. **JSON.parse():**
`JSON.parse()` converts a JSON string back into a JavaScript object. This is useful when you retrieve JSON data from a web server or from `localStorage` and you need to manipulate the data in your application. You will learn more about `localStorage` in a future lecture.

```js
const jsonString = '{"name":"John","age":30,"isAdmin":true}';
const userObject = JSON.parse(jsonString);
```

The JSON string is parsed back into a JavaScript object that looks like this:

```js
{
  name: "John",
  age: 30,
  isAdmin: true
}
```

This allows you to work with the data in your program as a normal JavaScript object, making it easier to manipulate and use.