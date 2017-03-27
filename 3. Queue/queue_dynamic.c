#include <stdio.h>
#include <stdlib.h>

struct queue {
	int *data;
	int front; // Deletion
	int rear; // Insertion
	int capacity;
}q;

void initialize();
void enqueue();
void dequeue();
void display();
int isFull();
int isEmpty();

void initialize() {
	q.front = -1;
	q.rear = -1;
	q.capacity = 1;
	q.data = (int*)malloc(q.capacity*sizeof(int));
}

int isFull() {
	if(q.front == 0 && q.rear == q.capacity - 1)
		return 1;
	if((q.rear + 1) % q.capacity == q.front)
		return 1;
	return 0;
}

int isEmpty() {
	if(q.front == -1)
		return 1;
	else
		return 0;
}

void enqueue () {
	int val;
	printf("\nEnter the data of queue.\n");
	scanf("%d", &val);
	if(isEmpty()) {
		q.front++;
		q.rear++;
	} else if(isFull()) {
		q.capacity *= 2;
		q.data = (int*)realloc(q.data, q.capacity*sizeof(int));
		if(q.front <= q.rear) {
		  q.rear++;
	    } else {
		  int i = q.capacity/2 - 1;
		  int j = q.capacity - 1;
		  while(i >= q.front) {
			q.data[j] = q.data[i];
			i--;
			j--;
		  }
		q.rear++;
	  }
	} else {
	  q.rear++;
	}
	q.data[q.rear] = val;
}

void dequeue() {
	if(isEmpty()) {
		printf("\nThe queue is empty\n");
		return;
	}
	int val;
	val = q.data[q.front];
	if(q.rear == q.front)
		q.rear = q.front = -1;
	else
		q.front += 1;
	printf("\n%d is removed from queue\n", val);
}

void display() {
	if(isEmpty()) {
		printf("\nThe queue is empty\n");
	    return;
	}
	printf("\nThe queue values are\n");
	int i = q.front;
	while (1) {
	  printf("  %d", q.data[i]);
	  if(i == q.rear)
	  	break;
      if(i == q.capacity)
		i = 0;
	  else
		i++;
	}
}

void main() {
	int ch;
	initialize();
	do {
		printf("\nEnter your choice of operation.\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1 :
			  enqueue();
			  break;
			case 2 :
			  dequeue();
			  break;
			case 3 :
			  display();
			  break;
			case 4 :
			  exit(0);
		}
	} while (1);
}