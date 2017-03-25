#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct listNode {
	int data;
	struct listNode *ptrdiff;
} node;

/**
 * function to calculate and return XOR value of 2 pointers
 * to calculate the pointer difference
 */
node* xor(node *a, node *b) {
	return (node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

// function to insert node at the start of the link list
void insert(node **h, int n) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = n;
	newNode->ptrdiff = xor(*h, NULL);
	if(*h != NULL) {
		node *next = xor((*h)->ptrdiff, NULL);
		(*h)->ptrdiff = xor(newNode, next);
	}
	*h = newNode;
}

// function to traverse through the link list
void print (node *h) {
	node *curr = h;
	node *prev = NULL;
	node *next;
	while(curr != NULL) {
		printf("-->%d", curr->data);
		next = xor(prev, curr->ptrdiff);
		prev = curr;
		curr = next;
	}
}

void main() {
	node *head = NULL;
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);

	print(head);
}