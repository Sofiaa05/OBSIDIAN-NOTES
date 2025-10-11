- A ClassCastException is thrown when an attempt is made to cast an object to a subclass type, but the object is actually of the superclass type. This indicates a missing or incorrect type check before casting.
- If a Java class has been modified and not recompiled, attempting to create an object from the class may lead to errors due to the discrepancy between the source and the compiled bytecode.
- A NullPointerException is thrown when an application attempts to use an object reference that has not been initialized and thus **points to no location in memory.**
- Encapsulation can be achieved by making class variables private to hide them from other classes and providing public getter and setter methods to allow controlled access to these variables.
- In Java, **interfaces can contain default methods that have a body.** This allows an interface to provide a default implementation for methods, which implementing classes can override if desired. This feature was introduced in Java 8 to provide more flexibility in interface design.
---
### Q2.   
Identify the mistake in the following Java code snippet:  
```java
class Student {  
	private int score;  
	public static void setScore(int s) {  
		score = s;  
	}  
}

//setScore cannot be static as it accesses an instance variable
```
- Static methods cannot access instance variables directly as they belong to the class, not to any instance unlike instance variables that belong to objects. The method setScore should not be static.
---
### ClassNotFoundException 

```java
class Animal {
    void sound() { System.out.println("Animal sound"); }
}

class Dog extends Animal {
    void sound() { System.out.println("Bark"); }
    void fetch() { System.out.println("Dog fetches ball"); }
}
```

---

## Downcasting Example

Downcasting = converting a **superclass reference** back to a **subclass reference**.  
Needs explicit cast `()` and can be risky (may throw `ClassCastException` if the object is not really of the subclass type).

```java
public class Main {
    public static void main(String[] args) {
        // 🔹 Upcasting first
        Animal a = new Dog();    // Dog → Animal (Upcasting, safe)
        a.sound();               // Bark (runtime polymorphism)

        // 🔹 Now Downcasting
        Dog d = (Dog) a;         // Animal → Dog (Downcasting, explicit)
        d.sound();               // Bark
        d.fetch();               // Dog fetches ball
    }
}
```

Works fine because `a` was really pointing to a `Dog` object.

---

## Unsafe Downcasting (Error Example)

```java
public class Main {
    public static void main(String[] args) {
        Animal a = new Animal(); // real object is Animal
        Dog d = (Dog) a;         // ClassCastException at runtime
        d.fetch();               // program crashes before this line
    }
}
```

At runtime, Java sees: “This object is not a Dog, it’s just an Animal,” so it throws **`ClassCastException`**.

---

