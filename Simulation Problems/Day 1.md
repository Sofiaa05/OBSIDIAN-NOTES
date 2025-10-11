- **Backend:** Create an Express server with one `/ping` route returning `"Server is running"`.

- **Frontend:** React app with one component showing `"Hello World"`.
    
- **Integration:** Call the `/ping` route from the React app using Axios and display the message.
### Backend Task:

**Goal:** Create an Express server with a simple `/ping` route returning `"Server is running"`.

```js
const express = require('express');
const app = require('express');

const cors = require('cors);
app.use(cors());

app.get('/ping', (req, res) => {
	res.send("server is running");
});

const PORT = 5001;
app.listen(PORT, () => {
	console.log(`listening on port ${PORT});
});
```

#### Test in browser/Postman:  
`http://localhost:5000/ping`

### Frontend Task:
**Goal**: Create a React app that shows "Hello World".
```java
//App.js
function App(){
  return (
    <>
    <h1>Hello World!</h1>
    </>
  )
}

export default App;

//index.js
import React from 'react';
```

### Integration
```js
import { useState, useEffect } from "react"; // React hooks
import axios from "axios"; // For API calls

function App() {
  const [message, setMessage] = useState(""); // State for storing backend message

  useEffect(() => {
    axios.get("http://localhost:5000/ping") // Call backend
      .then(res => setMessage(res.data)) // Save response in state
      .catch(err => console.error(err)); // Handle errors
  }, []); // [] means run only once when component loads

  return (
    <div>
      <h1>{message || "Loading..."}</h1> {/* Show message */}
    </div>
  );
}

export default App;

```

Integration here simply means:

- Your **frontend** (React app) will **talk** to your **backend** (Express server).
    
- React will **ask for data** from Express using an **HTTP request**.
    
- Express will **send back data**.
    
- React will **show that data** in the browser.

	- **React starts →** `useEffect` runs → sends GET request to backend.
	    
	- **Backend receives request →** responds with `"Server is running"`.
	    
	- **React receives response →** `setMessage` updates state.
	    
	- **React re-renders →** shows `"Server is running"` in browser.