```csharp
Frontend/Postman sends:
   POST /api/v1/add-income  → with data (title, amount...)

↓ hits route ↓
routes/transactions.js
   router.post('/add-income', addIncome)

↓ calls ↓
controllers/income.js
   addIncome(req, res)
   → creates new income object
   → saves to DB

↓ uses ↓
models/IncomeModel.js
   defines the schema/structure for MongoDB

↓ connects via ↓
db/db.js
   connects to MongoDB using mongoose

↓ finally ↓
res.send({ message: "Income added!" });

```