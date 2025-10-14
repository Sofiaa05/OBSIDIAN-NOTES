## UNIT 1
### Cyber Security Definition
- **Cyber Security** refers to the practice of protecting computers, servers, networks, and data from unauthorized access, attacks, damage, or theft.
- It ensures **confidentiality, integrity, and availability** of information in the digital environment.
#### Objectives / Principles of Cyber Security (CIA  + AA)

##### 1. CONFIDENTIALITY

- Confidentiality means **protecting information from unauthorized access and disclosure**.  
- Only **authorized users** should be able to view or use sensitive data.

###### Techniques to Maintain Confidentiality:

- **Data Encryption** (e.g., AES, RSA)
    
- **User Authentication** (passwords, biometrics)
    
- **Access Control Lists (ACLs)**


##### **2. INTEGRITY**

- Integrity means ensuring that **data remains accurate, consistent, and unaltered** during storage, transmission, and processing.

    
###### Techniques to Maintain Integrity:

- **Checksums and Hashing**
    
- **Version Control Systems**
    
- **Data Validation**


##### 3. AVAILABILITY

- Availability means ensuring that **information and systems are accessible to authorized users whenever needed**.
    
###### Techniques to Ensure Availability:

- **Regular Data Backups**
    
- **Redundant Systems and Servers**
    
- **Disaster Recovery Plans**
    

    
##### 4. AUTHENTICITY

- Authenticity ensures that **data, communication, or users are genuine** and not impersonated or forged.


    
###### Techniques to Ensure Authenticity:
    
- **Two-Factor Authentication (2FA)**
    
- **Digital Signatures**
    
- **Biometric Verification**
    
##### 5. ACCOUNTABILITY

- Accountability ensures that **all actions in a system can be traced to responsible individuals.**
    
###### Techniques to Ensure Accountability:

- **System Logs and Audit Trails**
    
- **Security Monitoring Systems**
    
#### Summary Table: Five Key Principles

| **Principle**       | **Meaning**                                        | **Goal**       | **Example / Technique**                   |
| ------------------- | -------------------------------------------------- | -------------- | ----------------------------------------- |
| **Confidentiality** | Prevent unauthorized access to data                | Privacy        | Encryption, Access control                |
| **Integrity**       | Maintain accuracy and consistency of data          | Trust          | Hashing, Data validation, version control |
| **Availability**    | Ensure data and systems are accessible when needed | Reliability    | Backups, Redundancy, Disaster recovery    |
| **Authenticity**    | Verify identity of users and data sources          | Verification   | 2FA, Digital signatures.                  |
| **Accountability**  | Trace actions to responsible users                 | Responsibility | Logs, Audit trails                        |


### Internet Governance – Challenges and Constraints
- **Internet Governance** refers to the development and application of principles and rules, that shape the use and evolution of the internet.
- In simple terms, it means **how the internet is managed, controlled, and regulated globally**.
#### Challenges in Internet Governance

1. **Jurisdictional Issues**
    
    - Internet is global, but laws are national.
        
    - Difficulty in deciding which country’s laws apply in cross-border cybercrimes.
        
2. **Privacy and Data Protection**
    
    - Misuse of personal data by companies and hackers.
        
    - Lack of uniform data protection laws globally.
        
3. **Cybercrimes and Security Threats**
    
    - Rise in hacking, identity theft, and cyber terrorism.
        
    - Need for international cooperation to track criminals.
        
4. **Content Regulation and Censorship**
    
    - Balancing free speech with the need to prevent hate speech and misinformation.
        
5. **Intellectual Property Rights (IPR) Issues**
    
    - Unauthorized use, copying, or sharing of digital content.
        
---
### Cyber Threats
- A **Cyber Threat** is any **potential danger or malicious attempt** to damage, steal, or disrupt data, computer systems, or digital networks.
- Cyber threats are actions that **compromise confidentiality, integrity, or availability** of information (the **CIA triad**)
#### Types of Cyber Threats


| **Type of Cyber Threat** | **Main Objective**       | **Example**         |
| ------------------------ | ------------------------ | ------------------- |
| Malware                  | Infect or damage systems | Virus, Trojan       |
| Phishing                 | Steal personal info      | Fake bank email     |
| DoS/DDoS                 | Disrupt services         | Flooding server     |
| MITM                     | Intercept communication  | Stealing login data |
| SQL Injection            | Access database          | Bypass login        |
#### Structured and Unstructured Cyber threats

