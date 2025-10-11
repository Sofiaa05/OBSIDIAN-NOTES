- Number (integer and floating points)
- String - sequence of characters enclosed in quotes
- Boolean - true/ false
- undefined - has been declared but not given a value. 
An empty value has nothing to do with `undefined`.
An empty string has both a legal value and a type
- null  - set to nothing. holds nothing. It’s just a special value which represents “nothing”, “empty” or “value unknown”.

- Symbol - for unique indentifiers
- bigInt - very large numbers
- object - key-value pair
## Variables
 - boxed that hold values
 -  Variables are Containers for Storing Data
	 - #### JavaScript Variables can be declared in 4 ways:

		- Automatically
		- Using `var`
		- Using `let`
		- Using `const`
 - variable names are case sensitive, start with digit (0-9), dollar sign or an underscore.
 - follow camelcase
 - cant use keywords as variables names
 ### When to Use var, let, or const?

1. Always declare variables

2. Always use `const` if the value should not be changed

3. Always use `const` if the type should not be changed (Arrays and Objects)

4. Only use `let` if you can't use `const`

5. Only use `var` if you MUST support old browsers.

![[Pasted image 20250621153832.png]]

### const

**Always declare a variable with `const` when you know that the value should not be changed.**

Use `const` when you declare:

- A new Array
- A new Object
- A new Function
- A new RegExp
#### Constant Objects and Arrays

The keyword `const` is a little misleading.

It does not define a constant value. It defines a constant reference to a value.

Because of this you can NOT:

- Reassign a constant value
- Reassign a constant array
- Reassign a constant object

But you CAN:

- Change the elements of constant array
- Change the properties of constant object
---
### review
##   Working with HTML, CSS, and JavaScript

While HTML and CSS provide website structure, JavaScript brings interactivity to websites by enabling complex functionality, such as handling user input, animating elements, and even building full web applications.

## Data Types in JavaScript

Data types help the program understand the kind of data it's working with, whether it's a number, text, or something else.

- **Number**: A number represents both integers and floating-point values. Examples of integers include 7, 19, and 90.
- **Floating point**: A floating point number is a number with a decimal point. Examples include 3.14, 0.5, and 0.0001.
- **String**: A string is a sequence of characters, or text, enclosed in quotes. `"I like coding"` and `'JavaScript is fun'` are examples of strings.
- **Boolean**: A boolean represents one of two possible values: `true` or `false`. You can use a boolean to represent a condition, such as `isLoggedIn = true`.
- **Undefined and Null**: An `undefined` value is a variable that has been declared but not assigned a value. A `null` value is an empty value, or a variable that has intentionally been assigned a value of `null`.
- **Object**: An object is a collection of key-value pairs. The key is the property name, and the value is the property value.

Here, the `pet` object has three properties or keys: `name`, `age`, and `type`. The values are `Fluffy`, `3`, and `dog`, respectively.

```js
let pet = {
  name: "Fluffy",
  age: 3,
  type: "dog"
};
```

- **Symbol**: The Symbol data type is a unique and immutable value that may be used as an identifier for object properties.

In this example below, two symbols are created with the same description, but they are not equal.

```js
const crypticKey1= Symbol("saltNpepper");
const crypticKey2= Symbol("saltNpepper");
console.log(crypticKey1 === crypticKey2); // false
```

- **BigInt**: When the number is too large for the `Number` data type, you can use the BigInt data type to represent integers of arbitrary length.

By adding an `n` to the end of the number, you can create a BigInt.

```js
const veryBigNumber = 1234567890123456789012345678901234567890n;
```

## Variables in JavaScript

- Variables can be declared using the `let` keyword.

```js
let cityName;
```

- To assign a value to a variable, you can use the assignment operator `=`.

```js
cityName = "New York";
```

- Variables declared using `let` can be reassigned a new value.

```js
cityName = "Los Angeles";
console.log(cityName); // Los Angeles
```

- Apart from `let`, you can also use `const` to declare a variable. However, a `const` variable cannot be reassigned a new value.

```js
const cityName = "New York";
cityName = "Los Angeles"; // TypeError: Assignment to constant variable.
```

