### Basic applications of stack:
1. **Matching parenthesis**: ensuring balanced symbols in expressions
2. **Parsing code:** Analyzing and structuring code syntax
3. **Evaluating expressions:** Calculating results from mathematical notations
4. **Tracking History:** Managing undo operations and history
#### Stack operations:
- push()
- pop()
- isFull()
- isEmpty()
- peek()
### Using Arrays

```java
public class StackArray{
	private int stack[];
	private top;
	private capacity;

	//constructor
	public StackArray(int size){
		stack = new int[size];
		top = -1; //stack is empty
		capacity = size;
	}

	//check overflow
	public boolean isFull(){
		return top == capacity - 1;
	}
	
	//check underflow
	public boolean isEmpty(){
		return top == -1;
	}
	
	//push elements
	public void push(int value){
		if(isFull()){
			System.out.println("Stack Overflow");
			return;
		};
		//stack[++top] = data; in a single line or
		top++
		stack[top] = value; 
	}

	//pop elements
	public int pop(){
		if(isEmpty()){
			System.out.println("Stack underflow");
			return -1;
		}
		return stack[top--];
	}

	//peek
	public int peek(){
		if(isEmpty()){
			System.out.println("Stack underflow");
			return -1;
		}
		return stack[top];
	}

	public void printStack(){
		if(isEmpty()){
			System.out.println("Stack is empty. Nothing to print");
			return;
		}
		for(int i = 0; i <= top; i++){
			System.out.print(stack[i] + " ");
		}
	}
}

public class StackArrayMain{
	public static void main(String[] args){
		StackArray st = new StackArray(5);
		st.push(34);
		st.push(69);
		st.pop();
		st.peek();
		st.push(45);
		st.peek();
		st.push(90);
		st.push(34);
		st.push(23);
	}
}

//output
Stack Overflow
34 45 90 34 23
```

### Using LinkedList
```java
class Node{
	int data;
	Node next;

	//constructor
	public Node(int data){
		this.data = data;
		this.next = null;
	}
}

class StackLL{
	Node top = null;

	//stack underflow
	public boolean isEmpty(){
		return top == null;
	}

	//push
	public void push(int data){
		Node newNode = new Node(data);
		newNode.next = top; //link new node to previous node
		top = newNode; //update top
	}

	//pop
	public int pop(){
		if(isEmpty()){
			System.out.println("Stack is empty.");
			return -1;
		}
		int popped = top.data; //return data
		top = top.next; //move top pointer
		return popped;
	}

	//peek
	public int peek(){
		if(isEmpty()){
			System.out.println("Stack is empty.");
			return -1;
		}
		return top.data;
	}

	public void printStack(){
		if(isEmpty()){
			System.out.println("Stack is empty.");
			return;
		}

		Node temp = top;
		while (temp != null){
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
	}
}

public class StackLLMain{
	public static void main(String[] args){
		StackLL st = new StackLL();
		st.push(23);
		st.push(45);
		st.push(87);
		st.printStack();
		st.pop();
		st.peek();
		st.pop();
		st.pop();
		st.pop();
	}
}

//output
87 45 23 Stack is empty.
```

###  Using Stack class
| Method             | Description                                                     |
| ------------------ | --------------------------------------------------------------- |
| `push(E item)`     | Pushes an item onto the stack                                   |
| `pop()`            | Removes and returns the top item                                |
| `peek()`           | Returns (but does not remove) the top item                      |
| `empty()`          | Returns true if stack is empty                                  |
| `search(Object o)` | Returns 1-based position of item from top, or `-1` if not found |
```java
import java.util.Stack;

public class StackClassDemo {
    public static void main(String[] args) {
        // Create a stack of integers
        Stack<Integer> stack = new Stack<>();

        // Push elements
        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Stack: " + stack); // [10, 20, 30]

        // Peek at top element
        System.out.println("Top element: " + stack.peek()); // 30

        // Pop element
        System.out.println("Popped: " + stack.pop()); // 30

        System.out.println("Stack after pop: " + stack); // [10, 20]

        // Search for element (1-based index from top)
        System.out.println("Position of 10: " + stack.search(10)); // 2

        // Check if empty
        System.out.println("Is stack empty? " + stack.empty()); // false
    }
}

```