#include <stdio.h>
#include <stdlib.h>

// in every link list representing the edge
// the source is always the array from which it originates
// the destination of the edge is saved in the link list
// so the link list has 2 variables one having the destination value and the other one is pointer to the next node
struct adjListNode {
	int dest;
	struct adjListNode *next;
};

// header for link list of edges
struct adjList {
	struct adjListNode *head;
};

// graph is an array of adjacency list here i.e. array of headers to the list
// v is the number of vertices (i.e. size of array of vertices or header)
struct graph {
	int v;
	struct adjList *array;
}

// function to create new adjacency(link) list node
struct adjListNode* newAdjListNode(int dest) {
	struct adjListNode *newNode = (struct adjListNode*)maloc(sizeof(struct adjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// function to create graph of v vertices
struct graph* createGraph(int v) {
	struct graph* g = (stuct graph*)malloc(sizeof(struct graph));
	g->v = v;
	// array of header of adjacency list of size v
	g->array = (struct adjList*)malloc(v*sizeof(struct adjList));
	int i;
	// initializing the header of adjacency list with null
	for(i = 0; i < v; i++)
		g->array[i] = NULL;
	return graph;
}

// add edges to undirected graph
void addEdge(struct graph *g, int src, int dest) {
	// add an edge from src to dest
	// new node is added at the adjacency list of src
	// the node is added at the beginning
	struct adjListNode *newNode = newAdjListNode(dest);
	newNode->next = g->array[src].head;
	g->array[src].head = newNode;

	// as graph is undirected, add an edge from dest to src
	newNode = newAdjListNode(src);
	newNode->next = g->array[dest].head;
	g->array[dest].head = newNode;
}

// to print adjacency list represntation of graph
void printGraph(struct graph* g) {
	int v;
	for(v = 0; v < g->v; v++) {
		struct adjListNode *pcrawl = g->array[v].head;
		printf("\n Adjacency list of vertex %d\n head", v);
		while(pcrawl) {
			printf("-> %d", pcrawl->dest);
			pcrawl = pcrawl->next;
		}
		printf("\n");
	}
}

void main() {
	int v = 5;
	struct graph *g = createGraph(v);
	addEdge(g, 0, 1);
	addEdge(g, 0, 4);
	addEdge(g, 1, 2);
	addEdge(g, 1, 3);
	addEdge(g, 1, 4);
	addEdge(g, 2, 3);
	addEdge(g, 3, 4);

	printGraph(g);
}