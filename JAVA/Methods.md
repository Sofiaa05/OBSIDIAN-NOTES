  - when an object is passed to a method to make changes in it, the changes made are also reflected in the original object as well.
- ![[Pasted image 20250426183723.png]]
- above example, as per our kjnowledge it should display 2 but **arrays in java are object** and when you pass an object to method calling it modifies the original object too. hence it displays 25 because `update()` method modified the first array element from 2 to 25.
- when you pass **primitives as parameter, they are passed by value not references,** but when you pass an object as a paramter to a method, then its reference is passed. **(objects are passed by references not value)**

```java
class Example{
	public static void change1(int arr[], int index, int value){ //called method
	//parameters inside called method are called formal parameters
		arr[index] = value; //changes original array
	}
	public static void change2(int x, int value){ //called method with formal paramters
		x = value;
	}
	public static void main(String[] args){ //calling method 
		int arr[] = {2,3,4,5,6};
		
		//passing array (object). as paramter to a method
		//parameters passed inside calling method are called actual parameters
		change1(arr,0,25); //array becomes [25,3,4,5,6]

		//passing primitive data type as parameter to a method
		int x = 69;
		change2(x,96); //x value still remains 69.
	}
}
```

![[Pasted image 20250426191234.png]]

### Practice Questions
```java
/*
q1: no prime or not
q2. gcd of two numbers
q3: find max element in array
*/

class Methods{
	public static boolean prime(int number){
		for(int i = 2; i < number/2; i++){
			if(number % i == 0 ){
				return false;
			}
		}
		return true;
	}

	public static int gcd(int number1, int number2){
		while(number1 != number2){
			if(number1 > number2){
				number1 -= number2;
			}
			else{
				number2 -= number1;
			}
		}

		return number1;
	}

	public static int maxArr(int arr[]){
		int max = arr[0];
		for(int i=1; i<arr.length; i++){
			if(max < arr[i]){
				max = arr[i];
			}
		}
		return max;
	}
	public static void main(String[] args){
		//prime or not
		int number = 2;

		boolean res = prime(number);
		if(res == true){
			System.out.println("yes");
		}
		else{
			System.out.println("no");
		}

		//gcd of two numbers
		System.out.println("GCD = " + gcd(25,15));

		//max element of array
		int arr[] = {34,45,56,2,1};
		System.out.println("Maximum element in array is = " + maxArr(arr));
	}
}

```

### Output:
```plaintext
yes
GCD = 5
Maximum element in array is = 56
```
---
## Method Overloading
```java
/*
q1. overload method to calculate area
q2. overload method to reverse an int or array
q3. overload method to validate name and age
*/

import java.util.*;

class MethodOverloading{

//calculate area
	public static int area(int length, int breadth){
		return length * breadth;
	}

	public static float area(int radius){
		return 3.14f * radius * radius;
	}

	public static double area(double side){
		return side * side;
	}

//reverse an int or array
	public static int reverse(int number){
		int sum = 0;
		while(number > 0){
			int r = number % 10;
			sum = sum*10 + r;
			number /= 10;
		}
		return sum;
	}

	public static int[] reverse(int arr[]){
		int start = 0, end = arr.length-1;
		while(start<end){
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++;
			end--;
		}
		return arr;
	}

//validate name and age
	public static boolean validate(String name){
		if(name.matches("[A-Za-z]+")) return true;
		return false;
	}

	public static boolean validate(int age){
		 return age > 3 && age < 15 ? true : false;
	}

	//find maximum 
	public static int max(int x, int y){
		return x > y ? x : y;
	}

	static float max(float x, float y){
		return x > y ? x : y;
	}

	static int max(int x, int y, int z){
		return x > y && x > z ? x : (y > z ? y : z);
	}

	static byte max ( byte x, byte y){
		return x > y ? x : y;
	}

	//main method
	public static void main(String[] args){
		System.out.println("Area of rectangle = " + area(3,4));
		System.out.println("Area of circle = " + area(3));
		System.out.println("Area of square = " + area(4.9));

		//reverse int
		int revInt = reverse(235);
		System.out.println("reversed integer is = " + revInt);
		int arr[] = {5,6,4,4,2};
		int revArr[] = reverse(arr);
		System.out.println("reversed array is = " + Arrays.toString(revArr));

		//validate name and age
		System.out.println("Is name valid? " + validate("Sofia"));
		System.out.println("Is age valid? " + validate(23));

		//find max
		System.out.println("max of 2 and 3 is: " + max(2,3));
		System.out.println("max of 2.5 and 6.9 is: " + max(2.5f,6.9f)); //always put f at end for float
		System.out.println("max of 2, 5 and 3 is: " + max(2,5,3));
		System.out.println("max of 0 and 1 : " + max(1001,101));	 //int, int
		System.out.println("Result: " + max((byte)1, (byte)2)); 	//byte, byte
	}
}
```

