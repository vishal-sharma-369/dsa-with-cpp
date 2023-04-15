#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <list>
#include <tuple>
#include <list>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

// Write a program to implement the bfs traversal of given graph g
// class solution
// {
// public:
//     vector<int> bfsOfGraph(int v, vector<int> g[])
//     {
//         queue<int> q;
//         vector<bool> visited(false);
//         q.push(0);
//         visited[0] = true;
//         vector<int> ans;
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             ans.push_back(front);
//             for (auto i : g[front])
//             {
//                 if (!visited[i])
//                 {
//                     visited[i] = true;
//                     q.push(i);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// The time complexity of this solution is O(v+e).

// Write a program to implement the dfs traversal of given graph g
// class solution
// {
// public:
//     void dfs(vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans, int node)
//     {
//         visited[node] = true;
//         ans.push_back(node);
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, ans, i);
//             }
//         }
//     }
//     vector<int> dfsOfGraph(int v, vector<int> adj[])
//     {
//         unordered_map<int, bool> visited;
//         vector<int> ans;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, ans, i);
//             }
//         }
//         return ans;
//     }
// };
// The time complexity of this solution is o(v+e).
// The space complexity of this solution is O(v). // due to the stack frame made.

// Implementing the DFS algorithm iteratively
// class solution
// {
//     vector<int> dfs(vector<vector<int>> &adj, int v, int e)
//     {
//         stack<int> st;
//         unordered_map<int, bool> visited;
//         st.push(0);
//         vector<int> ans;
//         while (!st.empty())
//         {
//             int node = st.top();
//             st.pop();
//             cout << node << " ";
//             for (auto i : adj[node])
//             {
//                 if (!visited[i])
//                 {
//                     st.push(i);
//                     visited[i] = true;
//                 }
//             }
//         }
//     }
// };

// Write a program to check whether the directed graph contains a cycle or not.
// class solution
// {
// public:
//     bool dfs(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &dinc, int node)
//     {
//         visited[node] = true;
//         dinc[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, dinc, node);
//             }
//             else if (dinc[i] == false)
//             {
//                 continue;
//             }
//             else
//             {
//                 return true;
//             }
//         }
//         dinc[node] = false;
//         return false;
//     }
//     bool isCyclic(int v, vector<int> adj[])
//     {
//         unordered_map<int, bool> visited;
//         unordered_map<int, bool> dinc;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 bool ans = dfs(adj, visited, dinc, i);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// Write a program to check whether the undirected graph contains a cycle or not using bfs
// class solution
// {
// public:
//     bool bfs(vector<int> adj[], unordered_map<int, bool> &visited, int node)
//     {
//         queue<int> q;
//         vector<int> parent;
//         q.push(node);
//         visited[node] = true;
//         parent[node] = -1;
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             for (auto i : adj[front])
//             {
//                 if (!visited[i])
//                 {
//                     visited[i] = true;
//                     q.push(i);
//                     parent[i] = front;
//                 }
//                 else if (i == parent[front])
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool isCycle(int v, vector<int> adj[])
//     {
//         unordered_map<int, bool> visited;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 bool ans = bfs(adj, visited, i);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// Write a program to check whether the undirected graph contains a cycle or not using dfs
// class solution
// {
// public:
//     bool dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 bool ans = dfs(adj, visited, i, node);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//             else if (i == parent)
//             {
//                 continue;
//             }
//             else
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool isCycle(int v, vector<int> adj[])
//     {
//         // your code goes here
//         unordered_map<int, bool> visited;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 bool ans = dfs(adj, visited, i, -1);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// cycle detection in unordered graph using DFS iterative.
// class solution
// {
//     bool dfs(vector<int> adj[], int node, unordered_map<int, bool> &visited, int p)
//     {
//         stack<int> st;
//         st.push(node);
//         vector<int> parent;
//         parent[node] = p;
//         visited[node] = true;
//         while (!st.empty())
//         {
//             int top = st.top();
//             st.pop();
//             for (auto i : adj[top])
//             {
//                 if (!visited[i])
//                 {
//                     st.push(i);
//                     visited[i] = true;
//                     parent[i] = top;
//                 }
//                 else if (i == parent[top])
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
// public:
//     bool isCyclic(vector<int> adj[], int v, int e)
//     {
//         unordered_map<int, bool> visited;
//         for (int i = 0; i < v; i++)
//         {
//             if (visited[i] == false)
//             {
//                 bool ans = dfs(adj, i, visited, -1);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// Write a program to solve the rat in a maze problem using DFS
// #define MAX 5
// class solution
// {
// public:
//     void solve(int m[MAX][MAX], int vis[MAX][MAX], int x, int y, int n, vector<string> &ans, string &path)
//     {
//         if (x == n - 1 && y == n - 1)
//         {
//             ans.push_back(path);
//             return;
//         }
//         vis[x][y] = true;
//         // up condition
//         if (y + 1 >= 0 && vis[x][y + 1] != 1 && m[x][y + 1] != 0)
//         {
//             path += "U";
//             solve(m, vis, x, y + 1, n, ans, path);
//             path.pop_back();
//         }
//         // right condition
//         if (x + 1 < n && vis[x + 1][y] != 1 && m[x + 1][y] != 0)
//         {
//             path += "R";
//             solve(m, vis, x + 1, y, n, ans, path);
//             path.pop_back();
//         }
//         // down condition
//         if (y - 1 < n && vis[x][y - 1] != 1 && m[x][y - 1] != 0)
//         {
//             path += "D";
//             solve(m, vis, x, y - 1, n, ans, path);
//             path.pop_back();
//         }
//         // left condition
//         if (x - 1 >= 0 && vis[x - 1][y] != 1 && m[x - 1][y] != 0)
//         {
//             path += "L";
//             solve(m, vis, x - 1, y, n, ans, path);
//             path.pop_back();
//         }
//         vis[x][y] = false;
//     }
//     vector<string> findPath(int m[MAX][MAX], int n)
//     {
//         vector<string> ans;
//         if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
//         {
//             return ans;
//         }
//         int vis[MAX][MAX];
//         string path = "";
//         solve(m, vis, 0, 0, n, ans, path);
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };
// The time complexity of this solution is O((n^2)^2) or O(n^8).
// The space complexity of this solution is O(L*X) , L = length of the path , X = number of paths

// Write a program to calculate the minimum steps taken by the knight to reach the target Using BFS
// class solution
// {
// public:
//     int minStepToReachTarget(vector<int> &knightPos, vector<int> &TargetPos, int n)
//     {
//         vector<vector<int>> board(n, vector<int>(n, INT_MAX));
//         queue<pair<int, int>> q;
//         q.push(make_pair(knightPos[0], knightPos[1]));
//         board[knightPos[0]][knightPos[1]] = 0;
//         while (!q.empty())
//         {
//             auto front = q.front();
//             q.pop();
//             int row = front.first;
//             int col = front.second;
//             // up left condition
//             if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == INT_MAX)
//             {
//                 board[row - 2][col - 1] = board[row][col] + 1;
//                 q.push(make_pair(row - 2, col - 1));
//             }
//             // up right condition
//             if (row - 2 >= 0 && col + 1 < n && board[row - 2][col + 1] == INT_MAX)
//             {
//                 board[row - 2][col + 1] = board[row][col] + 1;
//                 q.push(make_pair(row - 2, col + 1));
//             }
//             // right up condition
//             if (row - 1 >= 0 && col + 2 < n && board[row - 1][col + 2] == INT_MAX)
//             {
//                 board[row - 1][col + 2] = board[row][col] + 1;
//                 q.push(make_pair(row - 1, col + 2));
//             }
//             // right down condition
//             if (row + 1 < n && col + 2 < n && board[row + 1][col + 2] == INT_MAX)
//             {
//                 board[row + 1][col + 2] = board[row][col] + 1;
//                 q.push(make_pair(row + 1, col + 2));
//             }
//             // down right condition
//             if (row + 2 < n && col + 1 < n && board[row + 2][col + 1] == INT_MAX)
//             {
//                 board[row + 2][col + 1] = board[row][col] + 1;
//                 q.push(make_pair(row + 2, col + 1));
//             }
//             // down left condition
//             if (row + 2 < n && col - 1 >= 0 && board[row + 2][col - 1] == INT_MAX)
//             {
//                 board[row + 2][col - 1] = board[row][col] + 1;
//                 q.push(make_pair(row + 2, col - 1));
//             }
//             // left down condition
//             if (row + 1 < n && col - 2 >= 0 && board[row + 1][col - 2] == INT_MAX)
//             {
//                 board[row + 1][col - 2] = board[row][col] + 1;
//                 q.push(make_pair(row + 1, col - 2));
//             }
//             // left up condition
//             if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == INT_MAX)
//             {
//                 board[row - 1][col - 2] = board[row][col] + 1;
//                 q.push(make_pair(row - 1, col - 2));
//             }
//         }
//         return board[TargetPos[0]][TargetPos[1]];
//     }
// };
// The time complexity of this solution is O(n^2).
// The space complexity of this solution is O(n^2).

