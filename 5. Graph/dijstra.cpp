/*
 * Dijstra Algorithm is to find shortest path of all vertices from a given source vertex
 * Dijstra is a greedy Algorithm, it does not work if there is negative weight for an edge
 * For graph with negative weight edges Bellman-Ford algorithm is used
 * This is using Adjacency Matrix so time complexity is O(V^2)
 * This mostly same as Prim's algorithm
 */
 
#include <bits/stdc++.h>
using namespace std;

//total vertices in Graph
#define V 9

//to find vertex with minimum distance value
//from a set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	
	for(int v=0;v<V;v++)
		if(sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

//print the final result
void printSolution(int dist[], int n)
{
	cout<<"Vertex distnace from Source "<<endl;
	for(int i=0;i<V;i++)
		cout<<i<<"\t"<<dist[i]<<endl;
}

void dijkstra(int graph[V][V], int src)
{
	//array to hold shortest distance from src to i
	int dist[V];
	
	//sptSet[i] will be true if vertex i is included in the
	//shortest path tree or shoretst distance from src to i is finalized
	bool sptSet[V];
	
	//Initialize distance of all vertices as INFINITE and 
	//sptSet[] as false which means no node is visited
	for(int i=0;i<V;i++)
		dist[i]=INT_MAX, sptSet[i]=false;
	
	//Base case, distance of source vertex is 0
	dist[src] = 0;
	
	//Find shortest path of all vertices
	for(int count=0;count<V-1;count++)
	{
		//getting minimum distance from the set of vertices not yet visited
		int u = minDistance(dist, sptSet);
		
		//marking the selected vertex as visited
		sptSet[u] = true;
		
		//update distance value of adjacent vertices of the selected vertex
		for(int v=0;v<V;v++)
			//updating dist[v] only if is not in sptSet
			//there is an edge from u to v
			//and total weight of path from src to v through u is smaller than current value of dist[v]
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist, V);
}

int main()
{
	int graph[V][V] = 
					 {{0,  4, 0,  0,  0,  0, 0,  8, 0},
                      {4,  0, 8,  0,  0,  0, 0, 11, 0},
                      {0,  8, 0,  7,  0,  4, 0,  0, 2},
                      {0,  0, 7,  0,  9, 14, 0,  0, 0},
                      {0,  0, 0,  9,  0, 10, 0,  0, 0},
                      {0,  0, 4, 14, 10,  0, 2,  0, 0},
                      {0,  0, 0,  0,  0,  2, 0,  1, 6},
                      {8, 11, 0,  0,  0,  0, 1,  0, 7},
                      {0,  0, 2,  0,  0,  0, 6,  7, 0}
                     };
					 
	dijkstra(graph, 0);
	return 0;
}
