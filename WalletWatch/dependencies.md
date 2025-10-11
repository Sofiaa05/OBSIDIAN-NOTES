

### ✅ Installed Packages and Their Purpose:

1. `react-icons`
    
    - 🔧 **Purpose:** Provides a collection of popular icons from libraries like Font Awesome, Material Design, etc., as React components.
        
    - 📦 Example:
        
        ```js
        import { FaUser } from 'react-icons/fa';
        <FaUser />
        ```
        
2. `axios`
    
    - 🔧 **Purpose:** HTTP client for making API requests (GET, POST, PUT, DELETE).
        
    - 🚀 Better than `fetch` because of built-in features like interceptors, automatic JSON conversion, and better error handling.
        
    - 📦 Example:
        
        ```js
        axios.get('/api/user').then(res => console.log(res.data));
        ```
        
3. `moment`
    
    - 🔧 **Purpose:** Library for formatting, parsing, and manipulating dates and times.
        
    - 📦 Example:
        
        ```js
        moment().format('MMMM Do YYYY, h:mm:ss a');
        ```
        
4.  `emoji-picker-react`
    
    - 🔧 **Purpose:** A React emoji picker component (like you see in chat apps).
        
    - 📦 Example:
        
        ```js
        <EmojiPicker onEmojiClick={(emoji) => console.log(emoji)} />
        ```
        
5. `react-router-dom`
    
    - 🔧 **Purpose:** For client-side routing in React apps — enables navigating between pages (like `/home`, `/profile`) without reloading the browser.
        
    - 📦 Example:
        
        ```js
        <BrowserRouter>
          <Routes>
            <Route path="/home" element={<Home />} />
          </Routes>
        </BrowserRouter>
        ```
        
6. `recharts`
    
    - 🔧 **Purpose:** Charting library built with React — lets you create beautiful charts like bar charts, pie charts, line charts, etc.
        
    - 📦 Example:
        
        ```js
        <LineChart data={data}><Line type="monotone" dataKey="uv" /></LineChart>
        ```
        
7. `react-hot-toast`
    
    - 🔧 **Purpose:** Lightweight, customizable toast notifications.
        
    - 🚀 Great for showing quick messages like "Login Successful", "Error occurred", etc.
        
    - 📦 Example:
        
        ```js
        toast.success("Logged in!");
        ```
        