- Variables declared using `const` find uses in declaring constants, that are not allowed to change throughout the code, such as `PI` or `MAX_SIZE`.

## Variable Naming Conventions

- Variable names should be descriptive and meaningful.
- Variable names should be camelCase like `cityName`, `isLoggedIn`, and `veryBigNumber`.
- Variable names should not start with a number. They must begin with a letter, `_`, or `$`.
- Variable names should not contain spaces or special characters, except for `_` and `$`.
- Variable names should not be reserved keywords.
- Variable names are case-sensitive. `age` and `Age` are different variables.

## Strings and String immutability in JavaScript

- Strings are sequences of characters enclosed in quotes. They can be created using single quotes and double quotes.

```js
let correctWay = 'This is a string';
let alsoCorrect = "This is also a string";
```

- Strings are immutable in JavaScript. This means that once a string is created, you cannot change the characters in the string. However, you can still reassign strings to a new value.

```js
let firstName = "John";
firstName = "Jane"; // Reassigning the string to a new value
```

## String Concatenation in JavaScript

- Concatenation is the process of joining multiple strings or combining strings with variables that hold text. The `+` operator is one of the simplest and most frequently used methods to concatenate strings.

```js
let studentName = "Asad";
let studentAge = 25;
let studentInfo = studentName + " is " + studentAge + " years old.";
console.log(studentInfo); // Asad is 25 years old.
```

- If you need to add or append to an existing string, then you can use the `+=` operator. This is helpful when you want to build upon a string by adding more text to it over time.

```js
let message = "Welcome to programming, ";
message += "Asad!";
console.log(message); // Welcome to programming, Asad!
```

- Another way you can concatenate strings is to use the `concat()` method. This method joins two or more strings together.

```js
let firstName = "John";
let lastName = "Doe";
let fullName = firstName.concat(" ", lastName);
console.log(fullName); // John Doe
```

## Logging Messages with `console.log()`

- The `console.log()` method is used to log messages to the console. It's a helpful tool for debugging and testing your code.

```js
console.log("Hello, World!");
// Output: Hello, World!
```

## Semicolons in JavaScript

- Semicolons are primarily used to mark the end of a statement. This helps the JavaScript engine understand the separation of individual instructions, which is crucial for correct execution.

```js
let message = "Hello, World!"; // first statement ends here
let number = 42; // second statement starts here
```

- Semicolons help prevent ambiguities in code execution and ensure that statements are correctly terminated.

## Comments in JavaScript

- Any line of code that is commented out is ignored by the JavaScript engine. Comments are used to explain code, make notes, or temporarily disable code.
- Single-line comments are created using `//`.

```js
// This is a single-line comment and will be ignored by the JavaScript engine
```

- Multi-line comments are created using `/*` to start the comment and `*/` to end the comment.

```js
/*
This is a multi-line comment.
It can span multiple lines.
*/
```

## JavaScript as a Dynamically Typed Language

- JavaScript is a dynamically typed language, which means that you don't have to specify the data type of a variable when you declare it. The JavaScript engine automatically determines the data type based on the value assigned to the variable.

```js
let error = 404; // JavaScript treats error as a number
error = "Not Found"; // JavaScript now treats error as a string
```

- Other languages, like Java, that are not dynamically typed would result in an error:

```js
int error = 404; // value must always be an integer
error = "Not Found"; // This would cause an error in Java
```

## Using the `typeof` Operator

- The `typeof` operator is used to check the data type of a variable. It returns a string indicating the type of the variable.

```js
let age = 25;
console.log(typeof age); // "number"

let isLoggedIn = true;
console.log(typeof isLoggedIn); // "boolean"
```

- However, there's a well-known quirk in JavaScript when it comes to `null`. The `typeof` operator returns `"object"` for `null` values.

```js
let user = null;
console.log(typeof user); // "object
```

---
## String Basics

- **Definition**: A string is a sequence of characters wrapped in either single quotes, double quotes or backticks. Strings are primitive data types and they are immutable. Immutability means that once a string is created, is cannot be changed.
- **Accessing Characters from a String**: To access a character from a string you can use bracket notation and pass in the index number. An index is the position of a character within a string, and it is zero-based.

```js
const developer = "Jessica";
developer[0] // J
```

