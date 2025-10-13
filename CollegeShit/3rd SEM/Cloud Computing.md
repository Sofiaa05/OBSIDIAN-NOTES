
## UNIT 1:
### Introduction:
- technology which lets you **store and access computing resources over internet** instead of using your computer's hard drive or local server.
	- ###### computing resources: 
		- data storage, networking tools, virtual servers, software, development tools etc.
- term cloud in cloud computing refers to **network or internet.**
- offers platform independency
--- 
### Evolution:
Cloud Computing has evolved from the Distributed system to the current technology.
##### Distributed Systems: 
- independent systems which are physically located in various places but are connected through the network.
	- resource sharing, open to all, fault detection
	- main disadvantage is that all the plan has to be in the same location
##### Mainframe Computing:
- Among the four types of computers, mainframe computer performs very fast and lengthy computations easily.
- Mainframe computing due to its ability to **deal with a large amount of data**
##### Cluster Computing:
- computers are connected to make it a single computing
- each task is performed concurrently by each computer connected to the network
- activities performed by one is knwon to all. hence increased performace, transparency and speed.
##### Grid Computing:
- different nodes are placed in different geographical places but are connected to the same network using the internet.
##### Web 2.0
-  lets the users generate their content and collaborate with other people or share the information using social media
##### Virtualization:
- creates a software layer over the hardware and using this it provides the customer with cloud-based services.
##### Utility Computing:
- provides services based on pay-per-use model.

---
### Characteristics

##### **1. On-demand self-service**

You can use cloud resources (like storage, servers, or apps) **whenever you need**, without waiting for someone to provide them.  
Example:_ You can instantly create a virtual server in AWS without contacting an admin.

---

##### **2. Broad network access**

Cloud services are **accessible from anywhere** using the internet and any device — computer, phone, or tablet.  
Example:_ You can access Google Drive from your laptop or mobile.

---

##### **3. Resource pooling**

Cloud providers share their physical resources (servers, storage, networks) among many users using a **multi-tenant model**.  
Example:_ Multiple users share the same physical server, but securely separated.

---

##### **4. Measured service (Pay-as-you-go)**

You pay **only for what you use**, like electricity or mobile data.  
Example:_ If you use 50GB of cloud storage, you pay only for 50GB.

---

##### 5. Scalability

Cloud systems can **easily scale up or down** — add more storage, users, or computing power when needed.

---

##### 6. Security and reliability

Most cloud providers offer **data encryption, backup, and redundancy** to protect user data and ensure uptime.

---

### Issues and challenges

##### 1. Security and Privacy

- Data is stored on cloud servers owned by third parties.
    
- There’s always a **risk of data theft, hacking, or unauthorized access**.
    
- **Example:** Sensitive business or user data being leaked.
    

---

##### **2. Data Loss and Recovery**

- If cloud servers crash or get attacked, there’s a risk of **permanent data loss**.
    
- Backup and recovery may take time or fail if not managed properly.
    

---

##### 3. Internet Dependency

- Cloud computing **depends on internet connection**.
    
- If internet speed is low or connection fails — services stop working.
    

---
##### **4. Limited Control**

- Cloud infrastructure is managed by providers, not users.
    
- You have **less control over configuration, updates, and maintenance**.
    

---

##### **5. Performance Issues**

- When too many users access cloud resources at once, **network latency** (slowness) can occur.
    
---

##### 6. Integration Problems

- Integrating cloud systems with existing local systems can be **complex**.
    
---
### Applications of Cloud Computing

##### **1. Data Storage and Backup**

- Cloud provides **online storage** to save files, photos, and videos.
    
- Example: **Google Drive, Dropbox, OneDrive**
    
- Benefit: Access data **anytime, anywhere**.
    

---

##### **2. Software as a Service (SaaS)**

- Applications run directly on the cloud — no need to install.
    
- Example: **Gmail, Microsoft 365, Zoom**
    
- Benefit: Easy updates and accessibility.
    

---

##### **3. Cloud Hosting / Web Hosting**

- Websites and apps are hosted on cloud servers.
    
- Example: **AWS, Google Cloud, Azure**
    
- Benefit: **Scalable** — handles high traffic smoothly.
    

---

##### **4. Big Data Analytics**

- Cloud helps process and analyze **large amounts of data** quickly.
    
