#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int n) {
	stack[++top] = n;
}

int pop() {
	return stack[top--];
}

void print() {
	int i;
	for(i = top; i >= 0; i--) {
		printf("\n%d", stack[i]);
	}
}

int topS() {
	return stack[top];
}

bool isEmpty() {
	return top == -1;
}

bool isFull() {
	return top == MAX_SIZE - 1;
}

void main() {
	int ch, n;
	do {
	  printf("\nEnter your choice\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n");
	  scanf("%d", &ch);
	  switch (ch) {
		case 1:
		if (isFull()) {
			printf("\nStack OverFlow\n");
		} else {
		  printf("\nEnter no you want to push\n");
		  scanf("%d", &n);
		  push(n);
		}
		break;
		case 2:
		if(isEmpty()) {
			printf("\nStack underflow\n");
		} else {
		  printf("\n%d is removed from Stack\n", pop());
		}
		break;
		case 3:
		if(isEmpty()) {
			printf("\nStack underflow\n");
		} else {
			printf("\n%d is at top of Stack\n", topS());
		}
		break;
		case 4:
		if(isEmpty()) {
			printf("\nStack is Empty\n");
		} else {
			printf("\nThe elements in Stack are\n");
			print();
		}
		break;
		default:
		printf("\nEnter Correct choice\n");
	  }
    }while (ch != 5);
}