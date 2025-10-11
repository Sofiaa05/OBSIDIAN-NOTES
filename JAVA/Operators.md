
- short, byte (+,-,/,%) = int
- float, long = float
- float, double = double
- int, char = int

![[Pasted image 20250329181355.png]]


---
## Bitwise Operators:
### 1.  Bitwise AND (`&`):

- Returns **1** only if both bits are **1**, else returns **0**
    

| A   | B   | A & B |
| --- | --- | ----- |
| 0   | 0   | 0     |
| 0   | 1   | 0     |
| 1   | 0   | 0     |
| 1   | 1   | 1     |


---

### Bitwise OR (`|`)

- Returns **1** if at least one of the bits is **1**.
    
- Returns **0** only if both bits are **0**.
    

| A   | B   | A \| B |
| --- | --- | ------ |
| 0   | 0   | 0      |
| 0   | 1   | 1      |
| 1   | 0   | 1      |
| 1   | 1   | 1      |


---

### Bitwise XOR (`^`)

- Returns **1** if the bits are **different**.
    
- Returns **0** if the bits are **the same**.
    

|A|B|A ^ B|
|---|---|---|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|


### Summary of Bitwise Operations

| Operator  | Meaning                   | Condition for `1` Output | Example     |
| --------- | ------------------------- | ------------------------ | ----------- |
| `&` (AND) | Both bits must be `1`     | `1 & 1`                  | `5 & 3 = 1` |
| \| (OR)   | atleast one bit must be 1 | At least one bit is `1`  | `1          |
| `^` (XOR) | Bits must be different    | `1 ^ 0` or `0 ^ 1`       | `5 ^ 3 = 6` |

---

## Applications of Bitwise Operators:
### 1. AND (&) Operator:
- To find if a number is even or odd
```java
// to find even or odd using & operator

public class EvenOdd {
    public static void main(String[] args) {
        int num =8;
        if( (num & 1)==0){
            System.out.println("even");
        }
        else{
            System.out.println("odd");
        }
    }
}

```

### 2. XOR (^) Operator:
- To swap two numbers
```java
//swapping two numbers using xor operator
package BitwiseOperators;
public class Swapping{
    public static void main(String[] args) { 

        System.out.println("SWAPPING TWO NUMBERS");
        int a = 10, b=69;
        System.out.println("before swapping: " + a + " " +b);
        a = a^b;
        b = a^b;
        a = a^b;
        System.out.println("after swapping: "+  a + " " +b);

    }
}
```


- To find single unique element in an array
```java
//for finding only one unique element uisng xor operator
package BitwiseOperators;

public class UniqueInArray {
    public static void main(String[] args) {
        int arr[] = {12,12,5,6,5};
        int unique =0;
        for (int num : arr){
            unique ^= num;
        }
        System.out.println(unique);
    }
    
}

//output: 6
```

### 3. Left shift (<<) and Right shift (>>) Operators:
- Multiply or divide with power of 2
```java
//multiply or divide with power of 2 using left shift and right shift operators

public class PowerOf2 {
    public static void main(String[] args) {
        int num = 6;
        System.out.println("6*2 = " + (num<<1));
        System.out.println(" 6/2 = " + (num>>1) );
        System.out.println("6*4 = " + (num<<2));
    }
}

```