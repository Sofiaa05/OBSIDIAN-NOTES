### Reverse  a string using stack
```java
//reverse string using stack
import java.util.Scanner;
import java.util.Stack;
public class ReverseString{
	public static void main(String[] args){
		Stack<Character> st = new Stack<>();
		System.out.println("Enter a string");
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		//pushign characters in stack
		for(int i = 0; i < str.length(); i++){
			st.push(str.charAt(i));
		}

		StringBuilder rev = new StringBuilder();
		//popping and adding to string
		for(int i = 0; i < str.length(); i++){
			rev.append(st.pop());
		}

		System.out.println(rev.toString()); //can also write that automatically converts to string System.out.println(rev);
	}
}
```

### Balance Parenthesis
```java
//balance paranthesis
import java.util.*;
public class BalanceParanthesis{
	public static boolean isBalanced(String str){
		Stack<Character> st = new Stack<>();

		for(int i = 0; i < str.length(); i++){
			char ch = str.charAt(i);

			if(ch == '(' || ch == '{' || ch == '['){
				st.push(ch);
			}
			else if(ch == ')'){
				if(st.isEmpty() || st.peek() != '(') return false;
				st.pop();
			}
			else if(ch == '}'){
				if(st.isEmpty() || st.peek() != '{') return false;
				st.pop();
			}
			else if(ch == ']'){
				if(st.isEmpty() || st.peek() != '[') return false;
				st.pop();
			}
			//for input other than brackets (can omit if you want to check brackets with strings too)
			else{
				return false;
			}
		}
		return st.isEmpty();
	}

	public static void main(String[] args) {

		System.out.println("Enter a string to validate");
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		System.out.println(isBalanced(str));
	}
}
```

### Palindrome using stack
```java
import java.util.*;
public class PalindromeStack{
	public static void main(String[] args) {
		Stack<Character> st = new Stack<>();

		System.out.println("Enter a string");
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		//pushign characters in stack
		for(int i = 0; i < str.length(); i++){
			st.push(str.charAt(i));
		}

		StringBuilder rev = new StringBuilder();
		//popping and adding to string
		while(!st.isEmpty()){
			rev.append(st.pop());
		}

		System.out.println(str.equals(rev.toString())); //can also write that automatically converts to string System.out.println(rev);
	}
}
```

### Evaluate Reverse Polish Notation (RPN) / Postfix Expression

```java
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        
        for(String token: tokens){
            if(isOperator(token)){   // If the token is an operator
//why int because we are already first converitng it to int before pushing in stack           
                int n2 = st.pop();   // Pop last inserted number (second operand)
                int n1 = st.pop();   // Pop next number (first operand)
                
                int result = switch(token){
                    case "+" -> n1 + n2;
                    case "-" -> n1 - n2;
                    case "*" -> n1 * n2;
                    case "/" -> n1 / n2;
                    default -> -1;
                };
                
                st.push(result);  // Push result back to stack
            }else{
                st.push(Integer.parseInt(token)); // If it's a number → convert String to int → push
            }
        }
        return st.pop();  // Final result will be the only element left
    }

    // helper function to identify if string is operator or not
    private boolean isOperator(String token) {
        return token.equals("+") ||
               token.equals("-") ||
               token.equals("*") ||
               token.equals("/");
    }
}
```

### Min stack
```java
class MinStack {
    Stack<Integer> mainStack;
    Stack<Integer> minStack;
    public MinStack() {
        mainStack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int val) {
        mainStack.push(val);

        // Push to minStack if it's empty or val <= current min since the top of minStack gives the minimum value in entire stack
        if(minStack.isEmpty() || val <= minStack.peek()) 
            minStack.push(val);
    }
    
    public void pop() {
        if(mainStack.isEmpty()) return;

        // If removed element was the min, remove from minStack also
        int popped = mainStack.pop();
        if(popped == minStack.peek()){
            minStack.pop();
        }
    }
    
    public int top() {
        if(mainStack.isEmpty()) return -1;
        return mainStack.peek();
    }
    
    // Return minimum element in O(1)
    public int getMin() {
        if(minStack.isEmpty()) return -1;
        return minStack.peek();
    }
}
```

