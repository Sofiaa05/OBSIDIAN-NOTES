
A **package** in Java is a **namespace** that organizes a set of related classes and interfaces. Think of it as a folder in your computer that contains related files.

### Benefits:

- Avoids **name conflicts** (e.g., multiple `Employee` classes in different packages)
    
- Makes it easier to locate and use classes
    
- Provides **access protection**
    
- Supports **modular programming**
    

---

## 🔷 2. **Types of Packages**

### A. **Built-in Packages**

Provided by Java itself. Examples:

```java
import java.util.*; import java.io.*; import java.net.*;
```

### B. **User-defined Packages**

Created by the programmer to group related classes.

---

## 🔷 3. **Creating a User-defined Package**

### 📁 Step-by-Step Example:

📄 File: `MyClass.java`

```java
package mypack;

public class MyClass {
    public void show() {
        System.out.println("Hello from mypack!");
    }
}
```


🔧 **Compile:**

```java
javac -d . MyClass.java 
```


---

## 🔷 4. **The `package` Keyword**

Placed at the top of a Java file to declare the package:

```java
`package mypackage;`
```


📝 Rules:

- Must be the first non-comment line
    
- Only one package statement per file
    
---

## 🔷 5. **The `import` Statement**

Used to import other packages/classes:
```java
import java.util.Scanner; 
import mypack.MyClass;`
```


🛑 You can also use wildcards:
```java
import java.util.*; // Imports all classes from util`
```


---

## 🔷 6. **Access Modifiers and Packages**

### 📌 `Default (no modifier):`

- Accessible **only within the same package**
    

### 📌 `public`:

- Accessible **from any package**
    

### 📌 `protected`:

- Accessible in:
    
    - The same package
        
    - Subclasses in **any** package
        

### 📌 `private`:

- Accessible **only within the class**
    

---

## 🔷 7. **Sub-Packages in Java**

Java uses dot notation for **sub-packages**:

✔ A sub-package is **not** automatically imported with the parent.


---
```java
//Demo.java
public class Main {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
    }
}

//Compiled using: javac -d . Demo.java
//creates a folder named 'mypack' in your current directory and class Demo.class is placed in it.

//Demo2.java
package mypack1;

public class Demo2{
	public void display(){
		System.out.println("welcome to Demo2");
	}
}

//same as above

//Demo3.java
package mypack1.inner;

public class Demo3{
	public void display(){
		System.out.println("Welcome to Demo3");
	}
}
//same as above
//Packages/mypack1/inner (file location of Demo.class)

//Test.java
import mypack1.Demo;
import mypack1.Demo2;
import mypack1.inner.Demo3;


public class Test{
	public static void main(String[] args){
		Demo d1 = new Demo();
		d1.display();

		Demo2 d2 = new Demo2();
		d2.display();

		Demo3 d3 = new Demo3();
		d3.display();
	}
}

```

```md
welcome to display
welcome to Demo2
Welcome to Demo3
```
---

## 🔷 8. **Static Import**

Allows you to import static members directly:

java

CopyEdit

`import static java.lang.Math.*;  public class Main {     public static void main(String[] args) {         System.out.println(sqrt(25)); // no Math. needed     } }`

---

## 🔷 9. **Fully Qualified Name (FQN)**

Instead of importing, you can use the class’s full name:
```java
public class Main {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
    }
}
```


---

## 12. **Package Naming Conventions**

Use **reverse domain names** to avoid name clashes:

```java
package com.example.project.module;
```
✔ Avoid capital letters  
✔ Use short and meaningful names

---

## 🔷 13. **Best Practices**

- Keep related classes in the same package
    
- Do not overuse wildcard imports (`import java.util.*`)
    
- Follow Java naming conventions
    
- Use sub-packages to break large packages into logical units
    
- Separate **API** classes from **implementation** classes using packages
    



---

