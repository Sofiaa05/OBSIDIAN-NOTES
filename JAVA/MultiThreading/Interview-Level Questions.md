
### 💬 Q1: What is the difference between process and thread?

✅ **Answer:**  
A **process** is an independent executing instance with its own memory, while a **thread** is a lightweight sub-part of a process that shares memory with other threads in the same process.

---

### 💬 Q2: Why is multithreading important?

✅ **Answer:**  
Multithreading enhances performance by allowing concurrent execution, makes programs responsive, and makes better use of CPU resources especially in multi-core systems.

---

### 💬 Q3: How does thread communication happen in Java?

✅ **Answer:**  
Using `wait()`, `notify()`, and `notifyAll()` methods which are defined in the `Object` class, threads can coordinate by pausing and resuming execution based on shared conditions.

---

### 💬 Q4: What is the difference between `Runnable` and `Thread`?

✅ **Answer:**

- `Thread` is a class; you inherit and override `run()`.
    
- `Runnable` is an interface; more flexible as it allows implementing multiple interfaces and extending other classes.
    

---

### 💬 Q5: What happens when you call the `run()` method instead of `start()`?

✅ **Answer:**  
It runs in the **main thread**, not as a separate thread. So no concurrency is achieved — the thread code runs like a normal method.

---

### 💬 Q6: What is thread starvation?

✅ **Answer:**  
When a thread waits indefinitely to gain access to resources because other threads are continuously acquiring them — often due to poor thread scheduling or priority management.