- Example: **Amazon EMR, Google BigQuery**
    
- Benefit: Supports **decision-making and AI models**.
    

---

##### 5. Machine Learning & Artificial Intelligence

- Cloud provides **ready-made ML/AI services** without needing your own hardware.
    
- Example: **AWS SageMaker, Google AI Platform**
    
- Benefit: Easy to **train and deploy ML models**.
    

---

##### **6. Gaming and Entertainment**

- Cloud enables **online gaming** and **media streaming**.
    
- Example: **Netflix, Xbox Cloud, Google Stadia**
    
- Benefit: No need for powerful local devices.
    

---

##### 7. Education and E-learning

- Online learning platforms and virtual labs use cloud services.
    
- Example: **Google Classroom, Coursera**
    
- Benefit: Enables **remote and interactive learning**.
    

---

### Cloud Computing Models


| **Feature**                     | **IaaS (Infrastructure as a Service)**                                       | **PaaS (Platform as a Service)**                                           | **SaaS (Software as a Service)**                  |
| ------------------------------- | ---------------------------------------------------------------------------- | -------------------------------------------------------------------------- | ------------------------------------------------- |
| **Full Form**                   | Infrastructure as a Service                                                  | Platform as a Service                                                      | Software as a Service                             |
| **Purpose**                     | Provides virtualized computing resources like servers, storage, and networks | Provides a platform for developers to build, test, and deploy applications | Provides ready-to-use software over the internet  |
| **Main Users**                  | System Administrators, IT Managers                                           | Developers, Programmers                                                    | End Users, Business Users                         |
| **What You Manage**             | Applications, Data, Runtime, Middleware, and OS                              | Applications and Data                                                      | Nothing (only use the application)                |
| **What Cloud Provider Manages** | Virtualization, Servers, Storage, Networking                                 | Runtime, Middleware, OS, Virtualization, Servers, Storage, Networking      | Everything (Infrastructure, Platform, Software)   |
| **Control Level**               | Maximum control over infrastructure                                          | Moderate control                                                           | Minimum control                                   |
| **Scalability**                 | Highly scalable; add/remove resources easily                                 | Scalable as per development needs                                          | Automatically scalable                            |
| **Setup Complexity**            | Complex; requires technical knowledge                                        | Easier than IaaS                                                           | Easiest; just sign up and use                     |
| **Customization**               | Highly customizable                                                          | Moderate customization                                                     | Very limited customization                        |
| **Examples**                    | AWS EC2, Google Compute Engine, Microsoft Azure VM                           | Google App Engine, AWS Elastic Beanstalk, Heroku                           | Gmail, Salesforce, Microsoft 365, Zoom            |
| **Used For**                    | Hosting websites, storage, creating virtual servers                          | Application development, testing, deployment                               | Communication, CRM, Office tools, collaboration   |
| **Advantage**                   | High flexibility and control                                                 | Faster app development, no server management                               | No installation or maintenance, easily accessible |
| **Disadvantage**                | Requires technical expertise                                                 | Limited control over infrastructure                                        | Less customization, data dependency on provider   |
| **Example Scenario**            | A company renting virtual machines to host their servers                     | A developer deploying an app using a managed runtime                       | A user accessing Gmail to send emails             |

---
### Cloud Architecture

- Cloud architecture is the **structure and components** that make up a cloud computing system.  
- It defines **how cloud resources (like servers, storage, and applications)** are organized and work together to deliver services over the internet.

##### **Main Components of Cloud Architecture**

| **Layer / Component**              | **Description**                                                                                      | **Examples / Function**                                                   |
| ---------------------------------- | ---------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- |
| **1. Front-End**                   | It is the **client side** — what the user interacts with.                                            | Web browsers, mobile apps, or thin clients that access cloud services.    |
| **2. Back-End**                    | The **server side** — where data is processed and stored. It includes all the core cloud components. | Databases, application servers, virtual machines, storage systems.        |
| **3. Cloud Storage**               | Stores all data, files, and backups used by applications.                                            | AWS S3, Google Cloud Storage, Azure Blob Storage.                         |
| **4. Cloud Infrastructure**        | The **hardware and software** resources that form the foundation of the cloud.                       | Servers, networking, virtualization layer, storage devices.               |
| **5. Cloud Service Models**        | Defines **how services are provided** to users.                                                      | IaaS, PaaS, SaaS.                                                         |
| **6. Cloud Delivery Model**        | Defines **how the cloud is deployed** to users.                                                      | Public Cloud, Private Cloud, Hybrid Cloud, Community Cloud.               |
| **7. Cloud Management & Security** | Handles **resource allocation, monitoring, and data protection**.                                    | Authentication, encryption, load balancing, and service monitoring tools. |

