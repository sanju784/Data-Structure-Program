#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int f = -1;
int r = -1;

bool isEmpty() {
  return f == -1;
}

bool isFull() {
  return ((r + 1) % MAX_SIZE) == f;
}

void enque(int n) {
  if(isEmpty()) {
    r = f = 0;
  } else if (r == MAX_SIZE - 1) {
    r = 0;
  } else {
    r++;
  }
  queue[r] = n;
}

int deque() {
  int n = queue[f];
  if (f == r) {
    f = r = -1;
  } else if (f == MAX_SIZE - 1) {
    f = 0;
  } else {
    f++;
  }
  return n;
}

int top() {
  return queue[f];
}

void display() {
  int i;
  if(f <= r) {
    for(i = f; i <= r; i++) {
      printf("-->%d", queue[i]);
	}
  } else {
    for(i = f; i < MAX_SIZE; i++) {
	  printf("-->%d", queue[i]);
	}
	for(i = 0; i <= r; i++) {
	  printf("-->%d", queue[i]);
	}
  }
}

void main() {
  int ch, n;
  do {
    printf("\nEnter your choice\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit.\n");
	scanf("%d", &ch);
	switch(ch) {
	  case 1:
	    if(isFull()) {
		  printf("\nOverflow");
		} else {
	      printf("\nEnter number you want to insert.\n");
		  scanf("%d", &n);
		  enque(n);
		}
		break;
	  case 2:
	    if(isEmpty()) {
		  printf("\nUnderFlow\n");
		} else {
		  printf("\n%d is removed from Queue\n", deque());
		}
		break;
	  case 3:
	    if(isEmpty()) {
		  printf("\nUnderflow\n");
		} else {
		  display();
		}
		break;
	}
  } while(ch != 4);
}




