#####  1. STRUCTURED CYBER THREATS

- Structured cyber threats are **well-planned, organized, and professionally executed attacks** carried out by **skilled attackers or groups** with **specific objectives**.

- These threats are **systematic**, use **advanced tools and techniques**, and often involve **team coordination**.

######  Characteristics

- Highly **organized and coordinated**.
    
- Carried out by **experienced and trained professionals**.
    
- Involve **long-term planning and research**.
    
- Aim to cause **maximum impact** — economic, political, or military.
    
- May be **sponsored by organizations or nations**.
    
- Difficult to detect and defend against.
###### Examples

- **Cyber espionage** by foreign intelligence agencies.
    
- **Advanced Persistent Threats (APTs)** targeting government or defense systems.
    
- **Ransomware campaigns** run by organized cybercrime groups.
    
- **State-sponsored attacks** on power grids, banks, or military databases.
    
###### Objectives

- Stealing sensitive data (financial, military, or research).
    
- Disrupting national security or critical services.
    
- Gaining economic or political advantage.
    
- Cyber warfare or digital spying.
    

---

##### 2. UNSTRUCTURED CYBER THREATS

- Unstructured cyber threats are **unplanned, random, or amateur attacks** carried out by **inexperienced individuals (often called “script kiddies”)** using **ready-made hacking tools or software** without deep technical knowledge.

- These attacks are often done **for fun, curiosity, or personal challenge** rather than professional or financial gain.
###### Characteristics

- **No organized plan** or structured approach.
    
- Conducted by **individuals or small groups** with limited skills.
    
- Use **freely available tools** or scripts from the internet.
    
- Short-term attacks, not targeted for large-scale damage.
    
- Often cause **accidental or small-scale harm**.

---

###### Examples

- A beginner hacker defacing a small website.
    
- Random virus spread without specific targets.
    
- Social media account hacking for fun or revenge.

###### **Objectives**

- To gain attention or recognition.
    
- For amusement or challenge.
    
- To test or show off hacking abilities.
    
- To cause small-scale disruptions.
##### DIFFERENCE BETWEEN STRUCTURED AND UNSTRUCTURED CYBER THREATS

| **Basis**                | **Structured Cyber Threats**                                 | **Unstructured Cyber Threats**                      |
| ------------------------ | ------------------------------------------------------------ | --------------------------------------------------- |
| **Definition**           | Planned and organized attacks by skilled professionals.      | Random or unplanned attacks by amateurs.            |
| **Skill Level**          | High — involves trained hackers, experts.                    | Low — carried out by beginners or “script kiddies.” |
| **Motivation**           | Financial gain, espionage, political or military objectives. | Fun, curiosity, revenge, or showing off.            |
| **Planning**             | Long-term, strategic, and coordinated.                       | Short-term, unplanned, and opportunistic.           |
| **Tools Used**           | Advanced, customized hacking tools                           | Free ready-made hacking tools                       |
| **Impact**               | Severe, large-scale, and long-lasting damage.                | Limited, small-scale, and short-term impact.        |
| **Detection Difficulty** | Difficult to detect; often hidden for long periods.          | Easier to detect and trace.                         |

#### CyberSquatting

- **Cyber Squatting** (also called **Domain Squatting**) is the act of **registering, selling, or using a domain name** similar to a **well-known trademark, brand, or individual’s name** with the **intention to earn profit or mislead users**.
- **Example:** If someone registers **tatasteelindia.com** or **amazonsales.in** without being connected to Tata Steel or Amazon,  and later tries to sell it to those companies for profit — it is **cyber squatting**.

---

##### Types of Cyber Squatting

| **Type**                  | **Explanation**                                                                                                           | **Example**                                             |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------- |
| **1. Typo Squatting**     | The squatter registers **misspelled or mistyped** versions of a famous domain to trick users who make typing errors.      | e.g., `gooogle.com`, `facebok.com`, `amaz0n.com`        |
| **2. Identity Squatting** | The squatter registers a **domain name using someone’s personal or brand identity**, such as a celebrity or company name. | e.g., `salman-khan.com`, `microsoftofficial.in`         |
| **3. Name Jacking**       | When someone registers a **domain name belonging to a well-known person or brand before they do**, to later sell it.      | e.g., Registering `elonmusk.net` before Elon Musk does. |
| **4. Combo Squatting**    | Involves adding **extra words** to a popular domain to make it look authentic.                                            | e.g., `paypal-login.com`, `google-secure.net`           |