// Write a program to clone a graph using dfs
// class solution
// {
//     class Node
//     {
//     public:
//         int val;
//         vector<Node *> neighbors;
//         Node()
//         {
//             val = 0;
//             neighbors = vector<Node *>();
//         }
//         Node(int _val)
//         {
//             val = _val;
//             neighbors = vector<Node *>();
//         }
//         Node(int _val, vector<Node *> _neighbors)
//         {
//             val = _val;
//             neighbors = _neighbors;
//         }
//     };
// public:
//     void dfs(Node *node, Node *copy, vector<Node *> &vis)
//     {
//         vis[copy->val] = copy;
//         for (auto x : node->neighbors)
//         {
//             if (vis[x->val] == NULL)
//             {
//                 Node *newNode = new Node(x->val);
//                 (copy->neighbors).push_back(newNode);
//                 dfs(x, newNode, vis);
//             }
//             else
//             {
//                 (copy->neighbors).push_back(vis[x->val]);
//             }
//         }
//     }
//     Node *cloneGraph(Node *node)
//     {
//         if (node == NULL)
//         {
//             return NULL;
//         }
//         vector<Node *> vis(1000, NULL);
//         Node *copy = new Node(node->val);
//         dfs(node, copy, vis);
//         return copy;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// Write a program to make wired connections to make all the computers connected. return the minimum number of wires that can be replaced to make this happen. Return -1 if this is not possible.
// class solution
// {
// public:
//     void createAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj)
//     {
//         for (auto i : edges)
//         {
//             int u = i[0];
//             int v = i[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//     }
//     void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, i);
//             }
//         }
//     }
//     int makeConnected(int n, vector<vector<int>> &edges)
//     {
//         if (edges.size() < n - 1)
//         {
//             return -1;
//         }
//         unordered_map<int, list<int>> adj;
//         createAdjList(edges, adj);
//         unordered_map<int, bool> visited;
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (!visited[i])
//             {
//                 count++;
//                 dfs(adj, visited, i);
//             }
//         }
//         return count - 1;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v+e).

// Write a program to find the topological sort of a given graph. Using DFS
// class solution
// {
// public:
//     void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, stack<int> &st)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, i, st);
//             }
//         }
//         st.push(node);
//     }
//     vector<int> topoSort(int v, vector<int> adj[])
//     {
//         unordered_map<int, bool> visited;
//         stack<int> st;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, i, st);
//             }
//         }
//         vector<int> ans;
//         while (!st.empty())
//         {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };

// Write a program to find the topological sort of a given graph using BFS. i.e. Kahn's algorithm
// class solution
// {
// public:
//     vector<int> topoSort(int v, vector<int> adj[])
//     {
//         /*
//         kahn's algorithm:
//         1. find the inorder of all the nodes
//         2. push all the nodes with 0 indegree into the queue
//         3. do bfs with pushing the front elements of queue into the ans vector.
//         */
//         vector<int> indegree(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             for (auto x : adj[i])
//             {
//                 indegree[x]++;
//             }
//         }
//         queue<int> q;
//         for (int i = 0; i < v; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }
//         vector<int> ans;
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             ans.push_back(front);
//             for (auto i : adj[front])
//             {
//                 indegree[i]--;
//                 if (indegree[i] == 0)
//                 {
//                     q.push(i);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// Write a program to solve the word ladder graph problem.
// class solution
// {
// public:
//     int ladderLength(string start, string end, vector<string> &wordList)
//     {
//         queue<string> q;
//         q.push(start);
//         int wordSize = start.size();
//         unordered_set<string> word;
//         for (int i = 0; i < wordList.size(); i++)
//         {
//             word.insert(wordList[i]);
//         }
//         if (word.find(end) == word.end())
//         {
//             return 0;
//         }
//         int len = 0;
//         while (!q.empty())
//         {
//             len++;
//             int qlen = q.size();
//             for (int i = 0; i < qlen; i++)
//             {
//                 string s = q.front();
//                 q.pop();
//                 for (int j = 0; j < wordSize; j++)
//                 {
//                     char org = s[j];
//                     for (char ch = 'a'; ch <= 'z'; ch++)
//                     {
//                         s[j] = ch;
//                         if (s == end)
//                             return len + 1;
//                         if (word.find(s) == word.end())
//                             continue;
//                         word.erase(s);
//                         q.push(s);
//                     }
//                     s[j] = org;
//                 }
//             }
//         }
//         return 0;
//     }
// };
// The time complexity of this solution is O(n*m*26)
// the space complexity of this solution is O(n).

// Write a program to solve the word ladder graph problem.
// class solution
// {
// public:
//     int ladderLength(string start, string end, vector<string> &wordList)
//     {
//         unordered_set<string> list;
//         for (int i = 0; i < wordList.size(); i++)
//         {
//             list.insert(wordList[i]);
//         }
//         if (list.find(start) == list.end())
//             return 0;
//         if (list.find(end) == list.end())
//             return 0;
//         queue<pair<string, int>> q;
//         q.push(make_pair(start, 0));
//         list.erase(start);
//         while (!q.empty())
//         {
//             auto front = q.front();
//             q.pop();
//             string str = front.first;
//             int step = front.second;
//             if (str == end)
//             {
//                 return step;
//             }
//             for (int i = 0; i < str.length(); i++)
//             {
//                 char original = str[i];
//                 for (char c = 'a'; c <= 'z'; c++)
//                 {
//                     str[i] = c;
//                     // if (str == end)
//                     // {
//                     //     return step + 1;
//                     // }
//                     if (list.find(str) != list.end())
//                     {
//                         q.push(make_pair(str, step + 1));
//                         list.erase(str);
//                     }
//                 }
//                 str[i] = original;
//             }
//         }
//         return 0;
//     }
// };
// time complexity of this solution is O(n*m*26).
// space complexity of this solution is O(n).

// Write a program to detect a cycle in a directed graph using BFS. This will use the concept of topological sort.
// class solution
// {
// public:
//     bool isCyclic(int v, vector<int> adj[])
//     {
//         // using kahn's algorithm
//         vector<int> indegree(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             for (auto x : adj[i])
//             {
//                 indegree[x]++;
//             }
//         }
//         queue<int> q;
//         for (int i = 0; i < v; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }
//         int count = 0;
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             count++;
//             for (auto i : adj[front])
//             {
//                 indegree[i]--;
//                 if (indegree[i] == 0)
//                 {
//                     q.push(i);
//                 }
//             }
//         }
//         if (count == v)
//         {
//             return false;
//         }
//         else
//         {
//             return true;
//         }
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// Write a program to find the minimum time taken by each job to be completed given by a directed acyclic graph.
// class solution
// {
// public:
//     vector<int> minimumTimeToCompleteJob(int v, vector<int> adj[])
//     {
//         vector<int> indegree(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             for (auto x : adj[i])
//             {
//                 indegree[x]++;
//             }
//         }
//         queue<int> q;
//         vector<int> ans(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             if (indegree[i] == 0)
//             {
//                 q.push(i);
//                 ans[i] = 1;
//             }
//         }
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             for (auto i : adj[front])
//             {
//                 indegree[i]--;
//                 if (indegree[i] == 0)
//                 {
//                     ans[i] = ans[front] + 1;
//                     q.push(i);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// Write a program to check whether it is possible to finish all tasks or not from given dependencies.
// Solution: Make a directed graph from the given pair of vertices and then check for the presence of a cycle in the loop. If the graph contains a cycle , then it is not possible to complete all the tasks, otherwise it is possible to do the tasks.

// Write a program to find the number of islands in a graph.
// class solution
// {
// public:
//     void dfs(int row, int col, vector<vector<bool>> &visited, vector<int> a[], int n, int m)
//     {
//         if (row < 0 || row >= n || col < 0 || col >= n || a[row][col] == 0 || visited[row][col] == true)
//         {
//             return;
//         }
//         visited[row][col] = true;
//         // up
//         dfs(row - 1, col, visited, a, n, m);
//         // up right
//         dfs(row - 1, col + 1, visited, a, n, m);
//         // right
//         dfs(row, col + 1, visited, a, n, m);
//         // right down
//         dfs(row + 1, col + 1, visited, a, n, m);
//         // down
//         dfs(row + 1, col, visited, a, n, m);
//         // down left
//         dfs(row + 1, col - 1, visited, a, n, m);
//         // left
//         dfs(row, col - 1, visited, a, n, m);
//         // left up
//         dfs(row - 1, col - 1, visited, a, n, m);
//     }
//     int findIslands(vector<int> A[], int n, int m)
//     {
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         int c = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (!visited[i][j] && A[i][j] == 1)
//                 {
//                     c++;
//                     dfs(i, j, visited, A, n, m);
//                 }
//             }
//         }
//         return c;
//     }
// };
// The time complexity of this solution is O(n*m).
// The space complexity of this solution is O(n*m).

// Given a sorted dictionary of an alien language,find order of characters
// class solution
// {
// public:
//     void dfs(int node, vector<vector<int>> &g, vector<int> &vis, string &ans)
//     {
//         vis[node] = 1;
//         for (auto x : g[node])
//         {
//             if (!vis[x])
//             {
//                 dfs(x, g, vis, ans);
//             }
//         }
//         char ch = node + 'a';
//         ans = ch + ans;
//     }
//     string findOrder(string dict[], int n, int k)
//     {
//         vector<vector<int>> g(k);
//         for (int i = 0; i < n - 1; i++)
//         {
//             string w1 = dict[i];
//             string w2 = dict[i + 1];
//             for (int j = 0; j < min(w1.length(), w2.length()); j++)
//             {
//                 if (w1[j] != w2[j])
//                 {
//                     g[w1[j] - 'a'].push_back(w2[j] - 'a');
//                     break;
//                 }
//             }
//             // up till now we have successfully created the graph .
//             // Now we need to find the topological order of the graph.
//             vector<int> vis(k, 0);
//             string ans = "";
//             for (int i = 0; i < k; i++)
//             {
//                 if (!vis[i])
//                 {
//                     dfs(i, g, vis, ans);
//                 }
//             }
//         }
//     }
// };
// Time complexity of this solution is O().
// Space complexity of this solution is O().

