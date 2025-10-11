
```java
class Node {
	int data;
	Node next;

	Node(int data){
		this.data = data;
		next = null;
	}
}
```

## Fast and slow pointers
## Cycle related problems:
### Detecting cycle
- naive approach
- **Time Complexity**: `O(n)` (worst case: traverse list once).
- **Space Complexity**: `O(n)` (storing visited nodes in a `HashSet`)
```java
class Solution {
    // Function to check if the linked list has a loop.
    public static boolean detectLoop(Node head) {
        // code here
        if(head == null || head.next == null) return false;
        HashSet <Node> visited = new HashSet<>();
        Node current = head;
        
        while(current != null){
            if(visited.contains(current)){
                return true;
            }
            visited.add(current);
            current = current.next;
        }
        return false;
    }
}
```

- optimised
```java
public static boolean hasCycle(Node head){
	if(head == null || head.next == null) return false; //list is empty or has only one node
	Node slow = head;
	Node fast = head;

	while(fast != null && fast.next != null){ //ensures we don’t get a `NullPointerException` when moving `fast` by two steps.
		slow = slow.next;
		fast = fast.next.next;

		if(slow == fast) return true;
	}
	return false;
}
```

- **Time Complexity**: `O(n)` (worst case: traverse list once).
- **Space Complexity**: `O(1)` (constant extra space).

### Start of cycle
```java
if(hasCycle){
        HashSet <Node> visited = new HashSet<>();
        Node current = head;
        
        while(current != null){
            if(visited.contains(current)) return current;
            visited.add(current);
            current = current.next; 
        }
        return null;	
}
```

```java
if(hasCycle){
	slow = head;
	while(slow != fast){
		slow = slow.next;
		fast = fast.next;
	}
	return slow;
}
```

After finding the “party” (meeting point), send one friend back to the house (head) and have them both walk at the same pace — they’ll meet at the party’s entrance (loop start).

### Remove Cycle
- naive approach
```java
class Solution {
    public static void removeLoop(Node head) {
        // code here
        if(head == null || head.next == null) return;
        
        HashSet<Node> visited = new HashSet<>();
        
        Node prev = null;
        while(head != null){
            if(!visited.contains(head)){
                visited.add(head);
                prev = head;
                head = head.next;
            }
            else{
                prev.next = null;
                break;
            }
        }
    }
}
```

- optimised
```java
class Solution {
    public static void removeLoop(Node head) {
        // code here
        if (head == null || head.next == null) return;
        
        Node slow = head;
        Node fast = head;

        //detect cycle
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            
            if(slow == fast){
                break; //breaks out of while loop and executes rest statements
            }
        }
        
        if(slow != fast) return;
        
        // removing cyle
        slow = head;
        if(slow != fast){
            while(slow.next != fast.next){
                slow = slow.next;
                fast = fast.next;
            }
            //breaking loop if loop doesn't start at head
            fast.next = null;
        }
        //loop start at head
        else{
            while(fast.next != slow){
                fast = fast.next;
            }
            fast.next = null;
        }
           
    }
}
```

---
### Middle of Linked List
- counting nodes then looping till half count
```java
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode temp = head;
        int count = 0;
        if(head == null) return null;
        if(head.next == null) return head;

        //count nodes
        while(temp != null){
            count++;
            temp= temp.next;
        }

        temp = head;
        for(int i = 0; i < count / 2; i++){
            temp = temp.next;
        }
        return temp;
    }
}
```

- slow and fast pointers
```java
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;

```

- **counting approach**: **Two passes** over the list.
- **Slow–fast approach**: **One pass** over the list.
- time and space: O(n) and O(1) for both respecitvely

