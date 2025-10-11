- An aggregate function is a function that performs a calculation on a set of values, and returns a single value.

- Aggregate functions are often used with the `GROUP BY` clause of the `SELECT` statement. The `GROUP BY` clause splits the result-set into groups of values and the aggregate function can be used to return a single value for each group.

#### The most commonly used SQL aggregate functions are:

- `MIN()` - returns the smallest value within the selected column
- `MAX()` - returns the largest value within the selected column
- `COUNT()` - returns the number of rows in a set
- `SUM()` - returns the total sum of a numerical column
- `AVG()` - returns the average value of a numerical column

Aggregate functions ignore null values (except for `COUNT(*)`).

---
### MIN and MAX

```mysql
SELECT MIN(_column_name_)   
FROM _table_name_   
WHERE _condition_;

SELECT MAX(_column_name_)   
FROM _table_name_   
WHERE _condition_;
```

---
## Use MIN() with GROUP BY

Here we use the `MIN()` function and the `GROUP BY` clause, to return the smallest price for each category in the Products table:

### Example

```mysql
SELECT MIN(Price) AS SmallestPrice, CategoryID  
FROM Products  
GROUP BY CategoryID;
```

---
 
## Count
```sql
SELECT COUNT(DISTINCT Price)
FROM Products;
```

### Count() with groupBy
```sql
SELECT COUNT(*) AS [Number of records], CategoryID
FROM Products
GROUP BY CategoryID;
```

---

## SUM 
- can use alias too
```sql
SELECT SUM(column_name)
FROM table_name
WHERE condition;
```

### SUM() With an Expression

The parameter inside the `SUM()` function can also be an expression.

If we assume that each product in the `OrderDetails` column costs 10 dollars, we can find the total earnings in dollars by multiply each quantity with 10:

### Example

```sql
SELECT SUM(Quantity * 10)  
FROM OrderDetails;
```

---

## AVG

```SQL
SELECT AVG(_column_name_)  
FROM _table_name_  
WHERE _condition_;
```