### Output:
```plaintext
Area of rectangle = 12
Area of circle = 28.26
Area of square = 24.010000000000005
reversed integer is = 532
reversed array is = [2, 4, 4, 6, 5]
Is name valid? true
Is age valid? false
max of 2 and 3 is: 3
max of 2.5 and 6.9 is: 6.9
max of 2, 5 and 3 is: 5
max of 0 and 1 : 1001
Result: 2
```
---
## Variable Number of Arguments
- using `...` operator
```java
/*
q1. maximum of numbers using varArgs
q2. sum of all elements of varargs
q3. Calculate Discount using varargs
*/

class VariableArgs{

	//examplary questions
	public static void show(int ...arr){ //can also do show(int arr[]) but that will support only array parameter passing not variable args
										 //gives error for show() and show(10,20,30,40). and works only show(new int[]{69,96,6})
		//... supports array also and variable number of args also. hence more powerful than array
		for(int x: arr){
			System.out.print(x + " ");
		}
		System.out.println();
	}

	public static void showNames(int start, String... str){ //when passing other argument with variable number args. var ags shoud be the last parameter
		for(int i=0; i<str.length; i++){
			System.out.println(start + ". " + str[i]);
			start++;
		}
	}

	//q1. maximum number
	public static void max(int...args){
		int max = args[0];
		for(int i = 0; i < args.length; i++){
			if (args[i] > max){
				max = args[i];
			}
		}
		System.out.println("maximum is : " + max);
	}

	//q2. sum of all numbers
	public static void sum(int ...args){
		int sum = 0;
		for (int i=0; i < args.length ; i++) {
			sum += args[i];
		}
		System.out.println("sum is: " + sum);
	}

	//q3. calculate discount
	public static void discount(int...args){
		float sum = 0;
		float discount = 0f;
		for (int i=0; i < args.length ; i++) {
			sum += args[i];
			if(sum > 500)  discount = sum * 0.1f;
			else if(sum > 1000)  discount = sum * 0.2f;
			else discount = 0;
		}
		System.out.println("discount is: " + discount);
	}
	public static void main(String... args){
		show();
		show(10,20,30,40); //passing variable number of args but all parameters must be of same data type

		show(new int[]{69,96,6}); //anonymous array that doesnt have any reference
		showNames(3,"sofia", "mukul", "toby", "snowy"); //giving starting index as 3. can be changed to any int 

		max(1,22,3,4,5,4); //22
		sum(1,2,3,4,5); //15
		discount(40); //0.0

	}
}
```

### OUTPUT: 
```plaintext
10 20 30 40 
69 96 6 
3. sofia
4. mukul
5. toby
6. snowy
maximum is : 22
sum is: 15
discount is: 0.0

```

---
## Command line Arguments
```java

```

---
## Dynamic Method Dispatching
- When a **superclass reference** points to a **subclass object**, and you call an **overridden method**, **Java decides which method to run at runtime** based on the object type — not the reference type.
- supports runtime polymorphism.
###  What Cannot Be Dispatched Dynamically?

- **Variables** (only methods can be dispatched dynamically)
    
- **Static methods** (they are resolved at compile-time)
    
- **Private methods** (they’re not inherited)
    
- **Constructors** (they’re not inherited/overridden) 
```java
class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    void sound() {
        System.out.println("Cat meows");
    }
}

public class Test {
    public static void main(String[] args) {
        Animal a;         // Reference of parent class

        a = new Dog();    // Object of Dog
        a.sound();        // Output: Dog barks

        a = new Cat();    // Object of Cat
        a.sound();        // Output: Cat meows
    }
}
```