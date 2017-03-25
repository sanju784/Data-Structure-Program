#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

typedef struct list {
	int totalElements;
	int arr[MAX_SIZE];
	struct list *next;
} node;

void printList (node *h) {
	int i;
	while (h != NULL) {
		for (i = 0; i < h->totalElements; i++) {
			printf("-->%d", h->arr[i]);
		}
		h = h->next;
	}
}

void main() {
	node *head = NULL;
	node *second = NULL;
	node *third = NULL;

	head = (node*)malloc(sizeof(node));
	second = (node*)malloc(sizeof(node));
	third = (node*)malloc(sizeof(node));

	head->totalElements = 3;
	head->arr[0] = 1;
	head->arr[1] = 2;
	head->arr[2] = 3;
	head->next = second;

	second->totalElements = 3;
	second->arr[0] = 4;
	second->arr[1] = 5;
	second->arr[2] = 6;
	second->next = third;

	third->totalElements = 3;
	third->arr[0] = 7;
	third->arr[1] = 8;
	third->arr[2] = 9;
	third->next = NULL;

	printList(head);
}