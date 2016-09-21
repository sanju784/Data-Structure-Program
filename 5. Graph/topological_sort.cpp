/*
 * This is for directed graph, if there is an edge uv then u will always come before v in all topological sort result
 * There are multiple possible topological sort result for a single graph
 */
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	
public:
	Graph(int V);
	void addEdge(int u, int v);
	void topologicalSort();
	void topologicalSortUtil(int v, bool visited[], stack<int> &s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &stk)
{
	visited[v] = true;
	
	//check for all unvisted adjacent vertices
	list<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
		if(!visited[*itr])
			topologicalSortUtil(*itr, visited, stk);
		
	//add current vertex to stack to store result
	stk.push(v);
}

void Graph::topologicalSort()
{
	stack<int> stk;
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
	
	//checking for all unvisited verices
	for(int i=0;i<V;i++)
		if(visited[i] == false)
			topologicalSortUtil(i, visited, stk);
	
	while(!stk.empty())
	{
		cout<<stk.top()<<" ";
		stk.pop();
	}
}

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
	cout<<"The Topological Sort is ";
	g.topologicalSort();
}