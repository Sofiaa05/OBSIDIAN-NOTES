OSI - open source interconnection
ISO - International Organisation for Standardization
7 layers in OSI model : Physical, Data Link Layer, Network, Transport, Session, Presentation, Applicaton



---

### Basic Networking Commands (Windows & Linux/Unix)

### 1. **Check IP Configuration**

- **Windows:**
    
    ```
    ipconfig
    ```
    
    → Shows IP address, subnet mask, gateway, DNS.
    
- **Linux/Unix/Mac:**
    
    ```
    ifconfig
    ip addr show
    ```
    
    → Displays IP, MAC, and interface details.
    

---

### 2. **Check Connectivity**

- **Ping** (send test packets to another host):
    
    ```
    ping google.com
    ```
    
    → Tests if you can reach Google’s server.
    

---

### 3. **Trace Route**

- **Windows:**
    
    ```
    tracert google.com
    ```
    
- **Linux/Unix/Mac:**
    
    ```
    traceroute google.com
    ```
    
    → Shows the path packets take (routers/hops) to reach destination.
    

---

### 4. **DNS Lookup**

- **nslookup** (Windows/Linux):
    
    ```
    nslookup google.com
    ```
    
    → Shows domain → IP address mapping.
    
- **dig** (Linux/Mac):
    
    ```
    dig google.com
    ```
    
    → More detailed DNS records.
    

---

### 5. **Check Open Connections**

- **Windows/Linux:**
    
    ```
    netstat
    ```
    
    → Shows active connections, listening ports, routing tables.
    
- Example (Linux):
    
    ```
    netstat -tulnp
    ```
    
    → Shows TCP/UDP ports in use.
    

---

### 6. **Check Route Table**

- **Windows:**
    
    ```
    route print
    ```
    
- **Linux:**
    
    ```
    route -n
    ip route show
    ```
    
    → Displays routing information.
    

---

### 7. **Test Remote Login / File Transfer**

- **SSH (Linux/Mac/Windows with SSH client):**
    
    ```
    ssh user@hostname
    ```
    
    → Remote login to another machine securely.
    
- **Telnet (older, insecure):**
    
    ```
    telnet hostname port
    ```
    
    → Test connectivity to a specific port.
    

---

### 8. **Download from Web**

- **curl (Linux/Mac/Windows):**
    
    ```
    curl http://example.com
    ```
    
    → Fetches content from a URL.
    
- **wget (Linux):**
    
    ```
    wget http://example.com/file.zip
    ```
    
    → Downloads files from the web.
    

---

### 9. **Check ARP Table**

- **Windows:**
    
    ```
    arp -a
    ```
    
- **Linux:**
    
    ```
    arp -n
    ```
    
    → Shows IP-to-MAC address mapping.
    

---

### 10. **Check Who is Online in Network**

- **Linux:**
    
    ```
    who
    ```
    
    → Shows logged-in users.
    
- **Windows:**
    
    ```
    net view
    ```
    
    → Shows computers in local network.
    

---

## 📌 Quick Summary of Most Important Commands

- `ipconfig` / `ifconfig` → Check IP
    
- `ping` → Test connectivity
    
- `tracert` / `traceroute` → Trace path
    
- `nslookup` / `dig` → DNS check
    
- `netstat` → Active connections & ports
    
- `route` → Routing table
    
- `ssh` → Secure remote login
    
- `curl` / `wget` → Get web content
    
- `arp` → Check MAC ↔ IP mapping
    

---

