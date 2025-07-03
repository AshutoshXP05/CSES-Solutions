#include<stdio.h>
#include<stdlib.h>

    struct Node
    {
       int data;
       struct Node* next;
    };
    
    struct Node* createList ( int n ) {
         struct Node* temp = NULL;
         struct Node* head = NULL;
         struct Node* newnode;
         for ( int i=1; i<=n; i++ ) {
             newnode = (struct Node*) malloc ( sizeof (struct Node));
             newnode -> data = i;
             newnode -> next = NULL;
             if ( head == NULL ) {
                 head = newnode;
                 temp = head;
             }
             else {
                temp -> next = newnode;
                temp = newnode ;
             }
             
         }
         temp -> next = head;
         return head;
        }
         void orderOfDelete ( struct Node* head, int n ) {
            struct Node* temp = head;
            struct Node* temp2 = temp -> next -> next;
            while ( n != 2 ) {
                printf("%d ", temp -> next -> data);
                temp -> next = temp2;
                temp = temp2;
                temp2 = temp2 -> next -> next; 
                n--;
            }
            printf("%d ", temp -> next -> data);
            printf("%d ", temp -> data);
         }

 int main () {
             int n;
             scanf("%d", &n);
             if ( n == 1 ) {printf("%d", 1 ) ; return 0; }
             struct Node* head = NULL;
             head = createList(n);
             orderOfDelete(head, n);
             return 0;
         }
    
