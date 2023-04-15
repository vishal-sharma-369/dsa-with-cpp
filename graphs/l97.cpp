#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Write a program to implement the disjoint set algorithm
// Union by rank and path compression algorithm
// 2 important functions
/*
findParent() or findSet()
union() or unionSet()

*/

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if (u != v)
        {
            minWeight += edges[i][2];
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

// the time complexity of this solution is O(nlogm).

int main()
{
    return 0;
}