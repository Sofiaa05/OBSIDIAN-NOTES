

## **1️⃣ Aggregate / Grouping Queries**

1. **Count employees per department**
    

```sql
SELECT DepartmentID, COUNT(*) AS EmployeeCount
FROM Employees
GROUP BY DepartmentID;
```

2. **Average salary per department**
    

```sql
SELECT DepartmentID, AVG(Salary) AS AvgSalary
FROM Employees
GROUP BY DepartmentID;
```

3. **Maximum salary per department**
    

```sql
SELECT DepartmentID, MAX(Salary) AS MaxSalary
FROM Employees
GROUP BY DepartmentID;
```

4. **Employees earning more than their manager**
    

```sql
SELECT e.EmployeeName
FROM Employees e
JOIN Employees m ON e.ManagerID = m.EmployeeID
WHERE e.Salary > m.Salary;
```

5. **Employees joined in last N days**
    

```sql
SELECT *
FROM Employees
WHERE JoinDate >= CURDATE() - INTERVAL N DAY;
```

---

## **2️⃣ Ranking / Nth Queries**

1. **Second highest salary**
    

- Using `LIMIT`:
    

```sql
SELECT DISTINCT Salary
FROM Employees
ORDER BY Salary DESC
LIMIT 1 OFFSET 1;
```

- Using `DENSE_RANK()`:
    

```sql
SELECT Salary
FROM (
    SELECT Salary, DENSE_RANK() OVER (ORDER BY Salary DESC) AS Rank
    FROM Employees
) AS Ranked
WHERE Rank = 2;
```

2. **Nth highest salary** → just replace `2` with `n` in the above query.
    

---

## **3️⃣ Self Join / Hierarchy Queries**

1. **Employees and their manager names**
    

```sql
SELECT e.EmployeeName, m.EmployeeName AS ManagerName
FROM Employees e
LEFT JOIN Employees m ON e.ManagerID = m.EmployeeID;
```

2. **Employees without a manager**
    

```sql
SELECT *
FROM Employees
WHERE ManagerID IS NULL;
```

---

## **4️⃣ Date / Time Queries**

1. **Employees joined in a particular month/year**
    

```sql
SELECT *
FROM Employees
WHERE MONTH(JoinDate) = 5 AND YEAR(JoinDate) = 2025;
```

2. **Employees with birthdays today**
    

```sql
SELECT *
FROM Employees
WHERE MONTH(BirthDate) = MONTH(CURDATE())
  AND DAY(BirthDate) = DAY(CURDATE());
```

---

## **5️⃣ String / Pattern Matching**

1. **Employees whose name starts with 'A'**
    

```sql
SELECT *
FROM Employees
WHERE EmployeeName LIKE 'A%';
```

2. **Employees whose email ends with 'gmail.com'**
    

```sql
SELECT *
FROM Employees
WHERE Email LIKE '%@gmail.com';
```

---

## **6️⃣ Joins & Subqueries**

1. **Find employees who don’t have any projects**
    

```sql
SELECT e.EmployeeName
FROM Employees e
LEFT JOIN Projects p ON e.EmployeeID = p.EmployeeID
WHERE p.ProjectID IS NULL;
```

2. **Find employees working on multiple projects**
    

```sql
SELECT EmployeeID, COUNT(ProjectID) AS ProjectCount
FROM Projects
GROUP BY EmployeeID
HAVING COUNT(ProjectID) > 1;
```

3. **Top 3 employees with highest salaries**
    

```sql
SELECT *
FROM Employees
ORDER BY Salary DESC
LIMIT 3;
```

---

```sql
--- Find 3rd highest salary: ---
SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 2; 
```

.

---
## 🟢 **RAW UNNORMALIZED TABLE**

|StudentID|StudentName|Course|Instructor|InstructorPhone|
|---|---|---|---|---|
|101|Ram|Java, Python|A Sharma|9876543210|
|102|Siya|Python|B Verma|9988776655|
|101|Ram|Java|A Sharma|9876543210|

### Problems:

❌ Multiple courses in one cell (not atomic)  
❌ Repeated data (StudentName, Instructor details duplicate)  
❌ Update/Insert/Delete anomalies possible

---

## **1️⃣ First Normal Form (1NF)**

**Rule:** No repeating groups, every value must be atomic.

### Convert multivalued column into separate rows:

|StudentID|StudentName|Course|Instructor|InstructorPhone|
|---|---|---|---|---|
|101|Ram|Java|A Sharma|9876543210|
|101|Ram|Python|A Sharma|9876543210|
|102|Siya|Python|B Verma|9988776655|

### Now:

✔ Atomic values  
❌ Still redundancy (Ram + Instructor repeating)

---

## **2️⃣ Second Normal Form (2NF)**

**Rule:**  
✔ Must be in 1NF  
✔ No **partial dependency** on composite key

