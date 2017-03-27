#include <stdio.h>
#include <stdlib.h>

struct heap {
	int *arr;
	int capacity;
	int count;
	int heap_type; // This is to check weather heap created is min or max. Here i am making max heap
}h;

void init() {
	h.capacity = 1;
	h.count = -1;
	h.arr = (int *)malloc(h.capacity*sizeof(int));
}

int isEmpty() {
	if(h.count == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if(h.count == h.capacity - 1)
		return 1;
	else
		return 0;
}

int getParent(int i) {
	if (i <= 0 || i > h.count)
		return -1;
	else 
		return (i - 1)/2;
}

int getLchild(int i) {
	int c = 2*i + 1;
	if(c > h.count)
		return -1;
	else
		return c;
}

int getRchild(int i) {
	int c = 2*i + 2;
	if(c > h.count)
		return -1;
	else
		return c;
}

void insert(int data) {
	if(isFull()) {
		h.capacity *= 2;
		h.arr = (int*)realloc(h.arr, h.capacity*sizeof(int));
	}
	h.count++;
	if(h.count == 0) {
		h.arr[h.count] = data;
		return;
	}
	int i = h.count;
	h.arr[i] = data;
	int p, temp;
	while(i >= 0) {
		p = getParent(i);
		if(h.arr[p] < h.arr[i]) {
			temp = h.arr[p];
			h.arr[p] = h.arr[i];
			h.arr[i] = temp;
		} else {
			break;
		}
		i = p;
	}
}

int getMax() {
	if(h.count == -1)
		return -1;
	else
		return h.arr[0];
}

void percolateDown(int i) {
	int l,r,max,temp;
	while (i < h.count) {
	  l = getLchild(i);
	  r = getRchild(i);
	  if(l == -1 && r == -1)
		break;
	  if (h.arr[l] < h.arr[i] && h.arr[r] < h.arr[i])
	  	break;
	  if(l != -1 && h.arr[i] < h.arr[l])
		max = l;
	  else
		max = i;
	  if(r != -1 && h.arr[max] < h.arr[r])
		max = r;
	  if(max != i) {
		temp = h.arr[i];
		h.arr[i] = h.arr[max];
		h.arr[max] = temp;
		i = max;
	  } else {
	  	break;
	  }
   }
}

int delete() {
	int data, i;
	if(h.count == -1)
		return -1;
	data = h.arr[0];
	if(h.count == 0) {
		h.count--;
		return data;
	}
	h.arr[0] = h.arr[h.count];
	i = 0;
	h.count--;
	if(h.count > 0) {
		int l,r,max,temp;
		while (i < h.count) {
			l = getLchild(i);
			r = getRchild(i);
			if(l == -1 && r == -1)
				break;
			if(h.arr[l] < h.arr[i] && h.arr[r] < h.arr[i])
				break;
			if(l != -1) {
				if(h.arr[l] > h.arr[i])
					max = l;
				else
					max = i;
			}
			if(r != -1) {
				if(h.arr[r] > h.arr[max])
					max = r;
			}
			if (max != i) {
				temp = h.arr[max];
				h.arr[max] = h.arr[i];
				h.arr[i] = temp;
				i = max;
			} else {
				break;
			}
		}
	}
	// percolateDown(0);
	return data;
}

void print() {
	if(h.count == -1) {
		printf("\n The heap is empty.\n");
	    return;
	}
	int i;
	printf("\nThe elements in heap array are ");
	for(i = 0; i <= h.count; i++)
		printf("  %d",h.arr[i]);
	printf("\n");
}

void main() {
	init();
	int ch, n;
	while (1) {
	printf("\nEnter your choice.\n1. Insert.\n2. Delete.\n3. Get Maximum.\n4. Print. \n5. Exit\n");
	scanf("%d", &ch);
	switch(ch) {
		case 1:
		printf("\nEnter the number you want to insert ");
		scanf("%d", &n);
		insert(n);
		break;
		case 2:
		n = delete();
		if(n == -1)
			printf("\nThe heap is empty.\n");
		else
		    printf("\n%d is deleted from heap.\n", n);
		break;
		case 3:
		n = getMax();
		if(n == -1)
			printf("\nThe heap is empty.\n");
		else
		    printf("\nThe maximum element in heap is %d", n);
		break;
		case 4:
		print();
		break;
		case 5:
		exit(0);
	}
  }
}