- provides a erapper around primitives, so that the primitives become classes and we can create objects.
- available for every kind of primitive data type 

![[Pasted image 20250712235118.png]]
#### What are Wrapper Classes?

- In Java, **wrapper classes** are used to **wrap primitive data types into objects**. 
- Java is an object-oriented language, and sometimes you need to treat primitives like objects—for example, when working with **collections** (like `ArrayList`, `HashMap`, etc.) that only store objects, not primitives.

#### Why are Wrapper Classes Needed?

1. **Object-Oriented Features**: Primitives like `int`, `char`, etc., are not objects. If you want to store them in collections or use them with methods that require objects, you need wrappers.
    
2. **Utility Methods**: Wrapper classes provide many useful methods for parsing, converting, comparing, etc.
    
3. **Null Support**: Primitives can't be null, but wrappers can. This is helpful in databases or conditional logic.
    
4. **Autoboxing and Unboxing**: Java automatically converts primitives to wrapper objects and vice versa when needed
    

---

### 🟨 List of Primitive Types and Their Wrapper Classes

|**Primitive Type**|**Wrapper Class**|
|---|---|
|`byte`|`Byte`|
|`short`|`Short`|
|`int`|`Integer`|
|`long`|`Long`|
|`float`|`Float`|
|`double`|`Double`|
|`char`|`Character`|
|`boolean`|`Boolean`|

---

### ✅ Example

```java
int x = 5;
Integer y = Integer.valueOf(x);  // Wrapping (Boxing)
int z = y.intValue();            // Unwrapping (Unboxing)
```

> In modern Java, you can just write:

```java
Integer y = x;   // Autoboxing
int z = y;       // Auto-unboxing
```