// Write a program to solve the graph coloring problem.
// #define pb(x) push_back(x)
// void solve()
// {
//     int v, e;
//     cin >> v >> e;
//     vector<vector<int>> g(v);
//     for (int i = 0; i < e; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         g[x].pb(y);
//         g[y].pb(x);
//     }
//     int res[v];
//     bool available[v];
//     res[0] = 0;
//     for (int i = 1; i < v; i++)
//         res[i] = -1;
//     for (int i = 0; i < v; i++)
//         available[i] = false;
//     int cn = 0;
//     for (int i = 1; i < v; i++)
//     {
//         for (auto x : g[i])
//         {
//             if (res[x] != -1)
//             {
//                 available[res[x]] = true;
//             }
//         }
//         int cr;
//         for (cr = 0; cr < v; cr++)
//         {
//             if (available[cr] == false)
//             {
//                 break;
//             }
//         }
//         res[i] = cr;
//         cn = max(cn, cr + 1);
//         for (auto x : g[i])
//         {
//             if (res[x] != -1)
//             {
//                 available[res[x]] = false;
//             }
//         }
//     }
//     cout << cn << endl;
//     for (int i = 0; i < v; i++)
//         cout << res[i] << " ";
//     cout << endl;
// }
// The time complexity of this solution is O(n^2).
// The space complexity of this solution is O(v).

// Write a program to find the number of strongly connected components. Using kosaraju's algorithm.
// class solution
// {
// public:
//     void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, stack<int> &st)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, i, st);
//             }
//         }
//         st.push(node);
//     }
//     void revDfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 revDfs(adj, visited, i);
//             }
//         }
//     }
//     int kosaraju(int v, vector<int> adj[])
//     {
//         // Your code goes here.
//         // 1. find the topological sort of the given graph.
//         unordered_map<int, bool> visited;
//         stack<int> st;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, i, st);
//             }
//         }
//         // 2. find the transpose of the given graph.
//         unordered_map<int, list<int>> transpose;
//         for (int i = 0; i < v; i++)
//         {
//             visited[i] = false;
//             for (auto x : adj[i])
//             {
//                 transpose[x].push_back(i);
//             }
//         }
//         int count = 0;
//         while (!st.empty())
//         {
//             int top = st.top();
//             if (!visited[top])
//             {
//                 count++;
//                 revDfs(transpose, visited, top);
//             }
//         }
//         return count;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of tis solution is O(v).

// Write a program to check whether the given graph is a bipartite graph or not.
// This problem can be simplified down to the graph coloring problem where we need to check whether we are able to color all the nodes  of the graph using only two colors or not.
// class solution
// {
// public:
//     bool isBipartite(int v, vector<int> adj[])
//     {
//         vector<int> filledColor(v);
//         vector<bool> available(v);
//         filledColor[0] = 0;
//         for (int i = 1; i < v; i++)
//         {
//             filledColor[i] = -1;
//         }
//         for (int i = 0; i < v; i++)
//         {
//             available[i] = true;
//         }
//         int cn = 1;
//         for (int i = 1; i < v; i++)
//         {
//             for (auto x : adj[i])
//             {
//                 if (filledColor[x] != -1)
//                 {
//                     available[filledColor[x]] = false;
//                 }
//             }
//             int cr = 0;
//             for (int i = 0; i < v; i++)
//             {
//                 if (available[i] == true)
//                 {
//                     cr = i;
//                     break;
//                 }
//             }
//             cn = max(cn, cr + 1);
//             if (cn > 2)
//             {
//                 return false;
//             }
//             for (auto x : adj[i])
//             {
//                 if (filledColor[i] != -1)
//                 {
//                     available[filledColor[i]] = true;
//                 }
//             }
//         }
//         return true;
//     }
// };

// Write a program to check whether the given graph is bipartite or not using DFS.
// class solution
// {
// public:
//     int f = 0;
//     void dfs(int src, int parent, int col, vector<vector<int>> &g, vector<int> &vis)
//     {
//         vis[src] = col;
//         for (auto x : g[src])
//         {
//             if (vis[x] == -1)
//             {
//                 dfs(x, src, 3 - col, g, vis);
//             }
//             else if (x == parent)
//             {
//                 continue;
//             }
//             else if (x != parent && col == vis[x])
//             {
//                 f = 1;
//                 break;
//             }
//         }
//     }
//     void solve()
//     {
//         int v, e;
//         cin >> v >> e;
//         vector<vector<int>> g(v);
//         for (int i = 0; i < e; i++)
//         {
//             int x, y;
//             cin >> x >> y;
//             g[x].push_back(y);
//             g[y].push_back(x);
//         }
//         f = 0;
//         vector<int> vis(v, -1);
//         dfs(0, 0, 1, g, vis);
//         if (f)
//             cout << "Not bipartite" << endl;
//         else
//             cout << "Bipartite" << endl;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v).

// Write a program to check whether the given graph is bipartite or not using BFS.
// class solution
// {
// public:
//     bool bfs(vector<int> adj[], unordered_map<int, int> &visited, int node)
//     {
//         queue<pair<int, int>> q;
//         q.push(make_pair(node, 1));
//         visited[node] = 1;
//         unordered_map<int, int> parent;
//         parent[node] = -1;
//         while (!q.empty())
//         {
//             int fn = q.front().first;
//             int fc = q.front().second;
//             q.pop();
//             for (auto i : adj[fn])
//             {
//                 if (!visited[i])
//                 {
//                     visited[i] = 3 - fc;
//                     q.push(make_pair(i, 3 - fc));
//                 }
//                 else if (i == parent[fn])
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     if (visited[i] == fc)
//                     {
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
//     bool isBipartite(int v, int e, vector<int> adj[])
//     {
//         unordered_map<int, int> visited(0);
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 bool ans = bfs(adj, visited, i);
//                 if (ans == false)
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

// Write a program to calculate the longest path in a directed acyclic graph
// class solution
// {
// public:
//     vector<int> order;
//     void topo(int src, vector<int> &vis, vector<vector<pair<int, int>>> g)
//     {
//         vis[src] = 1;
//         for (auto x : g[src])
//         {
//             if (!vis[x.first])
//             {
//                 topo(x.first, vis, g);
//             }
//         }
//         order.push_back(src);
//     }
//     int main()
//     {
//         int v, e;
//         cin >> v >> e;
//         int src;
//         cin >> src;
//         vector<vector<pair<int, int>>> g(v);
//         for (int i = 0; i < e; i++)
//         {
//             int x, y, w;
//             cin >> x >> y >> w;
//             g[x].push_back({y, w});
//         }
//         vector<int> vis(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             if (!vis[i])
//             {
//                 topo(i, vis, g);
//             }
//         }
//         vector<int> dist(v);
//         for (int i = 0; i < v; i++)
//         {
//             dist[i] = INT_MIN;
//         }
//         dist[src] = 0;
//         for (int i = v - 1; i >= 0; i--)
//         {
//             if (dist[order[i]] != INT_MIN)
//             {
//                 for (auto x : g[order[i]])
//                 {
//                     int v = dist[x.first];
//                     int w = x.second;
//                     int u = dist[order[i]];
//                     if (u + w > v)
//                     {
//                         dist[x.first] = u + w;
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < v; i++)
//         {
//             if (i != src and dist[i] != INT_MIN)
//             {
//                 cout << src << " -> " << i << " = " << dist[i] << endl;
//             }
//         }
//         return 0;
//     }
// };
// The time complexity of this solution is O(v+e).
// The space complexity of this solution is O(v+e).

// Write a program to solve the journey to the moon problem. i.e. finding the total number of astronaut pairs that can be formed
// class solution
// {
// public:
//     void dfs(int src, vector<int> &vis, vector<int> g[], int &counter)
//     {
//         vis[src] = 1;
//         counter++;
//         for (auto x : g[src])
//         {
//             if (!vis[x])
//             {
//                 dfs(x, vis, g, counter);
//             }
//         }
//     }
//     int main()
//     {
//         int v, e;
//         cin >> v >> e;
//         vector<int> g[v];
//         for (int i = 0; i < e; i++)
//         {
//             int x, y;
//             cin >> x >> y;
//             g[x].push_back(y);
//             g[y].push_back(x);
//         }
//         vector<int> solution;
//         vector<int> vis(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             if (!vis[i])
//             {
//                 int counter = 0;
//                 dfs(i, vis, g, counter);
//                 solution.push_back(counter);
//             }
//         }
//         int val = (v * (v - 1)) / 2;
//         for (int i = 0; i < solution.size(); i++)
//         {
//             int x = (solution[i] * (solution[i] - 1)) / 2;
//             val = val - x;
//         }
//         cout << val;
//         return 0;
//     }
// };
// The time complexity  of this solution is O(v + e).
// The space complexity of this solution is O(v).

// Write a program to find the cheapest flights within k stops
// class solution
// {
// public:
//     // Illustrating the tuple class.
//     int main()
//     {
//         pair<int, int> p = {2, 2};
//         tuple<int, int, int> t = {3, 4, 5};
//         t = make_tuple(2, 3, 4);
//         cout << std::get<0>(t);
//         cout << std::get<1>(t);
//         cout << std::get<2>(t);
//     }
//     int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
//     {
//         vector<vector<pair<int, int>>> g(n);
//         for (auto x : flights)
//         {
//             g[x[0]].push_back({x[1], x[2]});
//         }
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
//         pq.push(make_tuple(0, src, 0));
//         while (!pq.empty())
//         {
//             int cost, u, stops;
//             tuple<int, int, int> top = pq.top();
//             cost = get<0>(top);
//             u = get<1>(top);
//             stops = get<2>(top);
//             // int
//             pq.pop();
//             if (u == dst)
//                 return cost;
//             if (stops > k)
//                 continue;
//             for (auto child : g[u])
//             {
//                 auto x = child;
//                 int v = get<0>(x);
//                 int w = x.second;
//                 pq.push(make_tuple(cost + w, v, stops + 1));
//             }
//         }
//         return -1;
//     }
// };

