#include <iostream>
#include <list>
#include <stack>

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

void dfs(int s) {
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
    visited[i] = false;
  stack<int> stk;
  stk.push(s);
  while(!stk.empty()) {
    s = stk.top();
    stk.pop();
    if(!visited[s]) {
        cout<<s<<" ";
        visited[s] = true;
    }
    list<int>::iterator i;
    for(i=adj[s].begin(); i != adj[s].end(); i++)
        if(!visited[*i])
          stk.push(*i);
  }
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
