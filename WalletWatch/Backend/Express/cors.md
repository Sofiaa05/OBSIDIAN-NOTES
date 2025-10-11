## Port
### 1. Imagine This:

Your **computer is like an apartment building**.

- It has **one address** (IP address), like `localhost` (which means "this computer").
    
- But inside the building, there are **many apartments** — like different **doors**.
    

Each door has a **number** → That’s the **port**.

So:

- The **computer** is the building
    
- The **port number** is the door
    

### 💬 Examples:

|Thing|Address|Meaning|
|---|---|---|
|Frontend app|`http://localhost:3000`|Door 3000 → where your React app runs|
|Backend API|`http://localhost:5000`|Door 5000 → where your Express server runs|

---

## ✅ 2. Why Does Frontend and Backend Use Different Ports?

Because they are **two separate services** running on the same computer.

- React dev server runs on port **3000**
    
- Express server runs on port **5000**
    

This way:

> You can keep **frontend and backend** separate but still run them together.

---

#### PROBLEM: **CORS Error**

The browser says:

> “Hey, you’re trying to talk to a different port than where you loaded the site from. That’s a **different origin** — is it safe?”

### 🤓 In Browser Terms:

|Part|Value|
|---|---|
|Protocol|`http`|
|Domain|`localhost`|
|Port|`3000` or `5000`|

Even if protocol and domain match, **port is different**, so:

> Browser blocks the request **unless** the backend **allows** it (via **CORS**).

---

## ✅ 3. How to Fix It?

```js
const cors = require('cors'); 
app.use(cors({ origin: 'http://localhost:3000' }));

```

This tells Express:

> “Yes, I allow requests from the frontend running on port 3000.”

🎯 That removes the error.

---

## 🔁 Real-World Analogy

Let’s say:

- You live in apartment building **localhost**
    
- You (frontend) are in **apartment 3000**
    
- Your friend (backend) is in **apartment 5000**
    

If the building has **security rules (browser CORS policy)**, you **can’t just walk into your friend’s room** without permission.

→ The backend needs to say:

> “Yes, she can come in from apartment 3000.”

That’s **CORS allowing a different port**.