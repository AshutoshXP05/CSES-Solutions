
// // #include<stdio.h>
// // #include<stdlib.h>
// // #include<string.h>

// // #define MAX 10

// // int st[MAX], top=-1;

// // void pushA(int val) {
// //      if ( top == MAX -1 ) { printf("Stack Overflow\n"); return ; }  
// //      st[++top] = val;
// //      printf("%d pushed into stack of Array \n", val);
// //     }

// // int  popA () {
// //       if ( top == -1 ) { printf("Stack underflow \n");}
// //       else printf("%d is popped from stack of array \n", st[top--]);
// //         return st[top--];
// //     }

// // int peekA() {
// //   if ( top == -1 ) { printf("Stack underflow \n");}
// //   else printf("%d is peedked from stack of array \n", st[top]);
// //   return -1;
// // }

// // void displayA() {
// //     if ( top == -1 ) { printf("Stack is empty \n"); return;}
// //     printf("Stack from Array element \n");
// //     for ( int i=top; i>=0; i-- ) {
// //         printf("%d ", st[i]);
// //     }
// // }

// // // stack using linked list ------

// // struct Node {
// //      int data;
// //      struct Node* next ; 
// // };
 
// // struct Node* temp = NULL;

// // void push(int val) {
// //      struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
// //      newnode -> data = val;
// //      newnode -> next = temp;
// //      temp = newnode;
// //      printf("%d is pushed into stack \n", val ); 
// // }

// // int pop () {
// //     if ( temp == NULL ) {
// //       printf("Stack is underflow \n");
// //       return -1 ;
// //     }
// //     struct Node* del = temp;
// //     printf("%d is popped ", del -> data );
// //     temp  = temp -> next;
// //     free(del);
// //     // return val;
// // }

// // int peek () {
// //      if ( temp == NULL ) {
// //       printf("Stack is empty \n");
// //       return -1;
// //      }
// //       printf("Peeked element is %d \n", temp -> data);
// // }
 
// // void display () {
// //   if ( temp == NULL ) {
// //     printf("Stack is empty \n");
// //     return;
// //    }
// //     struct Node* curr = temp;

// //     printf("Stack from linked list  \n");
// //     while ( curr != NULL ) {
// //        printf("%d ", curr -> data ) ;
// //        curr = curr -> next;
// //     }
// // }

// // int main () {
// //     printf("Stack using array \n\n");
// //     pushA(10);
// //     pushA(20);
// //     popA();
// //     pushA(30);
// //     pushA(40);
// //     pushA(50);
// //     pushA(60);
// //     popA();
// //     popA();
// //     peekA();
// //     displayA();

// //     printf("Stack using Linked List \n\n");
// //     push(10);
// //     push(20);
// //     popA();
// //     pushA(30);
// //     push(40);
// //     pop();
// //     pop();
// //     peek();
// //     display();

// //     return 0;
// // } 

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 3

// int st[MAX], top = -1;

// // Stack using Array
// void pushA(int val) {
//     if (top == MAX - 1) {
//         printf("Stack Overflow\n");
//         return;
//     }
//     st[++top] = val;
//     printf("%d pushed into stack of Array\n", val);
// }

// int popA() {
//     if (top == -1) {
//         printf("Stack underflow\n");
//         return -1;
//     }
//     printf("%d is popped from stack of array\n", st[top]);
//     return st[top--];
// }

// int peekA() {
//     if (top == -1) {
//         printf("Stack underflow\n");
//         return -1;
//     }
//     printf("%d is peeked from stack of array\n", st[top]);
//     return st[top];
// }

// void displayA() {
//     if (top == -1) {
//         printf("Stack is empty\n");
//         return;
//     }
//     printf("Stack from Array elements: ");
//     for (int i = top; i >= 0; i--) {
//         printf("%d ", st[i]);
//     }
//     printf("\n");
// }

// // Stack using Linked List
// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* temp = NULL;

// void push(int val) {
//     struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//     newnode->data = val;
//     newnode->next = temp;
//     temp = newnode;
//     printf("%d is pushed into stack\n", val);
// }

// int pop() {
//     if (temp == NULL) {
//         printf("Stack underflow\n");
//         return -1;
//     }
//     struct Node* del = temp;
//     int val = del->data;
//     printf("%d is popped\n", val);
//     temp = temp->next;
//     free(del);
//     return val;
// }

// int peek() {
//     if (temp == NULL) {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     printf("Peeked element is %d\n", temp->data);
//     return temp->data;
// }

// void display() {
//     if (temp == NULL) {
//         printf("Stack is empty\n");
//         return;
//     }
//     struct Node* curr = temp;
//     printf("Stack from Linked List: ");
//     while (curr != NULL) {
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }
//     printf("\n");
// }

