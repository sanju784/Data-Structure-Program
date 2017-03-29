#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

//queue variables and functions
int queue[MAX];
int rear = -1;
int front = -1;
//int front = 0;
int queue_count = 0;

void enqueue(int data) {
  if (rear == -1) {
    front++;
	rear++;
  } else {
    rear++;
  }
  queue[rear] = data;
  queue_count++;
}

/*void enqueue(int data) {
  queue[++rear] = data;
  queue_count++;
}*/

int dequeue() {
  queue_count--;
  int data;
  data = queue[front];
  if(front == rear) {
    front = rear = -1;
  } else {
    front++;
  }
  return data;
}

/*int dequeue() {
  queue_count--;
  return queue[front++];
}*/

bool isQEmpty() {
  return queue_count == 0;
}

struct vertex {
  char label;
  bool visited;
};

//Graph variables and functions
struct vertex *lstVertices[MAX];

int adjMatrix[MAX][MAX];

int vertexCount = 0;

void addVertex(char label) {
  struct vertex *newVertex = (struct vertex*)malloc(sizeof(struct vertex));
  newVertex->label = label;
  newVertex->visited = false;
  lstVertices[vertexCount++] = newVertex;
}

void addEdge(int start, int end) {
  adjMatrix[start][end] = 1;
  adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
  printf("%c ", lstVertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex) {
  int i;
  for(i = 0; i<vertexCount; i++) {
    if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
	  return i;
	}
  }
  return -1;
}

void breadthFirstSearch() {
  int i;
  lstVertices[0]->visited = true;
  enqueue(0);
  displayVertex(0);
  int unvisitedVertex;
  
  while(!isQEmpty()) {
    int tempVertex = dequeue();
	while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
	  lstVertices[unvisitedVertex]->visited = true;
	  displayVertex(unvisitedVertex);
	  enqueue(unvisitedVertex);
	}
  }
  
  for(i = 0; i<vertexCount; i++) {
    lstVertices[i]->visited = false;
  }
}

void main() {
  int i, j;
  for(i = 0; i<MAX; i++) {
    for(j =0; j<MAX; j++) {
	  adjMatrix[i][j] = 0;
	}
  }
  
  addVertex('S');
  addVertex('A');
  addVertex('B');
  addVertex('C');
  addVertex('D');
  
  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(0, 3);
  addEdge(1, 4);
  addEdge(2, 4);
  addEdge(3, 4);
  
  printf("\nThe Breadth First Search is: ");
  breadthFirstSearch();
}