### Palindrome Linked List
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public ListNode reverse(ListNode head){

        ListNode prev = null;
        ListNode nexxt = null;

        while(head != null){
            nexxt = head.next;
            head.next = prev;
            prev = head;
            head = nexxt;
        }
         return prev;
    }

    public ListNode copyList(ListNode head){
        ListNode dummy = new ListNode(0); //dummy node
        ListNode res = dummy; //to traverse new list
        ListNode temp = head; // totraverse og list
        while(temp != null){
            res.next = new ListNode(temp.val); //traverse copied list and keep creating new node with value that of temp and attach to copied 
            temp = temp.next;
            res = res.next;
        }
        res.next = null;
        return dummy.next;
    }

    public boolean isPalindrome(ListNode head) {

        ListNode copy = copyList(head); //copied list
        ListNode reversed = reverse(copy); //reversing copy as to preserve og list
        if(head == null || head.next == null) return true;

        // ListNode temp2 = reversed; //to traverse reversed list
        while(head != null && reversed != null){
            if(head.val != reversed.val) return false;
            else{
                head = head.next; //move head
                reversed = reversed.next; //move reversed 
            }
        }
        return true;
    }

}
```

- Optimised (slow and fast pointers)
```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;

        //step1: find middle
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        //Step 2: reversin g second half
        ListNode prev = null, curr = slow; //slo points to middle element

        while(curr != null){
            ListNode nexxt = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nexxt;
        }

        ListNode tail = prev;

        //compare both first and second halves
        while(tail != null){
            if(head.val != tail.val) return false;
            head = head.next;
            tail = tail.next;
        }
        return true;
    }    
}
```
---
## Reversal and variation. 

### Reverse a linked list
```java
class Solution {
    Node reverseList(Node head) {
        // code here
        Node current = head, prev = null, nexxt = null;
        while(current != null){
            nexxt = current.next; //keep track of next
            current.next = prev; //connect current to previous
            prev = current; //move previous
            current = nexxt; //move current 
        }
        head = prev;
        return head;
    }
}
```
### Rotate list by k places to left
#### 1. Moving head to tail repeatedly.
```java
class Solution {
    public Node rotate(Node head, int k) {
    
        if(head == null || head.next == null || k == 0) return head;
        
        //find tail and number of nodes in list
        Node tail = head;
        int len = 1;
        while(tail.next != null){
            tail = tail.next;
            len++;
        }
        k %= len;
        
        for(int i = 0; i < k; i++){
            tail.next = head;
            tail = head;
            head = head.next;
            tail.next = null;
        }
        return head;
    }
}
```

Each iteration:
1. `tail.next = head;` → attach the old head to the tail (moving head to the end).
2. `tail = head;` → tail becomes the old head.
3. `head = head.next;` → head moves forward.
4. `tail.next = null;` → cut off the tail’s next pointer.
So you basically **pop the head node and push it to the back**

#### 2. Making list circular
```java
class Solution {
    public Node rotate(Node head, int k) {
        // add code here
        if(head == null || head.next == null || k == 0) return head;
        
        //find tail and number of nodes in list
        Node tail = head;
        int len = 1;
        while(tail.next != null){
            tail = tail.next;
            len++;
        }
        
        k %= len;
        
       if(k == 0) return head;
       
       //make linked list circular
       tail.next = head;
       tail = head;
       
       for(int i = 1; i < k; i++){
           tail = tail.next;
       }
       
 // Update the (k + 1)th node as the new head        
        head = tail.next;
        tail.next = null;
        return head;
    }
}
```
- **Step 1:** Find length (`5`).
- **Step 2:** Make it circular → `1 → 2 → 3 → 4 → 5 → back to 1`
- **Step 3:** Move forward `k` steps to find cut point → land on `2`.
- **Step 4:** Break link after `2` → `3 → 4 → 5 → 1 → 2`
- Done.

O(n) for both.

### Rotate list to right by k places
- by making list circular
```java
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0) return head;

        ListNode temp = head;
        int len = 1;

        //finding number of nodes in list
        while(temp.next != null){
            temp = temp.next;
            len++;
        }

        k %= len;
        if(k == 0) return head;
        //making list circular
        temp.next = head;
        temp = head;
        int newStep = len - k;

        for(int i = 1; i < newStep; i++){
            temp = temp.next;
        }
        head = temp.next;
        temp.next = null;a
        return head;
    }
}
```

### Reverse Linked List II

- Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return _the reversed list_.
```java