---

All three terms — **Cybersquatting**, **Typo Squatting**, and **Gripe Sites** — are connected to **domain name misuse** on the internet.  
However, their **intent, legality, and purpose** are **different**.

##### Typo Squatting

- A **sub-type of cybersquatting** where the squatter registers **misspelled or mistyped versions** of popular domain names.
    
- The aim is to **mislead users** who make spelling mistakes while typing URLs, and to **earn ad revenue or steal information**.
    
- It is also **illegal** and done **with malicious intent**.
    

**Example:**  
Registering `gooogle.com`, `facebok.com`, or `amaz0n.net` to trick users who mistype the original address.

---

#####  Gripe Sites

- These are websites created by individuals or groups to **criticize, review, or complain** about a company, brand, or person.
    
- They are usually **non-commercial** and created for **freedom of expression**, not for profit.
    
- They are **not illegal** if they do not mislead users or contain defamatory or false information.
    

**Example:**  
A consumer who had a bad experience with ABC Airlines may create a site like `abcairlinessucks.com` to share their negative reviews.

##### Differences Between Cybersquatting, Typo Squatting, and Gripe Sites

|**Basis**|**Cybersquatting**|**Typo Squatting**|**Gripe Sites**|
|---|---|---|---|
|**Definition**|Registering or using a domain name identical/similar to a trademark with intent to profit.|Registering a misspelled or mistyped version of a famous domain to mislead users.|Creating a website to criticize or complain about a brand, product, or person.|
|**Intent / Purpose**|To **sell the domain** or **exploit** the brand for money.|To **divert web traffic** or **earn ad revenue** from user mistakes.|To **express opinion**, **criticize**, or **raise awareness**, not for profit.|
|**Legality**|**Illegal** under Trademark and IT laws.|**Illegal** as it misleads and causes deception.|**Generally legal** if it doesn’t involve defamation or fraud.|
|**Relation to Brand Owner**|Targets brand names directly for profit.|Targets typing errors of brand domains.|Targets brand reputation but in a **non-commercial** way.|
|**User Impact**|Users may get misled or scammed.|Users may land on fake or malicious sites.|Users get critical opinions or reviews.|
|**Example**|Registering `appleindia.com` to sell it to Apple.|Registering `applle.com` to get traffic from typing errors.|Registering `applesucks.com` to post complaints about Apple.|

---

### Cyber Crime / Cyber Offence and its Categories

- A **cyber crime** is any **illegal act or criminal activity** that involves the use of **computers, digital devices, or networks**.

- In simple terms, **cyber crime** means **committing a crime using a computer or the internet**.
    
####  CATEGORIES / CLASSIFICATION OF CYBER CRIMES

- Cyber crimes can be classified based on how the **computer is involved** or the **type of offense committed**.  
##### 1. Crimes Against Individuals
- These are crimes that target **individuals or their private data**.  
- The aim is usually to **harm, harass, or steal personal information**.

###### Examples:

- **Cyber Stalking** – Repeatedly harassing or threatening a person online.
    
- **Identity Theft** – Stealing someone’s personal details (like credit card or Aadhaar number) to commit fraud.
    
- **Phishing** – Fake emails or websites used to steal login credentials.
    
- **Online Defamation** – Spreading false or harmful information about someone.
    
- **Cyber Bullying** – Using social media to insult or threaten someone.
    
- **Email Spoofing** – Sending emails pretending to be someone else.
    

---
##### 2. Crimes Against Property

- These crimes target **data, information, or intellectual property** belonging to organizations or individuals.  
- The motive is often **financial gain**.

###### Examples:

- **Hacking** – Unauthorized access to computer systems.
    
- **Data Theft** – Stealing confidential or business data.
    
- **Denial of Service (DoS) Attacks** – Disrupting a website or network service.
    
- **Software Piracy** – Copying and distributing software illegally.
    
- **Credit Card Fraud** – Stealing or misusing payment card information.
    

---

##### 3. Crimes Against Government / Society

- These are serious cyber crimes that target **national security, defense systems, or public infrastructure**.  
- They are often **politically or ideologically motivated**.
###### Examples:

- **Cyber Terrorism** – Attacks on critical systems (like power grids or transport) to create fear or chaos.
    
