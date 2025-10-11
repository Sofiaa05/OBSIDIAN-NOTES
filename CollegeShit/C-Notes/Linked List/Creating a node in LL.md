```C
#include <stdio.h>
#include <stdlib.h> //to call malloc() function

struct Node{
    int data; //to store data
    struct Node *next; //pointer to next node. Self referential pointer
};

int main(){
    struct Node *head = NULL;  //this pointer can point to both data and next node 
    head=(struct Node *)malloc(sizeof(struct Node));

    head->data=69;
    head->next=NULL;

    printf("%d",head->data);
    return  0;
}

OUTPUT: 69
```

malloc to allocate memory to both data and pointer. malloc returns a void pointer which can be typecasted to (struct node), which can be stored in the head pointer. basically the address will be stored in the head pointer. this head node is capable of accessing the struct node.