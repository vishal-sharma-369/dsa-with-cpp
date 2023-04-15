#include <bits/stdc++.h>

using namespace std;

// DFS traversal in a graph
void createAdjList(int n, int m, vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    visited[node] = true;
    ans.push_back(node);

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(adj, visited, ans, i);
        }
    }
}

vector<vector<int>> DFS(int n, int m, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    createAdjList(n, m, edges, adj);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}

// The time complexity of this solution is O(n+e)
int main()
{
    return 0;
}