// Write a program to find the cheapest flights within k stops
// class solution
// {
// public:
//     int CheapestFlightsWithinKStops(vector<pair<pair<int, int>, int>> edges, int s, int t, int k)
//     {
//         vector<int> distance(INT_MAX);
//         vector<int> temp(INT_MAX);
//         distance[s] = 0;
//         temp[s] = 0;
//         for (int i = 0; i < k + 1; i++)
//         {
//             for (auto i : edges)
//             {
//                 int u = i.first.first;
//                 int v = i.first.second;
//                 int w = i.second;
//                 if (distance[u] == INT_MAX)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     if (distance[u] + w < temp[v])
//                     {
//                         temp[v] = distance[u] + w;
//                     }
//                 }
//             }
//             distance = temp;
//         }
//         if (distance[t] == INT_MAX)
//         {
//             return -1;
//         }
//         else
//         {
//             return distance[t];
//         }
//     }
// };

// Write a program to solve the oliver and the game problem.
// Working with the concept of euler tour
// class solution
// {
// public:
//     // we did not used the concept of visited array as it is given that the graph is a tree so we don't need visited map.
//     void dfs(vector<int> adj[], vector<pair<int, int>> &times, int timer, unordered_map<int, bool> &visited, int node, int parent)
//     {
//         times[node].first = timer++;
//         for (auto i : adj[node])
//         {
//             if (i != parent)
//             {
//                 dfs(adj, times, timer, visited, i, node);
//             }
//         }
//         times[node].second = timer++;
//     }
//     bool findOliver(vector<int> adj[], int v, int e, int ol, int bob, int direction)
//     {
//         unordered_map<int, bool> visited;
//         vector<pair<int, int>> times;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, times, 1, visited, i, -1);
//             }
//         }
//         if (direction == 0) // bob moves towards the mantion
//         {
//             if (times[ol].first < times[bob].first && times[bob].second < times[ol].second)
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         else // bob moves away from the mantion
//         {
//             if (times[bob].first < times[ol].first && times[ol].second < times[bob].second)
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
// };
// Time complexity of this solution is O(v + e).
// Space complexity of this solution is O(v).

// // Write a program to find if there is path of more than k length from a source and which does not contain any cycle.
// class solution
// {
// public:
//     bool dfs(vector<pair<int, int>> adj[], unordered_map<int, bool> &visited, int node, int length, int k)
//     {
//         visited[node] = true;
//         if (length > k)
//         {
//             return true;
//         }
//         for (auto i : adj[node])
//         {
//             if (!visited[i.first])
//             {
//                 bool ans = dfs(adj, visited, i.first, length + i.second, k);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         visited[node] = false; // backtracking
//         return false;
//     }
//     bool pathExist(vector<pair<int, int>> adj[], int v, int e, int source, int k)
//     {
//         unordered_map<int, bool> visited;
//         bool ans = dfs(adj, visited, source, 0, k);
//         return ans;
//     }
// };
// // Time complexity of this solution is O(n!).
// // Space complexity of this solution is O(v).

// Write a program to find the minimum edges to reverse to make path from a source to destination.
// This question uses the concepts of dijkstra's algorithm . So go and study it first

// Write a program to calculate the number of triangles in a graph.
// class solution
// {
// public:
//     int countTriangles(bool isDirected)
//     {
//         int v = 5;
//         int graph[][v] = {
//             {0, 1, 1, 0},
//             {1, 0, 1, 1},
//             {1, 1, 0, 1},
//             {0, 1, 1, 0}};
//         bool isDirected = false;
//         int countTriangles = false;
//         for (int i = 0; i < v; i++)
//         {
//             for (int j = 0; j < v; j++)
//             {
//                 for (int k = 0; k < v; k++)
//                 {
//                     if (graph[i][j] and graph[j][k] and graph[k][i])
//                     {
//                         countTriangles++;
//                     }
//                 }
//             }
//         }
//         if (isDirected)
//         {
//             countTriangles /= 3;
//         }
//         else
//         {
//             countTriangles /= 6;
//         }
//         return countTriangles;
//     }
// };
// Time complexity of this solution is O(v^3).
// Space complexity of this solution is O(1).

// Write a program to solve the TwoClique problem
// class solution
// {
// public:
//     int f = 0;
//     void bipartite(int src, int par, int col, vector<int> &color, vector<int> g[])
//     {
//         color[src] = col;
//         for (auto x : g[src])
//         {
//             if (!color[x])
//             {
//                 bipartite(x, src, 3 - col, color, g);
//             }
//             else if (x != par and col == color[x])
//             {
//                 f = 1;
//                 break;
//             }
//         }
//     }
//     void solve()
//     {
//         int v, e;
//         cin >> v >> e;
//         vector<int> g[v];
//         for (int i = 0; i < e; i++)
//         {
//             int x, y;
//             cin >> x >> y;
//             g[x].push_back(y);
//             g[y].push_back(x);
//         }
//         vector<int> reverse[v];
//         vector<int> dummy(v, 0);
//         for (int i = 0; i < v; i++)
//         {
//             dummy[i] = 1;
//             for (auto x : g[i])
//             {
//                 dummy[x] = 1;
//             }
//             for (int j = 0; j < v; j++)
//             {
//                 if (dummy[j] == 0)
//                 {
//                     reverse[i].push_back(j);
//                     reverse[j].push_back(i);
//                 }
//             }
//             dummy.clear();
//         }
//         vector<int> color(v, 0);
//         bipartite(0, 0, 1, color, reverse);
//         if (!f)
//             cout << "Two clique" << endl;
//         else
//             cout << "Not possible" << endl;
//     }
// };
// Space complexity : O(v).
// Time complexity : O(v^2).

// Write a program to solve the rotten oranges problem.
// int orangeRotting(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     // using bfs traversal over the grid
//     queue<tuple<int, int, int>> q; // row col time
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < m; col++)
//         {
//             if (grid[row][col] == 2)
//             {
//                 q.push(make_tuple(row, col, 0));
//                 visited[row][col] = true;
//             }
//         }
//     }
//     int time = 0;
//     while (!q.empty())
//     {
//         auto front = q.front();
//         q.pop();
//         int row = get<0>(front);
//         int col = get<1>(front);
//         int t = get<2>(front);
//         time = t;
//         // left
//         if (col - 1 >= 0 && visited[row][col - 1] == false && grid[row][col - 1] == 1)
//         {
//             visited[row][col - 1] = true;
//             // grid[row][col - 1] = 2;
//             q.push(make_tuple(row, col - 1, t + 1));
//         }
//         // up
//         if (row - 1 >= 0 && visited[row - 1][col] == false && grid[row - 1][col] == 1)
//         {
//             visited[row - 1][col] = true;
//             // grid[row - 1][col] = 2;
//             q.push(make_tuple(row - 1, col, t + 1));
//         }
//         // right
//         if (col + 1 < m && visited[row][col + 1] == false && grid[row][col + 1] == 1)
//         {
//             visited[row][col + 1] = true;
//             // grid[row][col + 1] = 2;
//             q.push(make_tuple(row, col - 1, t + 1));
//         }
//         // down
//         if (row + 1 < n && visited[row + 1][col] == false && grid[row + 1][col] == 1)
//         {
//             visited[row + 1][col] = true;
//             // grid[row + 1][col] = 2;
//             q.push(make_tuple(row + 1, col, t + 1));
//         }
//     }
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < m; col++)
//         {
//             if (grid[row][col] == 1)
//             {
//                 return -1;
//             }
//         }
//     }
//     return time;
// }
// The time and space complexity of this solution is O(n*m).

// Write a program to implement the floyd warshall algorithm.
// class solution
// {
// public:
//     void shortest_distance(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == -1)
//                 {
//                     matrix[i][j] = 1e9;
//                 }
//                 if (i == j)
//                     matrix[i][j] = 0;
//             }
//         }
//         for (int k = 0; k < n; k++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (matrix[i][i] < 0)
//             {
//                 cout << "The graph contains a negative cycle" << endl;
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == 1e9)
//                 {
//                     matrix[i][j] = -1;
//                 }
//             }
//         }
//     }
// };

