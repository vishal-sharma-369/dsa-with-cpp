#include <bits/stdc++.h>

using namespace std;

// Write a program to find the shortest path in undirected graph
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

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node)
{
    visited[node] = true;
    parent[node] = -1;

    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
}

vector<int> shortestPath(int n, int m, vector<pair<int, int>> &edges, int src, int dest)
{
    unordered_map<int, list<int>> adj;
    createAdjList(n, m, edges, adj);

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    bfs(adj, visited, parent, src);

    // prepare shortest path
    vector<int> ans;
    int currentNode = dest;
    ans.push_back(dest);
    while (currentNode != src)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
// The time complexity of this solution is O(n+e).
// The space complexity of this solution is O(n+e).

int main()
{
    return 0;
}