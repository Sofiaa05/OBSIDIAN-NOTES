

### What is NoSQL?

- Type of database that **does not use tables** like relational databases (MySQL, PostgreSQL).
- It is used for **handling large amounts of unstructured, semi-structured, or structured data** efficiently.
- NoSQL databases are flexible, scalable, and fast.

### NoSQL VS SQL

| Feature     | SQL (Relational DB)                         | NoSQL (Non-Relational DB)                                                  |
| ----------- | ------------------------------------------- | -------------------------------------------------------------------------- |
| Structure   | Tables (Rows & Columns)                     | Document-based, key-value, column-family, or graph-based                   |
| Schema      | Fixed Schema                                | Flexible Schema                                                            |
| Scalability | Vertical (upgrading single server hardware) | Horizontal (Add more servers to share workload)                            |
| Best for    | Structured Data (Banking, Transactions)     | All kinds (unstructured such as Large-Scale Data (Social Media, Big Data)) |
| example     | MySQL, Oracle, postgreSQL                   | MongoDB, Cassandra                                                         |
| ACID        | supports                                    | doesnt                                                                     |
## MongoDB
- **Document Oriented** (Uses Documents Instead of Tables)
- **NoSQL** database system
- Schema less, no tables or relations
- Stores data in **JSON** format (key:value pair)
- Documents are grouped into **collections** (similar to tables in SQL).
- It is highly **scalable, flexible, and fast.**
- written in c++


![[Screenshot 2025-03-09 at 7.02.22 PM.png]]

![[Screenshot 2025-03-09 at 7.05.28 PM.png]]
- Every document can have different fields
- No need to create different tables, **data is stored together** in one document
- Increased flexibility, scalability and performance.
- MongoDb is **open source** and **cross platform** database system.
- Can be used with several programming languages (java, c#, JS, python, GO, Ruby)

![[Screenshot 2025-03-09 at 7.10.24 PM.png]]

### Documents :
- **key-value pair** (similar to JSON objects). The values of fields may include other documents, arrays, and arrays of documents.
- **dynamic schema** (documents in the same collection do not need  to have the same set of field or structure)

---
### Role-Based Access Control (RBAC):
- to manage permissions

| **Role**      | **Permissions**                             |
| ------------- | ------------------------------------------- |
| **read**      | View data only                              |
| **readWrite** | View & modify data                          |
| **dbAdmin**   | Manage indexes & settings & not modify data |
| **userAdmin** | Manage user accounts                        |
| **root**      | Full control (super admin)                  |


| **Task**              | **Command**                                                      |
| --------------------- | ---------------------------------------------------------------- |
| Create User           | `db.createUser({user: "...", pwd: "...", roles: [...] })`        |
| Show Users            | `db.getUsers()`                                                  |
| Delete User           | `db.dropUser("username")`                                        |
| Enable Authentication | Edit `mongod.conf` and restart MongoDB                           |
| Login with User       | `mongo -u "user" -p "password" --authenticationDatabase "admin"` |