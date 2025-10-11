- **Method of  a class** that is called **automatically called** when an object is created.
- By default, there will be **one constructor** provided by the compiler.
- You can define your own constructor as well, so when you define your own construcor, it should:
	- have the **same name as the class name**
	- have **no return type.**
	- usually declared public, but can also be private
	- constructors **can be overloaded** (parameters must be different)

## Types of Constructors:
1. Non parameterised - replacement for default constructor
2. Parameterised

```java
//constructor example
class Rectangle{
	private double length;
	private double breadth;

	//getter methods
	public double getLength(){
		return length;
	}

	public double getBreadth(){
		return breadth;
	}

	//setter methods
	public void setLength(double l){
		if(l > 0) length = l;
		else length = 0;
	}

	public void setBreadth(double b){
		if (b>0) breadth = b;
		else breadth =0;
	}

	public double area(){
		return length * breadth;
	}

	public double perimeter(){
		return 2 * (length + breadth);
	}

	public boolean isSquare(){
		return length == breadth;
	}

	//Non parameterised constructor
	public Rectangle(){
		length = 1;
		breadth = 2;
	}

	//parameterised constructor
	public Rectangle(double l, double b){
		length = l; //setLength(l)
		breadth = b; //setBreadth(b)
	}

	public Rectangle(double s){
		if(s > 0)
			length = breadth = s;
	}
}

public class RectangleTest{
	public static void main(String[] args){
		Rectangle r = new Rectangle(); //first constructor
		Rectangle r1 = new Rectangle(10,20); //second constructor
		Rectangle r2 = new Rectangle(10); //third constructor
		r.setLength(20);
		r.setBreadth(30);
		System.out.println(r2.area());
		System.out.println(r2.perimeter());
		System.out.println("is Square? " + r2.isSquare());
		System.out.println("length is = " + r2.getLength());
		System.out.println("Breadth is = " + r2.getBreadth());

	}
}
```

```plaintext
Output when r is called:
2.0
6.0
is Square? false
length is = 1.0
Breadth is = 2.0

when r1 is called:
200.0
60.0
is Square? false
length is = 10.0
Breadth is = 20.0

when r2 is called:
100.0
40.0
is Square? true
length is = 10.0
Breadth is = 10.0
```

---
### Example: Rectangle
```java
//constructor example
class Rectangle{
	private double length;
	private double breadth;

	//getter methods
	public double getLength(){
		return length;
	}

	public double getBreadth(){
		return breadth;
	}

	//setter methods
	public void setLength(double l){
		if(l > 0) length = l;
		else length = 0;
	}

	public void setBreadth(double b){
		if (b>0) breadth = b;
		else breadth =0;
	}

	public double area(){
		return length * breadth;
	}

	public double perimeter(){
		return 2 * (length + breadth);
	}

	public boolean isSquare(){
		return length == breadth;
	}


	//Non parameterised constructor
	public Rectangle(){
		length = 1;
		breadth = 2;
	}

	//non parameterised constructor
	public Rectangle(double l, double b){
		length = l; //setLength(l)
		breadth = b; //setBreadth(b)
	}

	public Rectangle(double s){
		if(s > 0)
			length = breadth = s;
	}
}

public class RectangleTest{
	public static void main(String[] args){
		Rectangle r = new Rectangle(); //first constructor
		Rectangle r1 = new Rectangle(10,20); //second constructor
		Rectangle r2 = new Rectangle(-10); //third constructor //gives 0
		r.setLength(20); //fordefining length for non parameterised constructor
		r.setBreadth(30); //defining breadth for non parameterised constructor
		System.out.println(r2.area());
		System.out.println(r2.perimeter());
		System.out.println("is Square? " + r2.isSquare());
		System.out.println("length is = " + r2.getLength());
		System.out.println("Breadth is = " + r2.getBreadth());

	}
}
```

```plaintext
//when first constructor is called
200.0
60.0
is Square? false
length is = 10.0
Breadth is = 20.0

//when second constructor is called
100.0
40.0
is Square? true
length is = 10.0
Breadth is = 10.0

//calling third constructor 
0.0
0.0
is Square? true
length is = 0.0
Breadth is = 0.0
```

---
### Example 2: Product 
```java
class Product{
	private String itemno;
	private String name;
	private double price;
	private int quantity;

	//getter and setter methods
	public String getItemno(){  //only getter because Itemno is defined at construction time only
		return itemno;
	}

	public String getName(){  //only getter because name is defined at construction time only
		return name;
	}

	public double getPrice(){
		return price;
	}

	public void setPrice(int p){  //because price changes frequently
		price = p;
	}

	public int getQuantity(){
		return quantity;
	}

	public void setQuantity(int qty){ //because qty on hand can be changed
		quantity = qty;
	}

	//constructor
	public Product(String itmnom, String nm){
		itemno = itmnom; 
		name = nm;
		price = 1000;
		quantity = 69;
	}
}

public class ProductTest{
	public static void main(String[] args){
		Product p = new Product("J-001" , "Jeans");
		System.out.println("Itemno = " + p.getItemno());
		System.out.println("name = " + p.getName());
		System.out.println("price = " + p.getPrice());
		System.out.println("quantity available = " + p.getQuantity());
	}
}
```

