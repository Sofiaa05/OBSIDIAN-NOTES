- **Signup / Create new** → return **201** from backend.
- **Login / Fetch / Update** → return **200**.


### **1xx – Informational**

|Code|Meaning|Use Case|
|---|---|---|
|**100**|Continue|Client should continue sending request body.|
|**101**|Switching Protocols|Server agrees to switch protocol (e.g., HTTP → WebSocket).|
|**102**|Processing|Server has accepted request but not finished processing.|

---

### **2xx – Success**

|Code|Meaning|Use Case|
|---|---|---|
|**200**|OK|Standard success response.|
|**201**|Created|Resource successfully created (e.g., POST).|
|**202**|Accepted|Request accepted but not yet processed.|
|**204**|No Content|Successful, but no content in response.|
|**206**|Partial Content|Used in range requests (e.g., file downloads).|

---

### **3xx – Redirection**

|Code|Meaning|Use Case|
|---|---|---|
|**301**|Moved Permanently|Resource has a new permanent URL.|
|**302**|Found (Moved Temporarily)|Temporary redirect.|
|**303**|See Other|Redirect after POST to GET URL.|
|**304**|Not Modified|Cached resource still valid.|
|**307**|Temporary Redirect|Same method is used on redirected request.|
|**308**|Permanent Redirect|Method & body preserved across redirect.|

---

### **4xx – Client Error**

| Code    | Meaning                | Use Case                        |
| ------- | ---------------------- | ------------------------------- |
| **400** | Bad Request            | Invalid request syntax.         |
| **401** | Unauthorized           | Missing/invalid authentication. |
| **403** | Forbidden              | Authenticated not authorised    |
| **404** | Not Found              | Resource doesn’t exist.         |
| **405** | Method Not Allowed     | HTTP method not supported.      |
| **408** | Request Timeout        | Client took too long to send.   |
| **409** | Conflict               | Conflict with server state.     |
| **410** | Gone                   | Resource permanently removed.   |
| **415** | Unsupported Media Type | Content type not supported.     |
| **429** | Too Many Requests      | Rate limiting in effect.        |

---

### **5xx – Server Error**

|Code|Meaning|Use Case|
|---|---|---|
|**500**|Internal Server Error|Generic server error.|
|**501**|Not Implemented|Functionality not supported.|
|**502**|Bad Gateway|Invalid response from upstream server.|
|**503**|Service Unavailable|Server overloaded/maintenance.|
|**504**|Gateway Timeout|Upstream server timed out.|
|**505**|HTTP Version Not Supported|HTTP version not supported.|
|**507**|Insufficient Storage|Server unable to store representation.|

---

💡 **Quick Interview Memory Hack:**

- **1xx** → “Info” (Handshake in progress)
    
- **2xx** → “Success”
    
- **3xx** → “Redirect”
    
- **4xx** → “You messed up” (Client)
    
- **5xx** → “Server messed up”
    
