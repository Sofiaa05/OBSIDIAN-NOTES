
A **queue** is a **linear data structure** that follows the **FIFO (First In, First Out) principle**. It means the element added first is removed first, just like a real-life queue (e.g., people waiting in a line).

---

## **1. Queue Operations**

The main operations on a queue are:

1. **Enqueue** → Insert an element at the rear (end) of the queue.
2. **Dequeue** → Remove an element from the front of the queue.
3. **Peek (Front)** → View the front element without removing it.
4. **isEmpty** → Check if the queue is empty.
5. **isFull** → Check if the queue is full (for an array-based queue).
### Queue implementation using array
```c
#include <stdio.h>
#define N 4
int queue[N];
int front = -1, rear =-1;

//underflow()
int underflow(){
    if(front==-1 && rear == -1){
        printf("Undeflow.");
    }
    return 0;
}

//overflow
void overflow(){
   if (rear == N-1){
    printf("Overflow.");
   }
}

//enqueue()
void enqueue(int data){
    overflow();
    if(front==-1 && rear == -1){
        front=rear=0;
        queue[rear]=data;
    }
    rear++;
    queue[rear]=data;  
}

//dequeue()
void dequeue(){
    underflow();
    if(front==rear){ //only one element in queue
        front=rear=-1;
    }
    front++;
}

//getfront()
void getFront(){
    printf("Front = %d",queue[front]);
}
//getRear()
void getRear(){
    printf("Rear = %d",queue[rear]);
}

//display()
void display(){
    if(!underflow()){
    printf("Queue: \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
    }  
}

int main(){
    enqueue(23);
    enqueue(2323);
    enqueue(213);
    enqueue(24);
    enqueue(22);
    enqueue(69);
    dequeue();
    display();
}
```

### Queue implementation using LL:
```c
#include <stdio.h> 
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear=NULL;

// 1. isEmpty()
int isEmpty(){
    return front == NULL && rear == NULL;
}

// 3. enqueue()
void enqueue(int data) {
    struct node *newnode = (struct node * ) malloc(sizeof(struct node));    
        newnode -> data = data;
        newnode->next=NULL;
        if (isEmpty()) {
            front = rear = newnode;
            return;
        } 
        rear -> next = newnode;
        rear = newnode;
}

//dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Underflow");
        return;
    } 
    else if(front==rear){ //when only one node
        front = rear = NULL;
    }
    else{
        struct node* temp;
        temp=front;
        front = front -> next;
        free(temp);
    }
}

void getFront(){
    if(isEmpty()){
        printf("Empty");
    }
    printf("front = %d \n",front->data);
}

void getrear(){
    if(isEmpty()){
        printf("Empty");
    }
    printf("rear = %d \n",rear->data);
}

void display(){
    if (isEmpty()) {
        printf("Underflow");
        return;
    }
    struct node *temp=front;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
int main() {
    enqueue(45);
    enqueue(67);
    enqueue(42);
    enqueue(23);

    getFront();
    getrear();
    dequeue();
    display();

    return 0;
}

```

#### Time Complexity:
- O(1) for  all operations with both arrays and LL, except,
Dequeue (Deletion from Front)	O(n)	Shift all elements after deletion (costly).

---
### Circular Queues:
- A circular queue is the extended version of a regular queue where the last element is connected to the first element. Thus forming a circle-like structure.
- Solves the major limitation of the normal queue. In a normal queue, after a bit of insertion and deletion, there will be non-usable empty space.
#### Basic Operations:
1. enqueue()
2. dequeue()
3. getFront()
4. getRear()
```c
#include <stdio.h>
#define N 3
int q[N];
int front=-1;
int rear=-1;

//underflow
int underflow(){
    return (front==-1 && rear==-1);
}

int overflow(){
    return ((rear+1) % N == front);
}

void enqueue(int data){
    if(overflow()){
        printf("Overflow.\n");
    }
    else if(underflow()){
        front=rear=0;
        q[rear]=data;
    }
    else{
        rear=(rear+1) % N;
        q[rear]=data;
    }
}

void dequeue(){
    if(underflow()){
        printf("Underflow.\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1) % N;
    }
}

void getFront(){
    if(underflow()){
        printf("Underflow.\n");
    }
    printf("front= %d \n", q[front]);
}
void getRear(){
    if(overflow()){
        printf("Overflow.\n");
    }
    printf("rear= %d \n", q[rear]);
}


void display() {
    if (underflow()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while ( i != rear) {
        printf("%d ", q[i]);
        i = (i + 1) % N;
    }
    printf("%d ",q[rear]);
    printf("\n");
}

int main(){
    enqueue(34);
    enqueue(32);
    enqueue(54);
    dequeue();
    getFront();
    display();
    
}
```

O(1) for all operations

---
