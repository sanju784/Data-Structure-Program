#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node* head = NULL;

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
  printf("\n\n\nEnter what you want to do in the link list from the below Options\n");
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
    printf("\nThe sorted link list is \n");
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
void createNode(struct node **h)
{
  char ch;
  do {
  struct node *newN = (struct node*)malloc(sizeof(struct node));
  struct node *current;
  printf("\nEnter the value you want to enter in linklist node\n");
  scanf("%d", &newN->data);
  newN->next = NULL;
  if (*h == NULL) {
    *h = newN;
    current = *h;
  } else {
    current->next = newN;
    current = newN;
  }
  printf("\nDo you want to create another : ");
  ch = getche();
  } while(ch != 'n');
}

void printList(struct node *h)
{
  struct node *temp;
  temp=h;
  while (temp!=NULL) {
    printf("%d",temp->data);
    temp=temp->next;
    if (temp != NULL)
      printf("--->");
  }
}

int countNode(struct node* h) {
  int c = 0;
  struct node *temp;
  temp = h;
  while(temp != NULL) {
    c++;
    temp=temp->next;
  }
  return c;
}

int findNode(struct node *h, int val)
{
  struct node* temp = h;
  int c = 0, pos = 0;
  while(temp != NULL) {
    c++;
    if(temp->data == val) {
      pos = c;
      break;
    } else {
      temp = temp->next;
    }
  }
  return pos;
}

void sort(struct node *h)
{
  struct node *node1, *node2, *temp;
  node1 = h;
  int s;
  while (node1->next != NULL) {
    s = node1->data;
    node2 = node1->next;
    temp = NULL;
    while (node2 != NULL) {
      if (node2->data < s) {
        s = node2->data;
        temp = node2;
      }
      node2 = node2->next;
    }
    if (temp != NULL) {
      temp->data = node1->data;
      node1->data = s;
    }
    node1 = node1->next;
  }
}

void insertNode (struct node **h, int pos)
{
  struct node *newN = (struct node*)malloc(sizeof(struct node*));
  printf("\nEnter the number you want to insert in new node\n");
  scanf("%d",&newN->data);
  if(*h == NULL || pos == 1){
    newN->next = *h;
    *h = newN;
  } else {
    struct node *prev;
    struct node *temp = *h;
    int c = 1;
    while (temp != NULL) {
      c++;
      prev = temp;
      temp = temp->next;
      if(c == pos){
        break;
      }
    }
    newN->next = temp;
    prev->next = newN;
  }
}

void deleteNode(struct node **h, int pos) {
  struct node *temp;
  if (*h == NULL) {
    printf("The list is empty");
  }
  if (pos == 1) {
    temp = *h;
    *h = (*h)->next;
  } else if (pos > countNode(*h)) {
    printf("\nInvalid position. The node you want to delete does not exist.\n");
  } else {
    struct node *prev;
    temp = *h;
    int c = 1;
    while (temp != NULL) {
      c++;
      prev = temp;
      temp = temp->next;
      if (c == pos) {
        break;
      }
    }
    prev->next = temp->next;
  }
  free(temp);
}

void reverseList(struct node **h) {
  struct node *prev = NULL;
  struct node *current = *h;
  struct node *next;
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *h = prev;
}