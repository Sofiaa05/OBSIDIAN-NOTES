### What is Dependency Injection?

- **Dependency Injection (DI)** is a design principle to **decouple dependencies** between objects.
- Instead of an object creating or managing its dependencies directly, those dependencies are **provided (injected) from outside**.
- This helps in making the code more flexible, maintainable, and testable.

---

### Example: Drawing Application with Shapes

1. **Initial Approach (Tight Coupling):**
   - An `Application` class directly creates instances of specific shapes like `Triangle` or `Circle`.
   - Example:
     ```java
     Triangle triangle = new Triangle();
     triangle.draw();
     Circle circle = new Circle();
     circle.draw();
     ```
   - Problem: The application class is tightly coupled to specific shape classes.

2. **Using Polymorphism:**
   - Introduce a `Shape` interface or abstract class with a `draw()` method.
   - `Triangle` and `Circle` implement/extend `Shape` and override `draw()`.
   - The application class uses a `Shape` reference:
     ```java
     Shape shape = new Triangle();
     shape.draw();
     shape = new Circle();
     shape.draw();
     ```
   - This allows polymorphism but still requires the application class to instantiate specific shapes, so dependency is still hardcoded.

3. **Passing Shape as a Parameter:**
   - Create a method that accepts a `Shape` object and calls its `draw()` method.
   - This method doesn't care about the specific shape type.
   - However, somewhere else in the code, the shape object still needs to be instantiated explicitly.
```java
public void myDrawMethod (Shape shape) {
	shape.draw();
}

//somehere in class
Shape shape = new Triangle();
myDrawMethod(shape);
```
3. **Removing Dependency from the Class (Dependency Injection):**
   - Create a `Drawing` class with a private `Shape` member.
   - Provide a **setter method** to inject the `Shape` object:
```java
protected class Drawing {
	private Shape shape;
	
	 public void setShape(Shape shape) {
         this.shape = shape;
     }
     
     public void drawShape() {
         shape.draw();
     }
}

```
   - The `Drawing` class no longer creates or knows about specific shapes.
   - Another class is responsible for creating the shape instance and injecting it into `Drawing`.
   - This **separates the creation of dependencies from their usage**.

```java
Triangle triangle = new Triangle();
setShape(triangle);
drawing.drawShape();
```
---

### Benefits of Dependency Injection

- The `Drawing` class is **open for extension but closed for modification** — you can add new shapes without changing the `Drawing` class.
- The dependency (which shape to draw) is **injected from outside**, so the class is not tightly coupled to any specific implementation.
- This makes the code more modular, easier to test, and maintain.

---

### How Spring Helps

- Spring Framework automates this process.
- Instead of manually writing code to instantiate and inject dependencies, you **configure Spring** to manage object creation and injection.
- Spring **injects the right dependencies** into the right classes automatically.
- This reduces boilerplate code and improves application design.

---

### Summary

Dependency Injection is a design pattern that helps decouple classes by injecting their dependencies from outside rather than creating them internally. Using interfaces and polymorphism, you can write flexible code that works with any implementation of a dependency. Spring Framework simplifies this by managing the lifecycle and injection of dependencies for you.
