| Operator | Description                                                                     |
| -------- | ------------------------------------------------------------------------------- |
| =        | Equal                                                                           |
| >        | Greater than                                                                    |
| <        | Less than                                                                       |
| >=       | Greater than or equal                                                           |
| <=       | Less than or equal                                                              |
| <> or != | Not equal. **Note:** In some versions of SQL this operator may be written as != |
| BETWEEN  | Between a certain range                                                         |
| LIKE     | Search for a pattern                                                            |
| IN       | To specify multiple possible values for a column                                |

---
## AND vs OR

The `AND` operator displays a record if _all_ the conditions are TRUE.

The `OR` operator displays a record if _any_ of the conditions are TRUE.

---
## Combining AND and OR

The following SQL statement selects all customers from Spain that starts with a "G" or an "R".

Make sure you use parenthesis to get the correct result.

#### Example

Select all Spanish customers that starts with either "G" or "R":

```sql
SELECT * FROM Customers  
WHERE Country = 'Spain' AND (CustomerName LIKE 'G%' OR CustomerName LIKE 'R%');
```

---
## ORDER BY
- sort the result-set in ascending or descending order.
```sql
SELECT * FROM Products
ORDER BY Price ASC; --- ORDER BY Price DESC 
--- same goes for sorting alphabetically and numerically both