- **Espionage / Cyber Spying** – Stealing sensitive information from government or military databases. 
    
- **Propaganda and Fake News** – Spreading false information to influence public opinion.
    
- **Cyber Warfare** – Attacks launched by one nation against another’s digital infrastructure.
    

##### Summary Table: Categories of Cyber Crimes

|**Category**|**Target**|**Examples**|
|---|---|---|
|**Against Individuals**|Personal privacy, data, or reputation|Cyber stalking, phishing, defamation|
|**Against Property**|Data, information systems, digital assets|Hacking, ransomware, data theft|
|**Against Government/Society**|National infrastructure, political systems|Cyber terrorism, espionage, fake news|

---

### Classification of Cyber Crimes
| **Cyber Offense**       | **What is it?**                                                               | **How to Prevent**                                                                          |
| ----------------------- | ----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| **Email Spoofing**      | Sending emails that appear to come from a trusted source to trick recipients. | Verify sender addresses, use email authentication (SPF/DKIM), avoid clicking unknown links. |
| **Spamming**            | Sending unsolicited or bulk emails, often advertising or phishing attempts.   | Use spam filters, block suspicious senders, avoid sharing your email publicly.              |
| **Cyber Defamation**    | Posting false or harmful information online to damage a person’s reputation.  | Avoid sharing unverified info, use privacy settings, report defamatory content.             |
| **Internet Time Theft** | Using someone else’s internet service without permission.                     | Secure Wi-Fi with strong passwords, use WPA3 encryption, monitor connected devices.         |
| **Data Diddling**       | Unauthorized modification of data before or during entry into a system.       | Use access control, audit trails, data validation, and encryption.                          |
| **Espionage**           | Unauthorized access to confidential data for spying or competitive advantage. | Use encryption, secure networks, multi-factor authentication, limit access.                 |
| **Hacking**             | Unauthorized access to computer systems to steal or manipulate information.   | Use firewalls, strong passwords, antivirus software, and keep systems updated.              |
| **Online Frauds**       | Deceptive schemes conducted via the internet for financial gain.              | Verify websites and sellers, use secure payment methods, enable transaction alerts.         |
| **Email Bombing**       | Sending massive numbers of emails to overwhelm a recipient’s inbox or server. | Use email filtering, rate limiting, and monitor server traffic.                             |
| **Password Sniffing**   | Capturing passwords over networks using packet sniffers.                      | Use encrypted connections (HTTPS, VPN), strong passwords, and two-factor authentication.    |
| **Credit Card Frauds**  | Unauthorized use of credit/debit card information to steal money.             | Use secure payment gateways, monitor statements, and avoid public Wi-Fi for transactions.   |
| **Identity Theft**      | Stealing personal information to impersonate someone for fraud or gain.       | Keep personal info private, use strong passwords, enable 2FA, monitor accounts regularly.   |
### Wireless Computing and cyber attacks associated with it

#### Definition:

- Wireless computing refers to **transmitting data or accessing information over a network without using physical cables**.  
- It uses **radio waves, infrared, or satellite communication** instead of wired connections.


#### Characteristics of Wireless Computing

1. **Mobility:** Access network resources without being physically connected.
    
2. **Flexibility:** Devices can connect and disconnect easily.
    
3. **Accessibility:** Internet and data access from remote areas.
    
4. **Real-time Communication:** Instant sharing of data or messages.
    
5. **Vulnerability:** Wireless signals can be intercepted by attackers.

#### Common Wireless Technologies

| **Technology**              | **Description**                               | **Example Use**                   |
| --------------------------- | --------------------------------------------- | --------------------------------- |
| **Wi-Fi**                   | Wireless Local Area Network (WLAN) connection | Internet access at home or office |
| **Bluetooth**               | Short-range wireless communication            | Headphones, file sharing          |
| **Infrared (IR)**           | Line-of-sight short-range transfer            | Remote controls                   |
| **Cellular Network**        | Mobile communication (3G, 4G, 5G)             | Internet on smartphones           |
| **Satellite Communication** | Long-distance wireless link                   | GPS, remote broadcasting          |

####  CYBER ATTACKS IN MOBILE DEVICES AND WIRELESS COMPUTING

- Because wireless communication happens **through air**, it can be **intercepted, modified, or disrupted** by cybercriminals.  
##### 1. How Cyberattacks Happen in Mobile Devices
###### Common Mobile Cyberattacks:

