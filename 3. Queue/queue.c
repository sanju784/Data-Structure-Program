#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
  return front == -1;
}

bool isFull() {
  return rear == MAX_SIZE - 1;
}

void enque(int n) {
  if(isEmpty()) {
    front++;
  }
  queue[++rear] = n;
}

int deque() {
  if(rear == front) {
    int n = queue[front];
	rear = front = -1;
	return n;
  }
  return queue[front++];
}

int top() {
  return queue[front];
}

void display() {
  int i;
  for(i = front; i <= rear; i++) {
    printf("-->%d", queue[i]);
  }
}

void main() {
  int ch, n;
  do {
    printf("\nEnter your choice\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit.\n");
	scanf("%d", &ch);
	switch(ch) {
	  case 1:
	    if(isFull()) {
		  printf("\nOverflow");
		} else {
	      printf("\nEnter number you want to insert.\n");
		  scanf("%d", &n);
		  enque(n);
		}
		break;
	  case 2:
	    if(isEmpty()) {
		  printf("\nUnderFlow\n");
		} else {
		  printf("\n%d is removed from Queue\n", deque());
		}
		break;
	  case 3:
	    if(isEmpty()) {
		  printf("\nUnderflow\n");
		} else {
		  display();
		}
		break;
	}
  } while(ch != 4);
}




















