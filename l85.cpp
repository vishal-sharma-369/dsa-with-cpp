// Today we are going to learn about the graphs.
// Graph is a type of data structure which is a combination of nodes and edges.
/*
There are two types of graphs:
undirected graph
directed graph

nodes -> entity to store data
edge  -> entity to connect nodes

undirected graph:
degree(v) -> no. of nodess connected to node v

directed graph:
indegree(v) <- no of edges directed towards v
outdegree(v) -> no of edges directed away from v


weighted graph:

two types -> weighted undirected graph
          -> weighted directed graph


path :
    sequence of nodes such that each node in the path appears only once.


cyclic graph
weighted cyclic graph

acyclic graph
weighted acyclic directed graph


// How to represent a grpah
- Adjacency matrix
- Adjacency list


Adjacency matrix:
in the matrix the column of a particular row represents whether the element of the particular row is connected to the element of the particular column or not.
the space complexity of this solution is O(n^2).


Adjacency list:
the elements of a particular index represents the nodes to which the particular node at that index is connected to.
the adjacency list can be represented using a map whose key would be an integer i.e. the index of the node and the value will be a linked lsit or vector representing the elements to which it is connected to.


we also have to concept of disconnected graphs.
*/
// Write a program to implement a graph
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction 0 => undirected
        // direction 1 => directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto i : i.second)
            {
                cout << i << ", ";
            }
            cout << endl;
        }
    }
};

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto x : i.second)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }
};

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == false)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto x : i.second)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }
};

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == false)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto x : i.second)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }
};

class Graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == false)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto x : i.second)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing the graph
    g.printAdjList();
    return 0;
}

// Topological Sort can be used only in case of directed acyclic graph.
/*
It is a linear ordering of vertices such that every edge from u to v , u always appears before v in that ordering.
The concept of topoligica sorting doesn't exist for cyclic graphs.
The concept of topological sorting doesn't exist for undirected graphs.

The topological sort can be applied only to a directed acyclic graph.
So we can use the concept of invalid topological sort to detect cycles in a graph.
So we can use the concept of kahn's algorithm to check whether the cycles exist in a loop or not.

*/