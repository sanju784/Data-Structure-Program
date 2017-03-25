#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void push (int*, int, int*);
int pop (int*, int*);
void display(int*, int*);
int stack[MAX_SIZE];
int top = -1;

void main() {
  while(1) {
	int ch, val, n;
	printf("\nEnter the option which you want to perform.\n");
	printf("\n1. To push in the stack.");
	printf("\n2. To pop from the stack.");
	printf("\n3. To display the stack elements.");
	printf("\n4. Exit\n\n");
	scanf("%d", &ch);
	switch (ch) {
		case 1 :
		printf("\nEnter the number you want to push in stack.\n");
		scanf("%d", &val);
		push(stack, val, &top);
		break;
		case 2 :
		n = pop(stack, &top);
		printf("\nThe poped value is %d \n",n);
		break;
		case 3 :
		display(stack, &top);
		break;
		case 4 :
		exit(0);
	}
  }
}

void push(int *st, int n, int *h) {
	*h = *h + 1;
	if(*h >= 10) {
		printf("\nStack overflow.\n");
		*h = *h -1;
		return;
	}
	st[*h] = n;
}

void display (int *st, int *h) {
	int i;
	for (i = *h;i >= 0; i--) {
		printf("\n%d", st[i]);
	}
}

int pop (int *st, int *h) {
	int n;
	if(*h == -1) {
		printf("\nStack underflow.\n");
		return;
	}
	n = st[*h];
	*h = *h - 1;
	return n;
}