---

##### **How It Works (Simplified Flow):**

1. User accesses cloud services via **front-end interface** (browser/app).
    
2. Request is sent to the **cloud platform** over the internet.
    
3. **Back-end servers** process the request using storage, databases, and applications.
    
4. Processed output is sent back to the user in real time.
    
![[Pasted image 20251012135651.png]]

---

### Deployment of Models

- Cloud deployment models define **how the cloud infrastructure is set up, managed, and accessed** by users or organizations.

- There are **four main deployment models**:

	1. **Public Cloud**
	    
	2. **Private Cloud**
	    
	3. **Community Cloud**
	    
	4. **Hybrid Cloud**
    

---

##### **1. Public Cloud**

- Cloud resources are **owned and managed by third-party providers**.
    
- Available to **everyone over the internet**.
    
- Users share the **same hardware, storage, and network.**
    

**Example:** AWS, Microsoft Azure, Google Cloud, IBM Cloud

**Used by:** Startups, small businesses, or anyone who needs low-cost scalability.

**Advantages:**

- Cost-effective (pay-as-you-go)
    
- Highly scalable and reliable
    
- No maintenance needed
    

**Disadvantages:**

- Less security control
    
- Shared resources
    

---

##### **2. Private Cloud**

- Cloud infrastructure is **used by a single organization**.
    
- Managed either **internally** or by a **third party** but hosted privately.
    

**Example:** VMware, OpenStack, AWS Outposts

**Used by:** Banks, government, and large enterprises needing strict security.

**Advantages:**

- High security and control
    
- Customizable to organizational needs
    

**Disadvantages:**

- Expensive
    
- Requires internal management expertise
    

---

##### **3. Community Cloud**

- Shared between **organizations with similar interests or requirements**.
    
- Managed by one or more of the organizations or a third party.
    

**Example:** Cloud for universities, healthcare groups, or research organizations

**Used by:** Groups that share goals like compliance, security, or policy needs.

**Advantages:**

- Shared cost among community members
    
- Better security than public cloud
    

**Disadvantages:**

- Limited scalability
    
- Cost higher than public cloud
    

---

##### **4. Hybrid Cloud**

- **Combination of public and private clouds.**
    
- Data and applications can move between them as needed.
    

**Example:** A company uses a private cloud for sensitive data and public cloud for backups.

**Used by:** Businesses needing flexibility between security and cost.

**Advantages:**

- High flexibility
    
- Better data deployment and security balance
    

**Disadvantages:**

- Complex setup and management
    
- Data transfer security risks
    
###### **Comparison Table of Cloud Deployment Models**

|**Feature**|**Public Cloud**|**Private Cloud**|**Community Cloud**|**Hybrid Cloud**|
|---|---|---|---|---|
|**Ownership**|Third-party providers|Single organization|Group of organizations|Combination of public & private|
|**Accessibility**|Open to public via internet|Restricted to one organization|Restricted to a specific group|Controlled by organization|
|**Cost**|Low|High|Shared|Moderate|
|**Security**|Low|Very High|Medium-High|High|
|**Scalability**|Very High|Limited|Medium|High|
|**Maintenance**|Done by provider|Done by organization|Shared|Shared between both|
|**Data Control**|Low|Full|Partial|Partial|
|**Best Suited For**|Startups, general users|Enterprises, government|Research groups, communities|Organizations needing both security & scalability|
|**Examples**|AWS, Azure, GCP|VMware, OpenStack|Healthcare or educational clouds|AWS Outposts, Azure Stack|

---
### **IDaaS (Identity as a Service)**

- Identity as a Service (IDaaS) is a **cloud-based authentication and identity management solution** that enables organizations to manage and secure user identities centrally. 
- It provides **Single Sign-On (SSO)**, **Multi-Factor Authentication (MFA)**, **user provisioning**, and **access control** for cloud and on-premises applications.

---

##### Key Features of IDaaS

