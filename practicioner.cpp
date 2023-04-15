#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <limits.h>

/*
STL : standard template library
it consists of classes and functions
provides lot of inbuilt data structures and algorithms
major components
- algorithms - logic
- containers - storage
- iterators and functors

Why learn stl
easy to use
save implementation time
pass all testcases
optimized implementation

*/

using namespace std;

// today we will be talking about the pair container
// pair is a container which helps us to bind two values within a single container
// int main()
// {
//     // int arr[] = {1, 10, 11, 9, 100};
//     // int n = sizeof(arr) / sizeof(int);
//     // // search -> find
//     // int key;
//     // cin >> key;
//     // auto it = find(arr, arr + n, key);
//     // int index = it - arr;
//     // if (index == n)
//     // {
//     //     cout << "Element not present" << endl;
//     // }
//     // else
//     // {
//     //     cout << "Element present at index " << index << endl;
//     // }
//     // cout << index << endl;
//     // pair<int, int> p;
//     // p.first = 5;
//     // p.second = 10;
//     // cout << p.first << " -> " << p.second << endl;
//     // pair<int, int> q(p);
//     // cout << q.first << " -> " << q.second << endl;
//     // pair<int, int> r = p;
//     // r = make_pair(5, 5);
//     // so these are the ways to make a pair inside stl
//     // we can make an array of pairs , vector of pairs and all the stuff.
//     // Pair
//     pair<int, int> p;
//     p.first = 10;
//     p.second = 'B';
//     pair<int, int> p2(p);
//     cout << p2.first << " -> " << p2.second << endl;
//     // we can also use a make pair function
//     pair<int, string> p3 = make_pair(5, "audi");
//     cout << p3.first << " -> " << p3.second << endl;
//     // we can also make a pair of a pair
//     pair<pair<int, int>, pair<int, int>> x;
//     x.first.first = 1;
//     x.first.second = 2;
//     x.second.first = 3;
//     x.second.second = 4;
//     cout << x.first.first << " -> " << x.first.second << endl;
//     cout << x.second.first << " -> " << x.second.second << endl;
//     // Today we are going to work with the  swap functionality
//     // int a = 10;
//     // int b = 20;
//     // swap(a, b);
//     // cout << a << " and " << b << endl;
//     // cout << max(a, b) << endl;
//     // cout << min(a, b) << endl;
//     int a[] = {1, 2, 3, 4, 4, 5};
//     reverse(a, a + 4);
//     int n = sizeof(a) / sizeof(int);
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
//     // we can also use swap function with the array elements
//     swap(a[0], a[4]);
//     next_permutation(a, a + 5);
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
//     return 0;
// }

int main()
{
    return 0;
}

/*
max(a,b);
min(a,b);
next_permutation(a,a+5);
pair<int,int> p;
reverse(a,a+5);
swap(a,b);
*/

