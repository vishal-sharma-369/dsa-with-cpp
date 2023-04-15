#include <bits/stdc++.h>

using namespace std;

// topological sort
// : the linear ordering of vertices such that for every edge u to v in graph G, u comes before v in that linear ordering.

// Write a program to print the nodes of a graph in topological order using dfs

// topological sort is only valid for directed acyclic graphs
void createAdjList(int n, int m, vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
    }
}

void dfs(unordered_map<int, list<int>> &adj, stack<int> st, unordered_map<int, bool> &visited, int node)
{
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(adj, st, visited, i);
        }
    }

    st.push(node);
}

vector<int> topoSort(int n, int m, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    createAdjList(n, m, edges, adj);

    unordered_map<int, bool> visited;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, st, visited, i);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        int front = st.top();
        st.pop();
        ans.push_back(front);
    }
    return ans;
}
// The time complexity of this solution is O(n+e).
// The space complexity of this solution is O(n).

int main()
{
    return 0;
}