Here, composite key = (StudentID, Course)

**Issue:** StudentName depends only on StudentID, not on Course  
Instructor depends only on course, not on sTUDENTID

### Break into two tables:

**STUDENT Table**

|StudentID|StudentName|
|---|---|
|101|Ram|
|102|Siya|

**COURSE_ENROLLMENT Table**

| StudentID | Course | Instructor |
| --------- | ------ | ---------- |
| 101       | Java   | A Sharma   |
| 101       | Python | A Sharma   |
| 102       | Python | B Verma    |

✔ Partial dependencies removed  
❌ Still instructor phone repeated

---

## **3️⃣ Third Normal Form (3NF)**

**Rule:**  
✔ Must be in 2NF  
✔ No **transitive dependency**  
(Non-key attribute must not depend on another non-key attribute)

Here:  
InstructorPhone depends on Instructor (Instructor → InstructorPhone) — transitive dependency

### Split Instructor details:

**INSTRUCTOR Table**

|Instructor|InstructorPhone|
|---|---|
|A Sharma|9876543210|
|B Verma|9988776655|

**COURSE_ENROLLMENT Table** (updated)

|StudentID|Course|Instructor|
|---|---|---|
|101|Java|A Sharma|
|101|Python|A Sharma|
|102|Python|B Verma|

✔ No transitive dependencies now  
🎉 Database is now in **3NF**

---

## **4️⃣ Boyce–Codd Normal Form (BCNF)**

**Rule:** Every determinant must be a **super key**

BCNF is only needed when:

- A table has **multiple candidate keys**
    
- Dependencies violate 3NF (rare)
    

In our example, 3NF = BCNF because:

- StudentID uniquely identifies students
    
- Instructor uniquely identifies phone numbers
    
- No dependency violation exists
    

✔ So database is already in BCNF

---

## 🎯 **Super Crisp Summary for Interview**

|Normal Form|What it Removes|Rule|
|---|---|---|
|1NF|Repeating / multivalued data|Atomic values|
|2NF|Partial dependency|Every non-key depends on whole key|
|3NF|Transitive dependency|Non-key should not depend on non-key|
|BCNF|Remaining anomalies|Every determinant must be a key|


    

    

---

### ✅ **7. SQL Queries Practice**

Be ready to write queries for:

- Second highest salary
    
- Duplicate rows find/delete
    
- Group By + Having
    
- Order By + Limit
    
- Subqueries, correlated subqueries
    

**Must know functions:** COUNT, SUM, AVG, MIN, MAX

    

---



## 🎯 **If I had to pick ONLY 5 high-impact topics**

    

    
5. SQL Query Writing (Medium level)
    


---

### JOINS vs SUBQUERY



## 🔥 **Difference Between Subquery and JOIN**

|Feature|Subquery|JOIN|
|---|---|---|
|Definition|A query inside another query|Combines rows from two or more tables based on related columns|
|Execution|Inner query runs first, result used by outer query|Tables are combined first, then filters applied|
|Output Style|Produces values used for filtering or comparison|Produces combined rows from multiple tables|
|Readability|Simple for single condition checks|Better for relational data retrieval|
|Performance|Can be slower (depends on DB optimization)|Generally faster as joins are optimized using indexes|
|Use Case|When we need a value derived from another query|When we need related data from multiple tables|

---

## 🧠 **Which is Better? When and Why?**

### 🟢 **Use JOIN when:**

✔ You need data from multiple tables together  
✔ You want to combine rows based on relationships  
✔ Performance matters → JOIN uses indexes efficiently  
✔ You want to avoid issues with `NULL` in `NOT IN`

**Example:**

```sql
SELECT e.name, d.dept_name
FROM Employee e
JOIN Department d ON e.dept_id = d.dept_id;
```

**Why JOIN is often faster?**  
Database engines optimize JOINs using hashing, indexing, and merge algorithms.

---

### 🔵 **Use Subquery when:**

✔ You only need a single value or a filtered list  
✔ Query logic becomes clearer with nested filtering  
✔ You want to avoid multiple JOINs  
✔ You’re checking existence, comparison, or aggregation

**Example:**

```sql
SELECT name
FROM Employee
WHERE salary > (SELECT AVG(salary) FROM Employee);
```

This is simpler than writing a self-JOIN.

---

## 🚀 **Final Interview Summary**

Say this:

> **Joins are preferred when retrieving related data from multiple tables, as they are generally faster and optimized by the database engine. Subqueries are useful when we need to filter data based on aggregated results or conditions derived from another query. If performance and readability favor direct table relationships, choose JOIN; if logic favors hierarchical filtering, choose subqueries.**

---

## ⚠️ Important Corner Case

- `NOT IN (SELECT ...)` fails if subquery returns NULL
    
- `LEFT JOIN ... WHERE column IS NULL` is safer
    

