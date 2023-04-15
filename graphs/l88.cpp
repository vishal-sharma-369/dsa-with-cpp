#include <bits/stdc++.h>

using namespace std;

// cycle detection in undirected graph using BFS
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

bool bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node)
{
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(node);
    parent[node] = -1;
    visited[node] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
            else if (i == parent[front])
            {
                continue;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

bool BFS(int n, int m, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    createAdjList(n, m, edges, adj);

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = bfs(adj, visited, i);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}
// The time complexity of this solution is O(n+e)

// cycle detection in undirected graph using DFS

bool dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool ans = dfs(adj, visited, i, node);
            if (ans == true)
            {
                return true;
            }
        }
        else if (i == parent)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool DFS(int n, int m, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    createAdjList(n, m, edges, adj);

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(adj, visited, i, -1);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}

// The time complexity of this solution is O(n+e)
// The space complexity of this solution is O(n)

int main()
{
    return 0;
}