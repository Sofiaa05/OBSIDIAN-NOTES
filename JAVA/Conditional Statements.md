 ## Logical Operators

| **A** | **B** | **A && B** | **A \|\| B** | **A ^ B** | **!A** | **!B** |
|:----:|:----:|:--------:|:--------:|:------:|:----:|:----:|
|  T   |  T   |    T     |    T     |    F   |   F  |   F  |
|  T   |  F   |    F     |    T     |    T   |   F  |   T  |
|  F   |  T   |    F     |    T     |    T   |   T  |   F  |
|  F   |  F   |    F     |    F     |    F   |   T  |   T  |

---
## If - Else Statement

```java
if (condition) {
    // Code to be executed if the condition is true
}

```
**Condition**: This is an expression that returns a `boolean` value (`true` or `false`).

### Ternary Operator ( Shortened if-else):
```java
int age = 20;
String result = (age >= 18) ? "Adult" : "Minor";
System.out.println(result);

```
---

#### Program 1: Find radix 
```java 

import java.util.Scanner;
public class Radix {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter a number");
        String str = sc.nextLine();

        if(str.matches("[01]+")){
            System.out.println("Binary number, Radix = 2");
        }
        else if(str.matches("[0-7]+")){
            System.out.println("Octal Number, Radix = 8");
        }
        else if(str.matches("[0-9A-F]+")){
            System.out.println("Hexadecimal number, Radix = 16");
        }
        else if(str.matches("[0-9]+")){
            System.out.println("Decimal Number, Radix = 10");
        }
        else{
            System.out.println("Invalid number");
        }
    }   
}

```

---
#### Program 2 : Type of website and protocol used
```java

import java.util.Scanner;
public class TypeofWebsite {
    public static void main(String[] args) {
       Scanner sc = new Scanner (System.in);
       System.out.println("Enter a website: ");
       String web = sc.nextLine();
       
       //checking type of website
       int i = web.lastIndexOf('.');
       if(web.substring(i).equals(".com")){
        System.out.println("commercial website");
       }
       else if(web.substring(i).equals(".org")){
        System.out.println("organisational website");
       }
       else if(web.substring(i).equals(".gov")){
        System.out.println("government website");
       }
       else if(web.substring(i).equals(".net")){
        System.out.println("networking website");
       }
       else{
        System.out.println("invalid domain");
       }

       // checking protocol used 
       int j = web.indexOf(':');
       if(web.substring(0, j).equals ("http")){
        System.out.println("Hyper text transfer protocol");
       }
       else if(web.substring(0, j).equals("https")){
        System.out.println("Hyper text transfer security protocol");
       }
       else if(web.substring(0, j).equals("ftp")){
        System.out.println("File transfer protocol");
       }
       else{
        System.out.println("invalid protocol");
       }
       sc.close();
    }
}

```

---
#### Program 3 : Leap year or not
```java
import java.util.Scanner;
public class LeapYear {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter a year: ");
        int year = sc.nextInt();
       
        // if(year%4==0){
        //     if(year%100==0){
        //         if (year%400 == 0){
        //             System.out.println("leap year");
        //         }
        //         else{
        //             System.out.println("not a leap year.");
        //         }
        //     }
        //     else{
        //         System.out.println("Not a leap year");
        //       }
        // }
        // else{
        //     System.out.println("Not a leap year");
        // }

        if( year%4==0 && year%100==0 && year%400==0){
            System.out.println("leap year");
        }
        else{
            System.out.println("Not a leap year");
        }
    }
}

```

---
#### Program 4 : Greatest among 3 numbers
```java

import java.util.Scanner;
public class Greatest {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int a,b,c;
        System.out.println("Enter three numbers: ");
        System.out.println("Enter number 1: ");
        a = sc.nextInt();

        System.out.println("Enter number 2: ");
        b = sc.nextInt();

        System.out.println("Enter number 3: ");
        c = sc.nextInt();

        if(a>b && a>c){
            System.out.println(a + "is greatest.");
        }
        else if(b>c){
                System.out.println(b + "is greatest");
            }
        else{
                System.out.println(c + "is greatest.");
        }
    }
}

```

