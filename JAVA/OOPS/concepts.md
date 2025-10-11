### Data Hiding
- hiding data and show only the the necessary details
- Example: for a tv the data is the wiring structure and methods are operations that you can perform (buttons of tv). so when you press a button you are calling a method and that method is requesting data internally.
- this data is hidden ( the wiring strucutre) only the methods (buttons) are visible.
```java
//Data Hiding: getter and setter mthods 
class Rectangle{
	private int length;
	private int breadth;

	//getter methods
	public int getLength(){
		return length;
	}

	public int getBreadth(){
		return breadth;
	}

	//setter methods
	public void setLength(int l){
		if(l > 0) length = l;
		else length = 0;
	}

	public void setBreadth(int b){
		if (b>0) breadth = b;
		else breadth =0;
	}

	public int area(){
		return length * breadth;
	}

	public int perimeter(){
		return 2 * (length + breadth);
	}

	public boolean isSquare(){
		return length == breadth;
	}

}

public class Test{
	public static void main(String[] args){
		Rectangle r = new Rectangle();
		// r.length = 10; 
		// r.breadth = 20; //when length and breadth are prefixed with public access specifier
		r.setLength(20);
		r.setBreadth(30);
		System.out.println(r.area());
		System.out.println(r.perimeter());
		System.out.println("is Square? " + r.isSquare());
		System.out.println("length is = " + r.getLength());
		System.out.println("Breadth is = " + r.getBreadth());

	}
}
```

```plaintext
600
100
is Square? false
length is = 20
Breadth is = 30
```

