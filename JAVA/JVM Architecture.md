
#### Magician Analogy used:
- magician is the program  (method area)
- chairs for audience already arranged in the hall like variables used in program(stack)
- extra chairs arranged in corner one over other for people who join in between the program (heap)
- people may leave before the end of program and their chairs will be picked up by the garbage collector from the heap.

![[Pasted image 20250329124913.png]]

---
### What is JVM?
- Executes byte code.
- Responsible for calling main method.
- Part of JRE
- Other languages that support the JVM architecure (aka JVM languages): Scala, Kotlin and Groovy
#### Features:
1. Platform independence: WORA
2. Memory management: memory allocation and automatic garbage collection
3. Security
#### Virtual Machine:
A **Virtual Machine (VM)** is like a **fake computer inside your real computer**. It lets you run different operating systems or programs **without affecting your actual system**.

JVM is a **special virtual machine** made just for running **Java** programs

## JVM has 3 different components:

![[Pasted image 20250329141014.png]]
### 1. Class Loader :
- `.java` file to `.class` after compiling.
- When you try to use this class in your program, the **class loader loads it into the main memory.**
- The **first class** to be loaded is the one containing `public static void main(String[] args)`.

![[Pasted image 20250329141301.png]]

#### 3 Phases :
#### 1. Loading  (1st phase):
- The **Class Loader** loads the `.class` file (bytecode) into memory.
    
- This creates a **run-time representation** of the class in the **Method Area** of JVM memory.
    
- Memory allocation for methods and static variables is done here.

##### Types of class loaders :
##### 1. Bootstrap Class Loader:
- First classloader, superclass of extension class loader.
- It loads the **rt.jar file** that contains all class files of Java Standard Edition packages (`java.lang`, `java.net`, `java.util`, `java.io`)
##### 2. Extension Class Loader:
- Subclass of Bootstrap Class Loader and superclass of Application Class Loader. 
- Responsible for **loading extensions of standard Java libraries** from the `ext` directory of the JDK/JRE.
- Allow developers to extend the Java platform without modifying core classes.
- Removed in **Java 9** as part of the **module system**. It was replaced by the **Platform Class Loader**
##### 3. Application/System Class Loader: 
- Final class Loader and subclass of Extension Class Loader
- loads class files that are part of your applicaiton (`.class`).

```Plaintext
The JVM follows a Delegation Model for class loading:

1. Application requests a class (e.g., `javax.crypto.Cipher`).
    
2. The Bootstrap Class Loader tries to load it first.
    
3. If not found, the Extension Class Loader checks in `lib/ext/`.
    
4. If still not found, the Application Class Loader loads it from the classpath (`CLASSPATH`).
    
5. If none of the loaders find the class, JVM throws ClassNotFoundException.

```

---

#### Linking (2nd Phase):
- After a class is loaded into the main memory, it undergoes **linking** process
- Linking ensures that the loaded **class is valid, dependencies are resolved, and memory is allocated** before execution.
##### Follows steps:
##### 1. Verification:
- Checks the structural correctness of the `.class` file by checking it against a set of constraints or rules using **ByteCode Verifier.**
- Ensures the `.class` file is **valid and safe** to execute.
###### Example:
- if the code has been built using Java 11, but is being run on a system that has Java 8 installed, the verification phase will fail.
##### 2. Preparation:
- Allocates **memory for static variables** and assigns default values.
    
- **Does NOT initialize values** yet (that happens in Initialization).
###### Example:
```java
class Example {
    static int x = 5;  // Static variable
}
```

- Memory is allocated for x in the Method Area.
- `x` is set to its default value (0 for int, null for objects).
- The actual value 5 is assigned later in the Initialization phase.
##### 3. Resolution:
- Converts **symbolic references** into **actual memory addresses**.
    
- Resolves references to **other classes, methods, and variables**.
    
###### Example:

```java
class A {
    static int num = 10;
}
class B {
    void printNum() {
        System.out.println(A.num); // Resolution happens here
    }
}
```


 - `A.num` is stored as a **symbolic reference** initially.  
- In Resolution, JVM **finds `A.num` in memory** and replaces the reference.
---
#### Initialisation (3rd Phase):
- Assign actual values of static variables
- static blocks are executed in order.
- Superclass initialization happens first, then subclasses.
```plaintext
Initialisation happen when:
 - an object is created
 - static variables or static methods is accessed
```

---
---
### 2. Runtime Data Areas
![[Pasted image 20250329145604.png]]

#### 1. Method Area:
- Stores **class-level data** (e.g., class names, method names, static variables, constructor).  
- Shared among all threads.
- One method area per JVM
#### 2. Heap Area:
- Stores **objects their instance variables and arrays**.  
- Shared among all threads.
- One heap area per JVM
```plaintext
Note: Since the Method and Heap areas share the same memory for multiple threads, 
the data stored here is not thread safe.
```

#### 3. Stack Area:
- For every method call, one entry is made in the stack memory which is called the **Stack Frame**
- Stores **method-specific data** for each thread.
- All local variables, method calls, and partial results are stored in the stack area.
```plaintext
Note: Since the Stack Area is not shared, it is inherently thread safe.
```

#### 4. Program Counter (PC) Registers:
- Hold the address of the currently executing JVM instruction. After being executed, the PC register is updated with the next instruction.
- Each thread has its own PC register.
#### 5. Native Method Stack:
- Contains stacks that support  **native methods** (methods written in languages other than java such as C, C++ etc.)
-  For every new thread, a separate native method stack is also allocated.
---
---
### 3. Execution Engine
- execute the compiled Java bytecode.
- Before execution, it takes the compiled byte code (`.class`) and converts it to machine code for the underlying system using either an Interpreter or JIT Compiler
#### 1. Interpreter:
- Reads and executes the bytecode instructions line by line. (slower)
- when a method is called multiple times, every time a new interpretation is required.
#### 2. Just-In-Time (JIT) Compiler:
- Interpreter executes the byte code, but when it finds some repeated code, it uses the JIT compiler.
- The JIT compiler then compiles the entire bytecode and changes it to native machine code.
- This native machine code is used directly for repeated method calls, which improves the performance of the system, by skipping interpretation for common methods!
#### 3. Garbage Collector:
- Collects and removes unreferenced objects from the heap area to reclaim runtime unused memory.
- Done automatically by the JVM at regular intervals and does not need to be handled separately. 
- Can be called manually using`System.gc()`.

 ##### It involves two phases:

1. **Mark -** GC identifies the unused objects in memory
2. **Sweep -**  GC removes the objects identified during the previous phase

---
---
### 4. Native Method Interface (Java Native Interface (JNI)):
- **bridge** that allows Java applications to interact with **native code** written in **C, C++, or assembly**.
- Since Java runs inside the **JVM** and is platform-independent, it cannot directly call system-level code. JNI helps in accessing **platform-specific functionality**
- cases where we need to interact with hardware, or to overcome the memory management and performance constraints in Java. 
- Java supports the **execution of native code via the Java Native Interface (JNI)**.
--- 
---
### 5. Native Method Libraries:
- Native method libraries (libraries written in other languages than java) are used by Java applications through **JNI (Java Native Interface)** to execute platform-specific tasks.
- These are collections of native libraries required for executing native methods