### Queues using stack 
##### Push: (Enqueue)
1. just push the elements in input stack
##### Pop: (Dequeue)
1. if output stack is empty
	- pop all elements from input stack and push in output stack
2. Else just pop from output stack
- perform peek operation first then do pop.
##### Peek:
- return top element of output stack
##### isEmpty:
- queue is empty if both input and ouput stacks are empty

```java
class MyQueue {
    private Stack<Integer> input;
    private Stack<Integer> output;
    public MyQueue() {
        input = new Stack<>();
        output = new Stack<>();
    }
    
    public void push(int x) {
        input.push(x); //simply push
    }
    
    public int pop() {
        //look at the top element using peek() defined below in output stack and just pop it.
        peek();
        return output.pop();
    }
    
    public int peek() {
        if (output.isEmpty()){
            while (!input.isEmpty()){
                output.push(input.pop());
            }
        }
        return output.peek();
    }
    
    public boolean empty() {
        return input.isEmpty() && output.isEmpty();
    }
}
```

### Next Greater Element

#### Naive solution (https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1)
```java
class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {
        // code here
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < arr.length; i++){
            int nextGreater = -1; // assume -1 if no greater element
            
            for (int j = i + 1; j < arr.length; j++){
                if(arr[j] > arr[i]){
                    nextGreater = arr[j];
                    break;
                }
            }
            
            result.add(nextGreater);
        }
        return result;
    }
}
```

#### Using stack
```java
import java.util.Stack;

class Solution {
    public int[] nextLargerElement(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] result = new int[n];

        for (int i = n - 1; i >= 0; i--) {
            // Pop smaller elements
            while (!st.isEmpty() && arr[i] >= st.peek() ) {
//next smaller would be while(!st.isEmpty() && arri[j] <= st.peek())           
                st.pop();
            }

            // If stack empty → no greater element
            if (st.isEmpty()) {
                result[i] = -1;
            } else {
                result[i] = st.peek();
            }

            // Push current element for next iterations
            st.push(arr[i]);
        }

        return result;
    }
}
```

#### LeetCode Problem  https://leetcode.com/problems/next-greater-element-i/description
```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int ans[] = new int[nums1.length]; //next greater element corresponding to nums1
        int nge[] = new int[nums2.length]; //to store next greater element corresponding to nums2

        Stack<Integer> st = new Stack<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        //find next greater element
        for(int j = nums2.length - 1; j >= 0; j--){
            while(!st.isEmpty() && nums2[j] >= st.peek()){ 
                st.pop();
            }
            if(st.isEmpty()){
                nge[j] = -1;
            }
            else{
                nge[j] = st.peek();
            }
            st.push(nums2[j]);
        }
        
        //using map to find next greater value of elements in nums1 
        for(int i = 0; i < nums2.length; i++){
            map.put(nums2[i], nge[i]);
        }

        for(int i = 0; i < nums1.length; i++){
            ans[i] = map.get(nums1[i]);
        }
        return ans;
    }
}
```

We use a **stack + HashMap**:

1. Traverse `nums2` from right to left (like GFG problem).
    
2. Maintain a stack to find **next greater element** for each number in `nums2`.
    
3. Store the result in a HashMap → `map[num] = nextGreater`.
    
4. Finally, for each number in `nums1`, just lookup `map[num]`.
    

Complexity: **O(n + m)**, where `n = nums1.length`, `m = nums2.length`.

### Daily Temperatures

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int answer[] = new int[temperatures.length]; //result array to return

        Stack<Integer> st = new Stack<>(); //this will store the index of the next warmer temperature (or next greater element)

        for (int i = temperatures.length - 1; i >= 0; i--){
            while (!st.isEmpty() && temperatures[i] >= temperatures[st.peek()]){
                st.pop();
            }
            if(!st.isEmpty()){
                answer[i] = st.peek() - i;
            }
            st.push(i);
        }
        return answer;
    }
}
```

#### More optimal manual stack building

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] answer = new int[n];
        int[] stack = new int[n]; // acts like a stack to store indices
        int top = -1; // pointer for stack top

        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && temperatures[i] >= temperatures[stack[top]]) {
                top--; // pop
            }
            if (top >= 0) {
                answer[i] = stack[top] - i;
            }
            stack[++top] = i; // push
        }
        return answer;
    }
}
```
