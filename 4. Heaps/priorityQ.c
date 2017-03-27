#include <stdio.h>
#include <stdlib.h>

struct pq
{
	int *arr;
	int capacity;
	int count;
} q;

void init() {
	q.capacity = 1;
	q.count = -1;
	q.arr = (int*)malloc(q.capacity*sizeof(int));
}

int isEmpty() {
	if(q.count == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if(q.count == q.capacity -1)
		return 1;
	else
		return 0;
}

void insert(int data) {
	if(isEmpty()) {
		q.count++;
		q.arr[q.count] = data;
		return;
	}
	if(isFull()) {
		q.capacity *= 2;
		q.arr = (int *)realloc(q.arr, q.capacity*sizeof(int));
	}
	if(data >= getMin()) {
	  q.count++;
	  q.arr[q.count] = data;
	} else {
		int temp = getMin();
		q.arr[0] = data;
		q.count++;
		q.arr[q.count] = temp;
	}
}

void deleteMin() {
	if(isEmpty()) {
		printf("\nThe priority Q is Empty\n");
		return;
	}
	if(q.count == 0) {
		q.count--;
		return;
	}
	int min = q.arr[1];
	int loc = 1;
	int i;
	for(i = 2; i < q.capacity ; i++){
		if(q.arr[i] < min) {
			min = q.arr[i];
			loc = i;
		}
	}
   q.arr[0] = min;
   q.arr[loc] = q.arr[q.capacity - 1];
   q.count--;
}

int getMin() {
	if(isEmpty()) {
		printf("\nThe priority Q is Empty\n");
		return;
	}
	return q.arr[0];
}

void main() {
  int ch, data;
  init();
  while(1) {
  printf("Enter Choice. \n1. Insert.\n2. Delete Minimum. \n3. Get Minimum.\n4. Exit.\n\n");
  scanf("%d", &ch);
	switch(ch) {
		case 1 :
		  printf("\nEnter the element you want to insert in priority Q.\n");
		  scanf("%d", &data);
		  insert(data);
		  break;
		case 2 :
		  deleteMin();
		  break;
		case 3 :
		  data = getMin();
		  printf("\nThe minimum data in priority Q is %d\n", data);
		  break;
		case 4 :
		  exit(0);
	}
  }
}