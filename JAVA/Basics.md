- Owned by **Oracle**
- Case-sensitive
### Features of Java:

#### 1. Simple and easy to learn

- similar syntax to C and C++ but without complex features like pointers and operator overloading.

#### 2. Object-Oriented

- Follows OOP paradigm which helps in organizing code into reusable objects and OOPs features

#### 3. Platform-Independent (Write Once, Run Anywhere - WORA)

- Java code is compiled into **bytecode**, which runs on the **Java Virtual Machine (JVM)**, which is specific to each operating systems. 

#### 4. Secure

- **No Use of Pointers:** which prevents direct access to memory locations.
- **ByteCode Verifier:** prevents malicious code from executing.
- **Security Manager** that defines access controls for Java programs.
- **Automatic Memory management:** Garbage collection (prevents memory leaks, reduce security flaws caused by memory handling)

#### 5. Robust (Strong & Reliable)

- Java handles runtime errors using **exception handling** that guarantees program keeps executing even if there is an unavailability of resources unless and until user stops the program.

#### 6. Multithreading

- Java allows the execution of multiple threads simultaneously to improve performance.

#### 7. Architecture-Neutral

- Java programs do not depend on hardware architecture, making them portable across different machines.

#### 8. Portable

- Java code can be easily moved from one system to another because of its platform independence. 

#### 9. High Performance

- Java is not as fast as C/C++, but **Just-In-Time (JIT) Compiler** improves its speed by converting bytecode into native machine code at runtime.

#### 10. Distributed

- Java has built-in support for distributed computing using technologies like **RMI (Remote Method Invocation) and EJB (Enterprise JavaBeans)**.

#### 11. Dynamic

- Java supports dynamic memory allocation and loading of classes at runtime.

#### 12. Extensive Library Support

- Java provides a rich set of APIs for data structures, networking, database connectivity, etc.


---


```java
import java.lang.*; //import package 
public class First{ 
	public static void main(String args[]){
		System.out.println("Hello world"); 
		System.out.println(args[0]);
		System.out.println(args[1]);
	}
}

/* compile: javac First.java
java First
Output:
java First cmdLinearg1 cmdLineArg2
Hello world
cmdLinearg1
cmdLineArg2 */
```

#### Explanation: 
```sh
javac First.java  # Compiles First.java to First.class
java First        # Runs the compiled Java program
```
###  Java’s File Naming Rule for Public Classes 

In Java, if a class is declared as `public`, the **filename must match the class name exactly**, because: 

- The Java compiler (`javac`) looks for a file that matches the `public` class name, else the compiler gets confused and throws an error.
- The file name should or should not be same as the class name.
- Mandatorily to be same name as class name when class is declared public.

|Case|Will it work?|
|---|---|
|File: **First.java**, Class: `public class First`|✅ Yes|
|File: **Second.java**, Class: `public class First`|❌ No (Error)|
|File: **Second.java**, Class: `class First` (No `public`)|✅ Yes|

---

### Main() method :

```java
public static void main(String[] args)
```

| **Part**            | **Meaning**                                                                                   |
| ------------------- | --------------------------------------------------------------------------------------------- |
| **`public`**        | Anyone (Java) can call this method. It must be public so Java can run it.                     |
| **`static`**        | No need to create an object to run it. Java can run it directly.                              |
| **`void`**          | This method does **not** return any value.                                                    |
| **`main`**          | This is the **name** of the method. Java looks for `main()` to start.                         |
| **`String args[]`** | Stores any **extra words** given when running the program (not required for simple programs). |

---


```java
System.out.println()
```
`println()` is a method of object `out` which is an object of class `System`.

| **Part**        | **Meaning**                                                                |
| --------------- | -------------------------------------------------------------------------- |
| **`System`**    | A built-in Java class that provides system-related functions.              |
| **`out`**       | An object inside `System` that represents the **console output** (screen). |
| **`println()`** | A method that prints the text and moves to the next line.                  |

---
### To see all the methods given in a built in class
```java
// javap java.<pkgName>.<className>

javap java.lang.System
javap java.util.Scanner
```
---
### Taking input from user
```java
import java.util.Scanner;
Scanner s = new Scanner (System.in);
```

| **Part**               | **Meaning**                                         |
| ---------------------- | --------------------------------------------------- |
| **`Scanner`**          | A built-in Java class that allows us to take input. |
| **`s`**                | The name of the Scanner object (you can change it). |
| **`new Scanner(...)`** | Construct to create a new Scanner object.           |
| **`System.in`**        | Represents the **keyboard input (console)**.        |

---
### Compiler vs Interpreter:
- We generally write a computer program using a high-level language. A high-level language is one that is understandable by us, humans. This is called **source code**.


- However, a computer does not understand high-level language. It only understands the program written in **0**'s and **1**'s in binary, called the **machine code**.


- To convert source code into machine code, we use either a **compiler** or an **interpreter**, but they work differently.

| Feature               | Compiler                                                             | Interpreter                                    |
| --------------------- | -------------------------------------------------------------------- | ---------------------------------------------- |
| **Translation**       | Translates the entire code at once and then execute the entire code. | Translates and executes line by line           |
| **Execution Speed**   | Faster (since it's pre-compiled)                                     | Slower (because it executes as it translates)  |
| **Error Detection**   | Detects all errors at once after compilation                         | Stops execution at the first error             |
| **Example Languages** | C, C++ (compiles to bytecode)                                        | Python, JavaScript, PHP                        |
| **Output**            | Generates a separate executable file with an extension of (.exe)     | Does not create a separate file, runs directly |


In programming languages like C and C++, the code is first compiled into **platform-specific machine code**. These languages are called _compiled languages_.

On the other hand, in languages like JavaScript and Python, the computer executes the instructions directly without having to compile them. These languages are called _interpreted languages_.
#### Java: Both Compiler & Interpreter

Java uses both:

1. **Compiler (`javac`)**: Converts Java code into bytecode (`.class` file).
    
2. **Interpreter (`java`)**: The JVM (Java Virtual Machine) interprets the bytecode and executes it.