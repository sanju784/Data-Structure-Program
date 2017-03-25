#include <stdio.h>
#include <stdlib.h>

int isFull();
int isEmpty();
void initialize();
void push();
void pop();
void display();

struct stack {
	int *s;
	int top;
	int capacity;
}st;

void initialize () {
	st.top = -1;
	st.capacity = 1;
	st.s = (int*)malloc(st.capacity*sizeof(int));
}

int isFull () {
	if(st.top == st.capacity - 1)
		return 1;
	else
		return 0;
}

int isEmpty () {
	if(st.top == -1)
		return 1;
	else
		return 0;
}

void push () {
	int data;
	printf("\nEnter the number you want to push.\n");
	scanf("%d",&data);
	if(isFull()) {
		st.capacity = st.capacity + 1;
		st.s = (int*)realloc(st.s, st.capacity*sizeof(int));
	}
	st.top = st.top + 1;
	st.s[st.top] = data;
}

void pop () {
	if (isEmpty()) {
	  printf("\nThe stack is empty, no pop possible\n");
	} else {
	  int data;
	  data = st.s[st.top];
	  st.top = st.top - 1;
	  printf("\n%d is removed from stack.", data);
	}
}

void display () {
	if(isEmpty()) {
		printf("\nThe Stack is empty.\n");
	} else {
		int i;
		printf("\nThe stack value is\n");
		for (i = st.top;i >=0; i--) {
			printf("%d\n", st.s[i]);
		}
	}
}

void main() {
	int ch;
	initialize();
	do {
		printf("\nEnter the operation you want to perform.\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\n");
		scanf("%d",&ch);
		switch(ch) {
			case 1 :
			  push();
			  break;
			case 2 :
			  pop();
			  break;
			case 3 :
			  display();
			  break;
			case 4 :
			  exit(0);
		}
	} while(1);
}