1. **Malware Attacks**
        
2. **Phishing and Smishing**
        
3. **Man-in-the-Middle (MitM) Attack**
        
4. **App Permissions Exploitation**
    
    - Malicious apps request unnecessary permissions (camera, mic, contacts).
        
    - These permissions are used to **spy or collect data**.
        
5. **Spyware / Keyloggers**
6. **SIM Card Swap Fraud**
	- Attacker duplicates your SIM by social engineering, gains control of OTPs and messages.

##### 2. How Cyberattacks Happen in Wireless Computing (Wi-Fi and Wireless Networks)

###### Common Wireless Network Attacks:

1. **Eavesdropping / Packet Sniffing**
    
    - Attackers capture unencrypted data packets transmitted over Wi-Fi.
        
    - Sensitive data like passwords or emails can be stolen.
        
2. **Rogue Access Point**
    
    - Fake Wi-Fi access points created by hackers to trick users.
        
    - Once connected, the hacker can steal credentials or inject malware.
        
3. **Evil Twin Attack**
    
    - A more sophisticated rogue access point attack.
        
    - The fake network has a name similar to a real one (e.g., “Cafe_WiFi”).
        
    - Users connect unknowingly and attackers intercept their communication.
        
4. **Denial of Service (DoS) Attack**
    
    - Attackers flood the wireless network with fake requests, making it unavailable.
        
    - Disrupts legitimate users’ access.
        
5. **MAC Spoofing**
    
    - Hacker changes the MAC address of their device to impersonate another device and bypass access control.
        
##### Security Measures / Prevention Techniques

|**Area**|**Preventive Measures**|
|---|---|
|**Mobile Devices**|- Install apps only from trusted stores (Google Play, App Store).- Keep OS and apps updated.- Use antivirus and app permissions wisely.- Avoid clicking on unknown links or SMS.- Use biometric or strong passwords.|
|**Wireless Networks**|- Use **WPA3 encryption** for Wi-Fi.- Disable auto-connect to open networks.- Change default router password.- Use **VPN** when using public Wi-Fi.- Regularly monitor connected devices.|

---
## UNIT 2

### Vulnerabilities 

#### Definition

- A **cybersecurity vulnerability** is a **weakness or flaw in a system, network, or software** that can be **exploited by cyber attackers** to gain unauthorized access, steal data, disrupt services, or cause harm.
- Vulnerabilities are the **“open doors” in a system** that hackers can use to attack.
#### Classification of Cybersecurity Vulnerabilities

Cybersecurity vulnerabilities can be classified into **four main categories**:
- Software vulnerabilities
- Hardware vulnerabiliites
- Network vulnerabilities
- Human / social vulnerabilities
##### 1. Software Vulnerabilities

- Weaknesses in operating systems, applications, or software code.

- Can allow **unauthorized access, data leaks, or system crashes**.
    
- **Examples:**
    
    - Bugs in OS or apps
        
    - Unpatched software
        
    - Buffer overflow errors
        
- **Prevention:** Keep software updated, apply patches, use secure coding practices.
    

##### B. Hardware Vulnerabilities

- Weaknesses in physical devices like servers, routers, computers, or IoT devices.
    
- Attackers can exploit **unsecured ports, device firmware flaws, or outdated hardware**.
    
- **Examples:**
    
    - Weak BIOS security
        
    - Default passwords on IoT devices
        
    - Vulnerable network cards
        
- **Prevention:** Regular firmware updates, secure configurations, restrict physical access.
    
---

##### C. Network Vulnerabilities

- Weaknesses in network architecture, protocols, or wireless connections.
    
- Can allow attackers to intercept, modify, or disrupt network traffic.
    
- **Examples:**
    
    - Open Wi-Fi without encryption
        
    - Weak router passwords
        
    - Vulnerable network protocols (like HTTP instead of HTTPS)
        
- **Prevention:** Use encryption (WPA3, VPN, SSL), firewalls, intrusion detection systems, strong network policies.
    

---

##### D. Human / Social Vulnerabilities

- Weaknesses caused by human behavior or lack of awareness.
    
- Humans are often the **weakest link in cybersecurity**.
    
- **Examples:**
    
    - Weak or reused passwords
        
    - Falling for phishing attacks
        
    - Sharing confidential info online
        
- **Prevention:** Cybersecurity awareness training, strong password policies, multi-factor authentication.

