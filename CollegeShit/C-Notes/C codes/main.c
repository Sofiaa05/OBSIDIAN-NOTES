#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* prev;
   struct Node* next;
};

struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = NULL;
   return newNode;
}

void insLast(struct Node** head, int data) {
   struct Node* newNode = createNode(data);
   if (*head == NULL) {
       *head = newNode;
   } else {
       struct Node* temp = *head;
       while (temp->next != NULL) {
           temp = temp->next;
       }
       temp->next = newNode;
       newNode->prev = temp;
   }
}

void insBeg(struct Node** head, int data) {
   struct Node* newNode = createNode(data);
   if (*head == NULL) {
       *head = newNode;
   } else {
       newNode->next = *head;
       (*head)->prev = newNode;
       *head = newNode;
   }
}

void insBefore(struct Node** head, int before_data, int data) {
   if (*head == NULL) {
       printf("List is empty.\n");
       return;
   }
   if ((*head)->data == before_data) {
       insBeg(head, data);
       return;
   }
   struct Node* temp = *head;
   while (temp != NULL) {
       if (temp->data == before_data) {
           struct Node* newNode = createNode(data);
           newNode->next = temp;
           newNode->prev = temp->prev;
           temp->prev->next = newNode;
           temp->prev = newNode;
           return;
       }
       temp = temp->next;
   }
   printf("Node with data %d not found.\n", before_data);
}

void delLast(struct Node** head) {
   if (*head == NULL) {
       printf("List is empty.\n");
       return;
   }
   if ((*head)->next == NULL) {
       free(*head);
       *head = NULL;
       return;
   }
   struct Node* temp = *head;
   while (temp->next != NULL) {
       temp = temp->next;
   }
   temp->prev->next = NULL;
   free(temp);
}

void delBeg(struct Node** head) {
   if (*head == NULL) {
       printf("List is empty.\n");
       return;
   }
   if ((*head)->next == NULL) {
       free(*head);
       *head = NULL;
       return;
   }
   struct Node* temp = *head;
   *head = (*head)->next;
   (*head)->prev = NULL;
   free(temp);
}

void display(struct Node* head) {
   struct Node* temp = head;
   while (temp != NULL) {
       printf("%d <-> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}

int main() {
   struct Node* head = NULL;
   int choice, data, before_data;

   while (1) {
       printf("\nDoubly Linked List Operations:\n");
       printf("1. Insert at Last\n");
       printf("2. Insert at Beginning\n");
       printf("3. Insert Before\n");
       printf("4. Delete Last\n");
       printf("5. Delete Beginning\n");
       printf("6. Display\n");
       printf("7. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Enter data: ");
               scanf("%d", &data);
               insLast(&head, data);
               break;
           case 2:
               printf("Enter data: ");
               scanf("%d", &data);
               insBeg(&head, data);
               break;
           case 3:
               printf("Enter data before which to insert: ");
               scanf("%d", &before_data);
               printf("Enter data: ");
               scanf("%d", &data);
               insBefore(&head, before_data, data);
               break;
           case 4:
               delLast(&head);
               break;
           case 5:
               delBeg(&head);
               break;
           case 6:
               display(head);
               break;
           case 7:
               exit(0);
           default:
               printf("Invalid choice. Please try again.\n");
       }
   }

   return 0;
}
