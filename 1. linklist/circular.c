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

//1 create
void createNode(struct node **h) {
  char ch;
  struct node* current;
  do{
    struct node* newN = (struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the data of the node\n");
    scanf("%d", &newN->data);
    if (*h == NULL) {
      *h = newN;
      newN->next = *h;
      current = newN;
    } else {
      current->next = newN;
      newN->next = *h;
      current = newN;
    }
    printf("\nDo you want to enter a new node\n");
    ch = getche();
  } while (ch != 'n');
}

//2 print
void printList(struct node* h) {
  if (h == NULL) {
    printf("\nThe link list is empty\n");
    return;
  }
  struct node* temp = h;
  do{
    printf("%d", temp->data);
    temp = temp->next;
    if(temp != h) {
      printf("-->");
    }
  } while (temp != h);
}

//3 count
int countNode(struct node *h) {
  if(h == NULL)
    return 0;
  struct node* temp = h;
  int c = 0;
  do{
    c++;
    temp = temp->next;
  } while(temp != h);
  return c;
}

//4 search
int findNode(struct node *h, int val) {
  int pos, c;
  if (h == NULL)
    return 0;
  c = 0;
  struct node* temp = h;
  do{
    c++;
    if(temp->data == val) {
      break;
    }
    temp = temp->next;
  } while (temp != head);
  return c;
}

//5 sort
void sort(struct node* h) {
  struct node* node1 = h;
  struct node *node2, *temp;
  int s;
  if(node1 == NULL || node1->next == h)
    return;
  do{
    s = node1->data;
    node2 = node1->next;
    while (node2 != h) {
      if(node2->data < s) {
        s = node2->data;
        temp = node2;
      }
      node2 = node2->next;
    }
  if (s != node1->data) {
    temp->data = node1->data;
    node1->data = s;
  }
  node1 = node1->next;
  } while(node1->next != h);
}

//6 reverse
void reverseList(struct node **h) {
  struct node* prev = *h;
  struct node* current = (*h)->next;
  struct node* next;
  do{
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  } while (current != *h);
  (*h)->next = prev;
  *h = prev;
}

//7 insert node
void insertNode (struct node **h, int pos) {
  struct node* newN = (struct node*)malloc(sizeof(struct node*));
  struct node* temp;
  printf("\nInsert the value of the new node\n");
  scanf("%d", &newN->data);
  if(*h == NULL) {
    *h = newN;
    newN->next = *h;
  }
  temp = *h;
  if (pos == 1) {
  newN->next = *h;
  while(temp->next != *h){
    temp = temp->next;
  }
  *h = newN;
  temp->next = *h;
  return;
  } 
  int c = 1;
  while(c < (pos -1) && temp->next != *h) {
    temp = temp->next;
    c++;
  }
  newN->next = temp->next;
  temp->next = newN;
}

//8 delete node
void deleteNode(struct node **h, int pos) {
  if(*h == NULL){
  printf("\nList is empty. Delete not possible.\n");
  return;
  }
  if (pos > countNode(*h)) {
    printf("\nThe node does not exist\n");
    return;
  }
  struct node *temp, *temp2;
  temp = *h;
  if(pos == 1) {
    if (countNode(*h) == 1) {
      *h = NULL;
      free(temp);
      return;
    }
    *h = temp->next;
    temp2 = *h;
    while (temp2->next != temp) {
      temp2 = temp2->next;
    }
    temp2->next = *h;
    free(temp);
    return;
  } 
    int c = 1;
    while(temp->next != *h && c < pos) {
      temp2 = temp;
      temp = temp->next;
      c++;
    }
    temp2->next = temp->next;
    free(temp);
}