// int main() {
//     printf("Stack using array\n\n");
//     pushA(10);
//     pushA(20);
//     popA();
//     pushA(30);
//     pushA(40);
//     pushA(50);  // Stack Overflow
//     pushA(60);  // Stack Overflow
//     popA();
//     popA();
//     peekA();
//     displayA();

//     printf("\nStack using Linked List\n\n");
//     push(10);
//     push(20);
//     pop();
//     push(30);
//     push(40);
//     pop();
//     pop();
//     peek();
//     display();

//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// #define MAX 8

// int st[MAX], top = -1;
// void push ( int st[] , int val ) {

//      if ( top == MAX - 1 ){
//         printf("Stack is overflow \n");
//      }
//      else {
//         top ++;
//         st[top] = val;
//      }
// }

// void pop ( int st[] ) {
  
//      if ( top == -1 ) {
//         printf("Stack is Underflow \n");

//      }
//      else {
//          printf("Popped item is %d \n", st[top]);
//          top --;
//      }
// }

// int peek ( int st[]) {

//   if ( top == -1 ) {
//     printf("Stack is Underflow \n");

//  }
//  else {
//      printf("Peeked item is %d \n", st[top]);
//  }

// }
 
// void display ( int st[]) {
//   if ( top == -1 ) {
//     printf("Stack is Underflow \n");

//  }
//  else {
//   printf(" Item in stack are ");
//      for ( int i=top; i>= 0; i-- ) {
//       printf("%d ", st[i]);

//     }
//     printf("\n");
//      }
//  }

// int main () {
    
//   printf("\nStack using Array List\n\n");
//       push(st , 10);
//       push(st, 20);
//       pop(st);
//       push(st,30);
//       push(st,70);
//       push(st,60);
//       push(st, 40);
//       pop(st);
//       pop(st);
//       peek(st);
//       display(st);
  
//       return 0;
   
// }

// #include<stdio.h>
// #include<stdlib.h>

// // #define MAX 8

// struct Node {
//    int data;
//    struct Node* next;
// };

// struct Node* top = NULL;

// // int top = -1;

// void push ( struct Node* top, int val ) {
    
   
//        struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
//        newnode -> data = val;
      
//        if ( top == NULL ) {
//           //  newnode = temp;
//           newnode -> next = NULL;
//          top = newnode;

//        }
//        else {
//           newnode -> next = top;
//           top = newnode;
//        }
//         printf("Pushed item is %d ", top -> data);
//     }
   

// void pop ( struct Node* top ) {
//   struct Node* ptr = top;
//   ptr = top;
//      if ( top == NULL ) {
//         printf("Stack is empty \n");

//      }
//      else {
//         printf("Popped item is : %d  ",  ptr -> data );
//         free(ptr);
//         top = top -> next;
//      }
     
// }


// void peek ( struct Node* top ) {
//     if ( top == NULL ) printf("Stack is empty ");



// else {
//    printf("Peeked item is :  %d " ,  top -> data );
// }
// }
// void display ( struct Node* top ) {
//     struct Node* curr = top;
//     printf("Element in stack are : ");
//     while ( curr!= NULL ) {
//        printf("%d ", curr -> data );
//        curr = curr -> next;
//     }
// }

// int main () {
  
//   printf("\nStack using Linked List\n\n");
//       push(top , 10);
//       push(top, 20);
//       pop(top);
//       push(top,30);
//       push(top,70);
//       push(top,60);
//       push(top, 40);
//       pop(top);
//       pop(top);
//       peek(top);
//       display(top);
// }



// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* top = NULL;

// void push(int val) {
//     struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//     if (newnode == NULL) {
//         printf("Stack overflow\n");
//         return;
//     }
//     newnode->data = val;
//     newnode->next = top;
//     top = newnode;
//     printf("Pushed item is %d\n", top->data);
// }

// void pop() {
//     if (top == NULL) {
//         printf("Stack is empty\n");
//         return;
//     }
//     struct Node* temp = top;
//     printf("Popped item is: %d\n", temp->data);
//     top = top->next;
//     free(temp);
// }

// void peek() {
//     if (top == NULL) {
//         printf("Stack is empty\n");
//         return;
//     }
//     printf("Peeked item is: %d\n", top->data);
// }

// void display() {
//     if (top == NULL) {
//         printf("Stack is empty\n");
//         return;
//     }
//     struct Node* curr = top;
//     printf("Elements in stack are: ");
//     while (curr != NULL) {
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }
//     printf("\n");
// }

// int main() {
//     printf("\nStack using Linked List\n\n");
//     push(10);
//     push(20);
//     pop();
//     push(30);
//     push(70);
//     push(60);
//     push(40);
//     pop();
//     pop();
//     peek();
//     display();

