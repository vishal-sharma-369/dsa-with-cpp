#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Write a program for finding the shortest path using the dijkstra's algorithm

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < vertices; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);
    for (int i = 0; i < edges; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance upadte
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
// Time complexity of this solution is O(ElogV)

int main()
{
    return 0;
}