#### Program 5 : Even or Odd
```java
public class EvenOdd {
    public static void main(String[] args) {
        int num = 9;
    //     if ((num & 1)==0 ){
    //         System.out.println("even");
    //     }
    //     else{
    //         System.out.println("odd");
    //     }

    //using ternary operator 
    String result = ((num&1)==0) ? "even" : "odd";
    System.out.println(result);
    }   
}

```
---
---
## Switch Case :
- Good for performing menu-driven programs
- Faster than if-else statements.
### Rules for Switch Statement
- **Allowed data types for `switch` expression**:

	- `byte`, `short`, `int`, `char`
	    
	- `String` (since Java 7)
	    
	- `enum` (since Java 5)
	    
	- Wrapper classes  like `Integer`, `Character`
	    

 - **Not allowed**:

	- `float`, `double`, `long`, `boolean`
	    
	- Non-constant expressions
###  `default` Case in `switch`:

The `default` case is **optional** but recommended.

- It **executes when no case matches**.
    
- It is usually placed at the end but can be anywhere.
###  `break` Statement in `switch`

- `break` **exits** the `switch` statement after a match is found.
    
- Without `break`, execution **falls through** the next cases and they will be executed until break is found.
#### Program 1 : Menu driven program for calculations
```java
import java.util.Scanner;
public class Arithmetic{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter operation you want to perform in words (Add, Sub, Mul, Div) :");

		String op = sc.nextLine();

		System.out.println("Enter two numbers: ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int res;

		switch(op){
			case "Add":
				System.out.println("Result = " + (a+b));	
				break;	
			case "Sub":
				System.out.println("Result = " + (a-b));	
				break;			
			case "Mul":
				System.out.println("Result = " + (a*b));	
				break;			
			case "Div":
				if(b==0){
					System.out.println("Divide by zero is not possible");
				}
				else if(a<b){
					System.out.println("First number should be greater");
				}
				else{
					System.out.println("Result = " + (a/b));	
				}
				break;			
			default: 
				System.out.println("Enter a valid option.");
		}
	}
}
```

#### Program 2: Printing days based on their number
```java
public class SwitchCase{
	public static void main(String[] args){
		int n = 1;

		switch(n)
		{
			case 1: System.out.println("Monday");
				break;
			case 2: System.out.println("Tuesday");
				break;
			case 3: System.out.println("Wednesday");
				break;
			case 4: System.out.println("Thursday");
				break;
			case 5: System.out.println("Friday");
				break;
			case 6: System.out.println("Saturday");
				break;
			case 7: System.out.println("Sunday");
				break;
			default : System.out.println("Invalid number");
		}
	}
}
```

#### Program 3 : Finding type of website 
```java
import java.util.Scanner;
public class WebsiteType{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter website url: ");
		String url = sc.nextLine();

		String type = url.substring(url.lastIndexOf('.'));

		switch(type){
			case ".com" :
				System.out.println("commercial");
				break;
			case ".org" :
				System.out.println("organisation");
				break;
			case ".net" :
				System.out.println("networking");
				break;
			case ".biz" :
				System.out.println("business");
				break;
			case ".gov" :
				System.out.println("government");
				break;
			default : 
				System.out.println("Invalid type of website");
		}
	}
}
```

### Enhanced Switch Case:
Java 14 introduced a **simplified switch** with an **arrow (`->`)**:

- No need for `break` (automatic).
    
- Can return values.
```java
public class EnhancedSwitch{
	public static void main(String[] args){
		int day = 90;
		String result = switch (day){
			case 1 -> "Sunday";
			case 2 -> "Monday";
			case 3 -> "Tuesday";
			case 4 -> "Wednesday";
			case 5 -> "Thursday";
			case 6 -> "Friday";
			case 7 -> "Saturday";
			default -> "Invalid day";
		};	

		System.out.println(result);
	}
}
```
---
## If-Else vs Switch Case
|Feature|`if-else`|`switch`|
|---|---|---|
|**Data Types**|Works with all data types|Works with `int`, `char`, `String`, `enum`|
|**Multiple Conditions**|Best for complex conditions|Best for multiple exact matches|
|**Execution**|Checks all conditions|Directly jumps to matching case (faster)|
|**Scalability**|Slower for many conditions|Faster for many conditions|

### **Use `switch` when:**

✔ You have **fixed values** to compare (like numbers, enums, or strings).  
✔ Performance matters (direct jump to the matching case).  
✔ Code readability is important.

### **Use `if-else` when:**

✔ Conditions involve **comparisons** (`>`, `<`, `!=`).  
✔ Complex expressions (e.g., multiple boolean conditions).  
✔ Checking **ranges** (e.g., `if (x > 10 && x < 50) {}`)