//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// int stk[10], top = -1;

// void push ( int val ) {
//       stk[++top] = val;
// } 

// int pop () {
//      return stk[top--];
// }

// int main () {
//      int val, n,i;
//      int arr[10];
//       printf("Enter the number of element in array \n");
//       scanf("%d", &n); 
//       for ( int i=0; i<n; i++ ) {
          
//           scanf("%d", &arr[i]);
//       }
//       for ( int i=0; i<n;i++ ) {
//           push(arr[i]);
//       }
//       for ( int i=0; i<n; i++ ) {
//           arr[i] = pop();
//       }
//       printf("Reversed array is \n");
//       for ( int i=0; i<n; i++ ) {
//           printf("%d ", arr[i]);
//       }
// }


// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<stdbool.h>

// #define MAX 30

// int st[MAX], top = -1;

// void push ( char ch ) {
//     st[++top] = ch;
// }

// void pop() {
//   if ( top >= 0)
//     top --;
// }

// char peek () {
//   if ( top == -1 ) return '\0';
//    else return st[top];
// }

// bool isEmpty() {
//    if ( top == -1 ) return true;
//    else return false;
// }

// int main () {
//      char exp[MAX];
//     printf("Enter the expression \n");
//     scanf("%s", exp);
//       for (int i=0; i<strlen(exp); i++ ) {
//          if ( exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
//               push(exp[i]);
//          }
//         else if ( exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
//            if  ((exp[i] == ')' && peek() == '(') || (exp[i] == '}' && peek() == '{') || (exp[i] == ']' && peek() == '[') ) {
//                  pop();
//            }
//            else {push(exp[i]);
//            break;}
//      }
//       }
//       if ( isEmpty() ) {
//           printf("Balanced expression \n");
//       }
//       else {
//           printf("Unbalanced expression \n");
//       }
// }



// A programming example to evaluate a postfix expression using stack


// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<ctype.h>
// #include<math.h>

// #define MAX 30

// int st[MAX], top = -1;

// void push ( int val ) {
//   if ( top == MAX - 1 ) printf("Overflow");
//   else  st[++top] = val;
// }

// int pop () {
//   if ( top == -1 )  printf("Underflow");
//   else
//     return st[top--];
// }

// int main () {
//     char str[MAX];
//     printf("Enter the expression \n");
//     scanf("%s", str);
//     for ( int i=0; i<strlen(str); i++ ) {
//         if ( isdigit(str[i])) {
//             push(str[i] - '0');
//         }
//         else {
//             int val1 = pop();
//             int val2 = pop();
//            if ( str[i] == '+' ) push (val2 + val1);
//           else if ( str[i] == '-' ) push (val2 - val1);
//           else if ( str[i] == '*' ) push (val2 * val1);
//           else if ( str[i] == '/' ) push (val2 / val1);
//           else if ( str[i] == '%' ) push (val2 % val1);
//           else if ( str[i] == '^' ) push (pow(val2,val1));
//         }
//     }
//     printf("Result is %d \n", pop());
// }

// #include<stdio.h>
// #include<stdlib.h>

// struct Node {
//   int data;
//   struct Node* next;
// };


// struct Node*  createNodeFindMax (  int n) {
//   // int maxi = -1;
//    struct Node* head = NULL;
//    struct Node* temp = NULL;
//    for ( int i=0; i<n; i++ ) {
//       struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
//       printf("Enter data");
//       int data;
//       scanf("%d", &data);
//       // if ( data > maxi ) maxi = data;
//       newnode -> data = data;
//       newnode -> next = NULL;
//       if  ( head == NULL  ) {
//           head = newnode;
//           temp = head;
//       }
//       else {
//           temp -> next = newnode;
//           temp = newnode;
//       }
//    }
//    temp -> next = head;
//    return head;
// }

// struct 

// struct Node* reverse ( struct Node* head, struct Node* temp) {
     
// }


// #include<stdio.h>

// void swap ( int* a , int* b) {
//     int temp = *b ;
//     *a = *b;
//     *b = temp;
// }

// int partition ( int arr[], int low, int high ) {
//    int pivot = arr[low];
//    int i = low + 1; 
//    int j = high;
//    while ( i <= j ) {
//     while ( i <= high && arr[i] <= pivot ) i++;
//     while ( arr[j] >= pivot ) j--;
//     if ( i < j )
//     swap(&arr[i], &arr[j]);  
//   }
//   swap(&arr[j], &arr[low]);
//   return j;
// }

// void quicksort ( int arr[], int low , int high ) {
//      if ( low < high ) {
//          int pi = partition(arr, low, high);
//          quicksort(arr, low,pi-1);
//          quicksort(arr, pi+1,high);
//      }
// }

// int main () {
    
// }


