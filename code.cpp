#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <fstream>

using namespace std;

int bfs(int **rGraph, int s, int t, int parent[], int V)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

void dfs(int **rGraph, int s, bool visited[], int V)
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
        if (rGraph[s][i] && !visited[i])
            dfs(rGraph, i, visited, V);
}

int minCut(int **graph, int s, int t, int V)
{
    int u, v;

    int **rGraph = new int *[V];
    for (u = 0; u < V; u++)
    {
        rGraph[u] = new int[V];
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    }

    int parent[V];

    while (bfs(rGraph, s, t, parent, V))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }

    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited, V);

    int no_removed_edges = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (visited[i] && !visited[j] && graph[i][j]) {
                no_removed_edges ++;
            }

    for (u = 0; u < V; u++)
        delete[] rGraph[u];
    delete[] rGraph;

    return no_removed_edges;
}

int main()
{
    string filename;
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cout << "Error opening file!\n";
        return 1;
    }

    int no_computers, no_connections;
    inputFile >> no_computers >> no_connections;

    int **inital_graph = new int *[no_computers];
    for (int i = 0; i < no_computers; ++i)
        inital_graph[i] = new int[no_computers];

    for (int i = 0; i < no_connections; i++)
    {
        int x, y;
        inputFile >> x >> y;
        inital_graph[x - 1][y - 1] = 1;
        inital_graph[y - 1][x - 1] = 1;
    }
    inputFile.close();

    // // Print elements of the 2D array
    // std::cout << "Elements of the 2D array:" << std::endl;
    // for (int i = 0; i < no_computers; ++i)
    // {
    //     for (int j = 0; j < no_computers; ++j)
    //     {
    //         std::cout << inital_graph[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    int s = 0;
    int t = no_computers - 1;

    int no_edges = minCut(inital_graph, s, t, no_computers);

    cout << no_edges;

    for (int i = 0; i < no_computers; ++i)
        delete[] inital_graph[i];
    delete[] inital_graph;

    return 0;
}