// Find the town judge.
// int townJudge(int e, vector<pair<int, int>> &edges)
// {
//     unordered_map<int, vector<int>> adj;
//     for (auto i : edges)
//     {
//         int u = i.first;
//         int v = i.second;
//         adj[u].push_back(v);
//     }
//     vector<int> outdegree(adj.size(), 0);
//     vector<int> indegree(adj.size(), 0);
//     for (int i = 0; i < adj.size(); i++)
//     {
//         int count = 0;
//         for (auto x : adj[i])
//         {
//             indegree[x]++;
//             count++;
//         }
//         outdegree[i] = count;
//     }
//     for (int i = 0; i < adj.size(); i++)
//     {
//         if (outdegree[i] == 0 && indegree[i] == adj.size() - 1)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// // Write a program to solve the flood fill algorithm.
// class solution
// {
// public:
//     void dfs(int n, int m, vector<vector<int>> &image, int row, int col, int newColor, int oldColor)
//     {
//         image[row][col] = newColor;
//         // left
//         if (col - 1 >= 0 && image[row][col - 1] == oldColor)
//         {
//             dfs(n, m, image, row, col - 1, newColor, oldColor);
//         }
//         // right
//         if (col + 1 < m && image[row][col + 1] == oldColor)
//         {
//             dfs(n, m, image, row, col + 1, newColor, oldColor);
//         }
//         // up
//         if (row - 1 >= 0 && image[row - 1][col] == oldColor)
//         {
//             dfs(n, m, image, row - 1, col, newColor, oldColor);
//         }
//         // down
//         if (row + 1 >= 0 && image[row + 1][col] == oldColor)
//         {
//             dfs(n, m, image, row + 1, col, newColor, oldColor);
//         }
//     }
//     vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
//     {
//         int oldColor = image[sr][sc];
//         if (newColor == oldColor)
//         {
//             return image;
//         }
//         int n = image.size();
//         int m = image[0].size();
//         dfs(n, m, image, sr, sc, newColor, oldColor);
//         return image;
//     }
// };

// Write a program to find all the paths from source to target.
// class solution
// {
// private:
//     void dfs(vector<vector<int>> &graph, int source, int target, vector<int> &path, vector<vector<int>> &result)
//     {
//         if (source == target)
//         {
//             path.push_back(source);
//             result.push_back(path);
//             path.pop_back();
//             return;
//         }
//         path.push_back(source);
//         for (auto i : graph[source])
//         {
//             dfs(graph, i, target, path, result);
//         }
//         path.pop_back();
//     }
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
//     {
//         vector<vector<int>> result;
//         vector<int> path;
//         dfs(graph, 0, graph.size() - 1, path, result);
//         return result;
//     }
// };

// Write a program to solve the surrounded region problem.
// class solution
// {
//     void dfs(vector<vector<char>> &board, int row, int col, int n, int m)
//     {
//         board[row][col] = 'B';
//         // right
//         if (col + 1 < m && board[row][col + 1] == 'O')
//         {
//             dfs(board, row, col + 1, n, m);
//         }
//         // left
//         if (col - 1 >= 0 && board[row][col - 1] == 'O')
//         {
//             dfs(board, row, col - 1, n, m);
//         }
//         // up
//         if (row - 1 < m && board[row - 1][col] == 'O')
//         {
//             dfs(board, row - 1, col, n, m);
//         }
//         // down
//         if (row + 1 < m && board[row + 1][col] == 'O')
//         {
//             dfs(board, row + 1, col, n, m);
//         }
//     }
// public:
//     void solve(vector<vector<char>> &board)
//     {
//         int n = board.size();
//         int m = board[0].size();
//         for (int i = 0; i < n; i++)
//         {
//             int j = 0;
//             if (board[i][j] == 'O')
//             {
//                 dfs(board, i, j, n, m);
//             }
//             j = m - 1;
//             if (board[i][j] == 'O')
//             {
//                 dfs(board, i, j, n, m);
//             }
//         }
//         for (int j = 1; j < m - 1; j++)
//         {
//             int i = 0;
//             if (board[i][j] == 'O')
//             {
//                 dfs(board, i, j, n, m);
//             }
//             i = n - 1;
//             if (board[i][j] == 'O')
//             {
//                 dfs(board, i, j, n, m);
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (board[i][j] == 'B')
//                 {
//                     board[i][j] = 'O';
//                 }
//                 else if (board[i][j] == 'O')
//                 {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };

// Write a program to solve max area of island problem
// class solution
// {
//     void dfs(vector<vector<int>> &grid, int row, int col, int n, int m, int &area)
//     {
//         grid[row][col] = 0;
//         area += 1;
//         // left
//         if (col - 1 >= 0 && grid[row][col - 1] == 1)
//         {
//             dfs(grid, row, col - 1, n, m, area);
//         }
//         // right
//         if (col + 1 < m && grid[row][col + 1] == 1)
//         {
//             dfs(grid, row, col + 1, n, m, area);
//         }
//         // up
//         if (row - 1 >= 0 && grid[row - 1][col] == 1)
//         {
//             dfs(grid, row - 1, col, n, m, area);
//         }
//         // down
//         if (row + 1 < n && grid[row + 1][col] == 1)
//         {
//             dfs(grid, row + 1, col, n, m, area);
//         }
//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>> &grid)
//     {
//         int maxArea = INT_MIN;
//         int n = grid.size();
//         int m = grid[0].size();
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     int area = 0;
//                     dfs(grid, i, j, n, m, area);
//                     if (area > maxArea)
//                     {
//                         maxArea = area;
//                     }
//                 }
//             }
//         }
//         return maxArea;
//     }
// };

// Write a program to solve the rotting oranges problem.
// class solution
// {
// public:
//     int rottenOranges(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<tuple<int, int, int>> q; // row col time
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 2)
//                 {
//                     q.push(make_tuple(i, j, 0));
//                 }
//             }
//         }
//         int ansTime = 0;
//         while (!q.empty())
//         {
//             auto front = q.front();
//             q.pop();
//             int row = get<0>(front);
//             int col = get<1>(front);
//             int t = get<2>(front);
//             ansTime = t;
//             // left
//             if (col - 1 >= 0 && grid[row][col - 1] == 1)
//             {
//                 grid[row][col - 1] = 2;
//                 q.push(make_tuple(row, col - 1, t + 1));
//             }
//             // right
//             if (col + 1 < m && grid[row][col + 1] == 1)
//             {
//                 grid[row][col + 1] = 2;
//                 q.push(make_tuple(row, col + 1, t + 1));
//             }
//             // up
//             if (row - 1 >= 0 && grid[row - 1][col] == 1)
//             {
//                 grid[row - 1][col] = 2;
//                 q.push(make_tuple(row - 1, col, t + 1));
//             }
//             // down
//             if (row + 1 >= 0 && grid[row + 1][col] == 1)
//             {
//                 grid[row + 1][col] = 2;
//                 q.push(make_tuple(row + 1, col, t + 1));
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     return -1;
//                 }
//             }
//         }
//         return ansTime;
//     }
// };

// // Write a program to find the number of enclaves. uses the concept of boundary dfs
// class solution
// {
//     void dfs(vector<vector<int>> &grid, int row, int col)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         grid[row][col] = 0;
//         // left
//         if (col - 1 >= 0 && grid[row][col - 1] == 1)
//         {
//             dfs(grid, row, col - 1);
//         }
//         // right
//         if (col + 1 < m && grid[row][col + 1] == 1)
//         {
//             dfs(grid, row, col + 1);
//         }
//         // up
//         if (row - 1 >= 0 && grid[row - 1][col] == 1)
//         {
//             dfs(grid, row - 1, col);
//         }
//         // down
//         if (row + 1 < n && grid[row + 1][col] == 1)
//         {
//             dfs(grid, row + 1, col);
//         }
//     }
// public:
//     int enclaves(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         for (int i = 0; i < n; i++)
//         {
//             int j = 0;
//             if (grid[i][j] == 1)
//             {
//                 dfs(grid, i, j);
//             }
//             j = m - 1;
//             if (grid[i][j] == 1)
//             {
//                 dfs(grid, i, j);
//             }
//         }
//         for (int j = 1; j < m - 1; j++)
//         {
//             int i = 0;
//             if (grid[i][j] == 1)
//             {
//                 dfs(grid, i, j);
//             }
//             i = n - 1;
//             if (grid[i][j] == 1)
//             {
//                 dfs(grid, i, j);
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// Write a program to solve keys and rooms problem.
// class solution
// {
// public:
//     bool canVisitAllRooms(vector<vector<int>> &rooms)
//     {
//         int n = rooms.size();
//         vector<bool> visited(n, false);
//         queue<int> q;
//         visited[0] = true;
//         q.push(0);
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             for (auto i : rooms[front])
//             {
//                 if (!visited[i])
//                 {
//                     visited[i] = true;
//                     q.push(i);
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (visited[i] == false)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// // Write a program to find the total number of closed islands.
// class solution
// {
// public:
//     // 1 denotes water and 0 denotes land
//     void dfs(vector<vector<int>> &grid, int row, int col, int n, int m)
//     {
//         grid[row][col] = 1;
//         // left
//         if (col - 1 >= 0 && grid[row][col - 1] == 0)
//         {
//             dfs(grid, row, col - 1, n, m);
//         }
//         // right
//         if (col + 1 < m && grid[row][col + 1] == 0)
//         {
//             dfs(grid, row, col + 1, n, m);
//         }
//         // up
//         if (row - 1 >= 0 && grid[row - 1][col] == 0)
//         {
//             dfs(grid, row - 1, col, n, m);
//         }
//         // down
//         if (row + 1 < n && grid[row + 1][col] == 0)
//         {
//             dfs(grid, row + 1, col, n, m);
//         }
//     }
//     int closedIsland(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         // boundary dfs to remove all the boundary islands
//         for (int i = 0; i < n; i++)
//         {
//             int j = 0;
//             if (grid[i][j] == 0)
//             {
//                 dfs(grid, i, j, n, m);
//             }
//             j = m - 1;
//             if (grid[i][j] == 0)
//             {
//                 dfs(grid, i, j, n, m);
//             }
//         }
//         for (int j = 1; j < m - 1; j++)
//         {
//             int i = 0;
//             if (grid[i][j] == 0)
//             {
//                 dfs(grid, i, j, n, m);
//             }
//             i = n - 1;
//             if (grid[i][j] == 0)
//             {
//                 dfs(grid, i, j, n, m);
//             }
//         }
//         // now all the boundary islands are removed
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 0)
//                 {
//                     count++;
//                     dfs(grid, i, j, n, m);
//                 }
//             }
//         }
//         return count;
//     }
// };

