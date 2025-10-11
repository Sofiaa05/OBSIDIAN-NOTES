## 🔰 Spring Basics

|Term|Meaning|
|---|---|
|**Spring Framework**|A powerful Java framework to build secure and scalable applications. Handles objects, web, database, security, etc.|
|**Spring Boot**|A simplified version of Spring that auto-configures everything and helps you get started fast.|
|**Bean**|An object managed by Spring. Spring creates and controls it for you.|
|**IOC (Inversion of Control)**|Instead of you creating objects manually, Spring gives you objects when needed.|
|**DI (Dependency Injection)**|The process of automatically giving one class the objects (dependencies) it needs.|
|**ApplicationContext**|The container that manages all Spring Beans and configuration.|

---

## 🖥️ Annotations (You'll See These a Lot)

|Annotation|Meaning|
|---|---|
|`@SpringBootApplication`|Main annotation that starts the Spring Boot app. Combines 3 annotations: `@Configuration`, `@EnableAutoConfiguration`, `@ComponentScan`.|
|`@Component`|Tells Spring: "This is a class you should manage automatically."|
|`@Service`|Same as `@Component`, but used for service layer classes.|
|`@Repository`|Used on database-related classes. Handles exceptions automatically.|
|`@Controller`|Used for MVC (webpages).|
|`@RestController`|Used for REST APIs that return data (usually JSON).|
|`@Autowired`|Tells Spring to inject a dependency automatically into a class.|
|`@GetMapping`, `@PostMapping`, etc.|Define routes for GET/POST/PUT/DELETE HTTP methods.|
|`@PathVariable`|Extracts a variable from the URL.|
|`@RequestParam`|Extracts a parameter from the query string.|
|`@RequestBody`|Gets the body of a POST/PUT request as an object.|
|`@ResponseBody`|Sends data (like JSON) back to the client.|

---

## 🧱 Project Structure

|Term|Meaning|
|---|---|
|**Model**|Java class representing data (e.g., User, Product).|
|**Repository**|Interface to talk to the database (usually extends `JpaRepository`).|
|**Service**|Contains the business logic of the app (not controller, not DB).|
|**Controller**|The layer that receives HTTP requests and sends responses.|
|**DTO**|"Data Transfer Object" - used to transfer specific data, not the whole model.|
|**Entity**|A class mapped to a database table using JPA.|

---

## 🌐 Web Concepts

|Term|Meaning|
|---|---|
|**API (Application Programming Interface)**|A way for the frontend and backend to talk (e.g., `GET /users`, `POST /login`).|
|**REST API**|A type of API that follows rules like using HTTP methods and clean URLs.|
|**HTTP Methods**|Ways of interacting: GET (read), POST (create), PUT (update), DELETE (remove).|
|**JSON**|Format for sending/receiving data between frontend and backend.|
|**Status Code**|Response codes like 200 OK, 404 Not Found, 500 Internal Error.|
|**Request Body**|The actual data you send in a POST or PUT request.|
|**Query Parameters**|Extra data sent in the URL like `/users?sort=name`.|
|**Path Variables**|Dynamic parts of a URL like `/users/{id}`.|

---

## ⚙️ Configuration & Properties

|Term|Meaning|
|---|---|
|**application.properties** / **application.yml**|A config file where you set things like DB URL, port, etc.|
|**Port**|The "door" your app runs on (default is 8080).|
|**Environment**|Profiles like dev, test, prod — you can change settings per environment.|

---

## 🛢️ Database Concepts

|Term|Meaning|
|---|---|
|**JPA (Java Persistence API)**|A way to map Java objects (Entities) to database tables.|
|**Hibernate**|A JPA provider — it does the work of saving objects to the DB.|
|**Entity**|A class that represents a table.|
|**@Entity**|Annotation to mark a class as a database table.|
|**@Id**|Primary key of the entity.|
|**@GeneratedValue**|Automatically generates the value for the ID.|
|**@Column**|Maps a Java field to a table column (optional).|
|**CrudRepository / JpaRepository**|Interfaces used to interact with DB (they already have save(), findById(), delete() etc.).|

---

## 🔐 Security (Basics)

|Term|Meaning|
|---|---|
|**Spring Security**|Module used to handle login, logout, authentication, and role-based access.|
|**JWT (JSON Web Token)**|A secure token used to keep users logged in — sent with every API call.|
|**Authentication**|Verifying who the user is (login).|
|**Authorization**|Checking what the user can do (permissions/roles).|

---

## 🔁 Dependency Management & Tools

|Term|Meaning|
|---|---|
|**Maven / Gradle**|Tools to manage project dependencies (like downloading required libraries).|
|**POM.xml**|A file where Maven stores your project's dependencies.|
|**Dependency**|A library or tool your project needs (like Spring Web, MySQL, Lombok).|
|**Spring Initializr**|Website to generate a Spring Boot project easily ([https://start.spring.io](https://start.spring.io/)).|

---

## 🧪 Testing Tools

|Term|Meaning|
|---|---|
|**Postman**|Tool to test APIs manually (e.g., send POST requests to check responses).|
|**Unit Test**|Test for a single method/class.|
|**Integration Test**|Testing how different parts of the app work together.|
|**Mocking**|Faking data or services in tests to isolate behavior.|

---

## 💡 Common Dev Terms

|Term|Meaning|
|---|---|
|**Build**|Compiling your code into an executable (like a `.jar` file).|
|**Run**|Starting your Spring Boot application.|
|**Terminal / Console**|The command-line screen where logs and messages appear.|
|**Hot Reload**|Changes reflect in the app automatically without restarting.|
|**Logs**|Messages shown in the terminal for debugging.|

---

## 📦 Deployment / Hosting

|Term|Meaning|
|---|---|
|**Embedded Server**|Spring Boot includes a server like Tomcat — no need to install separately.|
|**JAR File**|A Java archive you can run like `java -jar app.jar`.|
|**WAR File**|A web app archive used in traditional deployment (not common in Spring Boot).|
|**Heroku / Render / AWS**|Platforms to host your Spring Boot application.|
|**Production-ready**|Ready to be used by real users, safely and reliably.|
