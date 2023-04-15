#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Write a program to print the topological sorting of the given graph using kahn's algorithm.
// Or implement the topological sort using BFS.
// find indegree of all nodes
// queue -> 0 indegree nodes insert
// do BFS
void createAdjList(int n, int m, vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v); // as topological sort is only valid for directed graphs
    }
}

vector<int> topologicalSort(vector<pair<int, int>> &edges, int v, int e)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    createAdjList(v, e, edges, adj);

    // find all indegrees
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}