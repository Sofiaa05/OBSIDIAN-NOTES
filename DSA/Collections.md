- basics for dsa


In Java, **collections** are **data structures** that store, manage, and manipulate groups of objects.  
Instead of you manually creating an array or linked list, Java provides ready-made, **highly optimized** data structures in the **`java.util`** package.

---

## **2. Why use Collections instead of arrays?**

Arrays are simple but have limitations:

- **Fixed size** → You can’t change the size after creation.
    
- **No built-in methods** → You must write your own logic to search, sort, etc.
    
- **No type flexibility** → Works best with one data type.
    

Collections solve these issues:

- **Dynamic size** (can grow or shrink as needed)
    
- **Built-in utility methods** (sorting, searching, filtering, etc.)
    
- **Better performance** in many operations
    
- **Different data structures for different needs** (lists, sets, queues, maps)
    

---

## **3. The Collection Framework Hierarchy**

The Java **Collection Framework** is organized like a **family tree**:

```
          Iterable (interface)
                |
          Collection (interface)
         /    |       \
   List   Set     Queue  (interfaces)
   |      |        |
ArrayList HashSet  PriorityQueue (classes)
LinkedList TreeSet  ArrayDeque (classes)
```

And separately:

```
          Map (interface)
          /    \
  HashMap   TreeMap  (classes)
```

---

### **Main Interfaces**

1. **`Collection`** → Root interface for storing groups of objects.
    
2. **`List`** → Ordered collection, allows duplicates.  
    Example: `ArrayList`, `LinkedList`
    
3. **`Set`** → Unordered collection, **no duplicates**.  
    Example: `HashSet`, `TreeSet`
    
4. **`Queue`** → Follows FIFO (First In, First Out).  
    Example: `PriorityQueue`, `ArrayDeque`
    
5. **`Map`** (Not a child of Collection) → Stores data in **key-value** pairs.  
    Example: `HashMap`, `TreeMap`
    

---

## **4. Common Classes**

|**Interface**|**Class**|**Key Feature**|
|---|---|---|
|`List`|`ArrayList`|Dynamic array, fast random access|
||`LinkedList`|Doubly linked list, fast insertion/deletion|
|`Set`|`HashSet`|No duplicates, fast lookup|
||`TreeSet`|Sorted set|
|`Queue`|`PriorityQueue`|Elements ordered by priority|
||`ArrayDeque`|Efficient double-ended queue|
|`Map`|`HashMap`|Key-value pairs, fast lookup|
||`TreeMap`|Sorted keys|

---

## **5. Key Methods in Collection**

(All these come from `Collection` interface and its children)

|**Method**|**Purpose**|
|---|---|
|`add(E e)`|Add an element|
|`remove(Object o)`|Remove an element|
|`size()`|Number of elements|
|`contains(Object o)`|Checks if element exists|
|`isEmpty()`|Checks if empty|
|`clear()`|Removes all elements|
|`iterator()`|Returns an iterator for looping|

---

## **6. Example: ArrayList**

```java
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> names = new ArrayList<>();
        
        names.add("Alice");
        names.add("Bob");
        names.add("Charlie");

        System.out.println(names); // [Alice, Bob, Charlie]
        System.out.println(names.contains("Bob")); // true
        names.remove("Alice");
        System.out.println(names); // [Bob, Charlie]
    }
}
```

---

## **7. Utilities with `Collections` Class**

Java has a helper class called **`java.util.Collections`** (note the **s** at the end), which has **static methods** like:

- `Collections.sort(list)`
    
- `Collections.reverse(list)`
    
- `Collections.max(list)`
    
- `Collections.min(list)`
    

Example:

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>(Arrays.asList(5, 2, 9, 1));
        
        Collections.sort(numbers); // Ascending order
        System.out.println(numbers); // [1, 2, 5, 9]
    }
}
```
