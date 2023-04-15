#include <bits/stdc++.h>

using namespace std;

// Write a program to detect a cycle in a directed graph using dfs
void createAdjList(int n, int m, vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
        // adj[v].push_back(u); we are not executing this statement because it is a directed graph
    }
}

bool dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dinc, int node)
{
    visited[node] = true;
    dinc[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool ans = dfs(adj, visited, dinc, i);
            if (ans == true)
            {
                return true;
            }
        }
        // else if (i == parent)
        // {
        //     continue;
        // } we are not using it as it is a directed graph
        else if (dinc[i] == true)
        {
            return true;
        }
    }
    dinc[node] = false;
    return false;
}

bool DFS(int n, int m, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    createAdjList(n, m, edges, adj);
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dinc;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(adj, visited, dinc, i);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}

// The time complexity of this solution is O(n+e).
// The space complexity of this solution is O(n).

int main()
{
    return 0;
}