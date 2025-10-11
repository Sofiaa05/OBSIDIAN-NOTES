### Static memory Allocation
-  Memory is allocated **at compile-time** using arrays.
- The size is **fixed** and cannot be changed at runtime.
- we can’t request for reallocation if need arises
- Example: Declaring arrays with fixed size:
```c
int arr[10]; // static allocation
```
### Dynamic memory allocation
- - Memory is allocated **at runtime** using `malloc()`.
- The linked list can grow or shrink dynamically.
- Requires manual deallocation using `free()`
- Using functions like `malloc`, `calloc`, `realloc`, and `free` in C:
```c
int* arr = (int*)malloc(10 * sizeof(int)); // dynamic allocation
```
#### Key Differences: Static vs. Dynamic Memory in Linked Lists:

| Feature               | Static Memory Allocation        | Dynamic Memory Allocation                  |
| --------------------- | ------------------------------- | ------------------------------------------ |
| **Memory Allocation** | At compile-time (fixed size)    | At runtime (flexible size)                 |
| **Size**              | Fixed                           | Grows/shrinks as needed                    |
| **Wastage**           | Possible if unused space exists | Minimal as memory is allocated dynamically |
| **Performance**       | Faster (pre-allocated)          | Slightly slower (malloc overhead)          |
| **Flexibility**       | Limited                         | Highly flexible                            |
| **Deallocation**      | Automatic (stack/array)         | Manual (`free()`)                          |

### Self Referential pointer: 
- Pointer that points to an instance (or object) of the same type as the structure it's part of. 
- In other words, it points to another instance of the same type it is defined in.
##### Example:

In **linked lists** or other data structures like trees where nodes need to point to other nodes of the same type.

```c
struct Node {     
	int data;     
	struct Node* next; // This is the self-referential pointer
};
```

##### Explanation:

- **`struct Node`**: This is a structure that represents a node in a linked list.
- **`next`**: The pointer `next` is a self-referential pointer. It points to another `struct Node` object, meaning that each node in the list can "reference" (point to) the next node in the list.

### Why is it called "self-referential"?

- **"Self-referential"** because the pointer inside the structure refers to the same type of structure (`struct Node*` points to another `struct Node`).
---

## Basic Operations on Singly Linked List:
### 1. Creating a node
```c
// Definition of a Node in a singly linked list
struct Node{
	int data;
	struct Node* link;
};

// Function to create a new Node
struct Node* createNode(int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->link=NULL;
	return newNode;
};
int main(){
	struct Node *head = createNode(2);
    head->link = createNode(5);
    display(head);
}
```

- malloc to allocate memory to both data and pointer. 
- It returns a void pointer which can be typecasted to (struct node) and can be stored in the head pointer. 
- Basically the address will be stored in the head pointer. This head node is capable of accessing the struct node.
---
### 2. Insertion
1. #### Insertion at the beginning:
- Create a new node with the given value.
- Set the **link** pointer of the new node to the current head.
- Move the head to point to the new node.
- Return the new head of the linked list.
 ```c
 struct Node *insBeg(struct Node *head, int data){
	 struct node *newNode=createNode(data);
	 newNode->link=head;
	 head=newNode;
	 return newNode;
 }
int main(){
	head = insBeg(head,33); //because head was passed by value not by reference
	display(head);
}

```

2. ####  At End
- Create a new node with the given value.
- Check if the list is empty:
    - If it is, make the new node the head and return.
- Traverse the list until the last node is reached.
- Link the new node to the current last node by setting the last node's next pointer to the new node.
```c
struct Node *insEnd(struct node *head, int data){
	struct Node *newNode = createNode(data);
	// If the Linked List is empty, make the new node as the head and return
    if (head == NULL) {
        return newNode;
    }
    
	struct Node *temp = head;
	while(temp->link != NULL){
		temp=temp->link;
	}
	temp->link=newNode;
}
int main(){
	insEnd(head,78);
	display(head);
}
```

