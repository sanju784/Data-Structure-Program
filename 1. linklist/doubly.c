#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};

void createNode(struct node**);
void printList(struct node*);
int countNode(struct node*);
int findNode(struct node*, int);
void sort(struct node*);
void insertNode(struct node**, int);
void deleteNode(struct node**, int);
void reverseList(struct node**);

void main(){
  struct node *head;
  head = NULL;
  int op;
  int val, pos;
  int c;
while (1) {
  printf("\n\nEnter what you want to do in the link list from the below Options\n");
  printf("\n1. To create a link list.");
  printf("\n2. Print link list.");
  printf("\n3. To count total node in link list.");
  printf("\n4. Find node with given key in link list.");
  printf("\n5. Sort the link list.");
  printf("\n6. Insert in the link list. (First, last or at given position.)");
  printf("\n7. Delete from link list. (First, last or at given position.)");
  printf("\n8. Reverse the link list.");
  printf("\n9. Exit\n\n");

  scanf("%d", &op);

  int n,i;
  switch (op) {
  case 1 :
    createNode(&head);
    printf("\nThe saved link list is\n");
    printList(head);
    break;
  case 2 :
    printf("\nThe link list is\n");
    printList(head);
    break;
  case 3 :
    c = countNode(head);
    printf("\nTotal node in the link list is = %d", c);
    break;
  case 4 :
    printf("\nEnter the value whose position you want to find.\n");
    scanf("%d", &val);
    pos = findNode(head, val);
    if (pos == 0)
      printf("The value dont exist in link list");
    else
      printf("\nThe number = %d exists at = %d position in the link list", val, pos);
    break;
  case 5 :
    sort(head);
    printf("\nThe sorted link list is ");
    printList(head);
    break;
  case 6 :
    printf("\nEnter the position where you want to insert node\n");
    scanf("%d", &pos);
    insertNode(&head, pos);
    printf("\nThe link list is\n");
    printList(head);
    break;
  case 7 :
    printf("\nEnter the position where you want to delete node\n");
    scanf("%d", &pos);
    deleteNode(&head, pos);
    printf("\nThe link list is\n");
    printList(head);
    break;
  case 8 :
    reverseList(&head);
    printf("\nThe reverse list is\n");
    printList(head);
    break;
  case 9 :
    printf("\nAll operations finished... Bye!!!\n\n");
    exit(0);
  }
 }
}

  void createNode(struct node **h) {
	struct node *current;
	char ch;
	*h = NULL;
	do {
		struct node* newN = (struct node*)malloc(sizeof(struct node*));
		printf("\nEnter the data in the node of link list\n");
		scanf("%d", &newN->data);
		newN->next = NULL;
	if (*h == NULL) {
		*h = newN;
		newN->prev = NULL;
		current = newN;
	} else {
		newN->prev = current;
		current->next = newN;
		current = newN;
	}
	printf("\nDo you want to create another : ");
    ch = getche();
	} while (ch != 'n');
}

void printList(struct node *h) {
	struct node *temp;
	temp = h;
	while (temp != NULL) {
	printf("%d", temp->data);
	temp = temp->next;
	if(temp != NULL)
		printf("-->");
	}
}

int countNode(struct node *h) {
	int c = 0;
	struct node *temp = h;
	while (temp != NULL) {
		c++;
		temp = temp->next;
	}
	return c;
}

int findNode(struct node *h, int val) {
	int pos = 0;
	struct node *temp = h;
	while (temp != NULL) {
		pos++;
		if(val == temp->data)
			break;
		temp = temp->next;
	}
	if(temp == NULL)
		pos = 0;
	return pos;
}

void sort(struct node* h) {
	struct node *temp1, *temp2, *node1;
	temp1 = h;
	int s;
	while (temp1->next != NULL) {
		s = temp1->data;
		temp2 = temp1->next;
		node1 = NULL;
		while (temp2 != NULL) {
			if(temp2->data < s) {
				s = temp2->data;
				node1 = temp2;
			}
			temp2 = temp2->next;
		}
		if(node1 != NULL) {
		  node1->data = temp1->data;
		  temp1->data = s;
		}
		temp1 = temp1->next;
	}
}

  void reverseList(struct node **h){
	struct node* temp = *h;
	struct node *temp1, *node1;
	while(temp != NULL) {
		node1 = temp;
		temp1 = temp->next;
		temp->next = temp->prev;
		temp->prev = temp1;
		temp = temp->prev;
	}
	*h = node1;
}

  void insertNode(struct node **h, int pos){
	struct node* newN = (struct node*)malloc(sizeof(struct node*));
	printf("\nEnter the number you want to insert in new node\n");
    scanf("%d",&newN->data);
	if(*h == NULL) {
		newN->next = NULL;
		newN->prev = NULL;
		*h = newN;
	}
	if(pos == 1) {
		newN->next = *h;
		newN->prev = NULL;
		(*h)->prev = newN;
		*h = newN;
	} else if(pos > countNode(*h)) {
		struct node *temp = *h;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newN;
		newN->prev = temp;
		newN->next = NULL;
	} else {
		struct node *temp1, *temp2;
		temp1 = *h;
		int c = 1;
		while (c < pos && temp1 != NULL) {
			temp2 = temp1;
			temp1 = temp1->next;
			c++;
		}
		newN->next = temp2->next;
		newN->prev = temp1->prev;
		temp2->next = newN;
		temp1->prev = newN;
	}
}

  void deleteNode(struct node **h, int pos) {
	struct node *temp, *temp2;
	temp = *h;
	int k = 1;
	if (*h == NULL){
		printf("\nThe link list is empty. No delete possible\n");
		return;
	}
	if(pos > countNode(*h)) {
		printf("\nThe position you entered is not proper\n");
		return;
	}
	if(pos == 1) {
		*h = (*h)->next;
		if(*h != NULL) {
		  (*h)->prev = NULL;
		}
		free(temp);
		return;
	}
	while (k < pos && temp->next != NULL) {
		temp = temp->next;
		k++;
	}
	temp2 = temp->prev;
	temp2->next = temp->next;
	if(temp->next) {
    	temp->next->prev = temp2;
    }
	free(temp);
}