A **static file** is any file that is **delivered to the browser exactly as it is** — **without any server-side processing or change**.
![[Pasted image 20250625214053.png]]

| Feature            | Static Files        | Dynamic Files                    |
| ------------------ | ------------------- | -------------------------------- |
| Changes per user?  | ❌ No                | ✅ Yes (customized)               |
| Server processing? | ❌ None              | ✅ Yes (e.g., Java, PHP, Node.js) |
| Example            | `about.html`        | `profile.jsp`, `orders.php`      |
| Example use        | Logo image, CSS, JS | Logged-in user's dashboard       |

### Without express.static()
```js
app.get('/logo.png', (req, res) => {
  res.sendFile(__dirname + '/public/logo.png');
});

```

Express provides a **built-in middleware**: `express.static()` to **serve everything in a folder**.

### With express.static()
```js
app.use(express.static('folderName'));
```

---
```js
console.log(__dirname) //gives path of your entire project
```

- now i want to attach the folder (which contain only static files) to the project directory path

### Example:
```js
const express = require('express');
const app = express(); //This creates an instance of the Express application.
const path = require('path');
/*path is a module that helps you work with file and folder paths.
It makes sure the paths work correctly on all computers (Windows, Mac, Linux) */

console.log(__dirname);  //Users/sofiaabbasi/Desktop/wallet-watch/backend
//__dirname is a special variable in Node.js.
//It gives the full absolute path of the folder where this file (your code) is located.

var public = path.join(__dirname, 'public'); 
/* This creates the full path to your public folder.
path.join() combines:
	__dirname (your current folder)
	'public' (the name of your static folder)
*/
 
console.log(public);
///Users/sofiaabbasi/Desktop/wallet-watch/backend/public

app.use(express.static(public); //Serve all the static files (HTML, CSS, images, JS) from this `public` folder.”

app.listen(3000, () => {
  console.log('Server is running at http://localhost:3000');
});
```

#### notes
```js
app.use() //
```
- to define middlware that executes on every request regardless of HTTP method

```js
express.static();
```

- middleware to serve static files like html, css, javascript , images from a specified direcotry on server
- automates the serving of static files by **mapping URLs directly to files** in the specified directory, simplifying configuration and reducing development effort