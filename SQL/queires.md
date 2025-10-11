

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

