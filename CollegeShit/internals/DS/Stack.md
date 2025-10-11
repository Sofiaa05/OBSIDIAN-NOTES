 
A **stack** is a **linear data structure** that follows the **LIFO (Last In, First Out) principle**. It means the last element added to the stack is the first one to be removed.

---

## **1. Stack Operations**

The main operations on a stack are:

1. **Push** → Insert an element at the top of the stack.
2. **Pop** → Remove the top element from the stack.
3. **Peek (Top)** → View the top element without removing it.
4. **isEmpty** → Check if the stack is empty.
### Stack implementation using arrays:
```c
#include <stdio.h>
#define N 5
int stack[N];
int top=-1;
 
//1. Underflow
void underflow(){
    if (top==-1){
        printf("Underflow.\n");
    }
}

//2. overflow
void overflow(){
    if(top==N-1){
        printf("Overflow\n");
    }
}

//3. push()
void push(int value){
    overflow();
    top++;
    stack[top]=value;
}

//4. pop()
void pop(){
    underflow();
    top--; 
}

//5. peek()
void peek(){
    underflow();
    printf("Top element of stack is: %d \n",stack[top]);
}

//display()
void display(){
    underflow();
    printf("Stack: \n");
    int i;
    for (i=top; i >= 0; i--){
        printf("%d \n",stack[i]);
    }
}

int main(){
    underflow();
    push(23);
    push(22);
    push(21);
    peek();
    pop();
    display();
}
```
---
### Stack Implementation using Linked Lists:
```c
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

//underflow
void underflow(){
    if (top==NULL){
        printf("Underflow.\n");
    }
}

//push()
void push(int data){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=top;
    top=newnode; //moving top pointer upwards
}

//pop()
void pop(){
    underflow();
    struct node *temp;
    temp=top;
    top=top->next; //moving top pointer downwards 
    free(temp);
}

//peek()
void peek(){
    underflow();
    printf("Top element= %d\n", top->data);
}

void display(){
    underflow();
    struct node* temp;
    temp=top;
    printf("Stack: \n");
    while (temp != NULL){
        printf("%d \n",temp->data);
        temp=temp->next; //moving temp pointer down
    }
}

int main(){
    underflow();
    push(34);
    push(69);
    push(45);
    peek();
    display();
    pop();
    display();
}
```
---

### Polish and Reverse Polish Notations:
prefix and postfix notations.
Precedency rule:
![[Pasted image 20250315112804.png]]

#### infix to postfix algorithm:

1. **Initialize an empty stack** to store operators and an **empty string** for the postfix expression.
2. Scan the infix expression **from left to right**. 
3. If the scanned character is an operand, put it in the postfix expression. 
4. Otherwise, do the following
    - If precedency of **current > top** || if the **stack is empty** || if the **stack contains a ‘(‘**, then push the current operator onto the stack (push(current)).
    - Else, **current < top**, then, pop all operators from the stack that have precedence higher than or equal to that of the current operator. After that push the current operator onto the stack.
5. If the scanned character is a ‘****(****‘, push it to the stack. 
6. If the scanned character is a ‘****)****’, pop the stack and output it until a ‘****(****‘ is encountered, and discard both the parenthesis. 
7. Repeat steps **2-5** until the infix expression is scanned. 
8. Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
9. Finally, print the postfix expression.

#### infix to prefix algorithm:
1. Reverse the infix expression, each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
2. Convert the reversed infix expression to postfix expression (above algorithm).
3. Reverse the postfix expression and return it.
---
- The **time complexity** for most stack operations remains **O(1)** whether you're using **arrays** or **linked lists**.