#include <iostream>
#include <list>

using namespace std;

int V;
list<int> *adj;

void init(int n) {
  V = n;
  adj = new list<int>[n];
}

void addEdge(int u, int v) {
  adj[u].push_back(v);
}

void dfsUtil(int v, bool visited[]) {
  visited[v] = true;
  cout<<v<<"  ";
  list<int>::iterator i;
  for(i=adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i])
           dfsUtil(*i, visited);
  }
}

void dfs(int s) {
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
    visited[i] = false;
  dfsUtil(s, visited);
}

int main() {
  init(4);
  addEdge(0,1);
  addEdge(0,2);
  addEdge(1,2);
  addEdge(2,0);
  addEdge(2,3);
  addEdge(3,3);
  dfs(2);
  return 0;
}