/*
for an unordered map the adjacency list can be made as unordered_map<int,list<pair<int,int>>> adj;
// this is the formula for implementing the adjacency list.
set is an ordered pair of elements.
an ordered set can also behave as a priority queue of minheap if we use the pair of elements inside the set.
The time complexity of dijkstra algorithm is O(elogv) where e is the number of edges and v is the no. of vertices.
O(n+e) space
Today we are going to learn about the prims algorithm
spanning tree : when you  can convert a graph into a tree which contains n nodes and n-1 edges i.e. no cycles should be present in the tee.
we use the prims and the kruskals algorithm to find the minimum spanning tree.
Minimal spanning tree:
                    Let G be a weighted graph. A minimal spanning tree of G is a spanning tree of G with minimum weight.
                    The number of nodes in the tree is equal to the number of nodes in graph but the number of edges is not equal to the number of edges . it is less then or equal to the number of edges in graph.
We use the krushkal's algorithm and the prim's algorithm to find the minimum spanning tree of a graph.

1. Krushkal's algorithm:

    Working rule

    chooose an edge of minimal weight
    at each step, choose the edge whose inclusion will not create a circuit
    if g has n vertices , stop after (n-1) edges.

2. Prim's algorithm:

    Working rule

    select any vertex & choose the edge and smallest weight of G.
    at each stage, choose the edge of smallest weight joining a vertex already included to vertex not yet included.
    continue until all vertices are included.




prims algorithm is used to find the minimum spanning tree
spanning tree is a part of a graph which can act as a tree(i.e. it contains all the n nodes and contains n-1 edges)
the spanning tree whose weighted sum is the minimum of all the spanning trees of the graph is known as the minimum spanning tree of graph.


we will use 3 arrays to implement prims algorithm
key array : it contains the minimum distance to reach that node from the already selected set of nodes.
mst array : it contains the set of nodes which are already included for the spanning tree.
parent array : it contains the set of nodes which are parent to a specific node.

in the starting the first node will be kept at a distance of 0 for the beginning of the solution

// Your homework is to implement the prim's algorithm using priority_queue or the minHeap


Today we are going to learn about disjoint set and the second kruskal's algorithm

Now we are going to learn about :
Union by rank and pair compression

disjoint set is a data structure which can be used to check if the two nodes belong to the same component or different component of the graph , or to check if the graph contains a cycle or not.


the disjoint set has two important functionalities:
findParent() or findSet()
union() or unionSet()


we will talk about the time complexity:
first sorting : TC : O(mlogm) where m is the number of edges
find parent : TC : O(1)
untion set : TC : O(1)
The time complexity of the entire kruskal algorithm is O(mlogm) where m is the number of edges
The space complexity of this solution is O(n)


Bridges :
    A bridge is an edge in a graph whose removal disconnects the graph.
    A bridge is an edge in a graph whose removal increases the number of connected components in the graph.

Write a program to check whether a connected edge is a bridge or not.


datastructures needed:
discovery array
low array
parent array
visited array

the brute force approach to check whether a given edge is a bridge or not is to take every edge and check whether the remvoval of given node increases the number of connected components in the graph or not.

The time complexity TC: O(n+e)
The space complexity SC: O(n)


Articulation points:
    An articulation point in a graph is a node in graph whose removal disconnects the graph.
    An articulation point in a graph is a node whose removal increases the number of connected components in the graph.

Write a program to check whether the given node is an articulation point or not?
Using brute force we remvoe each node one by one and check the number of components to see if the given node is an articulation point or not.
The time complexity of this solution will be O(n*(n+e))


// Today we are going to learn about the kosaraju's algorithm
this algorithm is used to find out the strongly connected components
a strongly connected component is that component of graph for which all the nodes present in the node can be reached after the whole traversal of all the nodes of that component in a directed graph
a graph can have as many number of strongly connected components.
remember : a single node in a graph is always a strongly connected component in itself.


kosaraju algorithm is based on 3 steps:
sort all the nodes based on their finishing time. i.e. topological sorting
take transpose of the graph.
dfs -> count / print all the strongly connected components.



Now we are going to learn about the Bellman Ford algorithm:
this algorithm is used to find the shortest path from one node to another node in a graph
dijikstra algorithm can be used to find the shortest path only if the length of paths are all non negative integers

but for the paths containing negative lengths the dijikstra algorithm fails
in that case bellman ford algorithm comes into play.

the only condition for bellman ford algorithm is that the graph should not contain negative cycles in it.

plus point:
We can use the bellman ford algorithm to find if a graph contains a negative cycle or not.

use:
directed graphs with negative weights.

in order to apply the bellman ford to undirected graphs you can convert an undirected graph to a directed graph.


the bellman formula states that we should apply the formula dist[u] + wt  < dist[v] to all the edges for n-1 times
after this
apply the same formula one more time and see if any distance gets updated , it concludes that the graph contains a cycle and if it does not contain a cycle then the graph does not contain a negative cycle and return the distance of the required node.
here n is the number of nodes in the graph.

The time complexity of this solution is O(n*m) where n is the number of nodes and m is the number of edges.
*/

