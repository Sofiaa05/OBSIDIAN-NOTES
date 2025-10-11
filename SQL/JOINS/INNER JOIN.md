**INNER JOIN** returns only the rows that have matching values **in both tables**.

### Syntax
```sql
SELECT table1.column, table2.column
FROM table1
INNER JOIN table2
ON table1.common_column = table2.common_column;
```

---
## Practice Questions: 
## EASY
### 1. Join `Customers` and `Orders` to get the names of customers who placed orders

```sql
Select Customers.name 
FROM Customers
INNER JOIN Orders
ON Customers.id = Orders.id
```

### 2. Get a list of employees and their department names.
```sql
SELECT Employees.name, Departments.deptname
FROM Employees 
INNER JOIN Departments 
ON Employees.deptid = Departments.deptid
```

### 3. Show products along with their category names.

```sql
SELECT Products.name, Categories.name
FROM Products
INNER JOIN Categories
ON Products.categoriesid = Categories.categoriesid
```

---

## Intermediate

### 4. Get all orders along with the customer names who placed them.

- **Primary Key**: `Customers.id`
    
- **Foreign Key**: `Orders.customer_id → Customers.id`

```sql
SELECT Orders.name, Customers.name
FROM Customers 
INNER JOIN Orders
ON Orders.customer_id = Customers.id
```


    
5. Show employees who work in the same department as another employee (self join).
    
6. Find all customers who ordered a product in the "Electronics" category



| Mistake                           | Fix                                       |
| --------------------------------- | ----------------------------------------- |
| Repeating `FROM` twice            | Only one `FROM` allowed                   |
| Using table name instead of alias | Stick to aliases (`c`, `o`, `p`, etc.)    |
| Wrong `ON` condition              | Always match PK → FK                      |
| Alias not declared                | Declare alias before using it in `SELECT` |

| Situation You Want                     | JOIN Type                                        | Pattern to Recognize                                    |
| -------------------------------------- | ------------------------------------------------ | ------------------------------------------------------- |
| Only matched data from both tables     | `INNER JOIN`                                     | "only if exists in both"                                |
| All from left table, even if no match  | `LEFT JOIN`                                      | "include even if unmatched", "must include left table"  |
| All from right table, even if no match | `RIGHT JOIN`                                     | "include even if unmatched", "must include right table" |
| Find things with **no match**          | `LEFT/RIGHT JOIN + WHERE other_table.id IS NULL` | "who has not done X", "who doesn’t belong"              |
| Count even zero matches                | `LEFT JOIN + GROUP BY`                           | "include all and count even 0"                          |