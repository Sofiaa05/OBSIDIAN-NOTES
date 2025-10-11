- to define anonymous/unnamed methods
- defined with the help of interfaces
- similar to inner classes
#### Without lambda expression

```java
@FunctionalInterface
interface Mylambda{
    void display(); //public abstract by default
}

class Child implements Mylambda{
    public void display(){  
        System.out.println("hi");
    }
} 

public class lambda {
    public static void main(String[] args) throws Exception {

        //creating an object of Interface and overriding method of that interface (Anonymous inner class)
        
        Mylambda c = new Mylambda() {
            public void display(){
                System.out.println("hello");
            }
        };
       
        c.display();
    }
}
```

#### With lambda expression
```java
//functional interface: interface having only one abstract method

@FunctionalInterface
interface Mylambda{
    void display(); //public abstract by default
}

public class lambda {
    public static void main(String[] args) throws Exception {

        Mylambda c = () -> {
            System.out.println("heloooo"); //referring to the display() method 
        };
        c.display();
    }
}

```


- how does this method `c.display()` know which method to refer to? becauser reference is `MyLambda` and as it is a functional interface it contains only one abstract method (hence only one method to refer to)
- method itself is an object here, anonymous method and it is acting as an object
- to make functional interfaces easy for implementation, java has introduced `lambda expressions`
---
#### Parameters in lambda expression
```java
@FunctionalInterface
interface Mylambda{
    // void display(String str); //public abstract by default
    int add(int x, int y);
}

public class lambda {
    public static void main(String[] args) throws Exception {
        Mylambda c = (x, y) -> {return x + y;};
        System.out.println(c.add(6,9));
    }
}

//output: 15
```

---
#### Can lambda expression have local variables? yes
#### Can they access local variables or instance variables? 
- yes can access local variables local to the method they are defined in (given that they are final or not modified in lambda expression)
- yes can access instance variable (need not final and can be modified)

```java
interface Mylambda{
    public void display(); 
}

class Demo{
    // Add methods or fields here if needed
    public void method1(){
        int num = 89; //instance variable
        Mylambda ml = () -> {
            int count = 68; //local variable
            count++;
            System.out.println("Hi from lambda");
            System.out.println("another statement inside lambda");
            System.out.println("local variable " + count);
            //can't do sout(count++);
            System.out.println("instance variable " + num);
            System.out.println("modifying instance variable " + (++num));
        };

        ml.display();
    }
}
public class Capture{
    public static void main(String[] args) {
        Demo d = new Demo();
        d.method1();
    }
}
```

- lamba expressions can access/ capture local variables only if they are final or never modified in the method
- cannot modify variables that are local to the method  (method1) where lambda expression is defined
#### Can you pass lambda expressions as parameters?
- yes
- passing method as an object

```java
interface Mylambda{
    public void display();
}

class useLambda{
    public void callLambda(Mylambda ml){ //method taking functional interface as parameter
        ml.display();
    }
}
class Demo{
    public void method1(){ 
    
	    useLambda ul = new useLambda();
	    ul.callLambda(() -> {System.out.println("hi from passing lambda as expression");});  //passing lambda expression as parameter
	    }
}
public class Capture{
    public static void main(String[] args) {
        Demo d = new Demo();
        d.method1();
    }
}
```

- when a method is taking a functional interface as paramter, then you can pass lambda function to that method
---

### Method Reference
- created using functional interface
- 