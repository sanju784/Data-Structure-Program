#include <stdio.h>
#include <stdlib.h>

struct stack {
  int data;
  struct stack *next;
};

void push (struct stack**, int);
void pop(struct stack**);
void display(struct stack**);

void main() {
  int ch, val, n;
  struct stack *head = NULL;
  do{
    printf("\nEnter the option for the operation which you want to perform.\n\n");
	  printf("\n1. Push onto stack.\n2. Pop from stack. \n3. Display the stack. \n4. Exit.\n");
	  scanf("%d", &ch);
	switch (ch) {
	  case 1 :
	    printf("\nEnter the number you want to push.\n");
		  scanf("%d",&val);
		  push(&head, val);
		  break;
	  case 2 :
	    pop(&head);
		  break;
	  case 3 :
	    display(&head);
		  break;
	  case 4 :
	    exit(0);
	}
  } while (1);
}

void push (struct stack **h, int no) {
  struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));
  newNode->data = no;
  newNode->next = *h;
  *h = newNode;
}

void pop (struct stack **h) {
  int val;
  if (*h == NULL) {
    printf("\nThe stack is empty. This is the case of underflow.\n");
	  return;
  }
  struct stack *temp;
  temp = *h;
  val = (*h)->data;
  *h = (*h)->next;
  printf("\nThe value deleted from stack is %d\n", val);
  free(temp);
}

void  display (struct stack **h) {
  struct stack *temp;
  temp = *h;
  printf("\nThe stack elements are\n");
  while (temp != NULL) {
    printf("%d\n", temp->data);
	  temp = temp->next;
  }
}