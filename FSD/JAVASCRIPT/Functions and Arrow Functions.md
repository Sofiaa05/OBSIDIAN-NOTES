### Variable number of arguments: 

#### 1. Using `arguments` keyword:
- In javascripts, we have a **built-in object called `arguments`** which can be used to store (any number of) parameters received by a function 
- can also loop through this `arguments` object
```js
function addNumbers(){
	let add = 0
	for(let i = 0; i < arguments.length; i++){
		add += arguments[i];
	}
	return add;
}

//calling
console.log(addNumbers(1,2,3,4,5));
```

#### 2. Using `Spread Operator`:
```js
function addNumbers(...numbers){
	let add = 0;
	for(let i = 0; i < numbers.length; i++){
		add += numbes[i];
	}
	return add;
}

console.log(addNumbers(1,2,3,4,5));
```

- `...numbers` creates an array of numbers of parameters passed to the function. 

---
## Arrow Functions
### 1. Syntax
#### Normal functions:
```js
function add(a, b){
	return a + b;
}

console.log(add(2,3));
```

#### Arrow Function
```js
const add = (a ,b) => {
	return a + b;
}

//or

const add = (a, b) => a + b; //no need to return and enclose in brackets if returning single value. must return if using paranthesis

//calling
console.log(add(2, 3));
```

### 2. `arguments` keyword
- Arrow function doesn't support working with `arguments` object 
```js
const add = () => {
	console.log(arguments);
}

add(1,2,3,4); 
//gives error: Uncaught ReferenceError: arguments is not defined at add (REPL7:2:13)
```

#### to work with variable number of arguments, use Spread operator
```js
const add = (...nums) => {
	console.log(nums);
}

add(1,2,3,4); //[ 1, 2, 3, 4 ]
```

---
### 3. Hoisting
- normal functions can be hoisted 
```js
greet();

function greet(){
	console.log("hi");
}

//outpu: hi
```

- Arrow functions cannot be hoisted
```js
greet();

const greet = () => {
    console.log("hi");
}

//Arrow.js:1 Uncaught ReferenceError: Cannot access 'greet' before initialization
```

- define first then  access
```js
const greet = () => {
    console.log("hi");
}
greet();

//hi
```

### 4. `This` keyword
- Arrow functions **do not have their own `this`**
    
- They inherit `this` from the **surrounding lexical scope**
#### Normal function with `this` keyword
```js
const obj1 = {
    value : 20,
    myfunction: function(){
        console.log(this); // Regular functions have their own 'this' context
        console.log(this.value); // 20, because 'this' refers to the obj1
    }
}

obj1.myfunction();

```

#### Arrow function with `this` keyword
```js
const obj = {
    value : 20,
    myfunction: () => {
    
        console.log(this); // Arrow functions do not have their own 'this', they inherit it from the parent scope. will point to global = window object
        
        console.log(this.value); // undefined, because 'this' refers to the global object (or undefined in strict mode)
    }
}

obj.myfunction(); //here this.value = obj.value

```

---
#### Another Example: 
```js
const person = {
  name: "Sofia",
  regular: function () {
    console.log("Regular:", this.name);
  },
  arrow: () => {
    console.log("Arrow:", this.name);
  }
};

person.regular(); // this = person → "Sofia"
person.arrow();   // this = not person → undefined

```

- `regular()` works fine because it gets `this` from the object `person`
    
- `arrow()` fails because arrow functions **don’t get `this` from the object**, only from the place they were **written**. 