3. ### Insertion at specific position:
```c
struct Node* insPos(struct node* head, int data, int pos){
	struct Node *newNode = createNode(data);
	struct Node *temp = head;
	pos--;
	while(pos != 1){
		temp = temp->link;
		pos--;
	}
	newNode->link=temp->link;
	temp-link=newNode
	return head;
}
int main(){
	int data = 23, pos = 3;
	insPos(head,data,pos);
	display(head);
}
```
---
### 3. Deletion
1. #### Deletion at beginning:
	- store the current **head**  in a temporary variable **temp
	- move the **head** pointer to the next node
	- delete the temporary head node (temp) using **free(temp)** and return the new **head** of the linked list.
```c
struct Node* delBeg(struct Node* head){
	if (head==NULL){
	printf("List is already empty.")
	}
	struct Node* temp = head;
	head= head->link; //move the head pointer to the next node
	free(temp); //deleting original head (the first node)
	temp=NULL;
	return head;
}
int main(){
	head=delBeg(head);
	display(head);
}
```
2. #### Deletion at End:
- Check if list is empty then return **NULL**.
- If the list has only one node then delete it.
- Traverse the list to find the second last node.
	- Delete the last node.
   - Set the next pointer of **second last** node to **NULL**.
```c
void delEnd(struct node *head){
	if(head==NULL){
		printf("List is already empty");
	}
	//if list has only one node
	else if(head->link==NULL){
		free(head);
		head=NULL;
	}
	else{
	//using only one pointer
		struct Node *temp = head;
		while(temp->link->link != NULL){
			temp=temp->link;
		}
		free(temp->link);
		temp->link=NULL;
	}
}
int main(){
	delEnd(head);
	display(head);
}
```

3. #### Deleting at a certain position:
- If the position is 1, we update the head to point to the next node and delete the current head.
- For other positions, traverse the list to reach the node just before the specified position. If the target node exists, we adjust the **link** of this previous node to point to node next of next node, which will result in skipping the target node.
- delete the target node using **free()**.
```c
struct Node* delPos(struct Node *head, int pos){
	struct Node* temp = head;
	struct Node *prev= NULL;

	if(head==NULL || pos<=0){
		return head;
	}
	else if(pos==1){
		temp=temp->link;
		free(head);
		head=temp;
		return head;
	}
	else{
		while(pos != 1 && temp != NULL){
			prev=temp;
			temp=temp->link;
			pos--;
		}
		if(temp==NULL){
			printf("position out of bounds\n");
			return head;
		}
		prev->link=temp->link;
		free(temp);
		temp=NULL;
	}
	return head;
}

int main(){
	int pos=1;
	head=delPos(head,pos);
	int pos=3;
	head=delPos(head,pos);
	display(head);
}
```

4. #### Deleting entire list:
```c
struct Node* delList(struct Node *head){
	struct Node* temp= head;
	while(temp != NULL){
		temp= temp->link;
		free(head);
		head=temp;
	}
	return head;
}
int main(){
	head=delList(head);
	if(head==NULL){
		printf("List has been deleted successfully.");
	}
}
```
---


### 3. Printing the list

```c
void display(struct node* head){

	if(head==NUll){
		printf("list is empty.");
		return;
	}
	struct node* temp = head;
	while(temp != NULL){
		printf("%d", temp->data);
		temp = temp->data;
	}
}
int main(){
	display(head);
}
``` 
---
### 4. Reversing the list:
```c
ss```
---
### 5. Merge Two sorted Lists
```c
struct Node* mergeLists(struct Node* list1, struct Node *list2){
    if(list1==NULL) return list2;    
    if(list2==NULL) return list1; 

    struct Node* head=NULL;
    if(list1->data <= list2->data){
        head=list1;
        list1= list1->link;
    }
    else{
        head=list2;
        list2= list2->link;
    }
    struct Node* merge=head; // Pointer to track the merged list

    while(list1 != NULL && list2 != NULL){
        if(list1->data<=list2->data){
            merge->link=list1;
            list1=list1->link;
        }
        else{
            merge->link=list2;
            list2=list2->link;
        }
        merge=merge->link; //move merge pointer forward
    }

    if(list1 != NULL){
        merge->link=list1;
    }
    else{
        merge->link=list2;
    }
    return head;
}

int main(){
		//creating sorted list1
        struct Node* list1=createNode(9);
        insEnd(list1,11);
        insEnd(list1,14);
        insEnd(list1,15);

		//creating sorted list2
        struct Node * list2 =createNode(8);
        insEnd(list2,12);
        insEnd(list2,16);
        insEnd(list2,19);
        insEnd(list2,23);
        insEnd(list2,900);

    printf("Merged Sorted Linked List: ");
    display(mergeLists(list1, list2));

}

OUTPUT:
Merged Sorted Linked List: List : 8 9 11 12 14 15 16 19 23 900 
```

