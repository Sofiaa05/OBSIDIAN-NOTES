### Definition:
**Multithreading** is a programming concept where **multiple threads run concurrently within a single process to perform multiple tasks at the same time.**

- A **thread** is a lightweight sub-process, the smallest unit of processing.
    
- Java provides built-in support for multithreaded programming.
    
- All Java programs have at least one thread — the **main thread**.

"Threads are called lightweight because they share the **same address space and resources of the process they belong to, resulting in lower memory and CPU overhead** compared to full-blown processes."
### Advantages: 

1. **Efficient CPU Utilization:** Threads can run concurrently on multi-core processors.
    
2. **Improved Performance:** Ideal for I/O-bound or long-waiting tasks (e.g., file download, database fetch).
    
3. **Resource Sharing:** Threads share the same memory space.
    
4. **Responsiveness:** UI or server apps stay responsive while background threads work.
---
### Implementation
### 1. Extending the Thread class
#### In a single class:
```java
//Multithreading Demo extending Thread in single class
public class DemoThread2 extends Thread{
	public void run(){
		int i = 1;
		while(i < 10){
			System.out.println(i + "hello");
			i++;		
		}
	}
	public static void main(String[] args) {
		DemoThread2 t = new DemoThread2(); //create object of class
		t.start(); 
		int i = 1;
		while(i < 5){
			System.out.println(i + "world");
			i++;
		}
	}
}

```

#### In two different classes
```java
//Thread class example with two different classes
class MyThread extends Thread{ //must extend Thread class
	public void run(){ //must override run()
		int i = 1;
		while(true){
			System.out.println(i + "hello");
			i++;
		}
	}
}
public class DemoThread{
	public static void main(String[] args) {
		MyThread t = new MyThread(); //must create object of thread
		t.start(); //calling run() method using start() not t.run()

		int i = 1;
		while(true){
			System.out.println(i + "world");
			i++;
		}
	}
}
```

---
### 2. Implementation with Runnable Interface
####  In a single class
```java
//Multithreading example using Runnable Interface in a single class
class DemoThread4 implements Runnable{
	public void run(){
		int i = 1;
		while(i < 6){
			System.out.println(i + "hello");
			i++;
		}
	}

	public static void main(String[] args) {
		DemoThread4 d = new DemoThread4(); //obj of class
		Thread t = new Thread(d); //obj of Runnable Interface
		t.start();
		int i = 1;
		while(i < 6){
			System.out.println(i + "world");
			i++;
		}
	}
}
```

#### In two different classes
```java
//Multithreading implementation with Runnable Interface
class MyThread implements Runnable{
	public void run(){
		int i = 1;
		while(i < 5){
			System.out.println(i + "hello");
			i++;
		}
	}
}

public class DemoThread3{
	public static void main(String[] args) {
		MyThread m = new MyThread(); //obj of class implementing Runnable
		Thread t = new Thread(m); // obj of class Thread
		t.start();
		int i = 1;
		while(i < 5){
			System.out.println(i + "world");
			i++;
		}
	}
}
```

---
### 3. Lambda Expression (Java 8+)
```java
public class Demo {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            System.out.println("Thread running using Lambda.");
        });
        t1.start();
    }
}
```