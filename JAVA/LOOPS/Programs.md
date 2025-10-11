## Programs Type -1:
### Program 1 : Table of a number
```java
import java.util.Scanner;
public class Table{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter a number: ");
		int n = sc.nextInt();

		while(n<=0){
			System.out.println("Invalid number, Enter again: ");
			n = sc.nextInt();
		}
		while(n>0){
			System.out.println("Table of " + n + "is: ");
			for(int i=1; i<=10; i++){
				System.out.println(n + " * " + i + " = " + (n*i));
			}
			break;
		}	
	}
}
```

### Program 2 : Sum of n natural numbers
```java
public class Sum{
	public static void main(String[] args){
		int n=6, sum=0;

		while (n<=0){
			System.out.println("Invalid input, Enter again: ");
			break;
		}
		while(n>0){
			for(int i=1; i<=n; i++){
				sum+=i;
			}
			System.out.println("Sum is "+ sum);
			break;
		}
	}
}

```

### Program 3 : Factorial of a number
```java
import java.util.Scanner;
public class Factorial{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter a positive number: ");
		int n = sc.nextInt();

		while(n<0){
			System.out.println("Invalid input, enter again");
			n = sc.nextInt();
			break;
		}

		int i=1; 
		long fact=1;
		while (i<=n){
			fact = fact*i;
			i++;
		}
		System.out.println("Factorial of " + n + " = " + fact);
	}
}
``` 

---

## Programs Type-2

![[Pasted image 20250331131755.png]]
### Program 1: Display digits of a number
```java
//Display digits
import java.util.Scanner;
public class Digits{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter a number: ");
		int n = sc.nextInt();

		while (n>0){
			int r =n%10;
			System.out.println(r);
			n=n/10;
		}
		System.out.println(n); //because n will become 0 at the end
		sc.close();
	}	
}
```

```plaintext
OUTPUT:

Enter a number: 
123
3
2
1
0
```

### Program 2: Count digits of a number:
```java
//Count digits
import java.util.Scanner;
public class Count{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter a number: ");
		int n = sc.nextInt();
		int count=0;

		while (n>0){
			count++;
			n=n/10;
			
		}
		System.out.println("Count = " + count ); //because n will become 0 at the end
		sc.close();
	}
}
```

```plaintext
OUTPUT: 

Enter a number: 
23456
Count = 5
```

### Program 3: Find if a number is Armstrong or not:
```java
//Count digits
import java.lang.*;
import java.util.Scanner;
public class Armstrong{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter a number: ");
		int num = sc.nextInt();
		int count=0;

		int n = num;
		while (n>0){
			n=n/10;
			count++;
		}

		n = num;
		double sum=0;
		while(n>0){
			int r = n%10;
			sum = sum + Math.pow(r,count);
			n=n/10;
		}

		String result = (Math.round(sum)==num) ? "Yes" : "No";
		System.out.println("Is the given number Armstrong Number? " + result);
		 sc.close();
	}
}
```

```plaintext
OUTPUT:

Enter a number: 
153
Is the given number Armstrong Number? Yes
```

### Program 4.1 : Reverse a number (without trailing zero)
```java
//Display digits
import java.util.Scanner;
public class Reverse{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter a number: ");
		int n = sc.nextInt();
		int sum=0;
		while (n>0){
			int r =n%10;
			sum=sum*10+r;
			n=n/10;
		}
		System.out.println("Reversed number is = "+ sum);
		sc.close();

	}
}
```

```plaintext
OUTPUT:

Enter a number: 
2345
Reversed number is = 5432
```

### Program 4.2: Reversing a number with trailing zero (Using String)
- read the number as a **string from the start**
- or convert integer to string
```java
int num = sc.nextInt();

	int r;
	String str ="";
	int n = num;
	while(n>0){
		r=n%10;
		n= n/10;
		str = str+r; //str + Integer.toString(r) (automatic type conversion)
	}
	System.out.println("Reversed number = " + str);	
```

```plaintext
OUTPUT:

Enter a number:
1703

Reversed number = 3071
```
### Program 5: Check a number is palindrome 

![[Pasted image 20250331184431.png]]

```java
//Palindrome
import java.util.Scanner;
public class Reverse{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);

		System.out.println("Enter a number: ");
		int n = sc.nextInt();
		int ognum = n;
		int sum=0;
		while (n>0){
			int r =n%10;
			sum=sum*10+r;
			n=n/10;
		}
		System.out.println("Reversed number is = "+ sum);
		String result = (ognum==sum)? "yes" : "no";
		System.out.println(result);
		sc.close();

	}
}
```

