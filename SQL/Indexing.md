- for faster data lookups by creating a separate data structure for that column you want to search in a sorted manner along with a pointer to that where data is stored


An **index** is a special data structure (usually a B-Tree) that helps the database **find rows faster**, just like the index of a book helps you locate a topic without flipping every page.

👉 Without index → full table scan (slow)  
👉 With index → fast lookup via index tree

---

### **Clustered vs Non-Clustered Index**

| Feature         | Clustered Index                        | Non-Clustered Index                                      |
| --------------- | -------------------------------------- | -------------------------------------------------------- |
| Data storage    | Stores the actual rows in sorted order | Stores only pointers to the data (reference)             |
| Sorting         | Sorts the table itself                 | Sorts only the index, not the table                      |
| Count per table | Only ONE                               | Can have MANY                                            |
| Use case        | Primary Key                            | Columns used frequently in search, join, or WHERE clause |
| speed           | faster                                 | slower                                                   |

📌 **Analogy**:  
Clustered index = the book pages are arranged alphabetically  
Non-clustered index = index page at the end of the book listing topics + page numbers

---

### **When NOT to use an index**

Do **NOT** create indexes on:

❌ Small tables (no performance gain)  
❌ Columns that change very frequently (UPDATE/INSERT cost increases)  
❌ Columns with many duplicate values (e.g., gender: M/F)  
❌ Columns used rarely in search, JOIN, WHERE

📌 If column has low selectivity (few distinct values), index does not help.

---

### **How indexing impacts SELECT, UPDATE, DELETE**

|Operation|Impact|Why|
|---|---|---|
|**SELECT**|⚡ Faster|Index helps locate records quickly|
|**UPDATE**|🐢 Slower|Must update both table and index|
|**DELETE**|🐢 Slower|Must remove entry from table and index|
|**INSERT**|🐢 Slower|Need to insert into index as well|

👉 **Indexes speed up reads but slow down writes**

---

## 🏁 **Interview Ready Summary**

> **An index speeds up data retrieval by creating a fast lookup structure. Clustered index sorts the actual data, while non-clustered index stores pointers to data. Use indexes on frequently searched columns, but avoid them on small or frequently updated tables, as indexes make SELECT fast but slow down INSERT, UPDATE, and DELETE operations.**

---

# Normalisation
- technique to organise data in a db to reduce redundancy and remove insertion, updation, deletion anomalies
- simplifies design, reduces redundancy, optimise performance by removing anomalies
- different stages- each stage imposes certain rules.