/*
Kahn's algorithm:
            This algorithm uses BFS for topological sorting of the given graph.
    1. find the indegree of all nodes.
    2. queue -> 0 indegree nodes -> insert
    3. do bfs
        whichever element's degree becomes 0 you can insert that element into the queue.
        if not present you can skip the element.


Cycle detection in directed graph using DFS:
we need two data structures:
visited
dfsVisited

Cycle detection in directed graph using BFS:
    in case of directed acyclic graph , the topological sort will be invalid indicating there is a cycle in a graph.
Time complexity : O(n+e)
Space complexity : O(n+e) linear


Shortest path in undirected graph:
we will be using the topological sort to solve this problem
data structures needed:
visited array
parent array
queue
Time complexity : O(n+e).
Space complexity : O(n+e).


Shortest path in a directed acyclic graph:
algorithm:
1. topological sort ordering
2. linear ordering -> distance array update
data structures needed:
1. stack
2. visited array
3. adjacency list(along with weights unordered_map<int,list<pair<int,int>>> adj;)
4. distance array (initialized with inf)
Time complexity : O(n+e)
Space complexity : O(n)


write a function for finding topological sort
make distance array and initialize it with int-max
dist[src] = 0;


Dijkstra's algorithm:
Dijkstra's shortest path algorithm.
Used when somebody asks to find the shortest distance of all the nodes from a specific node.
data structures needed:
distance array(initialized with INT_MAX)
priority_queue(minHeap) or ordered set
queue

int src = 0;
dist[src] = 0;

dijkstra's algorithm is the minimum edge distance algorithm in which the edge with the minimum distance is selected.
the iteration is ended when whose of the queue becomes empty.

Time Complexity : O(E log (V))
                    Edges   Vertices

Space complexity : O(N+E)
                    Linear


Prim's Algorithm:
        This algorithm is used to find the minimum spanning tree.
        every node is reachable by every other node.
        The total cost of the spanning tree should be minimum.
datastructures needed:
key array : indexes denote the nodes (initialized with INT_MAX)
parent array : initialized  with false
mst array : initialized with -1
*/

/*
disjoing set and the kruskal's algorithm
findParent() or findSet()
union() or unionSet()
data structures needed:
rank array

The time complexity of findParent and the union operation is O(1).

This is based on the concept of Union by rank and path compression.


Kruskal's algorithm:
data structures needed:
priority_queue(minHeap).
Time complexity of this solution is O(mlogm). where m is the number of edges in the graph.
Space complexity of this solution is O(n). Where n i sthe number of vertices in the graph.


Bridge : it is a node in a graph whose removal disconnects the graph or more precissely increases the number of connected components.
brute force : remove each edge and use dfs to check for number of components
data structures needed:


// Write a program to find the articulation points in a graph.

Articulation point: It is a node in a graph whose removal disconnects the graph. or more precisely the number of connected components increases.
The first approach to solve this problem will be the brute force . we will remove each node from the graph and apply the dfs or other algorithms to count the number of components.
Time complexity : O(V*(V+E)).


Kosaraju's algorithm:
This algorithm is used to find the strongly connected components.

We traverse the graph from the end of the topological sort of the graph.
We start from the front of the topological sort.

sort all nodes basis on their finishing time.
take transpose of the graph.
apply dfs to the transposed graph and count the scc's


Now we are going to learn about the Bellman Ford algorithm:
        Only condition is that the graph should not contain negative cycles.
        Dijkstra's algorithm doesn't work on the negative weight edges.

        Bellman ford algorithm can be used in case of directed graphs.
        You can use the undirected graphs into the directed graphs by converting the weight edge into two sided directed edges containing the same weight as is contained by the single undirected edge.

The time complexity of this solution is O(n*m). Where n is the number of nodes and m is the number of edges.
*/