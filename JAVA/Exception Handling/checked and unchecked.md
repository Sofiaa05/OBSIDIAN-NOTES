### Checked Exceptions:
- Checked exceptions are checked at compile time.
- You must either handle them using try-catch or declare them using throws.

```java
import java.io.FileReader;
import java.io.IOException;

public class CheckedExample {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("example.txt"); // file doesn't exist
            System.out.println("File is ready");
        } catch (IOException e) {
            System.out.println("Error: File not found or can't be read.");
        }
    }
}
```

**🔍 Explanation:**
- FileReader can throw IOException (a checked exception)

- You must handle it using try-catch or declare throws IOException

- If you don’t, the code will not compile
---
### Unchecked Exception

- Unchecked exceptions are not checked at compile time.
- You don’t have to catch or declare them — but you can if you want.

```java
public class UncheckedExample {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;

        try {
            int result = a / b; // division by zero
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        }
    }
}
🔍
```
 ##### Explanation:
- Dividing by zero causes an ArithmeticException (unchecked)

- You don’t have to catch it, but catching it avoids crashing

---
![[Pasted image 20250627180254.png]]

### checked

| Exception Class                | Description                                                        |
| ------------------------------ | ------------------------------------------------------------------ |
| **IOException**                | General input/output errors (e.g., file not found, stream errors)  |
| **FileNotFoundException**      | File doesn’t exist when trying to read it                          |
| **SQLException**               | SQL/database access errors                                         |
| **ParseException**             | Errors while parsing text into dates or numbers                    |
| **ClassNotFoundException**     | When trying to load a class that’s not found                       |
| **CloneNotSupportedException** | If an object doesn't implement `Cloneable` and you try to clone it |
| **InterruptedException**       | When a thread is interrupted during sleep/wait                     |
| **InstantiationException**     | When trying to instantiate an abstract class or interface          |
| **NoSuchMethodException**      | When a method does not exist via reflection                        |
| **MalformedURLException**      | Invalid URL format                                                 |
| **URISyntaxException**         | URI format is incorrect                                            |
| **TransformerException**       | Errors while transforming XML                                      |

### unchecked

| Exception Class                                      | Description                                               |
| ---------------------------------------------------- | --------------------------------------------------------- |
| **ArithmeticException**                              | E.g., divide by zero                                      |
| **NullPointerException**                             | Accessing methods/fields on `null`                        |
| **ArrayIndexOutOfBoundsException**                   | Accessing invalid array index                             |
| **StringIndexOutOfBoundsException**                  | String index is invalid                                   |
| **NumberFormatException**                            | Invalid number format in parsing (e.g., `"abc"` to `int`) |
| **IllegalArgumentException**                         | Argument passed to method is inappropriate                |
| **IllegalStateException**                            | When an object is in an illegal or inappropriate state    |
| **ClassCastException**                               | Invalid type casting                                      |
| **NegativeArraySizeException**                       | Trying to create an array with negative size              |
| **UnsupportedOperationException**                    | Operation not supported by the collection                 |
| **ConcurrentModificationException**                  | Modifying a collection while iterating                    |
| **StackOverflowError** (⚠️ technically an **error**) | Infinite recursion or deep call stack                     |

### Q: Why are unchecked exceptions not required to be caught?

- Unchecked exceptions usually represent **programming errors** like bad logic or null access. 
- Java doesn’t enforce their handling because it expects developers to **fix the root cause** rather than mask it with exception handling. This promotes cleaner, more maintainable code and helps identify bugs early.