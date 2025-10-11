```json
const { MongoClient } = require("mongodb");

const url = "mongodb://localhost:27017"; // Local MongoDB connection string
const client = new MongoClient(uri);

async function connectDB() {
  try {
    await client.connect(); // Establish connection
    console.log("Connected to MongoDB!");

    const db = client.db("myDatabase"); // Use/create database
    const collection = db.collection("users"); // Use/create collection

    // Insert a document
    await collection.insertOne({ name: "Alice", age: 25 });
    console.log("User inserted!");

  } catch (error) {
    console.error("Connection error:", error);
  } finally {
    await client.close(); // Close the connection
  }
}

connectDB();

```

refer to: 
https://youtu.be/_5kf2l5vVvM?si=udPx6ug_WpMyjYjU

```js
const {MongoClient} = require("mongodb");

const url = "mongodb://localhost:27017";

async function connectdb(){
	const client = new MongoClient(url);
	
	try{
		awat client.connect();
		console.log("connected");

		const db = client.db(adbname);
		const collection = db.collection("student");

		const docs = await collection.find({}).toArray();

		//display
		collection.forEach(collection =>{
			console.log(`name: ${collection.name}, age: ${collection.age}`);
		});
		
	}catch(error){
		clg("unsuccessfull connection", error);
	}finally{
		await client.close();
	}
		
}

connectdb();
```