#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
}node;

node *create() {
	node *p;
	int x;
	printf("\nEnter data(-1 for no data.):");
	scanf("%d", &x);
	if(x == -1)
		return NULL;
	p = (node*)malloc(sizeof(node));
	p->data = x;
	printf("\nEnter the left child of %d", x);
	p->left = create();
	printf("\nEnter the right child of %d", x);
	p->right = create();
	return p;
}

void preorder(node *t) {
	if(t != NULL) {
		printf("  %d", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder (node *t) {
	if(t != NULL) {
		inorder(t->left);
		printf("  %d", t->data);
		inorder(t->right);
	}
}

void postorder (node *t) {
	if (t) {
		postorder(t->left);
		postorder(t->right);
		printf("  %d", t->data);
	}
}

void preorderS(node *t) {
	
}

void main() {
	node *root;
	root = create();
	printf("\n\nThe preorder traversal of tree is : \n");
	preorder(root);
	printf("\n\nThe inorder traversal of tree is : \n");
	inorder(root);
	printf("\n\nThe postorder traversal of tree is : \n");
	postorder(root);
}