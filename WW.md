

### 🔹 1. Explain your WalletWatch project in 60 seconds.

_(Prepare your elevator pitch)_

### 🔹 2. Why did you choose MERN stack for this project?

### 🔹 3. What problem does WalletWatch solve, and who is the target user?

### 🔹 4. What differentiates your project from existing expense trackers like Walnut / MoneyView?

---

# ⚙️ **SYSTEM DESIGN & ARCHITECTURE QUESTIONS**

### 🔹 5. Draw and explain the architecture of WalletWatch.

> React → Node.js → Express APIs → MongoDB → Services → JWT Auth → Email Service → Charts UI

### 🔹 6. How did you design your database schema in MongoDB?

Follow-ups:

- Why MongoDB instead of SQL?
    
- How did you store expenses per user?
    
- Explain your schema relationships.
    

### 🔹 7. How do you handle scalability when data grows?

(Expenses increase daily)

Ideas:

- Pagination
    
- Indexing MongoDB
    
- Archival strategy
    

### 🔹 8. What will you do if 1 million users start using WalletWatch?

---

# 🔐 **AUTHENTICATION / SECURITY QUESTIONS**

### 🔹 9. Why did you use JWT instead of sessions?

### 🔹 10. Where do you store JWT on the frontend, and why?

(localStorage, HTTP-only cookies → pros/cons)

### 🔹 11. Explain how JWT authentication works in WalletWatch.

Follow-Up:

- Token expiry?
    
- Refresh tokens?
    

### 🔹 12. What security measures did you take?

Examples:

✔ Bcrypt password hashing  
✔ CORS  
✔ Input validation  
✔ Avoid storing AI keys on frontend

---

# 📊 **FEATURE & MODULE QUESTIONS**

### Income/Expense Logging

### 🔹 13. How did you design the CRUD operations for income/expenses?

### 🔹 14. How do you calculate total spends and category-wise spending?

---

### Budget Module

### 🔹 15. Explain how monthly budget setting works.

### 🔹 16. How did you trigger alerts when a user crosses budget?

- Cron job?
    
- Event trigger?
    
- On-demand calculation?
    

---

### Email Alerts (Nodemailer)

### 🔹 17. How does your automated email alert system work?

Follow-up:

- How do you manage SMTP credentials safely?
    

---

### Chart Visualizations (Chart.js)

### 🔹 18. Why use Chart.js instead of D3 or Recharts?

### 🔹 19. How do you update charts when new data arrives?

---

### Excel Export (XLSX)

### 🔹 20. How did you implement the Excel export feature?

Follow-up:

- What format did you use?
    
- Any performance concerns?
    

---

### AI Spending Summary (OpenAI)

### 🔹 21. How does your AI spending summary work?

Follow-ups:

- How do you prompt the model?
    
- How do you avoid exposing API keys?
    
- Can AI hallucinate?
    

---

# 🧠 **FULL STACK & BEST PRACTICES QUESTIONS**

### Backend (Node.js / Express)

### 🔹 22. How did you structure your backend code?

(models / routes / controllers / services)

### 🔹 23. Explain middleware used in your app.

e.g., auth middleware for JWT

---

### Frontend (React)

### 🔹 24. How did you manage state?

Follow-up:  
Why not Redux/Zustand/React Query?

### 🔹 25. Explain your routing strategy.

---

### Database

### 🔹 26. How do you ensure MongoDB performance?

✔ Indexes  
✔ Pagination  
✔ Lean queries  
✔ Aggregation

---

# ⚡ **BEHAVIORAL & THINKING QUESTIONS**

### 🔹 27. What was the hardest part of this project?

Possible answers:

- JWT authentication flow
    
- AI integration
    
- Optimizing queries
    
- Correct category filtering logic
    

---

### 🔹 28. If you had 1 more month, what would you improve?

Examples:

- Push notifications
    
- Multi-currency support
    
- Real-time charts
    
- WebSockets
    

---

### 🔹 29. Which trade-offs did you make during development?

Example:

- Chose MongoDB over SQL for fast iteration
    
- Simple cron job instead of event-driven workflow
    

---

### 🔹 30. What did you learn from this project?

(Your transformation matters!)

---

# 🥇 BONUS — 5 QUESTIONS THAT CAN GET YOU SELECTED

1. How do you test your system? Unit tests? Postman?
    
2. What is the most complex bug you fixed?
    
3. Explain a performance optimization you implemented.
    
4. What happens if JWT is stolen?
    
5. How would you convert WalletWatch into a SaaS product?
    


---

