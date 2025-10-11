https://youtu.be/zZFjHGKe4nA?si=N7IuiN3MiTXNDY7E

## Synchronous
* Synchronous is a **blocking architecture**, so the execution of each operation depends on
**completing the one before it.**

## Asynchronous
* Asynchronous is a **non-blocking architecture**, so the execution of one task isn’t dependent on another.
* Tasks can run simultaneously (**parallel).**

## Synchronous VS Asynchronous
* Async is **multi-thread**, which means operations or programs can run in parallel.
* Sync is a **single-thread**, so only one operation or program will run at a time.
* Async is non-blocking, which means it will send multiple requests to a server. Sync is blocking — it will only send the server one request at a time and wait for that request to be answered by the server. 
* Async increases throughput because multiple operations can run at the same time.
	Sync is slower and more methodical.
---
#### Examples :

##### Asynchronous File Read :
```JS
const fs = require("fs");  
console.log("Start");  
fs.readFile("file.txt", "utf8", (err, data) => {   
	if (err) throw err;   
	console.log(data); 
});  

console.log("End");

// Output (Order may vary due to async nature)

Start 
End 
(file contents)
```

##### Synchronous File Read :
```js
const fs = require("fs");

console.log("Start");

const data = fs.readFileSync("file.txt", "utf8"); // Blocking operation
console.log(data);

console.log("End");

//Output (Always in order):
Start 
(file contents) 
End
```
## NOTE: 
- Node.js uses **asynchronous, non-blocking I/O** operations, meaning tasks can run in the background without blocking the execution of other tasks
- It **can also handle synchronous operations**. It is designed to be **non-blocking and event-driven**, making it ideal for handling multiple requests efficiently.