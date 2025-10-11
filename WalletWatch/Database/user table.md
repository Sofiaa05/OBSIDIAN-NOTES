```js
const mongoose = require("mongoose");
const bcrypt = require("bcryptjs");

const userSchema = new mongoose.Schema({
    fullname: {
        type: String,
        required: true
    },
    email: {
        type: String,
        required: true,
        unique: true
    },
    password: {
        type: String,
        required: true
    },
    profileImageUrl:{
        type: String,
        default: null
    },
},
    {timestamps: true}
);

// Hash password before saving to database
userSchema.pre("save", async function (next){
    if(!this.isModified("password")) {
        return next();
    }
    this.password = await bcrypt.hash(this.password, 10);
    next();
});

//compare passwords
userSchema.methods.comparePassword = async function (enteredPassword) {
    return await bycrypt.compare(enteredPassword, this.password);
}


module.exports = mongoose.model("User", userSchema);

```

| Line                            | Meaning                                         |
| ------------------------------- | ----------------------------------------------- |
| `bcrypt.genSalt(10)`            | Creates a cryptographic salt (extra randomness) |
| `bcrypt.hash(password, salt)`   | Hashes password securely                        |
| `userSchema.pre('save')`        | Middleware to hash password before saving       |
| `bcrypt.compare(plain, hashed)` | Checks if password matches the hashed one       |
| `comparePassword()`             | Custom method to reuse `bcrypt.compare()`       |