##### Summary Table: Classification of Vulnerabilities

|**Type**|**What it affects**|**Examples**|**Prevention**|
|---|---|---|---|
|**Software**|OS, applications, code|Bugs, unpatched software, buffer overflows|Updates, patches, secure coding|
|**Hardware**|Devices, routers, IoT|Default passwords, firmware flaws|Firmware updates, physical security|
|**Network**|LAN, WLAN, protocols|Open Wi-Fi, weak encryption|Encryption, firewalls, VPN|
|**Human / Social**|Users and behavior|Phishing, weak passwords|Awareness training, MFA, strong password policies|

---

####  Vulnerabilites in Proxy Servers
- A **proxy server** is an **intermediary server** that **routes client requests to the internet** and returns the response. It acts as a **gateway between a user and the internet**.
    
##### Example

- Using a proxy to access websites from a restricted network or to hide your location.

##### Advantages

- Improves privacy and security.
    
- Reduces network traffic through caching.
    

##### Limitations

- Can be slow if overloaded.
    
- Not fully secure against advanced attacks.
    

---

#### Vulnerabilities in Anonymizers

- An **anonymizer** is a tool or service that **hides a user’s identity online** to make browsing **completely anonymous**. 
- It’s similar to a proxy but usually **offers stronger privacy protection**.

##### Examples

- Tor Browser
    
- VPN services with strong privacy policies
    

##### Advantages

- Stronger anonymity than standard proxies.
    
- Protects against tracking and surveillance.
    
- Can secure data on public networks.
    

##### Limitations

- Can reduce browsing speed.
    
- Some services may log user activity if not trustworthy.
    
---

### Why cyber attack?
| **Motive / Reason**                  | **One-line Explanation**                                                    |
| ------------------------------------ | --------------------------------------------------------------------------- |
| **Financial Gain**                   | Attackers aim to steal money or extort victims for ransom.                  |
| **Espionage / Intelligence**         | Stealing confidential data from organizations or governments.               |
| **Political / Ideological Goals**    | Disrupt or embarrass targets to promote a cause or protest.                 |
| **Revenge / Personal Grudge**        | Attacks motivated by anger or retaliation against individuals or companies. |
| **Competition / Economic Advantage** | Stealing trade secrets or sensitive info to gain business advantage.        |

#### How cyber attacks are done:
- Phishing
- Malware
- MITA
- SQL Injection
- DOS and DDOS attacks

#### Phishing

**Definition:**  
Phishing is when someone tries to **trick you into giving your personal information** like passwords, bank details, or credit card numbers by pretending to be a trusted source.

**How it works:**

- You get a fake email, message, or website that looks real.
    
- It asks you to click a link or open an attachment.
    
- When you enter your details, the attacker steals them.
    

**Example:**  
An email that looks like it’s from your bank asking you to “verify your account” and enter your password.

---

#### Password Cracking

**Definition:**  
Password cracking is when someone **tries to guess or find your password** to access your account without permission.

**How it works:**

- Attackers try common passwords like “123456” or “password.”
    
- They may try many combinations until the correct one is found.
    
- Sometimes they use stolen passwords from other websites.
    

**Example:**  
Someone guesses your social media password because you used “Sofia123” on multiple accounts.

---

#### Keyloggers and Spyware

**Definition:**

- **Keylogger:** A program or device that secretly **records everything you type** on your keyboard.
    
- **Spyware:** A program that secretly **spies on your device**, collecting information like passwords, messages, or browsing history.
    

**How it works:**

- You install a malicious app or click a bad link.
    
- Keylogger records your typing, like passwords and messages.
    
- Spyware can also check what websites you visit, what apps you use, or even take screenshots.
    
- The attacker uses this information to steal money or personal data.
    

**Example:**  
A fake app you downloaded tracks your passwords and sends them to the attacker.

#### Malware 

**Definition:**  
Malware is any **malicious software** that is designed to **damage your computer, steal information, or disrupt operations**.

**How it works:**

- Malware can be installed when you **download files, click bad links, or open infected emails**.
    
- Once inside your device, it can **slow down your system, steal data, or let attackers control your device**.
    
- **Types**: Trojan horse, virus, worms, spyware, keyloggers, backdoors.
**Example:**  
A malicious app that sends your photos and messages to someone else without your knowledge.


####   Virus

**Definition:**  
A virus is a type of malware that **attaches itself to files or programs** and spreads when those files are shared.

