The following SQL statement selects all orders with an OrderDate between '01-July-1996' and '31-July-1996':

### Example

```SQL
SELECT * FROM Orders
WHERE OrderDate BETWEEN #07/01/1996# AND #07/31/1996#;
```

OR:
### Example

```SQL
SELECT * FROM Orders
WHERE OrderDate BETWEEN '1996-07-01' AND '1996-07-31';
```