```plaintext
Itemno = J-001
name = Jeans
price = 1000.0
quantity available = 69
```

#### Note: 
- for phone number take data type as String because `+` and also for leading 0 cant be there in int so string is taken
---
## Array of Objects

### Example 1:
```java
class Subject{

	//Properties
	//private means they can only be accessed within the class they are defined in
	private String subID;
	private String name;
	private int maxMarks;
	private int marksObtain;

	//Property methods
	//getter methods. These methods are used to get values of the private variables from outside the class.
	public String getSubID(){
		return subID;
	}

	public String getName(){
		return name;
	}

	public int getMaxMarks(){
		return maxMarks;
	}

	public int getMarksObtain(){
		return marksObtain;
	}

	//setter methods. These methods are used to set or update the values of maxMarks and marksObtain.
	public void setMaxMarks(int maxMarks){
		this.maxMarks = maxMarks;
	}
	public void setMarksObtain(int m){
		marksObtain = m;
	}

	//constructors
	public Subject(String subID, String name, int maxMarks){
		this.subID = subID;
		this.name = name;
		this.maxMarks = maxMarks;
	}

	public Subject(String subID, String name){
		this.subID = subID;
		this.name = name;
	}

	boolean isQualified(int marks){
		return marks >= maxMarks / 10 * 4;
	}

	 /*	This is a special method in Java called toString().
		It tells Java how to display the object when you use System.out.println(object);
		It returns a string that shows the subject's details in a nice format */

	public String toString(){
		return "\nSubject ID = " + subID + "\nName: " + name + "\nMarks Obtained: " + marksObtain;
	}
}

public class SubjectTest{
	public static void main(String[] args){
		Subject subs[] = new Subject[3]; //This creates an array to hold 3 Subject objects.
		subs[0] = new Subject("s101" , "DS" , 100);
		subs[1] = new Subject("s102" , "Algorithms" , 100);
		subs[2] = new Subject("s103", "Operating System", 100);
		//This creates 3 subjects with ID, name, and max marks = 100.

		for(Subject s: subs){
			System.out.println(s);
		}
	}
}
```

```plaintext
Subject ID = s101
Name: DS
Marks Obtained: 0

Subject ID = s102
Name: Algorithms
Marks Obtained: 0

Subject ID = s103
Name: Operating System
Marks Obtained: 0
```

#### Alternatively (without using toString()):
```java
public void printDetails(){
	System.out.println("Subject ID = " + subID);
	System.out.println("Name: " + name);
	System.out.println("Marks Obtained: " + marksObtain);
	System.out.println("Maximum Marks: " + maxMarks);
	System.out.println(); // For an empty line between subjects
}

public class SubjectTest {
	public static void main(String[] args) {
		Subject subs[] = new Subject[3];
		subs[0] = new Subject("s101", "DS", 100);
		subs[1] = new Subject("s102", "Algorithms", 100);
		subs[2] = new Subject("s103", "Operating System", 100);

		// Setting some marks (you can change these)
		subs[0].setMarksObtain(85);
		subs[1].setMarksObtain(75);
		subs[2].setMarksObtain(90);

		for (Subject s : subs) {
			s.printDetails(); // call the custom method instead of toString()
		}
	}
}
```
### Example 2:
```java
class Student{
	private int rollno;
	private String name;
	private String dept;
	private String[] subjects;

	//property methods
	//getter methods
	public int getRollno(){
		return rollno;
	}

	public String getName(){
		return name;
	}

	public String getDept(){
		return dept;
	}

	public String[] getSubjects(){
		return subjects;
	}

	//setter methods
	public void setSubjects(String...args){
		subjects = args;
	}

	public Student(int rollno, String name, String dept){
		this.rollno = rollno;
		this.name = name;
		this.dept = dept;
	}

	public String toString(){
		return "\nRoll Number: " + rollno + "\nName: " + name + "\nDepartment: " + dept;
	}
}

public class StudentTest{
	public static void main(String[] args){
		Student s = new Student(1001, "Toby", "CS");
		s.setSubjects("dsa", "os", "java", "eati");
		System.out.println(s); //calls the toString() method 

		for(String subject : s.getSubjects()) //loop through subjects array
			System.out.println(subject);
	}
}
```

```plaintext
Roll Number: 1001
Name: Toby
Department: CS
dsa
os
java
eati
```