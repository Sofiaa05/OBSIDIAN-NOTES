 - MySQL supports the `LIMIT` clause to select a limited number of records,
```SQL
SELECT _column_name(s)_  
FROM _table_name_ 
WHERE _condition_  
LIMIT _number_;
```

#### Example:
```sql
SELECT * FROM Customers
ORDER BY CustomerName DESC
LIMIT 3;
```