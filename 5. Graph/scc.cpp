/**
 * This program is to find Strongly Connected Components of a Undirected Graph
 *
 * Here the number of times the DFS recursion is called by different Vertex gives the number of SCC
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
    void DFSUtil(int v, bool visited[]);
    void SCC();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout<<v <<" ";
    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
    {
        if(!visited[*itr])
            DFSUtil(*itr, visited);
    }
}

void Graph::SCC()
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            DFSUtil(i, visited);
            cout<<endl;
        }
    }
}

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,4);
    cout<<"Following are the Strongly Connected Components of a Graph\n";
    g.SCC();
}
