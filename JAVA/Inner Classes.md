- In Java, it is also possible to nest classes (a class within a class). The purpose of nested classes is to **group classes that belong together**, which makes your **code more readable and maintainable.**
#### When to Use Inner Classes?

- When the inner class logically belongs to the outer class.
    
- When you want to **hide** the class from outside classes.
    
- For better **encapsulation** and **code organization**.
### 1. Non-Static (regular) Inner classes
- Defined inside a class and associated with an instance of the outer class.
```java
//inner classes: Nested Inner class / non-static inner class
class Outer{
	int x = 10; //outer class variable
	// Inner i = new Inner(); //can also define object first and class later (in java)
	class Inner{
		int y = 69; //inner class variable
		public void innerDisplay(){
			System.out.println("This is the inner class.");
			System.out.println(x); //inner class can access members of outer class directly.
			System.out.println(y);
		}
	}
	//accessing inner class inside the outer class
	
	// public void outerDisplay(){
	 	//instantiating inner class in outer class but can also be done outside the outer class also
	// 	Inner i = new Inner(); //creating object of inner class within the outer class it is defined in and not out of outer class.
	 	//to access inner class data members use reference
	// 	System.out.println(i.y); //for Outer class to access members of inner class, create obj of inner class and use '.'
	// 	i.innerDisplay();
	// }
}

class Test{
	public static void main(String[] args) {
		Outer o = new Outer();
		// o.outerDisplay();
		System.out.println(o.x);

		//to access inner class outside inner class: create outer class obj and then inner class object using outer class '.'
		Outer.Inner i = new Outer().new Inner(); 
		i.innerDisplay();
		System.out.println();
	}
}
```

```plaintext
OUTPUT:

10
This is the inner class.
10
69
```

#### Files created:
- Outer$Inner.class: for inner class 
- Outer.class : for outer class 
- Test.java: main class
---
### 2. Local Inner Class
- A **Local Inner Class** is a class **defined inside a method**, constructor, or even inside a block. It behaves like a **local variable** — meaning:

	- It is **scoped only within the method** where it's declared.
    
	- You **cannot use it outside** the method.
```java
class Outer{
	void outerMethod(){
	 // Local Inner Class declared inside a method
		class LocalInner{
			void innerMethod(){
				System.out.println("Hello from Inner Class");
			}
		}
		
		// Creating object of local inner class inside the method
		LocalInner i = new LocalInner();
		i.innerMethod();
	}
}
class LocalTest {
    public static void main(String[] args) {
        LocalOuter o = new LocalOuter();
        o.outerMethod();  // This will call the method where the local inner class is used
    }
}

```

```plaintext
Ouptut:

Hello from Inner Class
```

#### Notes:
- `LocalInner` is **not accessible** outside the `outerMethod()`. That’s why it's called **local**.

| Feature                       | Description                                                                                      |
| ----------------------------- | ------------------------------------------------------------------------------------------------ |
| **Declared Inside**           | A method, constructor, or block                                                                  |
| **Scope**                     | Only within the method it is defined                                                             |
| **Access to Outer Class**     | ✅ Can access **all** members (even private) of the outer class                                   |
| **Access to Local Variables** | Can **only access final or effectively final** variables from the enclosing method               |
| **Modifiers**                 | Cannot use `private`, `protected`, or `static` modifiers (they are not allowed on local classes) |
#### REAL-WORLD USE CASE:
##### Can a Local Inner Class Extend Another Class / Implement Interface? Yes!
```java
void method() {
    class MyRunnable implements Runnable {
        public void run() {
            System.out.println("Running...");
        }
    }

    Thread t = new Thread(new MyRunnable());
    t.start();
}
```

---
### 3. Anonymous class
- An **anonymous inner class** in Java is a **class without a name** that is **defined and instantiated in a single expression**.

It is used when:

- You need a class **for one-time use** only.
    
- You want to **override methods** of an abstract class or interface quickly.

#### Where is it commonly used?

- **To implement interfaces**
    
- **To extend abstract classes**
    
- **To override methods of concrete classes**

```java
//Anonymous class

//interface
interface Animal{
	void makeSound();
}

//abstract class
abstract class Vehicle{
	abstract void type();
}

//concrete class
class Shape{
	void circle(){
		System.out.println("i am round");
	}
}

class Anonymous{
	public static void main(String[] args) {
//anonymous class implementing interface
		Animal cat = new Animal(){
			public void makeSound(){
				System.out.println("anonymous class implementing interface: meow");
			}
		};
		cat.makeSound();

//anonymous class extending abstract class
		Vehicle car = new Vehicle(){
			public void type(){
				System.out.println("anonymous class extending abstract class: i am a four-wheeler vehicle");
			}
		};
		car.type();

//anonymous class extending concrete class
		Shape s = new Shape(){
			void circle(){
				System.out.println("anonymous class extending conrete class: I have radius");
			}
		};

		s.circle();
	}
}
```

```plaintext
Output:

anonymous class implementing interface: meow
anonymous class extending abstract class: i am a four-wheeler vehicle
anonymous class extending conrete class: I have radius
```

|Area|Use|
|---|---|
|**Event Handling**|GUI apps (e.g., `ActionListener`)|
|**Multithreading**|Thread or Runnable implementation|
|**Short Overrides**|Overriding methods temporarily for one-time logic|

---
### 4. Static Inner Class

A **static inner class** (also called a **static nested class**) is a **nested class declared with the `static` keyword** inside an outer class.

🔹 **It does NOT require an instance of the outer class to be created.**  
🔹 It can access **only static members** of the outer class directly.

| Feature                                                 | Description                                     |
| ------------------------------------------------------- | ----------------------------------------------- |
| **Is it tied to an instance of the outer class?**       | ❌ No                                            |
| **Access to outer class members**                       | ✅ Only `static` members                         |
| **Can be declared `private`, `protected`, or `public`** | ✅ Yes                                           |
| **Can have its own static members**                     | ✅ Yes                                           |
| **Is it compiled as a separate class file?**            | ✅ Yes (like `Outer$StaticInner.class`)          |
| **Common Use**                                          | Helper classes, grouping logic, utility classes |
```java
//static inner class

class Outer{
	static int x = 10; //static variable
	int y = 10; //non static variable

	static class Inner{
		void show(){
			System.out.println("static member of outer class: " + x); // can access
			// System.out.println("non static member of outer class " + y); //compile time error: non-static variable y cannot be referenced from a static context

		}
	}

	static class Another{
		static void display(){
			System.out.println("static class and static method.");
		}
	}
}
class StaticInnerClass{
	public static void main(String[] args) {
		Outer.Inner i = new Outer.Inner();
		i.show();
		Outer.Another.display(); // Direct call to static method of static inner class
	}
}
```
 #### Static vs Non-static inner class
 ![[Pasted image 20250622152656.png]]