**How it works:**

- You open an infected file or program.
    
- The virus runs and may **delete files, slow down your computer, or spread to other files**.
    
- It often spreads when you **share infected files via USB, email, or downloads**.
    

**Example:**  
Opening an infected document from email causes your files to get damaged and spreads to your friends’ computers.

---

#### Worms

**Definition:**  
- A worm is malware that **spreads by itself** over networks, without needing a person to open a file.
- look for pathways between computers (computer networks) to spread and replicate themselves


**How it works:**

- Worms scan for computers connected to the internet or a network.
    
- They copy themselves and **infect other computers automatically**.
    
- They can slow down networks or delete files.
    

**Example:**  
A worm spreads through a network and makes all connected computers slow or crash.

---

#### Trojan Horse

**Definition:**  
A Trojan Horse is malware that **pretends to be something useful** (like a game or software) but actually **causes harm**.

**How it works:**

- You download or run a program thinking it’s safe.
    
- The Trojan secretly **steals information, damages files, or gives hackers access**.
    

**Example:**  
A free game app that secretly sends your passwords and personal data to hackers.

---

#### Backdoors

**Definition:**  
A backdoor is a hidden method that lets **hackers access a system or device** without going through normal login or security checks.

**How it works:**

- Malware like a Trojan can create a backdoor.
    
- Hackers can then **enter the system anytime** to steal data or control the device.
    

**Example:**  
A hacker uses a backdoor created by malware to remotely access your computer and view files.

#### Steganography

**Definition:**  
Steganography is the technique of **hiding secret information inside something else**, like images, videos, or audio files, so that it is not visible to others.

**How it works:**

- A secret message is embedded in a file (for example, hidden in the pixels of an image).
    
- The file looks normal and can be sent over the internet without raising suspicion.
    
- Only someone with the right method or key can extract the hidden message.
    

**Example:**  
Hiding a confidential text inside a picture and sending it via email — anyone opening the picture sees only the normal image.

#### DoS (Denial of Service) Attack

**Definition:**  
A DoS attack is when an attacker **floods a website or network with too many requests** to make it **slow or completely unavailable** to real users.

**How it works:**

- The attacker sends **massive traffic or fake requests** to the target server.
    
- The server becomes **overloaded** and cannot handle legitimate users.
    
- The website or service slows down or crashes.
    

**Example:**  
A website becomes unreachable because someone sent thousands of fake requests in a short time.

**Prevention (short):**  
Use firewalls, traffic filtering, and proper server capacity planning.

#### DDoS (Distributed Denial of Service) Attack

**Definition:**  
A DDoS attack is similar to a DoS attack, but it comes from **many computers at the same time** instead of just one, making it much more powerful.

**How it works:**

- The attacker controls a **network of infected computers (botnet)**.
    
- These computers send requests to the target simultaneously.
    
- The target server is **overwhelmed and crashes**.
    

**Example:**  
Hackers use thousands of infected PCs to crash an online shopping site during a big sale.

**Prevention (short):**  
Use DDoS protection services, CDNs, and traffic monitoring to block malicious traffic.

#### SQL Injection

**Definition:**  
SQL injection is an attack where a bad person tricks a website into running harmful database commands by entering specially crafted text into input fields.

**How it works (plain):**  
When a website takes what you type (like in a login box or search box) and directly uses it to build a database command, an attacker types extra code instead of normal text. The website sends that code to the database, which then returns or changes data the attacker shouldn’t access.

**Example:**  
Instead of typing a username, the attacker types a snippet that makes the site return all users’ passwords or lets the attacker log in without a real password.

**Prevention (one-line):**  
Never let user input run directly as commands — use prepared queries/parameterized inputs and validate all input.

---

#### Buffer Overflow

**Definition:**  
A buffer overflow happens when a program is given more data than it expects and that extra data spills over into other parts of memory, causing crashes or letting attackers run harmful code.

**How it works (plain):**  
A program allocates a fixed space (a “buffer”) for user input. If the program doesn’t check the size and someone gives much larger input, the extra bytes overwrite nearby memory. An attacker can craft the extra data so the program later executes the attacker’s code.

**Example:**  
A simple program that assumes a name will be 20 characters crashes or behaves badly when given 200 characters — an attacker can use this to take control of the program.

---

#### Identity Theft

