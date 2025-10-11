```js
import {useState} from 'react';
import AuthLayout from '../../components/layouts/AuthLayout';
import { Link, useNavigate } from 'react-router-dom'; 
import Input from '../../components/Inputs/Input';
import { isValidEmail } from '../../utils/helper';
import '../../styles/SignUp.css';
import ProfilePhotoSelector from '../../components/Inputs/ProfilePhotoSelector';


const SignUp = () => {
  const [profilePic, setProfilePic] = useState(null);
  const [fullName, setFullName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState(null);
  
  const navigate = useNavigate();

  //handle sign up form submit
  const handleSignUp = async (e) => {
    e.preventDefault();

    let profileImageUrl = "";

    if (!fullName){
      setError("Please Enter your name");
      return;
    }

    if (!isValidEmail(email)){
      setError("Please enter a valid email address");
      return;
    }

    if (!password || password.length < 8) {
      setError('Password must be at least 8 characters long');
      return;
    }

    setError(""); //If all validations passed, clear any previous error.

    //signup Api call
  }
  return (
    <AuthLayout>
      <div className='signUp-container'>
        <h3 className='create'>Create an Account</h3>
        <p className='signup-para'>
          Join us today by entering your details below
        </p>

        <form onSubmit={handleSignUp}>

          <ProfilePhotoSelector image={profilePic} setImage={setProfilePic} />
          <div className='input-container'>
            <Input
              value= {fullName}
              onChange={({target}) => setFullName(target.value)} 
              label="Full Name"
              placeholder="John"
              type="text"
            />

            <Input
            value={email}
            onChange={({target}) => setEmail(target.value)}
            label="Email Address"
            placeholder="john@example.com"
            type="email"
          />

          <Input
            value={password}
            onChange={({target}) => setPassword(target.value)}
            label="Password"
            placeholder="Min 8 characters"
            type="password"
          />

          </div>


          {error && <p className="error-message">{error}</p>} //If error is not null, display the error in a paragraph.

          <button type="submit" className="signup-button">SignUp</button>

          <p className="signup-footer">
            Already have an account?{" "}
            <Link className="have-account" to="/login">
              Login
            </Link>
          </p>

        </form>
      </div>
    </AuthLayout>
  )
}

export default SignUp
```


### 1. **Imports (React hooks, components, utilities, styles)**

```js
import { useState } from 'react';
```

- You're importing the `useState` hook from React.
    
- **Why?** To manage _state_ (like form inputs) inside a functional component.
    

---

```js
import AuthLayout from '../../components/layouts/AuthLayout';
```

- You're importing a **layout wrapper component** that surrounds this SignUp page.
    
- Likely used for consistent layout (e.g. sidebar/image or styling common to Auth pages).
    

---

```js
import { Link, useNavigate } from 'react-router-dom';
```

- `Link`: Used to navigate between pages without reloading (like `<a>` but SPA-friendly).
    
- `useNavigate`: A hook to redirect programmatically (e.g., after successful signup → redirect to `/login` or `/dashboard`).
    

---

```js
import Input from '../../components/Inputs/Input';
```

- A **reusable Input component** you created.
    
- Used instead of raw `<input>` to avoid repeating styles and logic.
    

---

```js
import { isValidEmail } from '../../utils/helper';
```

- Importing a utility function that validates the email format.
    
- Helps keep logic **clean and reusable**.
    

---

```js
import '../../styles/SignUp.css';
```

- Custom CSS styles just for the SignUp page.
    

---

```js
import ProfilePhotoSelector from '../../components/Inputs/ProfilePhotoSelector';
```

- This is a custom component to **select/upload profile pictures**.
    
- Accepts 2 props:
    
    - `image`: Current image state
        
    - `setImage`: Function to update it
        

---

## 🎯 Functional Component: `SignUp`

```js
const SignUp = () => {
```

- You're declaring a **React functional component** named `SignUp`.
    

---

### 🌟 Form State Management (with `useState`)

```js
const [profilePic, setProfilePic] = useState(null);
const [fullName, setFullName] = useState("");
const [email, setEmail] = useState("");
const [password, setPassword] = useState("");
const [error, setError] = useState(null);
```

- `useState` declares variables to hold and update form values.
    
- Example:
    
    - `profilePic` = image uploaded
        
    - `fullName` = value typed into name field
        
    - `email` = email input
        
    - `password` = password input
        
    - `error` = error message to show user if something goes wrong
        

Each `useState` returns:

```js
[value, setValue]
```

---

### 🚀 Page Navigation

```js
const navigate = useNavigate();
```

- Hook from React Router to **navigate programmatically**.
    
- Example use case: `navigate("/login")` after signup success.
    

---

## 🧠 `handleSignUp` – What happens when the user submits the form?

```js
const handleSignUp = async (e) => {
  e.preventDefault();
```

- `e.preventDefault()` stops the default form submit behavior (page refresh).
    
- You take full control of what happens on form submission.
    

---

### 🖼 Profile Image (Optional)

```js
let profileImageUrl = "";
```

- Placeholder for storing uploaded profile image's URL.
    
- You'll implement image upload logic later (e.g. to backend or cloud).
    

---

### ✅ Form Validations