| **Feature**                             | **Description**                                                                                           |
| --------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| **Single Sign-On (SSO)**                | Users can access multiple applications using one set of login credentials.                                |
| **Multi-Factor Authentication (MFA)**   | Adds an extra layer of security by requiring two or more verification factors.                            |
| **User Provisioning & De-provisioning** | Automatically creates, updates, and removes user accounts across systems.                                 |
| **Access Management**                   | Controls which users can access which resources based on roles and policies.                              |
| **Password Management**                 | Offers password reset and synchronization capabilities.                                                   |
| **Analytics & Reporting**               | Monitors user activities and detects potential security threats.                                          |

---

##### **Benefits of IDaaS**

|**Benefit**|**Description**|
|---|---|
|**Enhanced Security**|Centralized identity control reduces password leaks and unauthorized access.|
|**Cost Efficiency**|Eliminates need for on-premises identity infrastructure.|
|**Scalability**|Easily scales with organization size and user growth.|
|**Improved User Experience**|SSO provides seamless access to multiple apps.|
|**Compliance**|Helps meet security regulations like GDPR, HIPAA, etc.|
|**Faster Deployment**|Cloud-based model allows quick setup and integration.|

---

## UNIT 2:
### Virtualisation
- creation of a virtual version of a physical resource - such as operating system, server, storage device or network using a **hypervisor** or **virtual machine monitor (VMM)**

#### Key Concepts:
| **Term**                 | **Description**                                                                                           |
| ------------------------ | --------------------------------------------------------------------------------------------------------- |
| **Host Machine**         | The physical system on which virtualized software (hypervisor) runs.                                      |
| **Guest Machine**        | The virtual machines (VMs) created on the host.                                                           |
| **Hypervisor**           | Technology / software layer that is used to create virtualized environment.                               |
| **Virtual Machine (VM)** | A copy of a computer system running its own OS and applications borrowed from the host machine virtually. |

#### Hypervisor:
- software that lets run multiple OS run on a single physical machine.
- Manages hardware resources (CPU, memory, storage) and allocates them to virutal machine.
##### Types of hypervisors
###### Type-1 (Bare-Metal Hypervisor):
- runs directly on host's hardware
- Doesn't rely on host's OS
- better performance and security as there is no intermediary OS
-  **Example:** XenServer, Microsoft Hyper-V
###### Type-2 (Hosted Hypervisor):
- runs on top of host OS
- generally used for desktop virtualization, development, and testing environments where a user needs to run multiple OSs on their personal computer.
- performance lower than type-1 due to OS overhead
- **Example:** Oracle VirtualBox, VMware workstation
#### Implementation of Virtualization
| **Step**                             | **Description**                                                                       |
| ------------------------------------ | ------------------------------------------------------------------------------------- |
| **1. Hardware Setup**                | Prepare a physical server with sufficient CPU, RAM, and storage.                      |
| **2. Install Hypervisor**            | Install Type 1 or Type 2 hypervisor depending on requirements.                        |
| **3. Create Virtual Machines (VMs)** | Define VM configurations (CPU cores, memory, disk size, network).                     |
| **4. Install Guest OS**              | Install operating systems on each VM (Windows, Linux, etc.).                          |
| **5. Resource Allocation**           | Allocate CPU, memory, and network resources to each VM.                               |
| **6. Configure Networking**          | Set up virtual switches, IP configurations, and NAT/bridged networks.                 |
| **7. Storage Integration**           | Use virtual disks or connect shared storage (SAN/NAS).                                |
| **8. Install Management Tools**      | Use VM management platforms like **vCenter**, **Hyper-V Manager**, or **Proxmox VE**. |
| **9. Security & Backup**             | Implement isolation, snapshots, and backup systems.                                   |
| **10. Monitoring & Optimization**    | Monitor resource usage and adjust allocations for performance.                        |
#### Applications of Virtualization:
| **Area**                              | **Application / Example**                                                                                                         |
| ------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| **1. Cloud Computing**                | Virtualization is the **foundation of cloud** — allows creating virtual servers and storage on demand (e.g., AWS EC2, Azure VMs). |
| **2. Server Consolidation**           | Multiple servers are combined into fewer physical servers using VMs, reducing cost and power usage.                               |
| **3. Software Testing & Development** | Developers use virtual machines to test applications on different operating systems without needing multiple computers.           |
| **4. Disaster Recovery**              | VM snapshots and backups make it easy to restore systems after a failure.                                                         |
| **5. Data Centers**                   | Virtualization helps data centers run efficiently, using less hardware.                                                           |
| **6. Education & Training**           | Students and IT trainees use virtual labs for learning different OS and networking setups.                                        |

