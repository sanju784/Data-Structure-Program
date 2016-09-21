/**
 * Kruskals for minimum spanning tree
 * This is a greedy algorithm
 */
 
#include<bits/stdc++.h>
using namespace std;

//structure to represent weighted edge in a graph
struct Edge
{
	int src, dest, weight;
};

//structure to represent a connected, undirected and weighted graph
struct Graph
{
	//V - Number of vertices
	//E - Number of edges
	int V, E;
	
	struct Edge *edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	
	graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
	return graph;
};

struct subset
{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	
	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	
	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void *a, const void *b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void kruskalMST(struct Graph *graph)
{
	int V = graph->V;
	struct Edge result[V];
	int e = 0;
	int i = 0;
	
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	
	struct subset *subsets = (struct subset*)malloc(V*sizeof(struct subset));
	
	for(int v=0;v<V;v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	
	while(e < V-1)
	{
		struct Edge next_edge = graph->edge[i++];
		
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		
		if(x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}
	
	cout<<"Following are the edges included in MST"<<endl;
	cout<<"src\tdest\tweight"<<endl;
	for(i=0;i<e;i++)
		cout<<result[i].src<<"\t"<<result[i].dest<<"\t"<<result[i].weight<<endl;
}

int main()
{
	int V = 4;
	int E = 5;
	struct Graph* graph = createGraph(V, E);
	
	//add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;
	
	//add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;
	
	//add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;
	
	//add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;
	
	//add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;
	
	kruskalMST(graph);
	
	return 0;
}