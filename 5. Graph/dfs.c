#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

//stack variables
int stack[MAX];
int top = -1;

//stack functions
void push(int data) {
  stack[++top] = data;
}

int pop() {
  return stack[top--];
}

int peek() {
  return stack[top];
}

bool isEmpty() {
  return top == -1;
}

//graph vertex
struct vertex {
  char label;
  bool visited;
};

//graph variables (global)
// graph needs two variables to be represented V and E
// V is shown by an array here and E by a matrix of size |V|*|V|
//array of vertices

//1. Declare array of vertices 
//2. adjacency array or lsit for representaion of edges
//3. a counter variable to note the number of vertices in the graph
// Thses two variables are always declared whenever writting a graph program
struct vertex* lstVertices[MAX];

//adjacency matrix for edges
int adjMatrix[MAX][MAX];

//vertex counter
int vertexCount = 0;

//graph functions
//add a vertex to a vertex array

// In graph a function is always needed to add a vertex and edge
// 3 functions always written in graph

// 1. Add a vertex
// 2. Add an Edge
// 3. Display a vertex
void addVertex(char label) {
  struct vertex* newVertex = (struct vertex*) malloc(sizeof(struct vertex));
  newVertex->label = label;
  newVertex->visited = false;
  lstVertices[vertexCount++] = newVertex;
}

//add an edge between those vertices whose index are passed as argument
void addEdge(int start, int end) {
  adjMatrix[start][end] = 1;  //setting both as 1 as considering for undirected graph
  adjMatrix[end][start] = 1;  // in case of directed graph set 1 only from strat to end
}

//display vertex by index id
void displayVertex(int vertexIndex) {
  printf("%c ", lstVertices[vertexIndex]->label);
}

//to get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
  int i;
  for(i = 0; i<vertexCount; i++) {
    //checking for 1 in the row which represents the edge
    if(adjMatrix[vertexIndex][i] = 1 && lstVertices[i]->visited == false) {
	  return i;
	}
  }
  return -1;
}

void depthFirstSearch() {
  int i;
  
  //marking first node as visited and pushing it in stack
  lstVertices[0]->visited = true;
  push(0);
  
  //display the vertex that is marked as visited
  displayVertex(0);
  
  while(!isEmpty()) {
    //get unvisited vertex of vertex which is at top of stack
	int unvisitedVertex = getAdjUnvisitedVertex(peek());
	
	if(unvisitedVertex == -1) {
	  pop();
	} else {
	  lstVertices[unvisitedVertex]->visited = true;
	  displayVertex(unvisitedVertex);
	  push(unvisitedVertex);
	}
  }
  
  //stack is empty, search is complete, reset the visited flag
  for(i = 0; i < vertexCount; i++) {
    lstVertices[i]->visited = false;
  }
}

void main () {
  int i, j;
  
  //setting adjacency matrix to 0
  for(i = 0; i<MAX; i++) {
    for(j = 0; j<MAX; j++) {
	  adjMatrix[i][j] = 0;
    }
  }
  addVertex('S'); //0
  addVertex('A'); //1
  addVertex('B'); //2
  addVertex('C'); //3
  addVertex('D'); //4
  
  addEdge(0, 1);  // S - A
  addEdge(0, 2);  // S - B
  addEdge(0, 3);  // S - C
  addEdge(1, 4);  // A - D
  addEdge(2, 4);  // B - D
  addEdge(3, 4);  // C - D
  
  printf("Depth First Search: ");
  depthFirstSearch();
}
