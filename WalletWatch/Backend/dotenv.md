### What Are Environment Variables?

Environment variables are dynamic values that affect how running processes behave on a computer. They are used to configure applications without hardcoding settings into the source code.

### Key Concepts

- **Dynamic Values**: Stored outside the application code.
    
- **System/Process Level**: Can be set at the OS level or per application.
    
- **Configuration Management**: Used for API keys, database URLs, feature flags, etc.
    
- **Security**: Keep sensitive data (passwords, tokens) out of source code.
    
### What Does `npm install dotenv` Do?

`npm install dotenv` is a command that installs the **`dotenv`** package, a popular Node.js module used to load environment variables from a `.env` file into `process.env`.