class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode beforeLeft = head;
        ListNode leftNode = null;
        if(left == 1){
            beforeLeft = null;
            leftNode = head;
        }
        else{
            //find left node
            for(int i = 1; i < left - 1; i++){
                beforeLeft = beforeLeft.next;
            }

            leftNode = beforeLeft.next;
        }

        ListNode rightNode = head;

        for(int i = 1; i < right; i++){
            rightNode = rightNode.next;
        }

        ListNode afterRight = rightNode.next;
        rightNode.next = null; //to separate the list

        ListNode revHead = reverse(leftNode);

        if(beforeLeft != null) beforeLeft.next = revHead;
        else head = revHead;

/*         ListNode temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = afterRight;
 */        
        leftNode.next = afterRight; //above locs can be done like this. moving node also move their respective pointers with them
        return head;
    }
    public ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode next = null;

        while(head != null){
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}
```

--- 
## Traversals
### Remove Nth Node from List

```java

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //if Lsit is empty
        if(head == null) return null; 

                int len = length(head);
        if( n == len) return head.next; // If we need to remove the head node


        //position from start given from end
        int pos = len - n + 1;
        ListNode temp = head;
        
        for(int i = 1; i < pos - 1; i++){
                temp = temp.next;
        }
        
        //deletion after logic
        if(temp != null && temp.next != null){
            temp.next = temp.next.next;
        }
        return head;
    }

//function to count nodes in list
    public int length(ListNode head){
        int count = 0;
        while(head != null){
            count++;
            head = head.next;
        }
        return count;
    }
}
```

### Merge Two sorted Lists
```java
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0); //head of merged list
        ListNode temp = dummy; //to iterate merged list

//optional can also do but decreases beats 
        // if(list1 == null) return list2;
        // if(list2 == null) return list1;

        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                temp.next = list1;
                list1 = list1.next;
            }
            else{
                temp.next = list2;
                list2 = list2.next;
            }
            temp = temp.next;
        }

        //either one is non empty
        if(list1 != null){
            temp.next = list1;
        }
        else{
            temp.next = list2;
        }
        return dummy.next;
    }
}

```

### Clone list without random pointer
```java

if(head == null) return null;
if(head.next == null) return head; //return new Node(head.val); (if goal is true clone since we are returning og head here)

Node old = head; //traverse old list
Node newHead = new Node(old.val); //new list head
Node newCurr = newHead; //to traverse new list
old = old.next; //move old because head is already copied

while(old != null){
	newCurr.next = new Node(old.val);
	newCurr = newCurr.next;
	old = old.next;
}

return newHead;
```

### Clone List with next and random pointer
1. create clone of each og node in between two nodes in og list. (here random pointers are null initially), so each og node points to clone node and that cloned points to og next node.
2. set random pointers for each node, using og nodes random pointers.
3. separate both lists og and cloned.
4. Time: O(n) and Space: O(1).
```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;

        //step 1: clone each node using "in between" approach
        Node curr = head; //traverse og list

        while(curr != null){
            Node newNode = new Node(curr.val);
            newNode.next = curr.next;
            curr.next = newNode;
            curr = newNode.next;
        }

        //step 2: set random pointers
        curr = head;
        while(curr != null){
            if(curr.random != null) //because by default random pointer is set to null so need to write logic for the same again
                curr.next.random = curr.random.next;
                
            curr= curr.next.next; //move curr regardless
        }
        
        //step 3: separate both lists
        curr = head;
        Node newHead = head.next;
        Node newCurr = newHead;

        while(curr != null){
        //separating og list
            curr.next = newCurr.next;
            curr = curr.next;

			//separating cloned list
            if(curr != null){
                newCurr.next = curr.next;
                newCurr= newCurr.next;
            }
        }

        return newHead;
    }
}
```

### Add two linked list
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0); //sum List head
        ListNode temp = dummy; //traverse sum list

        int carry = 0;
        while( l1 != null || l2 != null ){
            int sum = carry;

            if(l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }

            if(l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }

            carry = sum / 10; //extract tens place
            sum %= 10; //extract unit place
            
            //appending node to sum list 
            temp.next = new ListNode(sum);
            temp = temp.next;
        }

        if(carry == 1) temp.next = new ListNode(1);
        return dummy.next;
    }
}
```