#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

// Representation of graphs:
// Adjacency matrix
// Adjacency list
// Implementation of graphs using adjacency matrix
// class graph
// {
//     int **arr;
//     int n;
// public:
//     graph(int n) // n is the number of nodes
//     {
//         arr = new int *[n];
//         for (int i = 0; i < n; i++)
//         {
//             arr[i] = new int[n];
//         }
//         // Initializing the graph with 0 edges
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 arr[i][j] = 0;
//             }
//         }
//         this->n = n;
//     }
//     void addEdge(int u, int v, bool direction)
//     {
//         // for 0 based node graphs
//         arr[u][v] = 1;
//         // for 1 based node graphs
//         // arr[u - 1][v - 1] = 1;
//         if (direction == false)
//         {
//             // for 0 based node graphs
//             arr[v][u] = 1;
//             // for 1 based node graphs
//             // arr[v - 1][u - 1] = 1;
//         }
//     }
//     void printAdjMatrix()
//     {
//         // for 0 based node graph
//         for (int i = 0; i < n; i++)
//         {
//             cout << i << " -> ";
//             for (int j = 0; j < n; j++)
//             {
//                 if (arr[i][j] == 1)
//                 {
//                     cout << j << ", ";
//                 }
//             }
//             cout << endl;
//         }
//         // for 1 based node graph
//         for (int i = 0; i < n; i++)
//         {
//             cout << i + 1 << " -> ";
//             for (int j = 0; j < n; j++)
//             {
//                 if (arr[i][j] == 1)
//                 {
//                     cout << j + 1 << ", ";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };

// // Implementation of graph using adjacency list
// class Graph
// {
//     unordered_map<int, list<int>> adj;

// public:
//     void addEdge(int u, int v, bool direction)
//     {
//         // for 0 based node graph
//         adj[u].push_back(v);

//         // for 1 based node graph
//         // adj[u - 1].push_back(v - 1);

//         if (direction == false)
//         {
//             adj[v].push_back(u);

//             // for 1 based node graph
//             // adj[v - 1].push_back(u - 1);
//         }
//     }

//     void printAdjList()
//     {
//         for (auto i : adj)
//         {
//             cout << i.first << " -> ";
//             for (auto x : i.second)
//             {
//                 cout << x << ", ";
//             }
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     int n;
//     cout << "Enter the number of nodes" << endl;
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges" << endl;
//     cin >> m;

//     Graph g;
//     Graph h;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         // creating an undirected graph
//         g.addEdge(u, v, false);

//         // creating a directed graph
//         h.addEdge(u, v, true);
//     }

//     // printing the graph

//     cout << "Printing the undirected graph" << endl;
//     g.printAdjList();

//     cout << "Printing the directed graph" << endl;
//     h.printAdjList();

//     return 0;
// }

// Write a program to print the adjacency list

// vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
// {
//     vector<int> ans[n];
//     for (int i = 0; i < m; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }

//     vector<vector<int>> adj;
//     for (int i = 0; i < n; i++)
//     {
//         adj[i].push_back(i);
//         for (auto x : ans[i])
//         {
//             adj[i].push_back(x);
//         }
//     }
//     return adj;
// }

// // write the time and the space complexity of this solution.
// int main()
// {
//     return 0;
// }

// Write a program to implement the BFS traversal of a graph

void createAdj(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adj)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

vector<int> BFS(vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;

    createAdj(edges, adj);
    unordered_map<int, bool> visited;
    vector<int> ans;
    int n = adj.size(); // here n is the number of nodes

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
        }
    }

    return ans;
}
// The time and space complexity of this solution is O(n+e).

int main()
{
    return 0;
}