#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void enqueue(struct node**, struct node**);
void dequeue(struct node**, struct node**);
void display(struct node**, struct node**);

void enqueue(struct node **front, struct node **rear) {
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data you want to insert.\n");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	if(*front == NULL) {
		*front = *rear = newNode;
	} else {
		(*front)->next = newNode;
		*front = newNode;
	}
}

void dequeue (struct node **front, struct node **rear) {
	if(*rear == NULL) {
		printf("\nThe queue is empty.\n");
		return;
	}
	struct node *temp;
	if (*front == *rear) {
		temp = *front;
		*front = *rear = NULL;
	} else {
		temp = *rear;
		*rear = (*rear)->next;
	}
	printf("\n%d is dequeued from the queue.", temp->data);
	free(temp);
}

void display (struct node **front, struct node **rear) {
	struct node *temp;
	temp = *rear;
	if(temp == NULL) {
		printf("\nThe queue is empty.\n");
		return;
	}
	printf("The queue is");
	while (temp != *front) {
		printf("  %d", temp->data);
		temp = temp->next;
	}
	printf("  %d", (*front)->data);
}

void main () {
	struct node *front, *rear;
	front = rear = NULL;
	int ch;
	do {
		printf("\nEnter the option.\n");
		printf("1. Enqueue. \n2. Dequeue. \n3. Display. \n4. Exit.\n\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1 :
			  enqueue(&front, &rear);
			  break;
			case 2 :
			  dequeue(&front, &rear);
			  break;
			case 3 :
			  display(&front, &rear);
			  break;
			case 4 :
			  exit(0);
		}
	} while(1);
}