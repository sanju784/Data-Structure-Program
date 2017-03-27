#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 10

int deque[SIZE];
int front = -1;
int rear = -1;

bool isEmpty(){
    return (front == -1);
}

bool isFull(){
  return ((rear + 1) % SIZE == front);
}

void push_front(int n) {
  if (isFull()) {
    printf("\nQueue Overflow.\n");
    return;
  }
  if(isEmpty()) {
    front = rear = 0;
    deque[front] = n;
    return;
  }
  if(front == 0) {
    front = SIZE;
  }
  deque[--front] = n;
}

void push_back(int n){
  if (isFull()) {
    printf("\nQueue Overflow.\n");
    return;
  }
  if(isEmpty()) {
    front = rear = 0;
    deque[rear] = n;
    return;
  }
  if (rear == SIZE - 1) {
    rear = 0;
    deque[rear] = n;
    return;
  }
  deque[++rear] = n;
}

int pop_front(){
  if (isEmpty()) {
    return INT_MIN;
  }
  if(front == rear) {
    int n = deque[front];
    front = rear = -1;
    return n;
  }
  if (front == SIZE - 1) {
    int n = deque[front];
    front = 0;
    return n;
  }
  return deque[front++];
}

int pop_back(){
  if (isEmpty()) {
    return INT_MIN;
  }
  if(front == rear) {
    int n = deque[front];
    front = rear = -1;
    return n;
  }
  if(rear == 0) {
    int n = deque[rear];
    rear = SIZE - 1;
    return n;
  }
  return deque[rear--];
}

void print() {
    if(isEmpty()) {
      printf("\nThe deque is empty.\n");
      return;
    }
    int i = front;
    printf("\nThe elements in deque are ");
    while (1){
      printf("%d ",deque[i]);
      if(i == rear)
        break;
      if(i == SIZE - 1) {
        i = -1;
      }
      i++;
    }
    printf("\n");
}

void main() {
  int op, n;
  do{
    printf("\nSelect option.\n1. Push front.\n2. Push back.\n3. Pop front.\n4. Pop back.\n5. Print.\n6. Exit.\n");
    scanf("%d", &op);
    switch (op) {
      case 1:
        printf("Enter the number\n");
        scanf("%d", &n);
        push_front(n);
        break;
      case 2:
        printf("Enter the number\n");
        scanf("%d", &n);
        push_back(n);
        break;
      case 3:
        n = pop_front();
        if (n == INT_MIN)
          printf("\nThe deque is empty.\n");
        else
          printf("%d is popped from front.\n", n);
        break;
      case 4:
        n = pop_back();
        if (n == INT_MIN)
          printf("\nThe deque is empty.\n");
        else
          printf("%d is popped from back.\n", n);
        break;
      case 5:
        print();
        break;
      case 6:
        exit(0);
    }
  } while(1);
}
