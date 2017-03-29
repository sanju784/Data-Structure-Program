#include <stdio.h>
#include <stdlib.h>

struct BST {
  int data;
  struct BST *left;
  struct BST *right;
};

typedef struct BST node;
node *root = NULL;

node* insert (node *root, node* newNode) {
  if(root == NULL)
    root = newNode;
  else if(newNode->data <= root->data)
    root->left = insert(root->left, newNode);
  else
    root->right = insert(root->right, newNode);
  return root;
}

int search(node *root, int num) {
  if(root == NULL) return 0;
  if(root->data == num) return 1;
  if(num < root->data)
    search(root->left, num);
  else
    search(root->right, num);
}


//The iterative way of traversal is written in iterativeTreeTraversal.txt
void inorder(node *t) {
  if(t != NULL) {
    inorder(t->left);
    printf("  %d", t->data);
    inorder(t->right);
  }
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

//another program to find height by iterative way is written in another file named findTreeHeightIterative.txt
int findHeight(node *root) {
  if(root == NULL)
    return -1;
  return max(findHeight(root->left), findHeight(root->right)) + 1;
}

// For this program check video 35 of Data Structure playlist in mycodeschool library
int isBST(node *root) {

}

node* search4Del(node *root, int num) {
  if(root == NULL) return NULL;
  if(root->data == num) return root;
  if(num < root->data)
    search(root->left, num);
  else
    search(root->right, num);
}

// It has 3 cases
// 1. Node has no children
// 2. Node has 1 children
// 3. Node has 2 children
// For this program check video 36 of Data Structure playlist in mycodeschool library
void delete(node *root, int data) {
  
}

void inorderSuccesor(node *root, int data) {
  
}

void main() {
  int ch, num;
  node *newNode;
  while(1) {
  printf("\nEnter your choice\n0. Exit\n1. Create or Insert\n2. Search\n3. Traverse\n4. Delete\n5. Find minimum.\n6. Find maximum.\n\n");
  scanf("%d", &ch);
  switch (ch) {
    case 0:
      exit(0);
    case 1:
	    printf("\nEnter the element you want to insert in tree\n");
      newNode = (node*)malloc(sizeof(node));
	    scanf("%d", &newNode->data);
	    newNode->left = newNode->right = NULL;
	    root = insert(root, newNode);
	    break;
	  case 2:
	    printf("\nEnter the element you want to search in tree\n");
	    scanf("%d", &num);
      int res;
	    res = search(root, num);
      if(res)
        printf("\n%d is present in the tree\n", num);
      else
        printf("\n%d is not present in the tree\n", num);
	    break;
	  case 3:
      printf("\nThe inorder traversal of tree is ");
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
