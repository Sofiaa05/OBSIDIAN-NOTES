

**Format per day:**

- **Backend** → Node.js + Express + MongoDB task
    
- **Frontend** → React component or UI task
    
- **Integration** → Combine backend & frontend
    

---

### **Day 1 — Basics**

- **Backend:** Create an Express server with one `/ping` route returning `"Server is running"`.
    
- **Frontend:** React app with one component showing `"Hello World"`.
    
- **Integration:** Call the `/ping` route from the React app using Axios and display the message.
    

---

### **Day 2 — Simple CRUD**

- **Backend:** Build `/api/users` route (GET, POST) with in-memory storage.
    
- **Frontend:** Create a form to add a new user (name, email) and a table to list users.
    
- **Integration:** Form submission → POST to backend → refresh list.
    

---

### **Day 3 — MongoDB Intro**

- **Backend:** Connect to MongoDB, create `users` collection, implement GET/POST.
    
- **Frontend:** Fetch and display users in a table.
    
- **Integration:** Store form data in MongoDB, then show updated list.
    

---

### **Day 4 — Authentication**

- **Backend:** Implement `/signup` & `/login` with password hashing (bcrypt).
    
- **Frontend:** Create signup/login forms with validation.
    
- **Integration:** Store JWT token in localStorage after login.
    

---

### **Day 5 — Protected Routes**

- **Backend:** Create `/profile` route, accessible only with valid JWT.
    
- **Frontend:** If user is logged in, show profile; otherwise redirect to login.
    
- **Integration:** Use Axios interceptor to send JWT token in headers.
    

---

### **Day 6 — File Upload**

- **Backend:** Implement profile picture upload with Multer.
    
- **Frontend:** Create a file input and preview before upload.
    
- **Integration:** Upload file to backend and display uploaded image.
    

---

### **Day 7 — Search & Filter**

- **Backend:** `/api/products` with name & category filters.
    
- **Frontend:** Search bar + category dropdown.
    
- **Integration:** Fetch filtered results from backend and display.
    

---

### **Day 8 — Pagination & Sorting**

- **Backend:** `/api/products` with pagination & sort by price.
    
- **Frontend:** Buttons for next/previous page and sorting controls.
    
- **Integration:** Keep results in sync with backend pagination.
    

---

### **Day 9 — Role-Based Access**

- **Backend:** Admin can delete users, normal users cannot.
    
- **Frontend:** Show delete button only for admins.
    
- **Integration:** Verify role on backend before deletion.
    

---

### **Day 10 — Mini Project Simulation**

- **Backend:** CRUD for “tasks” with authentication.
    
- **Frontend:** Login + Task List + Add Task + Delete Task.
    
- **Integration:** Full MERN mini project deployed locally.
    

---

## **How to Approach Each Task**

For each challenge:

1. **Write backend API first**
    
2. **Test with Postman**
    
3. **Integrate in React**
    
4. **Test end-to-end flow**
    
