#include <stdio.h>
#include <stdlib.h>

int getLchild(int i, int n) {
	int c = 2*i + 1;
	if(c > n)
		return -1;
	else
		return c;
}

int getRchild(int i, int n) {
	int c = 2*i + 2;
	if(c > n)
		return -1;
	else
		return c;
}

void print(int *a, int n) {
	int i;
	printf("\n");
	for(i = 0; i < n; i++)
		printf("  %d", a[i]);
	printf("\n");
}

void heapify(int *a, int n) {
	int i, l, r, lp, max, temp, j;
	lp = (n - 1) / 2;         //Running this loop only till that node which has children. so if last node is n then its parent is n-1/2
	j = lp;
	while (j > 0) {
	  i = 0;
	  while (i < lp) {
		l = getLchild(i, n);
		r = getRchild(i, n);
		if (a[l] > a[i]) {
			max = l;
		} else {
			max = i;
		}
		if(a[r] > a[max])
			max = r;
		if(max != i) {
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
		i++;
	  }
	  j--;
   }
}

int deleteMax(int *a, int n) {
	int data, i;
	data = a[0];
	if(n == 0) {
		return data;
	}
	a[0] = a[n];
	a[n] = a[0];
	i = 0;
	n--;
	if(n >= 0) {
		int l,r,max,temp;
		while (i < n) {
			l = getLchild(i, n);
			r = getRchild(i, n);
			if(l == -1 && r == -1)
				break;
			if(a[l] < a[i] && a[r] < a[i])
				break;
			if(l != -1) {
				if(a[l] > a[i])
					max = l;
				else
					max = i;
			}
			if(r != -1) {
				if(a[r] > a[max])
					max = r;
			}
			if (max != i) {
				temp = a[max];
				a[max] = a[i];
				a[i] = temp;
				i = max;
			} else {
				break;
			}
		}
	}
	return data;
}

void main() {
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(a[0]);
	printf("\nThe elements in array are \n");
	print(a, n);
	heapify(a, n);
	print(a, n);
	printf("\nThe sorted array is ");
	int i, data;
	for(i = n-1; i >= 0; i--) {
		data = deleteMax(a, i);
		printf("  %d", data);
	}
}