// #include<stdio.h>

// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partition ( int arr[], int low, int high ) {
//      int i = low + 1;
//      int j = high - 1;
//      int pivot = arr[low];
//      while  ( i < j ) {
//         while ( i <= high && arr[i] <= pivot ) i++;
//          while ( arr[j] >= pivot ) j--;
//          swap(&arr[i], &arr[j]);
//      }
//      swap(&arr[j], pivot);
//      return j;
// }

// void quicksort(int arr[], int low, int high ) {
//     if ( low < high ) {
//         int pi = partition(arr, low, high);
//         quicksort(arr, low, pi-1);
//         quicksort(arr, pi+1, high);

//     }
// }

// int main () {
    
// }


// #include<stdio.h>

// void merge(int arr[], int low, int mid , int high ) {
//     int n1 = mid - left + 1;
//     int n2 = high - mid;

//     int L[n1], R[n2];
//      int i =0;
//      int j = 0;

//      while ( i < n1 ) {
//        L[i] = arr[left+i];
//        i++;
//      }
//      while ( j < n2) {
//        R[i] = arr[mid+j+1];
//        j++;
//      }

//      i = 0;
//      j = 0;
//      int k = left ;
//      while (i < n1 && j < n2 ) {
//          if ( L[i] <= R[j] ) {
//              arr[k] = L[i];
//              i++;
//          }
//          else {
//           arr[k] = R[j];
//             j++;
//          }
//          k++;
//      }

//      while ( i < n1  ) {
//         arr[k] = L[i];
//         k++ ;
//         i++ ;
//      }

//      while ( j < n2  ) {
//       arr[k] = L[j];
//       k++ ;
//       j++ ;
//    }

   
// }


// void mergersort(int arr[], int low, int high ) {
//     if ( low < high ) {
//       int mid = ( low + high ) / 2;
//           mergersort(arr, low, mid);
//           mergersort(arr, mid+1, high);
//           merge(arr, low, mid, high);
//     }
// }


// int main () {

// }


// #include<stdio.h>

// void merge(int arr[], int low, int mid, int high ) {
//      int n1 = mid - low + 1;
//      int n2 = high - low;
//      int L[n1] , R[n2];
//      int i =0;
//      int j = 0;
//      while ( i < n1 ) {
//         L[i] = arr[left + i];
//          i++;
//      }
//      while (j < n2 ) {
//          R[j] = arr[mid+1+j];
//          j++;
//      }
//      i = 0;
//      j = 0;
//      int k = left;
//      while ( i < n1 && j < n2) {
//          if ( L[i] <= R[j]) {
//              arr[k] = L[i];
//              i++;
//          }
//          else {
//             arr[k] = R[j];
//             j++ ;
//          }
//          k++;
//      }
//      while ( i < n1) {
//        arr[k ] = L[i];
//        k++;
//        i++;
//      }
//      while ( j < n2) {
//        arr[k] = R[j];
//        k++ ;
//        j++;
//      }
// }

// void mergersort( int arr[], int low, int high ) {
//      if  ( low < high ) {
//          int mid = ( low + high ) / 2;
//          mergersort(arr, low, mid);
//          mergersort(arr, mid+1, high);
//          merge(arr, low, mid, high );
//      }
// }

// int main () {

// }



// #include<stdio.h>

// void insertion(int arr[], int n ) {
//      int i = 1;
//       while ( i < n ) {
//          int key = arr[i];
//          int j = i - 1;

//          while ( j >= 0 && arr[j] > key ) {
//              arr[j+1] = arr[j];
//              j--;
//          }
//          arr[j+1] = key; 
//          i++;
//       }
// }

// void printArray(int arr[], int size) {
//   int i = 0;
//   while (i < size) {
//       printf("%d ", arr[i]);
//       i++;
//   }
//   printf("\n");
// }

// int main () {
//    int arr[] = {1,2,7,3,6,3,7,8,1,4,6};
//    insertion(arr,11);
//    printArray(arr,11);
// }



#include<stdio.h>

void swap(int* a, int* b) {
      int temp = *a;
      *a = *b;
      *b = temp;
  }

void selection(int arr[], int n)  {
    int i = 0;
    while ( i < n-1) {
         int minind = i ;
         int j = i+1;

         while ( j < n ) {
             if ( arr[j] < arr[minind]) {
                 minind = j;
             }
             j++;
         }
        swap(&arr[i], &arr[minind]);
        i++;
    }
}


void printArray(int arr[], int size) {
  int i = 0;
  while (i < size) {
      printf("%d ", arr[i]);
      i++;
  }
  printf("\n");
}

int main () {
   int arr[] = {1,2,7,3,6,3,7,8,1,4,6};
   selection(arr,11);
   printArray(arr,11);
}