### **Steps:**

1. **Check for NULL Lists:**
    
    - If `list1` is `NULL`, return `list2` (nothing to merge).
        
    - If `list2` is `NULL`, return `list1`.
        
2. **Initialize Merged Head:**
    
    - Compare the data of the first nodes of `list1` and `list2`.
        
    - Assign the node with the smaller value to `head` (start of the merged list).
        
    - Move the pointer (`list1` or `list2`) forward accordingly.
        
    - Set `merge` pointer to `head` to build the rest of the merged list.
        
3. **Iteratively Merge Nodes:**
    
    - While both `list1` and `list2` are not `NULL`, do:
        
        - Compare `list1->data` with `list2->data`.
            
        - Append the smaller node to `merge->link`.
            
        - Move the pointer (`list1` or `list2`) forward.
            
        - Move `merge` to `merge->link` (next position in the merged list).
            
4. **Append Remaining Nodes:**
    
    - If `list1` is not `NULL`, append the rest of `list1` to `merge->link`.
        
    - Else, append the rest of `list2` to `merge->link`.
        
5. **Return Result:**
    
    - Return the `head` of the merged list
---
![[Pasted image 20250314205722.png]]

--- 
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node* link;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to insert at the beginning (returns void)
void insBeg(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }

    newNode->link = *head; // Point new node to old head
    *head = newNode; // Update head to point to new node
}

// Function to insert at the end (returns void)
void insEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    
    // If the Linked List is empty, make the new node as the head and return
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;

    // Traverse to the last node
    while (temp->link != NULL) {
        temp = temp->link;
    }

    // Change the next pointer of the last node to point to the new node
    temp->link = newNode;
}

//insertion before

//insertion after

// Function to count the number of nodes in the list
void countNodes(struct Node* head) {
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    printf("Number of nodes in list: %d\n", count);
}

// Function to display the list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Function to delete the first node (returns void)
void delBeg(struct Node **head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->link;
    free(temp);
}

// Function to delete the last node (returns void)
void delEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node *temp = *head;

    // If only one node is present
    if (temp->link == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}


// Function to delete the entire list (returns void)
void delList(struct Node **head) {
    struct Node *temp = *head;
    while (*head != NULL) {
        *head = (*head)->link;
        free(temp);
        *head = temp;
    }
}

// Function to reverse the linked list (returns void)
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *current = *head;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to merge two sorted lists (returns void)
void mergeLists(struct Node **list1, struct Node **list2) {
    struct Node *mergedHead = NULL;
    struct Node *mergedTail = NULL;

    // If either list is empty, return the other list
    if (*list1 == NULL) {
        *list1 = *list2; // Set list1's head to list2's head
        return;
    }
    if (*list2 == NULL) {
        *list2 = *list1;
        return;
    }

    // Merge the two lists
    while (*list1 != NULL && *list2 != NULL) {
        struct Node *temp;
        if ((*list1)->data <= (*list2)->data) {
            temp = *list1;
            *list1 = (*list1)->link;
        } else {
            temp = *list2;
            *list2 = (*list2)->link;
        }

        if (mergedHead == NULL) {
            mergedHead = mergedTail = temp;
        } else {
            mergedTail->link = temp;
            mergedTail = temp;
        }
    }

    // Attach remaining elements of either list
    if (*list1 != NULL) {
        mergedTail->link = *list1;
    } else {
        mergedTail->link = *list2;
    }

    *list1 = mergedHead;
}

