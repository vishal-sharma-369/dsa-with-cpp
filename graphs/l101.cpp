#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Write a program to implement bellman ford algorithm

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // n-1 times
    for (int i = 1; i <= n; i++)
    {
        // traverse all edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    bool flag = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
        {
            flag = true;
            dist[v] = dist[u] + wt;
        }
    }

    if (flag == true)
    {
        cout << "the graph contains a negative cycle" << endl;
        return -1;
    }
    else
    {
        return dist[dest];
    }
}
// Time complexity : O(n*m)
// Space complexity : O(n)

int main()
{
    return 0;
}