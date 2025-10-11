#### What are promises?
#### Why are promises important? / Why do we use promises?
- Object representing eventual completion or failure of an asynchronous function
- object like a placeholder which will be filled later with a value sent by asynchronous operation and its resulting value.
- A promise has: 
	- state
	- result
- A Promise is a **guarantee** that some code will finish in the future and give you either `success` or `failure`

![[Pasted image 20250715172545.png]]
#### Before Promises: 
- Before promise we used to depend on callback functions which would result in: 
	1. Callback Hell (Pyramid of doom) 
	2. Inversion of control 
#### After Promises:

##### Overcoming Inversion of control:
1. As soon as promise is rejected: It updates the empty object which is assigned undefined in pending state. 
2. If fullfilled: It updates the empty object with the response data
3. A promise resolves only once and it is immutable. 
4. Using .then() we can control when we call the cb(callback) function. 

##### Overcoming callback hell (Pyramid of doom): 
- Promise chaining: This way our code expands vertically instead of horizontally. As each function returns something which is used by next function.
	- Chaining is done using `.then()`
- A very common mistake that developers do is not returning a value during chaining of promises. Always remember to return a value. This returned value will be used by the next .then()
-  **Before promises:**
```js
placeOrder(orderDetails, function(order) {
  makePayment(order, function(paymentStatus) {
    getOrderSummary(paymentStatus, function(summary) {
      updateWallet(summary, function(walletStatus) {
        console.log("Order completed and wallet updated");
      });
    });
  });
});
```

- Each function depends on the result of the previous one. This deeply nested structure becomes **hard to read, debug, and maintain**.

- **After Promises:**
```js
placeOrder(orderDetails)
  .then(order => makePayment(order))
  .then(paymentStatus => getOrderSummary(paymentStatus))
  .then(summary => updateWallet(summary))
  .then(walletStatus => {
    console.log("Order completed and wallet updated");
  })
  .catch(error => {
    console.error("Something went wrong:", error);
  });

```
- **Linear** and readable.
- **Handles errors in one place** using `.catch()`.
- Easier to **maintain and debug**.
##### Make asynchronous code look cleaner and easier to read.
##### Better error handling using .catch()

---
### Creating Promises


- **Producing code**: The part of the code that **creates** a promise and eventually **resolves** or **rejects** it.

- **Consuming code**: The part of the code that **uses** the promise (via `.then()`, `.catch()`, or `await`) and handles the result or error.


#### 1. Producing Code — Functions that return Promises

```js
// Producing code: returns a promise
function placeOrder(orderDetails) {
  return new Promise((resolve, reject) => {
    console.log("Placing order...");
    setTimeout(() => {
      if (orderDetails) {
        resolve("Order123");
      } else {
        reject("Order details missing");
      }
    }, 1000);
  });
}

function makePayment(order) {
  return new Promise((resolve, reject) => {
    console.log("Processing payment...");
    setTimeout(() => {
      if (order) {
        resolve("Payment Successful");
      } else {
        reject("Invalid order");
      }
    }, 1000);
  });
}

function getOrderSummary(paymentStatus) {
  return new Promise((resolve, reject) => {
    console.log("Getting order summary...");
    setTimeout(() => {
      if (paymentStatus === "Payment Successful") {
        resolve("Order Summary Generated");
      } else {
        reject("Payment failed");
      }
    }, 1000);
  });
}

function updateWallet(summary) {
  return new Promise((resolve, reject) => {
    console.log("Updating wallet...");
    setTimeout(() => {
      if (summary) {
        resolve("Wallet updated successfully");
      } else {
        reject("Summary missing");
      }
    }, 1000);
  });
}
```

Each of these functions is a **producer** of a Promise.

---

#### 2. Consuming Code — Using the Promises

Now you **consume** these promises like this:

```js
const orderDetails = { item: "Pizza", quantity: 1 };

placeOrder(orderDetails)
  .then(order => {
    return makePayment(order);
  })
  .then(paymentStatus => {
    return getOrderSummary(paymentStatus);
  })
  .then(summary => {
    return updateWallet(summary);
  })
  .then(walletStatus => {
    console.log("✅ Order completed and wallet updated:", walletStatus);
  })
  .catch(error => {
    console.error("❌ Something went wrong:", error);
  });
```

This block is the **consumer**: it receives the promise results and processes them.

### 1️⃣ `const orderDetails = { item: "Pizza", quantity: 1 };`

You're preparing some **data** to send to the first function, like an object with order info.

---

### 2️⃣ `placeOrder(orderDetails)`

This calls the function that starts your async process. It **returns a Promise**.

---

### 3️⃣ `.then(order => { return makePayment(order); })`

- This waits until the `placeOrder()` Promise is **resolved**.
    
- It receives the resolved result (e.g. `"Order123"`) as `order`.
    
- Then it calls `makePayment(order)` and **returns another Promise**.
    

This is chaining: when one finishes, the next starts.

---

### 4️⃣ `.then(paymentStatus => { return getOrderSummary(paymentStatus); })`

- Waits for `makePayment()` to finish.
    
- Receives `paymentStatus` (e.g. `"Payment Successful"`).
    
- Calls `getOrderSummary()` with that status.
    

---

### 5️⃣ `.then(summary => { return updateWallet(summary); })`

- Waits for `getOrderSummary()` to finish.
    
- Receives `summary` (e.g. `"Order Summary Generated"`).
    
- Calls `updateWallet()` and returns its Promise.
    

---

### 6️⃣ `.then(walletStatus => { console.log(...); })`

- Waits for `updateWallet()` to finish.
    
- Receives final result like `"Wallet updated successfully"`.
    
- Finally logs: ✅ _Order completed and wallet updated_.
    

---

### 7️⃣ `.catch(error => { console.error(...); })`

- If **any one** of the above Promises **fails** (gets rejected),
    
- this `catch()` block **immediately runs** and logs the error.
    
