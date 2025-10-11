
* To provide **file handling** (the process by which data is stored and retrieved from files using a program.)
* It allows you to **work with the file system** on your computer.
---
- To include the File System module, use the **`require()`** method:

```js
var fs = require('fs');
```
---
# Uses:
## 1. Create Files
- Three ways to create files
 ### 1. **`fs.writeFile`** :
 
- If the file **does not exist**, it will be created.
-  If it **exists**, it will be **overwritten**
### Example :

```js
var fs = require('fs');

fs.writeFileSync("data.txt","this is example creating files in node."); 

fs.writeFile("data1.txt", "Asynchronous creating file", (error) => {
    if(error) console.log(error);
    else console.log("file has been written successfully");
});
```
##### Explanation :
- **`fs.writeFileSync`**: Blocks the execution until the file is written.
- A **callback function** is a function that is passed as an argument to another function and is executed later, usually after some operation completes. This is a key concept in **asynchronous programming**, such as handling events, reading files, or making API calls
---

### 2.  `fs.open()` :
- Takes a "flag" as the second argument, if the flag is **"w" for "writing"**, the specified file is opened for writing. 
- If the file does not exist, an empty file is created:

### Example

```js
fs.open('mynewfile2.txt', 'w', function (err, file) {  
  if (err) throw err;  
  console.log('Saved!');  
});
```  
---
### 3. `fs.appendFile()` :
- Appends specified content to a file. 
- If the file does not exist, the file will be created:

### Example :
```js
fs.appendFile('mynewfile1.txt', 'Hello content!', function (err) {  
  if (err) throw err;  
  console.log('Saved!');  
});
```
  ---
  ---
  ## 2. Read Files :
  
```js
//Synchronously
let read = fs.readFileSync("data.txt", "utf-8" )
console.log(read)

//asynchronously
fs.readFile("data1.txt" , "utf-8" , function (err,data){
    if(err) console.log(err);
    else console.log(data)
})
  
```

---
---
## 3. Update Files :
`fs.appendFile()`
`fs.writeFile()`

---
---
## 4. Delete Files :
`fs.unlink()`
```js
fs.unlink("newdata.txt", (err) => {
    if(err) console.log(err);
    console.log("file deleted");
});

//or
fs.unlinkSync("newdata.txt");
```

---
---
## 5. Rename Files : 
`fs.rename()`
```js
fs.rename("data1.txt", "rename.txt", function(err){
    if(err) console.log(err);
    console.log("done renaming");
})
```

## 6. Moving Files :
`fs.rename()`
```js
fs.rename("data.txt", "NewFolder/rename.txt", function(err){
    if(err) console.log(err);
    console.log("done renaming and moving to MyFolder");
})

```

---
---
## 7. Copying Files 
`fs.cp`
```js
fs.cp("data.txt", "data2.txt", function(err){
    if(err) console.log(err);
    console.log("done copying");
})
```

##### Important note:
We cant achieve file handling in core JavaScript (no framework, no library), since, File Handling concept is executed through server. NodeJs provide server side RTE.