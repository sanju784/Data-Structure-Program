#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void enqueue(int *, int *, int *);
void dequeue(int *, int *, int *);
void display(int *, int *, int *);

void main() {
	int ch;
	int front = -1, rear = -1; //first in first out so insert at front
	int queue[MAX_SIZE];
	do {
		printf("\nEnter your choice of operation.\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1 :
			  enqueue(queue, &front, &rear);
			  break;
			case 2 :
			  dequeue(queue, &front, &rear);
			  break;
			case 3 :
			  display(queue, &front, &rear);
			  break;
			case 4 :
			  exit(0);
		}
	} while (1);
}

void enqueue(int q[], int *f, int *r) {
  int val;
  printf("\nEnter the data you want to enqueue.\n");
  scanf("%d", &val);
  if (*r == 0 && *f == MAX_SIZE - 1) {
  	printf("\nNo empty space in Queue.\n");
  	return;
  }
  if(*f == *r - 1) {
  	printf("\nNo empty space in  Queue\n");
  	return;
  }
  if (*f == -1 && *r == -1) {
  	(*f)++;
  	(*r)++;
  } else if (*f == MAX_SIZE - 1) {
  	*f = 0;
  } else {
  	(*f)++;
  }
  q[*f] = val;
}

void dequeue (int q[], int *f, int *r) {
	if (*r == -1) {
		printf("\nThe queue is empty.\n");
		return;
	}
	int item;
	item = q[*r];
	if (*r == *f) {
		*r = -1;
		*f = -1;
	} else if (*r == MAX_SIZE - 1) {
		*r = 0;
	} else {
		*r = *r + 1;
	}
	printf("\n%d is removed from queue.\n", item);
}

void display (int q[], int *f, int *r) {
	int i;
	i = *r;
	if (i == -1) {
		printf("\nThe queue is empty.");
		return;
	}
	printf("\nThe queue is");
	while (1) {
		printf("  %d", q[i]);
		if (i == *f){
			break;
		}
		if(i == MAX_SIZE - 1) {
			i = 0;
		} else {
			i++;
		}
	}
}