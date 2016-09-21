/**
 * Bellman-Ford Algorithm
 * This algorithm is used to find single source shortest path
 * The difference b/w this and dijsktra is that this algo works for negative weight edges too, but has a higher time complexity
 * This algo can also be used to find negative weight edges
 *
 * To find single source shortest path this algo runs V-1 times
 * To find negative weight cycle this will run V times, where V is no of vertices
 * When there is a negative weight cycle in graph it does not find shortest path but reports the presence of negative weight cycle
 */
 
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;
	struct Edge *edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	
	graph->edge = (struct Edge*)malloc(graph->E*sizeof(struct Edge));
	
	return graph;
}

void printArr(int dist[], int V)
{
	printf("Vertex\tDistance\n");
	for(int i=0;i<V;i++)
		printf("%d\t%d\n", i, dist[i]);
}

void BellmanFord(struct Graph *graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	
	//Initializing all vertex distance as Infinity and distance of source as 0
	for(int i=0;i<V;i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	
	//running the loop V-1 times
	for(int i=0;i<V-1;i++)
	{
		//Checking for distance of each edge in a single loop run
		for(int j=0;j<E;j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}
	
	//Checking for negative weight cycle
	for(int i =0;i<E;i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			printf("Graph contains a negative weight cycle");
			return;
		}
	}
	
	printArr(dist, V);
}

int main()
{
	int V=5;
	int E=8;
	struct Graph * graph = createGraph(V, E);
	
	// add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
	
	BellmanFord(graph, 0);
	
	return 0;
}