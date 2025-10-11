### Object class
- mother of all classes in java.
- every class (usr defined and built in) inheriting from object class

#### finalise method
- called by the gargabage collector on an object when garbage collection determines that there are no more references

```java
public class LangDemo{
	public static void main(String[] args){
		Object o1 = new Object();
		Object o2 = new Object();
	
		System.out.println(o1.equals(o2));
		System.out.println(o1);
		System.out.println(o1.toString());	
		System.out.println(o2.equals(o3));	
	}
}

```

```plaintext
false
java.lang.Object@4df828d7
java.lang.Object@4df828d7
true
```

#### Overriding toString()

```java
class Myobject{
    public String toString(){
        return "My object";
    }
}

//Main
Myobject m = new Myobject();
		System.out.println(m.toString());
```

```plaintext
My object
```