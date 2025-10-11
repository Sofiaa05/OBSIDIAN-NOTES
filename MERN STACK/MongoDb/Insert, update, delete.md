### Insert: 
#### InsertOne : 
 
	- To insert a single document 
	- inserts a single object into the database.
```json
db.emp_coll.insertOne({name: "sofia", age: 22, designation: "developer"})
```
#### InsertMany : 
	- To insert multiple documents at once
	- inserts an array of objects into the database.
```json
db.emp_coll.insertMany([
{name: "tyler", age: 34, designation: "singer"},
{name: "joshua", age: 33, designation: "drummer"},
{name: "tom", age: 26, designation: "goober"}
])
``` 

---

### Update 
- The **first parameter** is a query object to define **which document** or documents should be updated.

- The **second parameter** is an object **defining the updated data**
- updateOne or updateMany(query object,object)
#### 1. updateOne():
- update the first document that is found matching the provided query. Rest documents will remain same.

##### updating age and designation of employee named "sahil": 
```json
db.emp_coll.updateOne(
    {name: "sahil"},
    { $set: {age: 35, designation: "sde-1"}}
)
```

###### using objectID:
```JSON
db.emp_coll.updateOne(
    { _id: ObjectId('67ceff25a3581b3a411fda99')},
    { $set: {age: 36, designation: "sde-1"}}
)
```

#### 2. updateMany() :
- will update all documents that match the provided query.
##### Update age=69 for every employee named "sahil"
```json
db.emp_coll.updateMany(
    {name: "sahil"},
    {$set: {age: 69}, designation: "manager" }
)
```

##### Updates all users older than 25, adding "status": "Active"
```json
db.users.updateMany(
  { age: { $gt: 25 } }, 
  { $set: { status: "Active" } }
)

```

#### 3. Rename Collection :
```json
db.users.renameCollection("members")
```

---
### Delete 
These methods accept a query object. The matching documents will be deleted.

#### 1. deleteOne():
- Delete the first document that matches the query provided.
```json
db.emp_coll.deleteOne(
	{name: "sahil"}
)
```

#### 2. deleteMany():
- Delete all documents that match the query provided.
```json
db.emp_coll.deleteMany(
	{age :  { $gt: 25}}
);
```

```json
db.emp_coll.deleteMany({})
```

###### Explanation:
- Deletes all documents within a given collection.
#### Delete a Database
```json
db.dropDatabase() 
```