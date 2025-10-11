### async
- keyword to declare a asynchronous function
- always returns a promise, if not returning promise, then wrap whatever the returning value is as a promise and then return it.

##### Example: 
```js
//async function always returns a promise

//example returning string 
const getdata = async () => {
    return "this is a promise in string" //wrap it inside promise and return it.
}

//getting promise
const data = getdata();
console.log(data) //Promise {<fulfilled>: 'this is a promise in string'}

//getting data from inside promise, (then method)
data.then(res => console.log(res)); //this is a promise in string

//example returning promise
async function anotherPromise(){
    return new Promise((resolve, reject) => {
        resolve("Promise resolved");
    })
}

anotherPromise().then(res => console.log(res)) //Promise resolved
```