- **execute a block of code multiple times** until a specific condition is met.
## 1. For Loop:
- **`for` loop** – Used when the number of iterations is known.

```java
	public class ForLoopExample {
    public static void main(String[] args) {
        for(int i = 1; i <= 5; i++) {
            System.out.println(i);
        }
    }
}
```

```plaintext
OUTPUT: 
1  
2  
3  
4  
5  
```

###  Variations of `For` Loop
### 1.1 Multiple Variables in `for` loop:
- Both loops will end with the loop ending first.
```java
for(int i = 1, j = 5; i <= 5 && j >= 1; i++, j--) {
    System.out.println("i: " + i + ", j: " + j);
}
```

```plaintext
OUTPUT:

i: 1, j: 5  
i: 2, j: 4  
i: 3, j: 3  
i: 4, j: 2  
i: 5, j: 1  

```

### 1.2  Infinite `for` Loop:
- will never stop.
```java
for(;;) {  
    System.out.println("Infinite loop!");  
}

```

### 1.3 Omitting parts of `for` loop:
- without initialisation and condition
```java
int i = 1; //omitting this will not run the program
for(; i <= 5;) { // Only condition is present and omitting this will print infinite loop
    System.out.println(i);
    i++; // Manual update inside loop and omitting this will print an infinite loop
}
```

```plaintext
OUTPUT:

1  
2  
3  
4  
5 
```

### 1.4 Changing initialisation
```java
	System.out.println("Different initialisation condition: ");
	int k=0;
	for(System.out.println("hi"); k<3; k++ ){
		System.out.println(k);
	}
```

```plaintext
OUTPUT:

hi
0
1
2

```

---
## 2. While loop (Best for unknown iterations)
- **condition is checked first**, so the loop may not run at all.
```java
i=0;
while(i<5){
	System.out.println(i);
	i++;  // Increment inside loop
}
```

```plaintext
Output:

0
1
2
3
4
```

### Variations of `While` loop:
### 1. Infinite while loop:
```java
while(true){
	System.out.println("Loop runs forever");
}

//any statement written after this infinite loop statement will give error "unreachable statement."
```

### 2. Using while for input validation:
```java
//input validation using while
Scanner sc= new Scanner(System.in);
System.out.println("Enter a positive number: ");
int num = sc.nextInt();
while(num<0){
	System.out.println("Invalid number, Enter again: ");	
}
System.out.print(num);

```

```plaintext
OUTPUT:

Enter a positive number: 
-69
Invalid number, Enter again: 
69
69% 
```

---

## 3. `do-while` Loop:
```java
public class DoWhileExample {
    public static void main(String[] args) {
        int i = 1;
        do {
            System.out.println(i);
            i++;
        } while(i <= 5);
    }
}

```

```plaintext
OUTPUT:

1  
2  
3  
4  
5
```

### Difference Between `while` and `do-while`

|Feature|`while` Loop|`do-while` Loop|
|---|---|---|
|**Execution Check**|Condition is checked **first**|Condition is checked **after execution**|
|**Minimum Execution**|May run **0 times**|Runs **at least once**|
|**Best for**|Unknown iterations **with pre-check**|Must execute at least onc|
### Break and Continue
- **break** - exits the loop completely (recommended to end infinite loops)
- **continue** - skips current iteration and move to the next