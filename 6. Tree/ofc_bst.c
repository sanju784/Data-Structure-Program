#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct BST {
  int data;
  struct BST *left;
  struct BST *right;
};

typedef struct BST node;

void insert (node *root, node* newNode) {
  if(root == NULL) {
    root = newNode;
	return;
  }
  if(newNode->data <= root->data)
    insert(root->left, newNode);
  else
    insert(root->right, newNode);
}

void inorder(node *root) {
if(root) {
  inorder(root->left);
  printf("  %d", root->data);
  inorder(root->right);
  }
}

void delete(node *root) {
  printf("\nDelete is not yet studied\n");
}

void findMin(node *root) {
  if(root == NULL) {
  printf("\nThe tree is Empty.\n");
  return;
  }
  while(root->left != NULL)
    root = root->left;
  printf("\nThe minimum element in tree is %d\n", root->data);
}

void findMax(node *root) {
  if(root == NULL) {
    printf("\nThe tree is empty.\n");
	return;
	}
  while(root->right != NULL)
    root = root->right;
  printf("\nThe maximum element in tree is %d\n", root->data);
}

int search(node *root, int num) {
  if(root == NULL) return 0;
  if(root->data == num) return 1;
  if(num < root->data)
    search(root->left, num);
  else
    search(root->right, num);
}

void main() {
  int ch, data, num, res;
  node *newNode, *root = NULL;
  char ans = 'n';
  while (1) {
  printf("\nEnter your choice\n0. Exit\n1. Create or Insert\n2. Search\n3. Traverse\n4. Delete\n5. Find minimum.\n6. Find maximum.\n\n");
  scanf("%d", &ch);
  switch (ch) {
    case 0:
	  exit(0);
    case 1: 
	  do {
	    printf("\nEnter the element you want to insert in tree\n");
		newNode = (node*)malloc(sizeof(node));
	    scanf("%d", newNode->data);
	    newNode->left = newNode->right = NULL;
	    insert(root, newNode);
		printf("\nDo you want to enter more node?\n");
		ans = getche();
	  } while(ans == 'y');
	  break;
	case 2:
	  printf("\nEnter the element you want to search in tree\n");
	  scanf("%d", &num);
	  res = search(root, num);
	  if(res)
	    printf("\n%d is present in the tree\n", num);
	  else
	    printf("\n%d is not present in the tree\n", num);
	  break;
	case 3:
	  inorder(root);
	  break;
	case 4:
	  delete(root);
	  break;
	case 5:
	  findMin(root);
	  break;
	case 6: 
	  findMax(root);
	  break;
  }
 }
}

int findHeight(node *root) {
  if(root == NULL)
    return 0;
  int lHeight = findHeight(root->left);
  int rHeight = findHeight(root->right);
  if(lHeight > rHeight)
    return lHeight + 1;
  else rHeight + 1;
}

// this is my self solution,
// geeksforgeek has a different solution http://www.geeksforgeeks.org/iterative-method-to-find-height-of-binary-tree/
int findHeightIterative(node *root) {
  node *temp;
  int h = 0;
  enqueue(Q1, root);
  enqueue(Q1, -1);
  while (!isEmpty(Q1)) {
    temp = pop(Q1);
	if(temp == -1){
	  int h++;
	  enqueue(Q1, -1);
	} else {
	  if(temp->left)
	    enqueue(Q1, temp->left);
	  if(temp->right)
	    enqueue(Q1, temp->right);
	}
  }
  return h;
}