// Find the time needed to inform all the employees.
// class solution
// {
//     int maxTime = 0;
//     void dfs(int node, unordered_map<int, vector<int>> &adj, int time, unordered_map<int, bool> &visited, vector<int> &informTime)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(i, adj, time + informTime[i], visited, informTime);
//             }
//         }
//         if (time > maxTime)
//         {
//             maxTime = time;
//         }
//     }
// public:
//     int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
//     {
//         unordered_map<int, vector<int>> adj;
//         for (int i = 0; i < n; i++)
//         {
//             if (manager[i] != -1)
//                 adj[manager[i]].push_back(i);
//         }
//         unordered_map<int, bool> visited;
//         dfs(headID, adj, 0, visited, informTime);
//         return maxTime;
//     }
// };

// Write a program to solve the atlantic and the pacific ocean problem.
// class solution
// {
//     void dfsDown(vector<vector<int>> &grid, vector<vector<bool>> &pacific, int row, int col, int n, int m)
//     {
//         pacific[row][col] = true;
//         int cur = grid[row][col];
//         if (row + 1 < n && grid[row + 1][col] > cur)
//         {
//             dfsDown(grid, pacific, row + 1, col, n, m);
//         }
//     }
//     void dfsUp(vector<vector<int>> &grid, vector<vector<bool>> &atlantic, int row, int col, int n, int m)
//     {
//         atlantic[row][col] = true;
//         int cur = grid[row][col];
//         if (row - 1 >= 0 && grid[row - 1][col] > cur)
//         {
//             dfsDown(grid, atlantic, row - 1, col, n, m);
//         }
//     }
//     void dfsLeft(vector<vector<int>> &grid, vector<vector<bool>> &atlantic, int row, int col, int n, int m)
//     {
//         atlantic[row][col] = true;
//         int cur = grid[row][col];
//         if (col - 1 >= 0 && grid[row][col - 1] > cur)
//         {
//             dfsDown(grid, atlantic, row, col - 1, n, m);
//         }
//     }
//     void dfsRight(vector<vector<int>> &grid, vector<vector<bool>> &pacific, int row, int col, int n, int m)
//     {
//         pacific[row][col] = true;
//         int cur = grid[row][col];
//         if (col + 1 < n && grid[row][col + 1] > cur)
//         {
//             dfsDown(grid, pacific, row, col + 1, n, m);
//         }
//     }
// public:
//     vector<pair<int, int>> pacificAndAtlantic(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> pacific;
//         vector<vector<bool>> atlantic;
//         for (int j = 0; j < m; j++)
//         {
//             int i = 0;
//             dfsDown(grid, pacific, i, j, n, m);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             int j = 0;
//             dfsRight(grid, pacific, i, j, n, m);
//         }
//         for (int j = 0; j < m; j++)
//         {
//             int i = n - 1;
//             dfsUp(grid, atlantic, i, j, n, m);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             int j = m - 1;
//             dfsLeft(grid, atlantic, i, j, n, m);
//         }
//         vector<pair<int, int>> ans;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (pacific[i][j] == true && atlantic[i][j] == true)
//                 {
//                     ans.push_back(make_pair(i, j));
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Write a program to solve the course schedule II problem. return the order in which the courses can be done . if not possible return empty vector.
// class solution
// {
//     void createAdjList(vector<pair<int, int>> &courses, unordered_map<int, vector<int>> &adj)
//     {
//         for (auto i : courses)
//         {
//             int u = i.first;
//             int v = i.second;
//             adj[v].push_back(u);
//         }
//     }
//     bool dfs(unordered_map<int, vector<int>> &adj, int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dinc, stack<int> &topo)
//     {
//         visited[node] = true;
//         dinc[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 bool ans = dfs(adj, i, visited, dinc, topo);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//             else if (dinc[node] == false)
//             {
//                 continue;
//             }
//             else if (dinc[node] == true)
//             {
//                 topo = {};
//                 return true;
//             }
//         }
//         dinc[node] = false;
//         topo.push(node);
//     }
// public:
//     vector<int> courseSchedule(vector<pair<int, int>> &courses)
//     {
//         unordered_map<int, vector<int>> adj;
//         createAdjList(courses, adj);
//         stack<int> topo;
//         unordered_map<int, bool> visited;
//         unordered_map<int, bool> dinc;
//     }
// };

// Write a program to solve the word search problem.
// class solution
// {
//     bool dfs(vector<vector<int>> &grid, string word, int i, int row, int col, int n, int m, vector<vector<bool>> &visited)
//     {
//         if (i == word.length() - 1)
//         {
//             return true;
//         }
//         // traversals
//         visited[row][col] = true;
//         // left
//         if (col - 1 >= 0 && grid[row][col - 1] == word[i + 1] && visited[row][col - 1] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row, col - 1, n, m, visited);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         // right
//         if (col + 1 < m && grid[row][col + 1] == word[i + 1] && visited[row][col + 1] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row, col + 1, n, m, visited);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         // up
//         if (row - 1 >= 0 && grid[row - 1][col] == word[i + 1] && visited[row - 1][col] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row - 1, col, n, m, visited);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         // down
//         if (row + 1 < n && grid[row + 1][col] == word[i + 1] && visited[row + 1][col] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row + 1, col, n, m, visited);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         visited[row][col] = false;
//         return false;
//     }
// public:
//     bool wordSearch(string word, vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == word[0])
//                 {
//                     bool ans = dfs(grid, word, 0, i, j, n, m, visited);
//                     if (ans == true)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

// Write a program to find the only perimeter of the island in the given grid.
// class solution
// {
//     void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int &ans, int n, int m)
//     {
//         visited[row][col] = true;
//         grid[row][col] = 0;
//         // traversals
//         // left
//         if (col - 1 >= 0 && grid[row][col] == 1)
//         {
//             dfs(grid, visited, row, col, ans, n, m);
//         }
//         else
//         {
//             if (col - 1 < 0 || visited[row][col - 1] == false)
//                 ans++;
//         }
//         // right
//         if (col + 1 < m && grid[row][col + 1] == 1)
//         {
//             dfs(grid, visited, row, col, ans, n, m);
//         }
//         else
//         {
//             if (col + 1 >= m || visited[row][col + 1] == false)
//             {
//                 ans++;
//             }
//         }
//         // up
//         if (row - 1 >= 0 && grid[row - 1][col] == 1)
//         {
//             dfs(grid, visited, row - 1, col, ans, n, m);
//         }
//         else
//         {
//             if (row - 1 < 0 || visited[row - 1][col] == false)
//             {
//                 ans++;
//             }
//         }
//         // down
//         if (row + 1 < n && grid[row + 1][col] == 1)
//         {
//             dfs(grid, visited, row + 1, col, ans, n, m);
//         }
//         else
//         {
//             if (row + 1 >= n || visited[row + 1][col] == false)
//             {
//                 ans++;
//             }
//         }
//     }
// public:
//     int perimeter(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         int perimeter = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     dfs(grid, visited, i, j, perimeter, n, m);
//                 }
//             }
//         }
//         return perimeter;
//     }
// };

// Write a program to find the only perimeter of the island in the given grid.
// class solution
// {
//     void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int &ans, int n, int m)
//     {
//         if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0)
//         {
//             ans++;
//             return;
//         }
//         if (visited[row][col] == true)
//         {
//             return;
//         }
//         visited[row][col] = true;
//         dfs(grid, visited, row, col - 1, ans, n, m);
//         dfs(grid, visited, row, col + 1, ans, n, m);
//         dfs(grid, visited, row - 1, col, ans, n, m);
//         dfs(grid, visited, row + 1, col, ans, n, m);
//     }
// public:
//     int perimeter(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         int perimeter = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 1 && visited[i][j] == false)
//                 {
//                     dfs(grid, visited, i, j, perimeter, n, m);
//                 }
//             }
//         }
//         return perimeter;
//     }
// };

// Write a program to reorder the routes to make all paths lead to the city zero.
// class solution
// {
// public:
//     int reorder(int v, int e, vector<int> adj[])
//     {
//         queue<int> q;
//         unordered_map<int, bool> visited;
//         int count = 0;
//         visited[0] = true;
//         q.push(0);
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             for (auto x : adj[front])
//             {
//                 if (visited[x] == false)
//                 {
//                     adj[x].push_back(front);
//                     count++;
//                 }
//             }
//             adj[front].clear();
//             for (int i = 0; i < v; i++)
//             {
//                 for (auto x : adj[i])
//                 {
//                     if (x == front)
//                     {
//                         visited[i] = true;
//                         q.push(i);
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };

// Write a program to reorder the routes to make all paths lead to the city zero.
// class solution
// {
//     void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int v, int &ans)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 ans++;
//                 adj[i].push_back(node);
//             }
//         }
//         adj[node].clear();
//         for (int i = 0; i < v; i++)
//         {
//             for (auto x : adj[i])
//             {
//                 if (x == node)
//                 {
//                     dfs(adj, visited, i, v, ans);
//                 }
//             }
//         }
//     }
// public:
//     int reorder(int v, int e, vector<pair<int, int>> &connectinons)
//     {
//         vector<int> adj[v];
//         for (auto i : connectinons)
//         {
//             adj[i.first].push_back(i.second);
//         }
//         unordered_map<int, bool> visited;
//         int ans;
//         dfs(adj, visited, 0, v, ans);
//         return ans;
//     }
// };

