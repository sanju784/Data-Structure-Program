#include <iostream>
#include <queue>
#include <list>

using namespace std;

//number of vertices in graph
int v;

//array of linked list to represent graph as adjency list
list<int> *adj;

void init(int n) {
	v = n;
	adj = new list<int>[n];
}

void addEdge(int u, int v) {
	adj[u].push_back(v);
}

void bfs(int s) {
	bool *visited = new bool[v];
	for (int i =0;i<v;i++)
		visited[i] = false;
	queue<int> q;
	visited[s] = true;
	q.push(s);

	//iterator to traverse through all adjacent node
	list<int>::iterator i;

	while(!q.empty()){
		s = q.front();
		cout<<s<<" ";
		q.pop();
		for(i = adj[s].begin(); i != adj[s].end(); i++){
			if(!visited[*i])
			{
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

int main() {
	init(4);
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(2, 0);
	addEdge(2, 3);
	addEdge(3, 3);

	cout<<"BFS from vertex 2 is ";
	bfs(2);
	
	return 0;
}