#### Middleware support in Virtualization:
- Middleware is **software that acts as a bridge** between applications, operating systems, and hardware.  
- It helps **virtual machines (VMs)** and **applications** communicate efficiently in a virtualized environment.
- Middleware = “Helper software” that makes virtualization smoother and more efficient.
- Middleware provides these **management, communication, and integration capabilities** effectively.
##### Functions of Middleware:
|**Function**|**Explanation**|
|---|---|
|**Resource Management**|Manages CPU, memory, and storage distribution among VMs.|
|**Communication**|Enables data exchange between virtual machines and the host system.|
|**Interoperability**|Allows applications running on different virtual systems to work together.|
|**Security**|Handles authentication, authorization, and secure data transfer between VMs.|
|**Monitoring**|Tracks the performance of virtual machines and network traffic.|
|**Load Balancing**|Distributes workload across multiple virtual machines for efficiency.|

---
#### Types of Virtualisation


![Types of Virtualization](https://media.geeksforgeeks.org/wp-content/uploads/20230324174741/Types-of-Virtualizaton.png)

##### 1. Application Virtualization: 
- You can **use an app** without installing it on your own computer.
- The app runs in a **virtual environment**.
- Enables remote access by which users can directly interact with deployed applications without installing them on their local machine. 
- **Example:** Using MS Word through a browser or App-V.
- No installation problems, saves space.

##### 2. Network Virtualization: 
- This allows multiple virtual networks to run on the same physical network, each operating independently. 
- Creates **virtual networks** inside a single physical network.
- Helps manage and secure data better. It saves time, money, and gives more flexibility.
- You can quickly set up virtual switches, routers, firewalls, and VPNs, making network management more flexible and efficient.
- **Example:** VLAN (Virtual LAN), VPN (Virtual Private Network).

##### 3. Desktop Virtualization: 
- You can **access your desktop** (computer screen, files, apps) **from anywhere** using the internet.
- The actual computer runs on a **remote server**.
- **Example:** Using **Remote Desktop** or **VMware Horizon**.
- **Use:** Work from home or any device easily.
##### 4. Storage Virtualization: 
- Combines **multiple physical storage devices** (like hard drives, SSDs) into a **single virtual storage unit**. 
- A software layer (called **storage virtualization software**) manages all storage devices and presents them as one logical unit to users or applications.
- Makes data management and backup easier.
- **Example:** Amazon S3 is an example of storage virtualization because in S3 we can easily store any amount of data from anywhere, Google Drive, RAID (combining multiple disks into one).

##### 5. Server Virtualization: 
- A **single physical server** is divided into **many small virtual servers**.
- Each one can run its own applications.
- It helps improve performance, cut costs and makes tasks like server migration and energy management easier.
- **Example:** AWS, Microsoft Hyper-V.
- Reduces hardware cost, better performance.

##### 6. Data Virtualization: 
- This brings data from different sources together in one place without needing to know where or how it’s stored. 
- It creates a unified view of the data, which can be accessed remotely via cloud services.
- **Example:** Companies like Oracle and IBM offer solutions for this.

---
#### Hardware Virtualization
- Hardware virtualization means **creating virtual machines (VMs)** on a single physical machine using a software called **Hypervisor**.  
- It divides the physical resources (CPU, RAM, storage) among multiple virtual environments.

##### How it works:

- The **Hypervisor** sits between hardware and OS.
    
- It allows multiple operating systems to run independently on the same physical hardware.
    
- Each OS behaves as if it’s running on its own separate machine.
    

##### Types of Hypervisors:

| Type                    | Description                        | Example                               |
| ----------------------- | ---------------------------------- | ------------------------------------- |
| **Type 1 (Bare-metal)** | Installed directly on the hardware | VMware ESXi, Microsoft Hyper-V, Xen   |
| **Type 2 (Hosted)**     | Runs on top of an existing OS      | VMware Workstation, Oracle VirtualBox |

##### **Advantages:**

- Better resource utilization
    
- Isolation between virtual machines
    
- Easy to create and delete VMs
---

#### Virtualisation implementation Techniques:

##### 1. Full Virtualization

- In this method, the **entire hardware system is simulated**.
    
- Multiple operating systems (OS) can run **without any modification** inside separate **Virtual Machines (VMs)**.
    
- Provides **strong isolation** and **high security**, as each VM runs independently.
    
- **Example:** VMware, Oracle VirtualBox.
    

**Advantages:**

- Supports unmodified guest OS.
    
- High level of security and isolation.
    

**Disadvantages:**

- Performance can be slightly slower because hardware is fully simulated.
    

---

##### 2. Para-Virtualization

- Requires modifications to the guest operating systems
- The **guest OS is modified** to work with the **hypervisor**.
- **Example:** Xen Hypervisor.
    

**Advantages:**

- Faster than full virtualization.
    
- Lower overhead because guest OS interacts directly with hypervisor.
    

**Disadvantages:**

- Requires OS modification.
    
- Complex setup.
    

---

##### 3. OS-Level Virtualization (Containerization)

- Multiple **isolated containers** share the same OS kernel but have **separate user spaces**.
    
- Containers are **lightweight** and start quickly, unlike VMs that need full OS instances.
    
- Ideal for **microservices**, **application testing**, and **rapid deployment**.
    
- **Example:** Docker, LXC, Kubernetes.
    

**Advantages:**

- Very fast and efficient.
    
- Uses less memory and CPU.
    
- Easy to deploy and scale.
    

**Disadvantages:**

- All containers share the same OS kernel → less isolation than full virtualization.
    
- Not suitable for running different OS types on the same system.
----


### Security in Cloud Computing:

Security in cloud computing means protecting:

- **Data** (from loss, theft, or unauthorized access)
    
- **Applications** (from malware and attacks)
    
- **Infrastructure** (servers, networks, and storage)

#### 2. Security Challenges in Cloud Computing

##### 1.  Data Breaches

- Sensitive data (like personal info, passwords, or financial records) can be **stolen** by attackers.
    
- Common cause: weak passwords, poor encryption, or insider threats.
    

##### 2. Data Loss

- Data may be **deleted accidentally** or **corrupted** due to hardware failure, cyberattack, or natural disasters.
    
- Without proper backups, data cannot be recovered.
    
##### 4. Account Hijacking

- Attackers can steal user credentials and take over cloud accounts.
    
- This can lead to data theft, service misuse, or unauthorized operations.
    
##### 5. Lack of Data Privacy

- Data stored on cloud servers may be accessed by cloud providers or governments.
    
- Users have **less control** over how their data is handled.
    

##### 6. Shared Technology Vulnerabilities

- In public clouds, multiple users share the same hardware.
    
- A vulnerability in one virtual machine can **affect others** running on the same physical server.
    

##### 7. Denial of Service (DoS) Attacks

- Attackers overload the cloud server with traffic, making the service **slow or unavailable** to legitimate users.
    

##### 8. Compliance and Legal Issues

- Different countries have different **data protection laws**.
    
- It can be hard to ensure that cloud providers **follow all legal requirements** for data storage and privacy.
---
### Information Security
- **Information Security (InfoSec)** means **protecting information and data** from being accessed, changed, or destroyed by **unauthorized people**.
##### Objectives of Information Security (CIA Triad)

| Objective              | Meaning                                                                  | Example                                                          |
| ---------------------- | ------------------------------------------------------------------------ | ---------------------------------------------------------------- |
| **C –Confidentiality** | Keeping information **private** and accessible only to authorized users. | Using **passwords** or **encryption** to protect files.          |
| **I – Integrity**      | Making sure data is **accurate and not changed** by unauthorized people. | Checking file **hash values** or using **digital signatures**.   |
| **A – Availability**   | Ensuring data and systems are **available whenever needed**.             | Using **backups** and **reliable networks** to prevent downtime. |
##### Types of Information Security Threats:
| Type                        | Description                                         | Example                                    |
| --------------------------- | --------------------------------------------------- | ------------------------------------------ |
| **Malware**                 | Malicious software that damages or steals data.     | Virus, Trojan, Ransomware.                 |
| **Phishing**                | Tricking users into sharing personal information.   | Fake login pages, scam emails.             |
| **Hacking**                 | Unauthorized access to computer systems.            | Breaking into websites or databases.       |
| **Data Breach**             | Sensitive information being leaked or stolen.       | User data leaked from a company’s servers. |
| **Denial of Service (DoS)** | Overloading a system so it can’t function properly. | Flooding a website with fake traffic.      |

##### Techniques to Ensure Information Security
| Technique              | Description                                       |
| ---------------------- | ------------------------------------------------- |
| **Encryption**         | Converts data into unreadable form to protect it. |
| **Firewalls**          | Block unauthorized network traffic.               |
| **Antivirus Software** | Detects and removes malware.                      |
| **Backup**             | Keeps copies of important data.                   |
| **Access Control**     | Restricts who can use what information.           |
| **Regular Updates**    | Keeps systems protected from new threats.         |

---

### Privacy and Trust in Cloud Computing

#### Privacy:
- **Privacy** means **protecting user data** — ensuring that personal or sensitive information is **not shared, leaked, or misused** by unauthorized people or even by the cloud provider.
- Protecting personal info like names, emails, or financial details stored in the cloud.
##### Privacy Issues in Cloud Computing

| Issue               | Explanation                                                                    |
| ------------------- | ------------------------------------------------------------------------------ |
| **Data Ownership**  | Users don’t always know who “owns” their data once it’s stored in the cloud.   |
| **Data Leakage**    | Data can accidentally or intentionally be exposed to unauthorized people.      |
| **Data Location**   | Data may be stored in another country, causing **legal and privacy concerns**. |
| **Lack of Control** | Users cannot directly manage or monitor their data in the cloud.               |
#### Trust

**Trust** means the **confidence** that users have in a cloud provider — believing that the provider will **protect data**, **maintain services**, and **act responsibly**.

##### Factors Affecting Trust in Cloud Computing

| Factor           | Description                                                                                    |
| ---------------- | ---------------------------------------------------------------------------------------------- |
| **Security**     | The cloud provider should use strong security methods (encryption, firewalls, access control). |
| **Transparency** | Provider should clearly explain how they store and manage user data.                           |
| **Compliance**   | Provider should follow government and data protection laws (like GDPR).                        |
| **Reliability**  | Services should be available 24/7 without data loss or downtime.                               |
| **Reputation**   | A trusted provider has a good track record (e.g., AWS, Microsoft Azure, Google Cloud).         |

---

## UNIT 3:
### Data Centre Architecture and Technologies

#### 1. Overview

- A **Data Centre (DC)** is a facility that houses IT infrastructure, such as servers, storage devices, and networking equipment.
    
- It is used to **store, manage, and process** large amounts of data efficiently.
    
- The architecture of a data centre ensures:
    
    - **High availability** – continuous service without interruptions.
        
    - **Scalability** – the ability to grow as business needs increase.
        
    - **Security** – protection from unauthorized access.
        
    - **Efficiency** – optimized use of power, cooling, and hardware.

#### 2. Architectural Building Blocks

##### 1. Compute Layer (Servers)

- Hosts applications, databases, and virtual machines.
    
- Can be **physical servers** (individual machines) or **virtualized servers** (multiple virtual servers on one machine).
    
- Central to processing all the data and applications in the data centre.
    

##### 2. Storage Layer

- Responsible for keeping **data safe and accessible.**
    
- Types of storage:
    
    - **DAS (Direct Attached Storage)**: Storage devices connected directly to a single server.
    
	- **NAS (Network Attached Storage)**: Storage connected over a network, allowing multiple servers to access files.
	    
	- **SAN (Storage Area Network)**: A dedicated high-speed network that provides block-level storage accessible by multiple servers.
        
- Must provide **fast access** and **redundancy** to prevent data loss.
    

##### 3. Network Layer

- Connects servers, storage, and users inside and outside the data centre.
    
- Uses devices like **switches, routers, and firewalls**.
    
- Handles:
    
    - **East-west traffic** – data moving within the data centre.
        
    - **North-south traffic** – data moving to/from external users.
        
- Ensures **low latency** and **high bandwidth** communication.
    

##### 4. Data Centre Infrastructure Layer

- Includes all  physical support systems that keep the data centre running:
    
	- **Power systems**: Such as Uninterrupted Power Supply (UPS) and generators to prevent downtime during power failures.
	    
	- **Cooling systems**: Including CRAC units, liquid cooling, and airflow management to keep equipment at safe temperatures.
	    
	- **Racks and cabling**: Organized structures that hold servers and storage devices, with proper cabling for connectivity and airflow.
        

##### 5. Virtualization and Hypervisors

- Allows a single physical server to run multiple **virtual machines (VMs)**.
    
- Hypervisors manage the virtual machines.
    
- Benefits:
    
    - Reduces hardware costs.
        
    - Improves server utilization.
        
    - Enables rapid deployment of new services.
        

##### 6. Management and Automation Layer

- Tools to **monitor, control, and automate** data centre operations.
    
- Examples: DCIM software, automation scripts, and Software-Defined Networking (SDN).
    
- Helps administrators manage resources efficiently and detect problems early.
    

##### 7. Security Layer

- Ensures protection of both the facility and the data:
    
    - **Physical security**: access control, biometrics, CCTV.
        
    - **Logical security**: firewalls, intrusion detection, encryption.
        
- Ensures **data integrity, confidentiality, and compliance**.
    

##### 8. Redundancy and High Availability

- Includes **redundant components** such as backup power, cooling, and network paths.
    
- **Failover mechanisms** like backup servers and clustering ensure continuous service.
    
- Reduces the risk of downtime during failures.
    

---

### Industry Direction:
- Refers to the **current trends, growth patterns, and future focus areas** of data centre technology. 
- It shows where the industry is heading and what strategies organizations are adopting.

#### Key Points:

- **Cloud-First Approach:**
    
    - Many businesses are moving their workloads to **public, private, or hybrid cloud environments**.
        
    - This allows flexibility, scalability, and cost savings, as companies no longer need to maintain large on-premises infrastructure.
        
- **Edge Data Centres:**
    
    - Smaller data centres located **closer to end-users** to reduce latency and improve performance.
        
    - Important for applications like IoT, gaming, and real-time analytics.
        
- **Sustainability & Green Initiatives:**
    
    - Focus on **energy-efficient designs**, using renewable energy and advanced cooling systems.
        
    - Reduces operational costs and supports environmental goals.
        
- **Automation & Artificial Intelligence (AI):**
    
    - AI and automation tools help in **predictive maintenance, workload management, and resource optimization**.
        
    - Minimizes human intervention and reduces errors.
        
- **Software-Defined Infrastructure:**
    
    - **SDN (Software-Defined Networking)** and **SDS (Software-Defined Storage)** allow flexible and dynamic management of network and storage resources.
        
    - Improves efficiency, scalability, and adaptability to changing business needs.
        
- **Security & Compliance Focus:**
    
    - Growing emphasis on **data privacy, cybersecurity, and regulatory compliance**.
        
    - Security measures are now integrated into the design, operations, and management of data centres.


### Operational Phasing

- Operational phasing describes how a data centre is **managed and maintained day-to-day**.
    
##### Key steps:

- **Planning & Design**: Define business and IT requirements; plan compute, storage, network, and cooling.
    
- **Deployment**: Install servers, storage, networking, virtualization, and monitoring tools.
    
- **Operation & Management**: Monitor workloads, power, cooling, and network health; perform backups and failover management.
    
- **Optimization & Upgrades**: Scale resources, replace aging hardware, and implement new technologies.

---

### Technical Phasing – Overview of 5 Phases

The technical phasing of a data centre focuses on **implementing technology layers efficiently**:

1. **Assessment & Planning**
    
    - Analyze business and IT requirements.
        
    - Determine compute, storage, and network capacity.
        
    - Plan for redundancy, scalability, and security.
        
2. **Design & Architecture**
    
    - Define physical and logical layout of the data centre.
        
    - Design server racks, storage, networking, and cooling systems.
        
    - Plan virtualization and software-defined infrastructure.
        
3. **Implementation & Deployment**
    
    - Install servers, storage, networking, and power/cooling systems.
        
    - Configure operating systems, virtualization, and management tools.
        
    - Integrate monitoring and automation systems.
        
4. **Operation & Monitoring**
    
    - Run workloads and manage resources efficiently.
        
    - Monitor performance, power, cooling, and network health.
        
    - Perform routine maintenance and updates.
        
5. **Optimization & Evolution**
    
    - Scale resources based on changing demand.
        
    - Upgrade hardware and software.
        
    - Implement advanced technologies like AI, SDN, and automation to improve efficiency and reliability.