int main() {
    // Creating and displaying List 1
    struct Node *list1 = createNode(9);
    insEnd(&list1, 11);
    insEnd(&list1, 14);
    insEnd(&list1, 15);

    printf("List 1: ");
    display(list1);

    // Creating and displaying List 2
    struct Node *list2 = createNode(8);
    insEnd(&list2, 12);
    insEnd(&list2, 16);
    insEnd(&list2, 19);
    insEnd(&list2, 23);
    insEnd(&list2, 900);

    printf("List 2: ");
    display(list2);

    // reverse(&list1);
    display(list1);

    // Merging both lists
    mergeLists(&list1, &list2);

    printf("Merged Sorted Linked List: ");
    display(list1);

    return 0;
}

```

---
## ****Disadvantages Of Linked List********:****

- ****Memory usage:**** More memory is required in the linked list as compared to an array. Because in a linked list, a [pointer](https://www.geeksforgeeks.org/pointers-in-c-and-c-set-1-introduction-arithmetic-and-array/) is also required to store the address of the next element and it requires extra memory for itself.
- ****Traversal:**** In a [Linked list traversal](https://www.geeksforgeeks.org/recursive-insertion-and-traversal-linked-list/) is more time-consuming as compared to an array. Direct access to an element is not possible in a linked list as in an array by index. For example, for accessing a node at position n, one has to traverse all the nodes before it.
- ****Reverse Traversing:**** In a singly linked list reverse traversing is not possible, but in the case of a [doubly-linked list](https://www.geeksforgeeks.org/doubly-linked-list/), it can be possible as it contains a pointer to the previously connected nodes with each node. For performing this extra memory is required for the back pointer hence, there is a wastage of memory.
- ****Random Access:**** Random access is not possible in a linked list due to its [dynamic memory allocation](https://www.geeksforgeeks.org/what-is-dynamic-memory-allocation/).
- ****Complex implementation:****  The linked list implementation is more complex when compared to array. It requires a complex programming understanding.
---
## Create a pseudo code which moves the last element of link list to first elementof the link list.

Traverse the list till the l****ast node****. Use two pointers to store the reference of the ****last node**** and ****second last**** node. After the end of loop, make the ****second last**** node as the ****last**** node and the ****last**** node as the ****head**** node.

```plaintext
FUNCTION moveLastToFront(head)
    IF head == NULL OR head.next == NULL THEN
        RETURN head  // list is empty or has only one node

    SET secondLast = NULL
    SET last = head

    // Traverse till last node
    WHILE last.next != NULL DO
        secondLast = last
        last = last.next

    // Detach last node
    secondLast.next = NULL

    // Make last node new head
    last.next = head
    head = last

    RETURN head
```

## Array vs LL
| Feature                | **Linear List (Linked List)**                  | **Linear Array (Array)**                                      |
| ---------------------- | ---------------------------------------------- | ------------------------------------------------------------- |
| **Memory Allocation**  | Dynamic (nodes allocated at runtime)           | Static (fixed size at compile or defined once at runtime)     |
| **Size**               | Can grow/shrink at runtime                     | Fixed size (unless using dynamic structures like vectors)     |
| **Access Time**        | O(n) for access by index (traverse from head)  | O(1) for access by index                                      |
| **Insertion/Deletion** | O(1) at beginning or middle (if pointer known) | O(n) in worst case (requires shifting)                        |
| **Memory Usage**       | Extra memory for pointer(s) in each node       | Memory-efficient (no overhead per element)                    |
| **Implementation**     | More complex due to pointers                   | Simple (continuous memory layout)                             |

```java
int arr[]
while(num > 0){
	int r = num % 10;
	
	
}
```