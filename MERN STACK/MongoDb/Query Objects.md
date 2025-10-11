- A query object is a **JavaScript object** containing **key-value pairs** that represent conditions.

### Comparison operators
- to compare and reference document fields.


| **Operator** | **Description**               | **Example**                       |
| ------------ | ----------------------------- | --------------------------------- |
| `$eq`        | Equal to                      | `{ age: { $eq: 25 } }`            |
| `$ne`        | Not equal to                  | `{ age: { $ne: 25 } }`            |
| `$gt`        | Greater than                  | `{ age: { $gt: 20 } }`            |
| `$gte`       | Greater than or equal to      | `{ age: { $gte: 30 } }`           |
| `$lt`        | Less than                     | `{ age: { $lt: 30 } }`            |
| `$lte`       | Less than or equal to         | `{ age: { $lte: 25 } }`           |
| `$in`        | Matches any value in an array | `{ age: { $in: [20, 25, 30] } }`  |
| `$nin`       | Excludes values in an array   | `{ age: { $nin: [20, 25, 30] } }` |
### Logical Operators

Logically compare multiple queries and returns documents.

|**Operator**|**Description**|**Example**|
|---|---|---|
|`$and`|Matches all conditions|`{ $and: [{ age: { $gt: 20 } }, { age: { $lt: 30 } }] }`|
|`$or`|Matches at least one condition|`{ $or: [{ age: 25 }, { name: "Alice" }] }`|
|`$not`|Negates a condition|`{ age: { $not: { $gt: 30 } } }`|
|`$nor`|Matches neither condition|`{ $nor: [{ age: 25 }, { name: "Alice" }] }`|

### Evaluation

Assist in evaluating documents.

- `$regex`: Allows the use of regular expressions when evaluating field values
- `$text`: Performs a text search
- `$where`: Uses a JavaScript expression to match documents
### Querying Arrays

|**Operator**|**Description**|**Example**|
|---|---|---|
|`$all`|Matches all values in an array|`{ hobbies: { $all: ["reading", "gaming"] } }`|
|`$size`|Matches arrays with a specific size|`{ hobbies: { $size: 3 } }`|
|`$elemMatch`|Matches at least one condition in an array|`{ scores: { $elemMatch: { subject: "Math", score: { $gte: 80 } } } }`|

---

### Regular Expressions for Pattern Matching

MongoDB allows **pattern matching** using **Regular Expressions (Regex)**.

|**Operator**|**Description**|**Example**|
|---|---|---|
|`/pattern/`|Matches string patterns|`{ name: /Al/ }` (Matches names containing "Al")|
|`^pattern`|Matches strings that start with pattern|`{ name: /^Al/ }` (Starts with "Al")|
|`pattern$`|Matches strings that end with pattern|`{ name: /ce$/ }` (Ends with "ce")|
|`i`|Case-insensitive matching|`{ name: /alice/i }`|

---

### Querying Nested Documents

|**Operator**|**Description**|**Example**|
|---|---|---|
|`dot notation`|Access nested fields|`{ "address.city": "New York" }`|
|`$elemMatch`|Match conditions in arrays of objects|`{ scores: { $elemMatch: { subject: "Math", score: { $gte: 80 } } } }`|

#### Example Data

```json
{
  "name": "Alice",
  "address": { "city": "New York", "zip": "10001" }
}
```

```js
db.users.find({ "address.city": "New York" }) 
// Find users who live in New York
```

---

### 8. Sorting, Limiting, and Skipping

| **Method** | **Description**                                | **Example**          |
| ---------- | ---------------------------------------------- | -------------------- |
| `.sort()`  | Sorts results (1 = ascending, -1 = descending) | `.sort({ age: -1 })` |
| `.limit()` | Limits the number of results                   | `.limit(5)`          |
| `.skip()`  | Skips a number of documents                    | `.skip(2)`           |
|            |                                                |                      |
####  Example

```json
db.users.find().sort({ age: -1 }).limit(5).skip(2)
```

---



---
