#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Write a program to implement the kosaraju's algorithm
// This algorithm is used to find the strongly connected components
// sort all nodes basis on their finishing time
// take transpose of the given graph
// apply dfs to the transposed graph

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, st, adj);
        }
    }

    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            revDfs(i, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adj
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    // create a transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // dfs call using above ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            count++;
            revDfs(top, vis, adj);
        }
    }
    return count;
}

// Time complexity of this solution is O(n+e).
// Space complexity of this solution is O(n).

int main()
{
    return 0;
}