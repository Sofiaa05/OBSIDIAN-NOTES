-  In Node.js, any file that consists of **JavaScript code** in a file ending with **.js** is a module.
- A module can contain definitions of **functions, classes, objects, or variables** that can be referenced or used in another JavaScript file.
- To make it easier to **maintain, reuse and organize code**, you need to **split** the code into **multiple files**. This process is called **modularization.**
- Chunk of code in an external file that performs a specific task or function.
- Provides a way to **re-use code** in your Node application  (like classes in Java).

### 1. Creating a Module :
* Modules are created in Node.js by creating a **JavaScript file.**
* Every time you create a new file with .js extension, it becomes a module.
```js

//library.js
function Subtract(a,b) {
    return a-b
}

const myObject={
    name: "sofia",
    age: 22,
    greet: function (){
        return `Hi my name is ${this.name} and my age is ${this.age}`
    },   
}
module.exports = {Subtract,myObject};
```
### 2. Exporting a module :
```js
//library.js (from which exporting is to be done)
module.exports = {Subtract,myObject};
```

### 3. Importing a module :

   #### 1.  Using 'dot' notation:
 
- Using **require**  keyword and **`.`** notation.
- The result of require is then **stored in a variable** which is used to **invoke the functions** using the dot **`.`** notation
```js
//main.js (from which importing is to be done)
const lib = require('./library')
console.log(lib.Subtract(20,19))
console.log(lib.myObject.name)
console.log(lib.myObject.greet())

```

#### 2. Using Destructuring :

```js

//library.js
function Subtract(a,b) {
    return a-b
}

const myObject={
    name: "sofia",
    age: 22,
    greet: function (){
        return `Hi my name is ${this.name} and my age is ${this.age}`
    },   
}
module.exports = {Subtract,myObject};
```

```js
//main.js
const {myObject,Subtract} =require('./library');
console.log(Subtract(53,53));
console.log(myObject.name,myObject.greet());
```

---
# Types of modules :
## 1. Local Modules :
- Modules you **create yourself** and use.
-  Import using `require('./filename')`
## 2. Core Modules : Global and Non-Global 
- Come with **Node.js by default.** No need downloading
- ##### Examples: 
	- **FS(File System), OS(Operating System), PATH**, etc.
- Global Core Module: **`console`** No need importing
- Non-global Core module: **`FS.`** Needs importing.
## 3. Third-Party Modules :
- Downloaded with a package manager such as **`npm`**.
- stored in **`node_modules`** folder
- can be installed **globally** or **locally**.
- ##### Examples :
	- **Express, mongoose, react** etc.
##### Installation: 

```js
npm i module_name (locally)

//or

npm i module_name -g (globally)
```

##### Importing :
using **`require`** function
```js
const exp = require("express");
```