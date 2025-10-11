- Allows a function to accept an **indefinite number of arguments** as an array. 
- It is represented by three dots (…) followed by the parameter name.
- It must be the **last parameter** in the function, not at start or middle.
- A function can be called with any number of arguments, no matter how it was defined.
- Used during **function declaration.**

### Example 1: Without using rest parameter:

```c
const sub = (a,b) => {
	return a-b;
}

document.write(sub(90,80) + "</br"); // output: 10

document.write(sub(90,50,60)) //output: 40
```

### Example 2: Using Rest Parameter:

```c
const add = (...args) => {
	let sum =0;
	
	for(let i in args){
		sum += args[i]
	}

	const display=document.getElementById("display").innerText=`${sum}`;
}

add(69,96,6969)

OUTPUT: 7134 
```

### Example 3: Another way without rest parameter:

NOT ALLOWED IN ARROW FUNCTIONS
```javascript
function add() {
	let sum =0;

	for (let i in arguments){
		sum += arguments[i];
	}
	document.write(sum, " ");
}

add(5,10);
add(5,10,100);
add(5,110,1000);
add("sofia",10,50,30);

OUTPUT: 15 115 1115 0sofia105030 //0 comes from sum=0

Adding string "sofia" treated all arguments as string so, it concatenates all the values.
```

### Example 4: Using Rest Parameter with Other Parameters
```c
const add = (val,...args) => {
	let sum =0;
	
	for(let i in args){
		sum += args[i]
	}

	const display=document.getElementById("display").innerText=`value is: ${val}     and ${sum}`;
}

add("sofia" ,69,96,6969)

OUTPUT: value is: sofia and 30

let arr = [1,2,3]
add("sofia", arr); 

Output: error as rest parameter expect multiple values to function not single 

```

### Example 5: Spread Operator and Rest Parameter in one code
```js
const restSpread= (val,...args)=>{
	let sum=0;
	for(let i in args){
	sum+=args[i];
}

	console.log("sum is: ",sum)
	console.log("value is:",val)
}

let array1 =[23,342,5325]
restSpread("sofia",...array1)

Output:
sum is:  5690
value is: sofia
```