```sql
INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
VALUES
('Cardinal', 'Tom B. Erichsen', 'Skagen 21', 'Stavanger', '4006', 'Norway'),
('Greasy Burger', 'Per Olsen', 'Gateveien 15', 'Sandnes', '4306', 'Norway'),
('Tasty Tee', 'Finn Egan', 'Streetroad 19B', 'Liverpool', 'L1 0AA', 'UK');

```

- Make sure you separate each set of values with a comma ,
---
 
## NULL
 - NULL value is different from a zero value or a field that contains spaces. A field with a NULL value is one that has been left blank during record creation!

---
## Update
```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;

```

- Be careful when updating records. If you omit the `WHERE` clause, ALL records will be updated!

---
 
## DELETE
```sql
 DELETE FROM _table_name_ WHERE _condition_;
```

### Delete all records
- deletes all record, keeping empty table
```sql
DELETE FROM _table_name_
```

### Delete all rows including table
```sql
DROP TABLE _table_name_
```