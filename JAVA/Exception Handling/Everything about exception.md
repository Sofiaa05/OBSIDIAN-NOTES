## What Is Exception Handling?

**Exception Handling** is Java’s way of **handling runtime errors** to maintain **normal program flow**.

- **Exception** = abnormal condition at runtime.
    
- It provides a mechanism to **catch and handle** runtime issues like divide-by-zero, null pointer access, file not found, etc.
    

---

# ⚙️ 2. Java Exception Hierarchy

```java
Object
 └── Throwable
      ├── Exception (checked)
      │    ├── IOException, SQLException, etc.
      │    └── RuntimeException (unchecked)
      │         ├── NullPointerException
      │         ├── ArrayIndexOutOfBoundsException
      │         └── ArithmeticException
      └── Error (unchecked, serious system issues)
           ├── StackOverflowError
           └── OutOfMemoryError
```

---

# 🛠 3. Types of Exceptions

| Type            | Checked Exceptions                               | Unchecked Exceptions                      |
| --------------- | ------------------------------------------------ | ----------------------------------------- |
| Definition      | Checked by compiler                              | Not checked by compiler                   |
| Inheritance     | Directly inherit `Exception`                     | Inherit `RuntimeException`                |
| Examples        | IOException, SQLException, FileNotFoundException | NullPointerException, ArithmeticException |
| Need to Handle? | Yes (must use try-catch or throws)               | No (optional, but recommended)            |

---

# 💥 4. Errors vs Exceptions

|Feature|Exception|Error|
|---|---|---|
|Recoverable?|Yes|No|
|Occurrence|Due to program logic|Due to system/resource failure|
|Handle it?|Yes, generally|No (avoid handling them)|

---

# 🔄 5. Core Keywords

|Keyword|Use|
|---|---|
|`try`|Block of code that might throw an exception|
|`catch`|Block to handle the exception|
|`finally`|Executes regardless of exception (for cleanup)|
|`throw`|Used to explicitly throw an exception|
|`throws`|Declares an exception in method signature (for checked)|

---

# 📦 6. Syntax and Examples

### ✅ try-catch

```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero: " + e);
}
```
### ✅ try-catch-finally

```java
try {
    int[] arr = new int[3];
    arr[5] = 100;
} catch (ArrayIndexOutOfBoundsException e) {
    System.out.println("Index out of bounds!");
} finally {
    System.out.println("Cleanup done.");
}
```

### ✅ Multiple catch blocks
```java
try {
    String s = null;
    System.out.println(s.length());
} catch (NullPointerException e) {
    System.out.println("NullPointerException");
} catch (Exception e) {
    System.out.println("General Exception");
}

```

### ✅ Nested try-catch

```java
try {
    try {
        int data = 50 / 0;
    } catch (ArithmeticException e) {
        System.out.println("Inner: " + e);
    }
} catch (Exception e) {
    System.out.println("Outer: " + e);
}
```
---

# 🪓 7. `throw` vs `throws`

|Feature|`throw`|`throws`|
|---|---|---|
|Purpose|Used to actually throw exception|Declares an exception|
|Use|Inside method|With method signature|
|Example|`throw new IOException();`|`void readFile() throws IOException`|
```java
public void readFile() throws IOException {
    throw new IOException("File not found");
}
```
---

# 🧱 8. Custom Exceptions

### ✅ Define Your Own Exception

```java
class MyException extends Exception {
    public MyException(String msg) {
        super(msg);
    }
}
```

### ✅ Use Custom Exception

```java
public void validate(int age) throws MyException {
    if (age < 18) throw new MyException("Not eligible to vote");
}
```

---

# 🔄 9. `finally` Block

- Always executes after try-catch, whether or not an exception is thrown.
    
- Even executes after `return` statements.
    
- Can be **omitted** if not needed.
    
- Common use: Closing resources (files, DB connections).
    It ensures that essential cleanup tasks are performed, such as releasing resources or closing connections, contributing to the overall robustness of the program.

---

# 10. try-with-resources (Java 7+)

Automatically closes resources that implement `AutoCloseable`.

```java
try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
    String line = br.readLine();
} catch (IOException e) {
    System.out.println(e);
}
```
---

# 11. Common Built-in Exceptions (with use-case)

|Exception|When It Occurs|
|---|---|
|`ArithmeticException`|Divide by zero|
|`NullPointerException`|Accessing method/field of a null object|
|`ArrayIndexOutOfBoundsException`|Invalid index on array|
|`NumberFormatException`|Parsing invalid string to number|
|`IOException`|File-related issues|
|`FileNotFoundException`|File not found|
|`ClassNotFoundException`|Class loading failure|
|`SQLException`|JDBC/SQL-related failures|

---

# 📌 12. Best Practices

✅ Always catch **specific exceptions first**  
✅ Never suppress exceptions silently  
✅ Use **finally** to release resources  
✅ Avoid catching `Throwable` or `Error`  
✅ Prefer custom exceptions for business logic  
✅ Do not use exceptions for flow control

---

# 🧠 13. Interview-Level Concepts

### Q: What is the difference between final, finally, and finalize?

|Term|Use|
|---|---|
|`final`|Keyword to prevent modification|
|`finally`|Block always executed after try-catch|
|`finalize`|Method called by GC before object destroy|

---

### Q: What happens if exception is thrown in `finally`?

Only that exception is propagated — previous exceptions are suppressed unless handled. If an exception is thrown from within the finally block, it will override any exception thrown in the preceding try block or catch block.

---

### Q: Can a constructor throw exceptions?

Yes. It can declare `throws` and even use `try-catch`.
When a constructor encounters a situation where it cannot properly initialize an object (e.g., invalid input parameters, resource allocation failure), it can throw an exception to signal this problem.
```java
public MyClass() throws IOException {
    throw new IOException("Error");
}
```

--- 
### Q:  Can a finally block be used without a try block?

No, a finally block must always be associated with a preceding try block. It cannot exist independently. The finally block provides a mechanism to define cleanup code that executes whether an exception occurs or not within the associated try block

### Q: Can we have try without catch or finally?

Only allowed in try-with-resources (Java 7+), otherwise compilation error.

---

# 📚 14. Exception Propagation

If an exception isn't caught in one method, it **propagates** up the call stack.

```java
void methodA() {
    methodB();
}
void methodB() {
    int x = 10 / 0; // propagates to A
}
```

```java

public class ExcepTest {

   public static void main(String args[]) {
      int a = 3;
      int b = 0;
      try {
         System.out.println("result:" + divide(a,b));
      }catch(ArithmeticException e) {
         System.out.println(e.getMessage());
      }
   }

   private static int divide(int a, int b) {
      return a / b;
   }
}
```

---

# 🧭 15. Summary Table

|Concept|Key Point|
|---|---|
|Exception|Object representing an error|
|Checked Exception|Compile-time, must handle|
|Unchecked Exception|Runtime, optional handling|
|Error|Serious, unrecoverable (JVM errors)|
|throw|To throw exception manually|
|throws|Declares exception in method|
|try-catch-finally|Main structure for handling|
|Custom Exception|Extends `Exception` or `RuntimeException`|
|try-with-resources|Auto-close resources, Java 7+|
|Best Practice|Catch specific exceptions|