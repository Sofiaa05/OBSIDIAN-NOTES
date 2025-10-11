- Breaking up code into separate files.
- Must mention "type=module" with "script" tag when working with module
	 **`<script type="module" src="./program.js"></script>`**
- **ES6 modules** enhance **JavaScript** by allowing developers to modularize code, breaking it into manageable pieces that can be imported and reused across different parts of an application.

Exports in a module can be classified as:
1. Named Exports
2. Default Exports
### 1. Named Export:
- Distinguished by their names.
- There can be **several** named exports in a module.
- Aliases can be provided for named exports using **as** keyword
- imported inside { }

```js
Method 1: exporting one at a time

export let name ="sofia";

export const showMsg = (data) => 
   console.log(`Hi this is showing ${data}`);

export class Student{
    constructor(){
        console.log("This is my student class.")
    }
}
```


```js
Method 2: exporting all together

 let name ="sofia";

 const showMsg = (data) => 
   console.log(`Hi this is showing ${data}`);

 class Student{
    constructor(){
        console.log("This is my student class.")
    }
}

export {name, showMsg, Student}
```

### 2. Default Export:
- Modules that need to export only a single value can use default export.
- There can be only **one default** export per module.
- unlike, named exports, a default export can be imported with any name. 
- Doesn't require { }

```js
export default function Hello(){
    console.log("Hi this is default export. this can be only one. can be imported with any name")
}
```

### Importing default and named exports:

```js
import {name, showMsg, Student} from "./index.js"  // importing named export
import Hello from "./index.js";  // importing default export 

//named and default exports can be imported together in one single line as well:
import Hello, {name, showMsg, Student} from "./index.js"

console.log(name)
showMsg("named export.")

const obj = new Student();
Hello(); 
```

for default export you dont need to specify name (if you dont want to) while exporting. You can also import the default export with any name.

```js
export default function(){
    console.log("Hi this is default export. this can be only one. can be imported with any name")
}

importing:
import sofia from "./index.js"

```