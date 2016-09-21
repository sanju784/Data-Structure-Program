/**
 * Kosaraju Algorithm - This algorithm is to find strongly Connected Components of a Graph
 * This algorithm is for directed Graph
 * The connected components of a graph is collection of those vertices in which from one vertex we can reach all other vertices of that component
 *
 * It does DFS of a graph 2 times
 * In first DFS it saves vertex in a Stack
 * Then reverse the Graph, then pop an element from Graph
 * Do DFS again with the popped elements of the Stack
 *
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
    void fillOrder(int v, bool visited[], stack<int> &stack);
    void DFSUtil(int v, bool visited[]);
    void printSCCs();
    Graph getTranspose();
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

void Graph::DFSUtil(int v, bool visited[])
{
    //marking the current as visited and printing it
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator itr;

    //Recur for all verices adjacent to the current vertex
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
    {
        if(!visited[*itr])
            DFSUtil(*itr, visited);
    }
}

//Function to return Transpose of a Graph
Graph Graph::getTranspose()
{
    Graph g(V);
    for(int v=0;v<V;v++)
    {
        list<int>::iterator itr;
        for(itr = adj[v].begin(); itr != adj[v].end();itr++)
        {
            g.adj[*itr].push_back(v);
        }
    }
    return g;
}

//Fills Stack with vertices
//This function performs first DFS too and insert vertex to stack when all adjacent vertex of it is visited
void Graph::fillOrder(int v, bool visited[], stack<int> &stk)
{
    visited[v] = true;
    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
    {
        if(!visited[*itr])
            fillOrder(*itr, visited, stk);
    }
    stk.push(v);
}

//function to find and print Strongly Connected Components of a Graph
void Graph::printSCCs()
{
    stack<int> stk;

    //mark all vertices as not visited (for first DFS)
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    //fill vertices in stack
    for(int i=0;i<V;i++)
        if(visited[i] == false)
            fillOrder(i, visited, stk);

    //creating a reverse graph
    Graph gr = getTranspose();

    //mark all vertices as not visited (for second DFS)
    for(int i=0;i<V;i++)
        visited[i]=false;

    //Processing all vertices in the order defined by Stack
    while(!stk.empty())
    {
        //getting a vertex from a stack
        int v = stk.top();
        stk.pop();

        //Print Strongly Connected Components of the popped Vertex
        if(visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            cout<<endl;
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout<<"The Strongly Connected Components of Graph are \n";
    g.printSCCs();

    return 0;
}
