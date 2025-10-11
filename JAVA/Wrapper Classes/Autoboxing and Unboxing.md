###  What is Autoboxing?

**Autoboxing** is the automatic conversion of a **primitive type to its corresponding wrapper class object**.

#### ✅ Example:

```java
int num = 10;
Integer obj = num;  // Autoboxing: primitive int → Integer object
```

---

### 🟣 What is Unboxing?

**Unboxing** is the reverse process—**automatically converting a wrapper class object back to its primitive type**.

#### ✅ Example:

```java
Integer obj = 20;
int num = obj;  // Unboxing: Integer object → primitive int
```

---

### Combined Example:

```java
public class Main {
    public static void main(String[] args) {
             int x = 10;
       Integer y = Integer.valueOf(x); //wrapping / boxing
       System.out.println(y);
       
       int z = y.intValue(); //unwrapping / unboxing
       System.out.println(z);

		//autoboxing and auto unboxinh
       int num = 69;
       Integer numObj = num; //autoboxing
        System.out.println(numObj);

       int numPrim = numObj; //autounboxing
        System.out.println(numPrim);

```

---

### Behind the Scenes

The compiler converts:

```java
Integer wrapper = 5;
```

into:

```java
Integer wrapper = Integer.valueOf(5);  // Autoboxing
```

And:

```java
int num = wrapper;
```

into:

```java
int num = wrapper.intValue();  // Unboxing
```

---

### ✅ Why It Matters

1. **Simplifies code**: You don’t have to call `.valueOf()` or `.intValue()` explicitly.
    
2. **Used with collections**: Collections like `ArrayList<Integer>` can only hold objects, so autoboxing is required when you add primitive values.
    