```plaintext
OUTPUT:

Enter a number: 
1441
yes
```
---
## Problem Type-3:

### Program 1:  Display a number in words without trailing 0
```java
//display a number in words even without tailing 0
import java.util.Scanner;
public class NumWords{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number: ");
		int num = sc.nextInt();

		//first reverse a number
		int n = num, r, rev=0;
		while (n>0){
			r = n%10;
			rev=rev*10+r;
			n/=10;
		}
		n=rev;
		while(n>0){
			r=n%10;

			String word = switch(r){
				case 0 -> "zero";
				case 1 -> "one";
				case 2 -> "two";
				case 3 -> "three";
				case 4 -> "four";
				case 5 -> "five";
				case 6 -> "six";
				case 7 -> "seven";
				case 8 -> "eight";
				case 9 -> "nine";
				default -> "invalid input";
			};
			n/=10;
			System.out.print(word + " ");
		}
	}
}

```

```plaintext
OUTPUT:

Enter a number: 
1723
one seven two three
```

### Program 2:  Display a number in words with trailing 0
#### Method 1 : finding remainder and concatenate it in string then printing it using reverse loop
```java
		int num = sc.nextInt();

		int r;
		String str ="";
		 int n = num;
		while(n>0){
			r=n%10;
			n= n/10;
			str = str+r;
		}

		for (int i=str.length()-1; i>=0; i--){
			char ch = str.charAt(i);
			String word = switch(ch){
				case '0' -> "zero";
				case '1' -> "one";
				case '2' -> "two";
				case '3' -> "three";
				case '4' -> "four";
				case '5' -> "five";
				case '6' -> "six";
				case '7' -> "seven";
				case '8' -> "eight";
				case '9' -> "nine";
				default -> "invalid input";
			};
			System.out.print(word + " ");
		}

```

---
 
 #### Method 2: converting int to string then printing each character 
 ```java
 		String number = String.valueOf(num); //converting num(int) to string

		for(int i=0; i<number.length(); i++){
			char ch = number.charAt(i);
			String word = switch(ch){
				case '0' -> "zero";
				case '1' -> "one";
				case '2' -> "two";
				case '3' -> "three";
				case '4' -> "four";
				case '5' -> "five";
				case '6' -> "six";
				case '7' -> "seven";
				case '8' -> "eight";
				case '9' -> "nine";
				default -> "invalid input";
			};
			System.out.print(word + " ");
		}
```

---
## Problem Type-4:
### Program 1: Display AP series
```java
//Arithmetic Progression series
import java.util.Scanner;
public class AP{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the first term of AP series");
		int a = sc.nextInt();

		System.out.println("Enter the common difference of AP series");
		int d = sc.nextInt();

		System.out.println("Enter the number of terms: ");
		int n = sc.nextInt();

		for(int i=1; i<=n; i++){
			System.out.print(a);

			if (i != n) { // To avoid an extra comma at the end
                System.out.print(", ");
            }
			a += d;
		}
		sc.close();
	}
}
```

```plaintext

OUTPUT:

Enter the first term of AP series
3
Enter the common difference of AP series
5
Enter the number of terms: 
10
3, 8, 13, 18, 23, 28, 33, 38, 43, 48
```

### Problem 2: Display GP series
```java
//Arithmetic Progression series
import java.util.Scanner;
public class GP{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the first term of GP series");
		int a = sc.nextInt();

		System.out.println("Enter the common ratio of AP series");
		int r = sc.nextInt();

		System.out.println("Enter the number of terms: ");
		int n = sc.nextInt();

		for(int i=1; i<=n; i++){
			System.out.print(a);

			if (i != n) { // To avoid an extra comma at the end
                System.out.print(", ");
            }
			a *= r;
		}
		sc.close();
	}
}
```

```plaintext
OUTPUT:

Enter the first term of GP series
5
Enter the common ratio of AP series
2
Enter the number of terms: 
10
5, 10, 20, 40, 80, 160, 320, 640, 1280, 2560
```

### Program 3: Display Fibonacci series
```java
//Fibonacci Series
import java.util.Scanner;
public class Fibonacci{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the number of terms: ");
		int n = sc.nextInt();
		int a=0, b=1;

		for(int i=0; i<n; i++){
			System.out.print(a);

			if(i != n-1){
				System.out.print(", ");
			}
			int c = a+b;
			a=b;
			b=c;
		}
		sc.close();
	}
}
```

```plaintext
OUTPUT:

Enter the number of terms: 
10
0, 1, 1, 2, 3, 5, 8, 13, 21, 34
```

---

