#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << *max_element(v.begin(), v.end()) << endl;
    cout << *min_element(v.begin(), v.end()) << endl;
    return 0;
}

// Floyd's warshall algorithm.  Used for calculating the shortest path from evedry vertex to every other vertex of the graph.
// Ford - Fulkerson algorithm.  Used for calculating the maximum flow of the graph.
// Fleury's algorithm for find out the euler path or euler cycle.
// Tarjan's algorithm is used to find the articulation points.

/*
disjoint set / union find
union by rank.
union by size.
path compression.


Greedy algorithms:
kruskal's
prim's
dijkstra's

hamiltonian path : visiting each vertex exactly once.
euler path : visit each edge exactly once.
*/

// 4 - 1 = 3
// 4 - 2 = 2
// 4 - 3 = 1
// 4 - 1 = 3