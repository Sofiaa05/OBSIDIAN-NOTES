#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));

    head->data =65;
    head->next =NULL;

    struct Node *current = (struct Node *)malloc(sizeof(struct Node));

    current->data = 98;
    current->next = NULL;
    head->next = current;
}