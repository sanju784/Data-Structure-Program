/**
 * Ford-Fulkerson Algorithm for maximum Flow
 */
#include <bits/stdc++.h>
using namespace std;

#define V 6

//Returns true if there is a path from source s to sink t in residual graph,
//with flow value greater than 0, also save parent of the path
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    //setting all vertex as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    //create a queue and add source vertex to it, and marking source vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    //traversing graph as bfs
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v=0;v<V;v++)
        {
            if(visited[v] == false && rGraph[u][v]>0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    //If sink is reached starting from source doing BFS then we return true
    return (visited[t] == true);
}

//return maximum flow from source to sink in a graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u,v;

    //creating a residual graph and filling it with capacities of original graph
    int rGraph[V][V];
    for(u=0;u<V;u++)
        for(v=0;v<V;v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    //checking if there is a path from source to sink
    //if path exists then we find the maximum flow of that path
    while(bfs(rGraph, s, t, parent))
    {
        //finding maximum flow possible for the path found in BFS from source s to sink t
        int path_flow = INT_MAX;
        for(v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        //updating residual capacity of edge after subtracting the flow from the path
        for(v=t;v!=s;v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        //adding current flow to the previous max flow
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    //matrix representation of Graph with value as permissible flow
    int graph[V][V] = { {0, 16, 13,  0,  0,  0},
                        {0,  0, 10, 12,  0,  0},
                        {0,  4,  0,  0, 14,  0},
                        {0,  0,  9,  0,  0, 20},
                        {0,  0,  0,  7,  0,  4},
                        {0,  0,  0,  0,  0,  0}
                      };

    cout<<"Maximum Flow in Graph is "<<fordFulkerson(graph, 0, 5);
}
