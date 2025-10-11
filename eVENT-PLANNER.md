```JS
            {/* User */}
            <Route path="/events" element={<EventList />} />              {/* List all events */}
            <Route path="/events/:id" element={<EventDetails />} />      {/* Event details + RSVP */}
            <Route path="/getRsvp" element={<Rsvp />} />            {/* User’s RSVPs */}

            {/* Admin */}
           
            <Route path="/admin/events/create" element={<CreateEvent />} />
            <Route path="/admin/events/edit/:id" element={<EditEvent />} />
            

            {/* Fallback */}
            <Route path="*" element={<NotFound />} />

```


## **Next Steps for Frontend**

### **1️⃣ Setup Axios / API calls**

- Install Axios:
    

`npm install axios`

- Create a folder: `src/api/`
    
- Create a file: `api.js`
    
    - Configure a base URL for your backend (e.g., `http://localhost:5000/api`)
        
    - Export axios instance for all components to use.
        

---

### **2️⃣ Implement Authentication**

- Pages: `Login.jsx` and `Register.jsx`
    
- Steps:
    
    1. Create forms with inputs (name, email, password, etc.)
        
    2. Connect form to backend via Axios POST `/api/auth/register` and `/api/auth/login`
        
    3. Save JWT token in `localStorage` on successful login
        
    4. Redirect based on role:
        
        - Admin → `/admin/events`
            
        - User → `/getEvents`
            

---

### **3️⃣ Create ProtectedRoute**

- Protect user/admin pages so only logged-in users can access
    
- Optional: check role for admin-only pages
    
- This ensures frontend role-based access control
    

---

### **4️⃣ Build Event Pages**

**User pages:**

- `/getEvents` → list of upcoming events
    
    - Use `EventCard.jsx` component for each event
        
    - Include RSVP buttons (`RSVPButtons.jsx`)
        
- `/getEventDetails/:id` → show full event details + RSVP status
    
- `/getRsvp` → show a list of events the user has RSVP’d to
    

**Admin pages:**

- `/admin/events` → list all events with Edit/Delete buttons
    
- `/admin/events/create` → form to add event
    
- `/admin/events/edit/:id` → form to edit event details
    
- `/api/event/summary/:eventId` → show RSVP summary for each event
    

---

### **5️⃣ Implement RSVP Functionality**

- `RSVPButtons.jsx` component for “Going / Maybe / Decline”
    
- Call backend endpoints:
    
    - POST `/api/rsvps/submit` → submit RSVP
        
    - PUT `/api/rsvps/update/:id` → update RSVP
        
- Update UI after submission
    

---

### **6️⃣ UI / Styling**

- Use plain CSS for:
    
    - Navbar, Event cards, Forms
        
- Make sure mobile responsive (flex/grid, media queries)
    

---

### **7️⃣ Testing**

- Test all flows:
    
    1. Register/Login
        
    2. Admin: Create/Update/Delete events
        
    3. User: View events, RSVP, update RSVP
        
    4. Admin: View RSVP summary
        
- Optional: write 3 basic unit tests or component tests
    

---

### **8️⃣ Connect Frontend → Backend**

- Use `axios` calls with `Authorization: Bearer <token>` headers
    
- Ensure all protected routes work with JWT
    

---

### **9️⃣ Final Steps**

- Clean up code, comments, folder structure
    
- Push to GitHub with meaningful commits
    
- Optional: CI with GitHub Actions
```js
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Events</title>
</head>
<body>
  <h1>All Events</h1>
  <div id="events"></div>

  <script>
    const token = localStorage.getItem("token");

    if (!token) {
      alert("Please log in first!");
      window.location.href = "index.html";
    }

    async function fetchEvents() {
      const res = await fetch("http://localhost:5001/api/events", {
        headers: { Authorization: `Bearer ${token}` },
      });
      const events = await res.json();

      const container = document.getElementById("events");
      container.innerHTML = "";

      events.forEach(event => {
        const eventDiv = document.createElement("div");
        eventDiv.innerHTML = `
          <h3>${event.title}</h3>
          <p>${event.description}</p>
          <p>Date: ${new Date(event.date).toLocaleDateString()}</p>
          <p>Time: ${event.time}</p>
          <p>Location: ${event.location}</p>
          <p>Your Status: ${event.status}</p>

          <!-- RSVP buttons fixed to match backend enums -->
          <button onclick="submitRsvp('${event._id}', 'Going')">Going</button>
          <button onclick="submitRsvp('${event._id}', 'Maybe')">Maybe</button>
          <button onclick="submitRsvp('${event._id}', 'Decline')">Decline</button>
        `;
        container.appendChild(eventDiv);
      });
    }

    async function submitRsvp(eventId, status) {
      const res = await fetch("http://localhost:5001/api/rsvp", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
          Authorization: `Bearer ${token}`,
        },
        body: JSON.stringify({ eventId: eventId, status }), // Status now matches backend
      });

      const data = await res.json();
      alert(data.message || "RSVP submitted");
      fetchEvents();
    }

    fetchEvents();
  </script>
</body>
</html>

```