**Definition:**  
Identity theft is when someone steals another person’s personal information (name, ID numbers, bank details) and uses it to commit fraud or pretend to be that person.

**How it works (plain):**  
Attackers collect personal info from hacked databases, phishing messages, stolen mail, or careless sharing. They then use that info to open accounts, make purchases, or access the victim’s services in their name.

**Example:**  
A criminal uses your name and ID to open a bank account or take a loan, leaving you with the debt and ruined credit history.

**Prevention (one-line):**  
Protect personal data—use strong passwords, don’t share sensitive info publicly, monitor bank statements and credit reports, and enable two-factor authentication.

#### Exam Tip (One-line summaries)

| **Term**                    | **One-line Explanation**                                                   |
| --------------------------- | -------------------------------------------------------------------------- |
| **Steganography**           | Hiding secret information inside files like images or videos.              |
| **DoS Attack**              | Overloading a server with fake requests to make it unavailable.            |
| **DDoS Attack**             | Using many computers to flood a server and crash it.                       |
| **Malware**                 | Software designed to harm or steal from your computer.                     |
| **Virus**                   | Malware that attaches to files and spreads when the files are shared.      |
| **Worm**                    | Malware that spreads automatically over networks.                          |
| **Trojan Horse**            | Malware that pretends to be safe software but is harmful.                  |
| **Backdoor**                | Hidden way for hackers to access a system secretly.                        |
| **Phishing**                | Tricking users into giving personal info via fake messages or websites.    |
| **Password cracking**       | Finding someone’s password to access accounts without permission.          |
| **Keyloggers and spywares** | Programs that secretly record your activity or information on your device. |

## Extra Topics
#### Digital Signatures

**Definition:**  
A digital signature is a way to **prove that a digital message, document, or file really comes from the sender and has not been altered**. It’s like a handwritten signature or a stamp for electronic data.

**How it works (simple explanation):**

1. The sender creates a **unique signature** using their private key (a secret code only they have).
    
2. This signature is attached to the message or document.
    
3. The receiver uses the sender’s **public key** (a code anyone can use) to check:
    
    - If the message is really from the sender.
        
    - If the message has been changed in transit.
            

**Why it’s useful:**

- Confirms **authenticity** (who sent it).
    
- Ensures **integrity** (data wasn’t changed).
    
- Provides **non-repudiation** (sender cannot deny sending it).

#### IT Act 2000

**Definition:**  
The IT Act 2000 is a law in India that **makes electronic records, emails, and digital signatures legally valid** and **helps stop cybercrime**.
##### Key Points

1. **Legal Validity** – Emails, online contracts, and digital signatures are treated like real paper documents and signatures.
    
2. **Cybercrime Prevention** – Punishes hacking, stealing data, online fraud, and posting illegal content online.
    
3. **Digital Signatures** – Lets people sign documents electronically and proves they are authentic.
    
4. **Certifying Authorities** – Organizations approved by the government issue digital certificates to verify signatures.
    
5. **Dispute Resolution** – There is a system to solve cybercrime and e-commerce disputes in courts.
##### Why it is Important:

- Makes **online transactions and communication safe and legal**.
    
- Protects people from **cybercrime**.

#### Digital platform in the context of cyber security 
- A digital platform is an **online system or service that allows users, businesses, or devices to interact, share information, or perform transactions** over the internet. 
- Examples include e-commerce sites, social media platforms, cloud services, and online banking.
- A digital platform is an online system where users interact or transact, and cybersecurity protects it from data theft, attacks, and misuse.

#### Ways in which technology is influencing the cyber world
| **Technology Influence**                 | **How it affects the cyber world**                                                     | **Example**                                         |
| ---------------------------------------- | -------------------------------------------------------------------------------------- | --------------------------------------------------- |
| **Increased Connectivity**               | Connects people and devices globally, increasing communication and targets for attacks | Social media, IoT devices                           |
| **Digital Transformation of Businesses** | Online tools improve efficiency but increase cyber risks                               | Online banking, e-commerce                          |
| **Big Data & Cloud Computing**           | Enables data storage and analysis but increases risk of breaches                       | Cloud storage by Amazon, Google                     |
| **Automation & AI in Cybersecurity**     | Predicts, detects, and responds to threats quickly                                     | AI-driven spam filters, predictive threat detection |
| **IoT Expansion**                        | Connects everyday devices, offering convenience but also more vulnerabilities          | Smart thermostats, wearable devices                 |