// Write a program to solve the redundant connection problem.
// class solution
// {
// public:
//     void makeSet(int n, vector<int> &parent)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             parent[i] = i;
//         }
//     }
//     int findParent(int node, vector<int> &parent)
//     {
//         if (parent[node] == node)
//         {
//             return node;
//         }
//         return parent[node] = findParent(parent[node], parent);
//     }
//     void unionSet(int u, int v, vector<int> &rank, vector<int> &parent)
//     {
//         u = findParent(u, parent);
//         v = findParent(v, parent);
//         if (rank[u] > rank[v])
//         {
//             parent[v] = u;
//         }
//         else if (rank[v] > rank[u])
//         {
//             parent[u] = v;
//         }
//         else
//         {
//             parent[v] = u;
//             rank[u]++;
//         }
//     }
//     pair<int, int> isRedundant(vector<pair<int, int>> &edges, int v, int e)
//     {
//         vector<int> parent;
//         vector<int> rank(v, 0);
//         makeSet(v, parent);
//         pair<int, int> ans = make_pair(-1, -1);
//         for (int i = 0; i < e; i++)
//         {
//             int u = edges[i].first;
//             int v = edges[i].second;
//             int pu = findParent(u, parent);
//             int pv = findParent(v, parent);
//             if (pu != pv)
//             {
//                 unionSet(u, v, rank, parent);
//             }
//             else
//             {
//                 ans = make_pair(u, v);
//             }
//         }
//         return ans;
//     }
// };

// // Write a program to check whether the graph forms a valid tree or not.
// // to  be a valid tree the graph should not have a loop and the graph should not be disconnected i.e. it should not have more than one components.
// class solution
// {
//     bool dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 bool ans = dfs(adj, visited, i, node);
//                 if (ans == true)
//                 {
//                     return true;
//                 }
//             }
//             else if (i == parent)
//             {
//                 continue;
//             }
//             else
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool isValidTree(int v, int e, vector<pair<int, int>> &edges)
//     {
//         vector<int> adj[v];
//         for (auto i : edges)
//         {
//             int u = i.first;
//             int v = i.second;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         unordered_map<int, bool> visited(false);
//         int count = 0;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 count++;
//                 bool ans = dfs(adj, visited, i, -1);
//                 if (ans == true) // if the graph contains a loop
//                 {
//                     return false;
//                 }
//             }
//         }
//         if (count > 1) // if the graph is disconnected
//         {
//             return false;
//         }
//         else
//         {
//             return true;
//         }
//     }
// };

// Write a program to find the list of words that exist in the given grid of alphabets.
// Word search II.
// class solution
// {
//     bool dfs(vector<vector<char>> &grid, string word, int i, int row, int col, vector<vector<bool>> &visited, int n, int m)
//     {
//         if (i == word.length())
//         {
//             return true;
//         }
//         visited[row][col] = true;
//         // traversals
//         // left
//         if (col - 1 >= 0 && grid[row][col - 1] == word[i + 1] && visited[row][col - 1] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row, col - 1, visited, n, m);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         // right
//         if (col + 1 < m && grid[row][col + 1] == word[i + 1] && visited[row][col + 1] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row, col + 1, visited, n, m);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         // up
//         if (row - 1 >= 0 && grid[row - 1][col] == word[i + 1] && visited[row - 1][col] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row - 1, col, visited, n, m);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         // down
//         if (row + 1 < n && grid[row + 1][col] == word[i + 1] && visited[row + 1][col] == false)
//         {
//             bool ans = dfs(grid, word, i + 1, row + 1, col, visited, n, m);
//             if (ans == true)
//             {
//                 return true;
//             }
//         }
//         visited[row][col] = false;
//         return false;
//     }
// public:
//     vector<string> wordSearch(vector<vector<char>> &grid, vector<string> words)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<string> result;
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         for (string word : words)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 bool find = false;
//                 for (int j = 0; j < m; j++)
//                 {
//                     if (grid[i][j] == word[0])
//                     {
//                         bool ans = dfs(grid, word, 0, i, j, visited, n, m);
//                         if (ans == true)
//                         {
//                             find = true;
//                             result.push_back(word);
//                         }
//                     }
//                     if (find == true)
//                     {
//                         break;
//                     }
//                 }
//                 if (find == true)
//                 {
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

// Word Search II using trie
// class solution
// {
//     class Trie
//     {
//     public:
//         char val;
//         vector<Trie *> children;
//         bool isWord;
//         Trie()
//         {
//             val = '\0';
//             children = vector<Trie *>(26, NULL);
//             isWord = false;
//         }
//         Trie(char ch)
//         {
//             val = ch;
//             children = vector<Trie *>(26, NULL);
//             isWord = false;
//         }
//         void addWord(string word)
//         {
//             if (word.length() == 0)
//             {
//                 this->isWord = true;
//             }
//             char ch = word[0];
//             if (this->children[ch - 'a'])
//             {
//                 this->children[ch - 'a']->addWord(word.substr(1));
//             }
//             else
//             {
//                 this->children[ch - 'a'] = new Trie(ch);
//                 this->children[ch - 'a']->addWord(word.substr(1));
//             }
//         }
//     };
//     void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, Trie *node, int row, int col, int n, int m, vector<string> &result, string word)
//     {
//         if (row < 0 || row >= n || col < 0 || col >= m || node->children[grid[row][col]] == NULL || visited[row][col] == true)
//         {
//             return;
//         }
//         visited[row][col] = true;
//         node = node->children[grid[row][col]];
//         word += grid[row][col];
//         if (node->isWord)
//         {
//             result.push_back(word);
//         }
//         dfs(grid, visited, node, row, col + 1, n, m, result, word);
//         dfs(grid, visited, node, row, col - 1, n, m, result, word);
//         dfs(grid, visited, node, row - 1, col, n, m, result, word);
//         dfs(grid, visited, node, row + 1, col, n, m, result, word);
//         visited[row][col] = false;
//     }
// public:
//     vector<string> findWords(vector<string> words, vector<vector<char>> &grid)
//     {
//         Trie *root = new Trie();
//         for (auto word : words)
//         {
//             root->addWord(word);
//         }
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<string> result;
//         vector<vector<bool>> visited;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 string word = "";
//                 dfs(grid, visited, root, i, j, n, m, result, word);
//             }
//         }
//         return result;
//     }
// };

// Write a program to find the number of connected components
// class solution
// {
//     void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node)
//     {
//         visited[node] = true;
//         for (auto i : adj[node])
//         {
//             if (!visited[i])
//             {
//                 dfs(adj, visited, i);
//             }
//         }
//     }
// public:
//     int connectedComponents(int v, int e, vector<pair<int, int>> &edges)
//     {
//         vector<int> adj[v];
//         for (auto i : edges)
//         {
//             int u = i.first;
//             int v = i.second;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         int count = 0;
//         unordered_map<int, bool> visited;
//         for (int i = 0; i < v; i++)
//         {
//             if (!visited[i])
//             {
//                 count++;
//                 dfs(adj, visited, i);
//             }
//         }
//         return count;
//     }
// };
// ------------------------------------------------------------
// ------------------------------------------------------------
// Using Disjoint set method
// class solution
// {
//     void makeSet(int n, vector<int> &parent)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             parent[i] = i;
//         }
//     }
//     int findParent(int node, vector<int> &parent)
//     {
//         if (node == parent[node])
//         {
//             return node;
//         }
//         return parent[node] = findParent(parent[node], parent);
//     }
//     void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
//     {
//         u = findParent(u, parent);
//         v = findParent(v, parent);
//         if (rank[u] < rank[v])
//         {
//             parent[u] = v;
//         }
//         else if (rank[v] < rank[u])
//         {
//             parent[v] = u;
//         }
//         else
//         {
//             parent[u] = v;
//             rank[v]++;
//         }
//     }
// public:
//     int connectedComponents(int v, int e, vector<pair<int, int>> &edges)
//     {
//         vector<int> parent;
//         vector<int> rank(v, 0);
//         makeSet(v, parent);
//         for (int i = 0; i < e; i++)
//         {
//             int u = edges[i].first;
//             int v = edges[i].second;
//             int pu = findParent(u, parent);
//             int pv = findParent(v, parent);
//             if (pu != pv)
//             {
//                 unionSet(u, v, parent, rank);
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < v; i++)
//         {
//             if (parent[i] == i)
//             {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// Write a program to find the minimum cost to connect all the points.
// class solution
// {
// public:
//     int minCost(vector<pair<int, int>> &points)
//     {
//         unordered_map<int, vector<pair<int, int>>> adj;
//         for (int i = 0; i < points.size() - 1; i++)
//         {
//             for (int j = i + 1; j < points.size(); j++)
//             {
//                 int dist = fabs(points[j].first - points[i].first) + fabs(points[j].second - points[i].second);
//                 adj[i].push_back(make_pair(j, dist));
//                 adj[j].push_back(make_pair(i, dist));
//             }
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//         minHeap.push(make_pair(0, 0));
//         unordered_map<int, bool> mst;
//         int minDist = 0;
//         while (!minHeap.empty())
//         {
//             auto front = minHeap.top();
//             int d = front.first;
//             int n = front.second;
//             if (mst[n] == false)
//             {
//                 mst[n] = true;
//                 minDist += d;
//             }
//             else
//             {
//                 continue;
//             }
//             for (auto i : adj[n])
//             {
//                 if (mst[i.first] == false)
//                 {
//                     minHeap.push(make_pair(i.second, i.first));
//                 }
//             }
//         }
//         return minDist;
//     }
// };

