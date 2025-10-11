
| **Data Type** | **Size (in bytes)** | **Description**                                                | **Number of Whole Numbers Stored**                         |
| ------------- | ------------------- | -------------------------------------------------------------- | ---------------------------------------------------------- |
| **byte**      | 1                   | -128 to 127                                                    | **256** (127 - (-128) + 1)                                 |
| **short**     | 2                   | -32,768 to 32,767                                              | **65,536** (32,767 - (-32,768) + 1)                        |
| **int**       | 4                   | -2,147,483,648 to 2,147,483,647                                | **4,294,967,296**                                          |
| **long**      | 8                   | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807        | **18,446,744,073,709,551,616**                             |
| **float**     | 4                   | Stores fractional numbers. Precison upto 6 to 7 decimal digits | **N/A** (Not for whole numbers)                            |
| **double**    | 8                   | Precision upto 15 to 16 decimal digits                         | **N/A** (Not for whole numbers)                            |
| **boolean**   | (JVM Dependent)     | Stores `true` or `false` values                                | **2** (`true` and `false`)                                 |
| **char**      | 2                   | Stores a single character/letter or Unicode values             | **65,536** (0 to 65,535, as `char` is **unsigned 16-bit**) |

##### Use `float` or `double`?

The **precision** of a floating point value indicates how many digits the value can have after the decimal point. (safer to use double)

##### Java char takes 2 bytes :
- Uses UNICODE (UTF-16), to support all languages and symbols.
- Earlier Languages used 1 byte as they used ASCII characters only.

----
### Primitive vs Non-Primitive Data Types
|**Feature**|**Primitive Types**|**Non-Primitive Types**|
|---|---|---|
|**Definition**|Predefined and built into Java|Created by the programmer (except `String`)|
|**Method Usage**|Cannot call methods|Can call methods to perform operations|
|**Naming Convention**|Starts with a **lowercase** letter (e.g., `int`, `char`)|Starts with an **uppercase** letter (e.g., `String`, `ArrayList`)|
|**Storage**|Always holds a value|Can be **null** (no reference)|

---

## Java Type Casting

- Type casting is when you assign a value of one primitive data type to another type.
- In Java, there are two types of casting:
	
	**Widening Casting** (automatically) - converting a smaller type to a larger type size  
	    `byte` -> `short` -> `char` -> `int` -> `long` -> `float` -> `double`  
	      
	    
	 **Narrowing Casting** (manually) - converting a larger type to a smaller size type  
	    `double` -> `float` -> `long` -> `int` -> `char` -> `short` -> `byte`
	    
![[Pasted image 20250329210759.png]]
![[Pasted image 20250329210933.png]]

---
### To convert string to int
-  using `Integer.parseInt()` method

```java
String str = "123";
int number = Integer.parseInt(str);
System.out.println(number); // Output: 123

```

- `Integer.parseInt()` returns **primitive** `int`
    
- For **Integer object**, use `Integer.valueOf()`
```java
Integer obj = Integer.valueOf("123");
```