```js
if (!fullName) {
  setError("Please Enter your name");
  return;
}
```

- Checks if the name field is empty.
    
- If yes, sets an error message and **exits the function**.
    

---

```js
if (!isValidEmail(email)) {
  setError("Please enter a valid email address");
  return;
}
```

- Calls the imported `isValidEmail` function to check email format.
    
- If invalid, shows error and exits.
    

---

```js
if (!password || password.length < 8) {
  setError("Password must be at least 8 characters long");
  return;
}
```

- Checks if password exists and is at least 8 characters.
    
- Returns early if not valid.
    

---

```js
setError("");
```

- If all validations passed, clear any previous error.
    

---

```js
//signup Api call
```

- Placeholder comment where you'll add the Axios call to backend later.
    

---

## 🧾 JSX (UI Markup)

```jsx
<AuthLayout>
```

- Wraps your page inside `AuthLayout` (probably adds background layout or structure)
    

---

### 🔲 Form Header

```jsx
<h3 className='create'>Create an Account</h3>
<p className='signup-para'>
  Join us today by entering your details below
</p>
```

- User-friendly heading and message at the top of the form.
    

---

### 🖼 Profile Image Upload

```jsx
<ProfilePhotoSelector image={profilePic} setImage={setProfilePic} />
```

- Component to choose and preview profile image.
    
- Controlled by the `profilePic` state.
    

---

### 🔤 Inputs (Name, Email, Password)

```jsx
<Input
  value={fullName}
  onChange={({target}) => setFullName(target.value)}
  label="Full Name"
  placeholder="John"
  type="text"
/>
```

- Reusable `Input` component.
    
- `value` → the current state
    
- `onChange` → updates the state as user types
    
- `label`, `placeholder`, `type` → customize the input field
    

Same format is used for email and password.

---

### ⚠️ Error Display

```js
{error && <p className="error-message">{error}</p>}
```

- If `error` is not `null`, display the error in a paragraph.
    
- Helps user understand what went wrong.
    

---

### 🟢 Submit Button

```js
<button type="submit" className="signup-button">SignUp</button>
```

- When clicked, triggers `handleSignUp`.
    

---

### 🔁 Link to Login Page

```jsx
<p className="signup-footer">
  Already have an account?{" "}
  <Link className="have-account" to="/login">
    Login
  </Link>
</p>
```

- Provides navigation to `/login` page.
    
- Uses `<Link>` from React Router to avoid full page reload.
    

---

## ✅ Final Thoughts (Interview-Ready Summary)

If asked in interview:

> **What is this code doing?**

You can say:

> "This is a signup page built with React. It uses functional components and hooks like `useState` to manage form data. It includes validation logic for name, email, and password. Errors are handled gracefully with `setError`. There's a custom `Input` component and a profile image selector for better UX. When the form is submitted, it first validates inputs, then prepares for an API call. React Router's `useNavigate` helps redirect after successful signup."

---
Q: Why do we initialize some state as `""` and some as `null`?

- It depends on what type of data the state holds. Input fields are always initialized with empty strings (`""`) because React expects the input value to be a string. For file uploads or optional objects like profile pictures, `null` is used to represent 'nothing selected yet'. For error handling, `null` makes it easy to conditionally render error messages only when there is one.
---
```js
const [error, setError] = useState(null);
```

| Part       | What It Is                                                |
| ---------- | --------------------------------------------------------- |
| `error`    | A **state variable** that holds the current error message |
| `setError` | A **function** to update `error`                          |

Initially:

```js
error === null
```

Later:

```js
setError("Please enter a valid email.");
// Now error === "Please enter a valid email."
```

---

## 🧪 In JavaScript, non-empty strings are "truthy"

|Value|Boolean Equivalent|
|---|---|
|`null`|❌ false (falsy)|
|`""` (empty str)|❌ false (falsy)|
|`"something"`|✅ true (truthy)|

So when you write:

```js
if (error) {
  // This runs only if error is NOT null or ""
}
```

And in JSX:

```js
{error && <p>{error}</p>}
```

That means:

> "If `error` is a truthy value (non-null, non-empty), show this `<p>` tag."

---


> **Q: What are `error` and `setError` in React state?**

> "`error` is a piece of state that stores the current error message. It's usually initialized as `null`, and updated with a string using `setError`. In JSX, we can use `error && <p>{error}</p>` because JavaScript treats non-empty strings as 'truthy', so this renders the error message only when it exists."

---

```js
onChange={({ target }) => setFullName(target.value)}
```

Here’s the full version of what you're doing:
```js
onChange={(event) => {
  const target = event.target;
  const value = target.value;
  setFullName(value);
}}
```

| Part               | Meaning                                                              |
| ------------------ | -------------------------------------------------------------------- |
| `onChange`         | This is the prop that listens for changes in the input field         |
| `(event) => ...`   | The function that runs when the change happens                       |
| `{ target }`       | This is **object destructuring** → it extracts `target` from `event` |
| `target.value`     | This gives the current value typed in the input                      |
| `setFullName(...)` | This updates the React state with the new value                      |
It's a React onChange handler that uses object destructuring to extract `target` from the event object. It then takes `target.value`, which is the latest input, and updates the `fullName` state."