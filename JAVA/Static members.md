- The `static` keyword in Java means **"belonging to the class instead of an instance"**.

![[Pasted image 20250622164718.png]]

### 1. Static Variable
- A variable declared with `static` belongs to the **class**, not to instances (objects). 
- All objects **share** the same variable.
### 2. Static Methods
- A method declared as `static` belongs to the class and can be called **without creating an object**.

### ✅ Rules:

- Can **only access static variables** directly.
    
- Cannot access **non-static members** unless you create an object.
    
- **Cannot use `this` or `super`** keywords inside static methods as they are used to refer to instances not classes.
```java
//static 

class Demo{ //only inner classes can be static not the outer classes
	static int x = 20;
	int y = 69;

	void show(){
		System.out.println(x + " " + y); //can access both static and non static data members
	}

	static void display(){
		System.out.println(x); //cannot access y as it is non static member
	}
}

public class StaticPractice{
	public static void main(String[] args) {
		Demo d1 = new Demo();
		d1.show(); //instance method
		//modifying values for x and y using instance
		d1.x = 30; //static 
		d1.y = 50; //non-static

		Demo d2 = new Demo();
		d2.show(); //x isupdated while y remains same as static members are shared among all instances of a class


		Demo.display();  //static method
	}
}
```

```plaintext
Output:

20 69
30 69
30
```

---
### 3. Static Block (not used commonly)
- A **static block** is used to **initialize static variables**. 
- It runs **once** when the class is **first loaded** (before `main` or constructor).
```java
//static blocks

class StaticBlock{
	static int x;

	static{
		x = 30;
		System.out.println(x);
		System.out.println("static vlock called");
	}
}
class StaticBlockMain{
	static{
		System.out.println("this will be executed first before main");
	}
	
	public static void main(String[] args) {
		StaticBlock s = new StaticBlock();
	}
}
```

```plaintext
Output:

this will be executed first before main
30
static vlock called
```

### 4. Static nested classes
[[Inner Classes]] (scroll to last)

### Real-Life Analogy

Imagine a **classroom**:

- `static` variable = whiteboard (shared by everyone)
    
- `non-static` variable = individual notebook (personal)
    
- `static` method = general announcements (don’t need to call each student)
    
- `non-static` method = asking a student for their name
---
