#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Write a program to find the bridge in a graph.

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(node, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[node]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> result;
    // adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}
// Time complexity of this solution is O(n+e).
// Space complexity of this solution is O(n).

int main()
{
    return 0;
}