// // Write a program to count subislands
// class solution
// {
//     void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int row, int col, vector<vector<bool>> &visited, bool &ans, int n, int m)
//     {
//         visited[row][col] = true;
//         // traversals
//         // left
//         if (col - 1 >= 0 && grid2[row][col - 1] == 1 && visited[row][col - 1] == false)
//         {
//             dfs(grid1, grid2, row, col - 1, visited, ans, n, m);
//         }
//         // right
//         if (col + 1 < m && grid2[row][col + 1] == 1 && visited[row][col + 1] == false)
//         {
//             dfs(grid1, grid2, row, col + 1, visited, ans, n, m);
//         }
//         // up
//         if (row - 1 >= 0 && grid2[row - 1][col] == 1 && visited[row - 1][col] == false)
//         {
//             dfs(grid1, grid2, row - 1, col, visited, ans, n, m);
//         }
//         // down
//         if (row + 1 < n && grid2[row + 1][col] == 1 && visited[row + 1][col] == false)
//         {
//             dfs(grid1, grid2, row + 1, col, visited, ans, n, m);
//         }
//         if (grid1[row][col] == 0)
//         {
//             ans = false;
//         }
//     }
// public:
//     int subIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
//     {
//         int n = grid2.size();
//         int m = grid2[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid2[i][j] == 1 && visited[i][j] == false)
//                 {
//                     bool ans = true;
//                     dfs(grid1, grid2, i, j, visited, ans, n, m);
//                     if (ans == true)
//                     {
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };
// // The time complexity of this solution is O(n*m).

// Write a program to solve the rising water problem. Uses Dijkstra's algorithm LC : 778
// class solution
// {
// public:
//     int risingWater(vector<vector<int>> &grid, int t)
//     {
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
//         vector<vector<bool>> visited;
//         minHeap.push(make_tuple(grid[0][0], 0, 0));
//         visited[0][0] = true;
//         int n = grid.size();
//         vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
//         while (!minHeap.empty())
//         {
//             auto top = minHeap.top();
//             minHeap.pop();
//             int t = get<0>(top);
//             int r = get<1>(top);
//             int c = get<2>(top);
//             if (r == n - 1 && c == n - 1)
//             {
//                 return t;
//             }
//             // traversals
//             for (int i = 0; i < directions.size(); i++)
//             {
//                 int nr = r + directions[i].first;
//                 int nc = c + directions[i].second;
//                 if (nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == false)
//                 {
//                     visited[nr][nc] = true;
//                     minHeap.push(make_tuple(max(t, grid[nr][nc]), nr, nc));
//                 }
//             }
//         }
//     }
// };

// Write a program to solve the rising water problem. Uses Dijkstra's algorithm LC : 778
// class solution
// {
// public:
//     int risingWater(vector<vector<int>> &grid, int t)
//     {
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
//         vector<vector<bool>> visited;
//         minHeap.push(make_tuple(grid[0][0], 0, 0));
//         visited[0][0] = true;
//         int n = grid.size();
//         vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
//         while (!minHeap.empty())
//         {
//             auto top = minHeap.top();
//             minHeap.pop();
//             int t = get<0>(top);
//             int r = get<1>(top);
//             int c = get<2>(top);
//             if (r == n - 1 && c == n - 1)
//             {
//                 return t;
//             }
//             // traversals
//             for (int i = 0; i < directions.size(); i++)
//             {
//                 int nr = r + directions[i].first;
//                 int nc = c + directions[i].second;
//                 if (nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == false)
//                 {
//                     visited[nr][nc] = true;
//                     minHeap.push(make_tuple(max(t, grid[nr][nc]), nr, nc));
//                 }
//             }
//         }
//     }
// };
// Write a program to solve the walls and the gates problem. Uses BFS. LC : 286
// class solution
// {
// public:
//     void wallsAndGates(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         queue<tuple<int, int, int>> q;
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == 0)
//                 {
//                     visited[i][j] = true;
//                     q.push(make_tuple(i, j, 0));
//                 }
//             }
//         }
//         vector<pair<int, int>> directions = {{0, -1},
//                                              {0, 1},
//                                              {-1, 0},
//                                              {1, 0}};
//         while (!q.empty())
//         {
//             auto front = q.front();
//             q.pop();
//             int r = get<0>(front);
//             int c = get<1>(front);
//             int s = get<2>(front);
//             for (int i = 0; i < directions.size(); i++)
//             {
//                 int nr = r + directions[i].first;
//                 int nc = c + directions[i].second;
//                 if (nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == false && grid[nr][nc] != -1)
//                 {
//                     visited[nr][nc] = true;
//                     grid[nr][nc] = s + 1;
//                     q.push(make_tuple(nr, nc, s + 1));
//                 }
//             }
//         }
//     }
// };

// Write a program to solve the surrounded regions problem. // using boundary dfs concept.
// class solution
// {
//     void dfs(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited, int n, int m)
//     {
//         grid[row][col] = 'T';
//         visited[row][col] = true;
//         vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
//         // traversals
//         for (int i = 0; i < directions.size(); i++)
//         {
//             int nr = row + directions[i].first;
//             int nc = col + directions[i].second;
//             if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] == false && grid[nr][nc] == 'O')
//             {
//                 dfs(grid, nr, nc, visited, n, m);
//             }
//         }
//     }
// public:
//     void captureSurroundedRegions(vector<vector<char>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited;
//         for (int i = 0; i < n; i++)
//         {
//             int j = 0;
//             if (grid[i][j] == 'O' && visited[i][j] == false)
//             {
//                 dfs(grid, i, j, visited, n, m);
//             }
//             int j = m - 1;
//             if (grid[i][j] == 'O' && visited[i][j] == false)
//             {
//                 dfs(grid, i, j, visited, n, m);
//             }
//         }
//         for (int j = 0; j < m; j++)
//         {
//             int i = 0;
//             if (grid[i][j] == 'O' && visited[i][j] == false)
//             {
//                 dfs(grid, i, j, visited, n, m);
//             }
//             int i = n - 1;
//             if (grid[i][j] == 'O' && visited[i][j] == false)
//             {
//                 dfs(grid, i, j, visited, n, m);
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == 'O')
//                 {
//                     grid[i][j] = 'X';
//                 }
//                 if (grid[i][j] == 'T')
//                 {
//                     grid[i][j] = 'O';
//                 }
//             }
//         }
//     }
// };

// Write a program to reconstruct an itinerary : Leet code 332.
// class solution
// {
//     bool dfs(vector<string> &res, vector<pair<string, string>> &tickets, string source, unordered_map<string, vector<string>> &adj)
//     {
//         if (res.size() == tickets.size() + 1)
//         {
//             return true;
//         }
//         if (adj.find(source) == adj.end())
//         {
//             return false;
//         }
//         vector<string> temp = adj[source];
//         vector<string>::iterator it = adj[source].begin();
//         for (int i = 0; i < temp.size(); i++)
//         {
//             adj[source].erase(it + i);
//             res.push_back(temp[i]);
//             if (dfs(res, tickets, temp[i], adj))
//             {
//                 return true;
//             }
//             adj[source].insert(it + i, temp[i]);
//             res.pop_back();
//         }
//         return false;
//     }
// public:
//     vector<string> findItinerary(vector<pair<string, string>> &tickets)
//     {
//         unordered_map<string, vector<string>> adj;
//         for (auto i : tickets)
//         {
//             adj[i.first].push_back(i.second);
//         }
//         for (auto i : adj)
//         {
//             sort(i.second.begin(), i.second.end());
//         }
//         vector<string> result;
//         result.push_back("JFK");
//         dfs(result, tickets, "JFK", adj);
//         return result;
//     }
// };

// Write a program to find the longest path in a matrix:
// class solution
// {
//     int dfs(vector<vector<int>> &grid, vector<vector<int>> &lip, int row, int col, int prevVal)
//     {
//         if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] <= prevVal)
//         {
//             return 0;
//         }
//         if (lip[row][col] != -1)
//         {
//             return lip[row][col];
//         }
//         int length = 1;
//         length = max(length, dfs(grid, lip, row, col - 1, grid[row][col]) + 1);
//         length = max(length, dfs(grid, lip, row, col + 1, grid[row][col]) + 1);
//         length = max(length, dfs(grid, lip, row - 1, col, grid[row][col]) + 1);
//         length = max(length, dfs(grid, lip, row + 1, col, grid[row][col]) + 1);
//         lip[row][col] = length;
//         return length;
//     }
// public:
//     int longestPath(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> LIP(n, vector<int>(m, -1));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 dfs(grid, LIP, i, j, -1);
//             }
//         }
//         int maxi = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 maxi = max(maxi, LIP[i][j]);
//             }
//         }
//         return maxi;
//     }
// };

int main()
{
    // Implementing graphs adjacency list way
    // int v, e;
    // cin >> v >> e;
    // vector<int> g[v + 1];
    // for (int i = 0; i < e; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     g[x].push_back(y);
    //     g[y].push_back(x);
    // }
    // for (int i = 1; i <= v; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // Time complexity of this solution is O(v+e).
    // Implementing graphs adjacency matrix way
    // int v, e;
    // cin >> v >> e;
    // int g[v + 1][v + 1];
    // for (int i = 1; i <= v; i++)
    // {
    //     for (int j = 1; j <= v; j++)
    //         g[i][j] = 0;
    // }
    // for (int i = 0; i < e; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     g[x][y] = 1;
    //     g[y][x] = 1;
    // }
    // for (int i = 1; i <= v; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 1; j <= v; j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    // }
    // // Time complexity of this solution is O(v*v).
    return 0;
}