- **`\n` (Newline Character)**: You can create a newline in a string by using the `\n` newline character.

```js
const poem = "Roses are red,\nViolets are blue,\nJavaScript is fun,\nAnd so are you.";
console.log(poem);
```

- **Escaping Strings**: You can escape characters in a string by placing backlashes (`\`) in front of the quotes.

```js
const statement = "She said, \"Hello!\"";
console.log(statement); // She said, "Hello!"
```

## Template Literals (Template Strings) and String Interpolation

- **Definition**: Template literals are defined with backticks (`). They allow for easier string manipulation, including embedding variables directly inside a string, a feature known as string interpolation.

```js
const name = "Jessica";
const greeting = `Hello, ${name}!`; // "Hello, Jessica!"
```

## ASCII, the `charCodeAt()` Method and the `fromCharCode()` Method

- **ASCII**: ASCII, short for American Standard Code for Information Interchange, is a character encoding standard used in computers to represent text. It assigns a numeric value to each character, which is universally recognized by machines.
- **The `charCodeAt()` Method**: This method is called on a string and returns the ASCII code of the character at a specified index.

```js
const letter = "A";
console.log(letter.charCodeAt(0));  // 65
```

- **The `fromCharCode()` Method**: This method converts an ASCII code into its corresponding character.

```js
const char = String.fromCharCode(65);
console.log(char);  // A
```

## Other Common String Methods

- **The `indexOf` Method**: This method is used to search for a substring within a string. If the substring is found, `indexOf` returns the index (or position) of the first occurrence of that substring. If the substring is not found, `indexOf` returns -1, which indicates that the search was unsuccessful.

```js
const text = "The quick brown fox jumps over the lazy dog.";
console.log(text.indexOf("fox")); // 16
console.log(text.indexOf("cat")); // -1
```

- **The `includes()` Method**: This method is used to check if a string contains a specific substring. If the substring is found within the string, the method returns true. Otherwise, it returns false.

```js
const text = "The quick brown fox jumps over the lazy dog.";
console.log(text.includes("fox")); // true
console.log(text.includes("cat")); // false
```

- **The `slice()` Method**: This method extracts a portion of a string and returns a new string, without modifying the original string. It takes two parameters: the starting index and the optional ending index.

```js
const text = "freeCodeCamp";
console.log(text.slice(0, 4));  // "free"
console.log(text.slice(4, 8));  // "Code"
console.log(text.slice(8, 12)); // "Camp"
```

- **The `toUpperCase()` Method**: This method converts all the characters to uppercase letters and returns a new string with all uppercase characters.

```js
const text = "Hello, world!";
console.log(text.toUpperCase()); // "HELLO, WORLD!"
```

- **The `toLowerCase()` Method**: This method converts all characters in a string to lowercase.

```js
const text = "HELLO, WORLD!"
console.log(text.toLowerCase()); // "hello, world!"
```

- **The `replace()` Method**: This method is used to find a specified value (like a word or character) in a string and replace it with another value.

```js
const text = "I like cats";
console.log(text.replace("cats", "dogs")); // "I like dogs"
```

- **The `repeat()` Method**: This method is used to repeat a string a specified number of times.

```js
const text = "Hello";
console.log(text.repeat(3)); // "HelloHelloHello"
```

- **The `trim()` Method**: This method is used to remove whitespaces from both the beginning and the end of a string.

```js
const text = "  Hello, world!  ";
console.log(text.trim()); // "Hello, world!"
```

- **The `trimStart()` Method**: This method removes whitespaces from the beginning (or "start") of the string.

```js
const text = "  Hello, world!  ";
console.log(text.trimStart()); // "Hello, world!  "
```

- **The `trimEnd()` Method**: This method removes whitespaces from the end of the string.

```js
const text = " Hello, world! ";
console.log(text.trimEnd()); // "  Hello, world!"
```

- **The `prompt()` Method**: This method of the `window` is used to get information from a user through the form of a dialog box. This method takes two arguments. The first argument is the message which will appear inside the dialog box, typically prompting the user to enter information. The second one is a default value which is optional and will fill the input field initially.

```js
const answer = window.prompt("What's your favorite animal?"); // This will change depending on what the user answers
```