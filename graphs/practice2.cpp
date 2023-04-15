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
// #include <bits/stdc++.h>
using namespace std;

class solution
{
    bool dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dinc, int node)
    {
        visited[node] = true;
        dinc[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, visited, dinc, i);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (dinc[i] == false)
            {
                continue;
            }
            else
            {
                return true;
            }
        }

        dinc[node] = false;
        return false;
    }

public:
    bool isPossible(vector<pair<int, int>> &courses)
    {
        unordered_map<int, vector<int>> adj;

        for (auto i : courses)
        {
            int u = i.first;
            int v = i.second;

            adj[v].push_back(u);
        }

        int v = adj.size();

        // check if it contains a cycle or not
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dinc;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, visited, dinc, i);
                if (ans)
                    return false;
            }
        }

        return true;
    }
};

class solution
{
    bool dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dinc, int node, stack<int> &st)
    {
        visited[node] = true;
        dinc[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, visited, dinc, i, st);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (dinc[i] == false)
            {
                continue;
            }
            else if (dinc[i] == true)
            {
                st = {};
                return true;
            }
        }

        st.push(node);
        return false;
    }

public:
    vector<int> courseSchedule(vector<pair<int, int>> &courses)
    {
        unordered_map<int, vector<int>> adj;
        for (auto i : courses)
        {
            int u = i.first;
            int v = i.second;

            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dinc;
        stack<int> st;
        vector<int> result;
        int v = adj.size();

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, visited, dinc, i, st);
                if (ans == true)
                {
                    return result;
                }
            }
        }

        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

class solution
{
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int n, int m)
    {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || visited[row][col] == true)
        {
            return;
        }

        visited[row][col] = true;

        // left
        dfs(grid, visited, row, col - 1, n, m);

        // right
        dfs(grid, visited, row, col + 1, n, m);

        // up
        dfs(grid, visited, row - 1, col, n, m);

        // down
        dfs(grid, visited, row + 1, col, n, m);
    }

    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int n, int m)
    {
        queue<pair<int, int>> q;
        visited[row][col] = true;
        q.push(make_pair(row, col));

        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;

            for (int i = 0; i < directions.size(); i++)
            {
                int nr = r + directions[i].first;
                int nc = c + directions[i].second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && visited[nr][nc] == false)
                {
                    visited[nr][nc] = true;
                    q.push(make_pair(nr, nc));
                }
            }
        }
    }

public:
    int islands(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    count++;
                    dfs(grid, visited, i, j, n, m);
                }
            }
        }

        return count;
    }
};

// Write a program to clone a grapb
class solution
{
    class Node
    {
    public:
        int val;
        vector<Node *> neighbors;

        Node(int val)
        {
            this->val = val;
            this->neighbors = vector<Node *>();
        }
        Node(int val, vector<Node *> &neighbors)
        {
            this->val = val;
            this->neighbors = vector<Node *>(neighbors);
        }
    };

    void dfs(Node *node, Node *clone, unordered_map<int, Node *> visited)
    {
        visited[node->val] = clone;

        for (auto i : node->neighbors)
        {
            if (visited[i->val] == NULL)
            {
                Node *temp = new Node(i->val);
                clone->neighbors.push_back(temp);
                dfs(i, temp, visited);
            }
            else
            {
                clone->neighbors.push_back(visited[i->val]);
            }
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        Node *clone = new Node(node->val);
        unordered_map<int, Node *> visited;
        dfs(node, clone, visited);
        return clone;
    }
};

class solution
{
    class Node
    {
    public:
        int val;
        vector<Node *> neighbors;

        Node()
        {
            this->val = 0;
            this->neighbors = vector<Node *>();
        }
        Node(int _val)
        {
            this->val = _val;
            this->neighbors = vector<Node *>();
        }
        Node(int _val, vector<Node *> _neighbors)
        {
            this->val = _val;
            // this->neighbors = _neighbors;
            this->neighbors = vector<Node *>(_neighbors);
        }
    };

    void dfs(Node *node, Node *clone, unordered_map<int, Node *> visited)
    {
        visited[node->val] = clone;

        for (auto i : node->neighbors)
        {
            if (visited[i->val] == NULL)
            {
                Node *temp = new Node(i->val);
                clone->neighbors.push_back(temp);
                dfs(i, temp, visited);
            }
            else
            {
                clone->neighbors.push_back(visited[i->val]);
            }
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        Node *clone = new Node(node->val);
        unordered_map<int, Node *> visited;
        dfs(node, clone, visited);
        return clone;
    }
};

// Write a program to solve the word ladder problem.
class solution
{
public:
    int wordLadder(string start, string end, vector<string> &list)
    {
        unordered_set<string> wlist;

        for (auto i : list)
        {
            wlist.insert(i);
        }

        if (wlist.find(end) == wlist.end())
        {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push(make_pair(start, 0));
        wlist.erase(start);

        while (!q.empty())
        {
            auto front = q.front();
            string str = front.first;
            int steps = front.second;

            if (str == end)
            {
                return steps;
            }

            for (int i = 0; i < str.length(); i++)
            {
                char o = str[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    str[i] = ch;
                    if (wlist.find(str) == wlist.end())
                    {
                        continue;
                    }

                    if (str == end)
                    {
                        return steps + 1;
                    }

                    wlist.erase(str);
                    q.push(make_pair(str, steps + 1));
                }
                str[i] = o;
            }
        }

        return 0;
    }
};

// Write a program to solve the pacific atlantic water flow problem.
class solution
{
    // pacific
    void downDfs(vector<vector<int>> &grid, vector<vector<bool>> &pacific, int row, int col)
    {
        pacific[row][col] = true;

        if (row + 1 < grid.size() && grid[row + 1][col] >= grid[row][col])
        {
            downDfs(grid, pacific, row + 1, col);
        }
    }

    void rightDfs(vector<vector<int>> &grid, vector<vector<bool>> &pacific, int row, int col)
    {
        pacific[row][col] = true;

        if (col + 1 < grid[0].size() && grid[row][col + 1] >= grid[row][col])
        {
            downDfs(grid, pacific, row, col + 1);
        }
    }

    // atlantic
    void upDfs(vector<vector<int>> &grid, vector<vector<bool>> &atlantic, int row, int col)
    {
        atlantic[row][col] = true;

        if (row - 1 >= 0 && grid[row - 1][col] >= grid[row][col])
        {
            downDfs(grid, atlantic, row - 1, col);
        }
    }

    void leftDfs(vector<vector<int>> &grid, vector<vector<bool>> &atlantic, int row, int col)
    {
        atlantic[row][col] = true;

        if (col - 1 >= 0 && grid[row][col - 1] >= grid[row][col])
        {
            downDfs(grid, atlantic, row, col - 1);
        }
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> pacific;
        vector<vector<bool>> atlantic;

        for (int j = 0; j < m; j++)
        {
            int i = 0;
            downDfs(grid, pacific, i, j);
        }

        for (int i = 0; i < n; i++)
        {
            int j = 0;
            rightDfs(grid, pacific, i, j);
        }

        for (int i = 0; i < n; i++)
        {
            int j = m - 1;
            leftDfs(grid, atlantic, i, j);
        }

        for (int j = 0; j < m; j++)
        {
            int i = n - 1;
            upDfs(grid, atlantic, i, j);
        }

        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacific[i][j] == true && atlantic[i][j] == true)
                {
                    ans.push_back(make_pair(i, j));
                }
            }
        }

        return ans;
    }
};

// Write a program to solve the network delay time problem.
class solution
{
    int bfs(vector<pair<int, int>> adj[], unordered_map<int, int> &dist, int node)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, node));
        int mintime = 0;
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int d = front.first;
            int n = front.second;

            for (auto i : adj[n])
            {
                if (i.second + d < dist[i.first])
                {
                    dist[i.first] = i.second + d;
                    pq.push(make_pair(i.first + d, i.first));
                }
            }
        }

        int maxT = 0;
        for (auto i : dist)
        {
            if (i.second == INT_MAX)
            {
                return -1;
            }
            maxT = max(maxT, i.first);
        }

        return maxT;
    }

public:
    void networkDelayTime(int n, int k)
    {
    }
};

// Write a program to solve the word search problem.
class solution
{
    bool dfs(vector<vector<char>> &grid, string word, int row, int col, vector<vector<bool>> &visited, int n, int m)
    {
        if (word.length() == 1)
        {
            return true;
        }

        visited[row][col] = true;

        // traversals
        // left
        if (col - 1 >= 0 && grid[row][col - 1] == word[1] && visited[row][col - 1] == false)
        {
            bool ans = dfs(grid, word.substr(1), row, col - 1, visited, n, m);
            if (ans == true)
            {
                return true;
            }
        }

        // right
        if (col + 1 < m && grid[row][col + 1] == word[1] && visited[row][col + 1] == false)
        {
            bool ans = dfs(grid, word.substr(1), row, col + 1, visited, n, m);
            if (ans == true)
            {
                return true;
            }
        }

        // up
        if (row - 1 < m && grid[row - 1][col] == word[1] && visited[row - 1][col] == false)
        {
            bool ans = dfs(grid, word.substr(1), row - 1, col, visited, n, m);
            if (ans == true)
            {
                return true;
            }
        }

        // down
        if (row + 1 < m && grid[row + 1][col] == word[1] && visited[row + 1][col] == false)
        {
            bool ans = dfs(grid, word.substr(1), row + 1, col, visited, n, m);
            if (ans == true)
            {
                return true;
            }
        }

        visited[row][col] = false;
    }

public:
    bool wordSearch(vector<vector<char>> &grid, string word)
    {
        vector<vector<bool>> visited;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == word[0])
                {
                    bool ans = dfs(grid, word, i, j, visited, n, m);
                    if (ans == true)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

class solution
{
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int n, int m, int &ans)
    {
        visited[row][col] = true;

        // traversals
        // left
        if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == false)
        {
            dfs(grid, visited, row, col - 1, n, m, ans);
        }
        else
        {
            if (col - 1 < 0 || grid[row][col - 1] == 0)
            {
                ans++;
            }
        }

        // right
        if (col + 1 < m && grid[row][col + 1] == 1 && visited[row][col + 1] == false)
        {
            dfs(grid, visited, row, col + 1, n, m, ans);
        }
        else
        {
            if (col + 1 < m || grid[row][col + 1] == 0)
            {
                ans++;
            }
        }

        // up
        if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == false)
        {
            dfs(grid, visited, row - 1, col, n, m, ans);
        }
        else
        {
            if (row - 1 >= 0 || grid[row - 1][col] == 0)
            {
                ans++;
            }
        }

        // down
        if (row + 1 < n && grid[row + 1][col] == 1 && visited[row + 1][col] == false)
        {
            dfs(grid, visited, row + 1, col, n, m, ans);
        }
        else
        {
            if (row + 1 < n || grid[row + 1][col] == 0)
            {
                ans++;
            }
        }
    }

public:
    int perimeter(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited;
        int n = grid.size();
        int m = grid[0].size();

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    int ans = 0;
                    dfs(grid, visited, i, j, n, m, ans);
                    result += ans;
                }
            }
        }

        return result;
    }
};

class solution
{
public:
    int reorder(int v, int e, vector<pair<int, int>> &connectinons)
    {
        unordered_map<int, vector<int>> adj;
        for (auto i : connectinons)
        {
            adj[i.first].push_back(i.second);
        }

        // using BFS
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {
                if (!visited[i])

                {
                    adj[i].push_back(front);
                    count++;
                }
            }

            adj[front].clear();

            for (int i = 0; i < v; i++)
            {
                for (auto x : adj[i])
                {
                    if (x == front)
                    {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        return count;
    }
};

class solution
{
    void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int v, int &ans)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                ans++;
                adj[i].push_back(node);
            }
        }
        adj[node].clear();

        for (int i = 0; i < v; i++)
        {
            for (auto x : adj[i])
            {
                if (x == node)
                {
                    dfs(adj, visited, i, v, ans);
                }
            }
        }
    }

public:
    int reorder(int v, int e, vector<pair<int, int>> &connectinons)
    {
        vector<int> adj[v];
        for (auto i : connectinons)
        {
            adj[i.first].push_back(i.second);
        }
        unordered_map<int, bool> visited;
        int ans;
        dfs(adj, visited, 0, v, ans);
        return ans;
    }
};

class solution
{
    void makeSet(int n, vector<int> &parent)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node, vector<int> &parent)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else if (rank[v] > rank[u])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    pair<int, int> redundantEdge(vector<pair<int, int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto i : edges)
        {
            adj[i.first].push_back(i.second);
        }

        int v = adj.size();

        vector<int> parent;
        makeSet(v, parent);
        vector<int> rank(v, 0);
        pair<int, int> result;

        for (auto i : edges)
        {
            int u = i.first;
            int v = i.second;

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu != pv)
            {
                unionSet(u, v, parent, rank);
            }
            else
            {
                result.first = u;
                result.second = v;
            }
        }

        return result;
    }
};

class solution
{
    bool dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, int node, int parent)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, visited, i, node);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (i == parent)
            {
                continue;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

public:
    bool isValidTree(int v, int e, vector<pair<int, int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto i : edges)
        {
            int u = i.first;
            int v = i.second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                count++;
                bool ans = dfs(adj, visited, i, -1);
                if (ans == true)
                {
                    return false;
                }
            }
        }

        if (count <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Write a program to solve the word search II problem.
class solution
{
    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, string word, int row, int col)
    {
        if (word.length() == 1)
        {
            return true;
        }

        visited[row][col] = true;
        int n = grid.size();
        int m = grid[0].size();

        // traversals
        // left
        if (col - 1 >= 0 && grid[row][col - 1] == word[1] && visited[row][col - 1] == false)
        {
            bool ans = dfs(grid, visited, word.substr(1), row, col - 1);
            if (ans == true)
            {
                return true;
            }
        }

        // right
        if (col + 1 < m && grid[row][col + 1] == word[1] && visited[row][col + 1] == false)
        {
            bool ans = dfs(grid, visited, word.substr(1), row, col + 1);
            if (ans == true)
            {
                return true;
            }
        }

        // up
        if (row - 1 >= 0 && grid[row - 1][col] == word[1] && visited[row - 1][col] == false)
        {
            bool ans = dfs(grid, visited, word.substr(1), row - 1, col);
            if (ans == true)
            {
                return true;
            }
        }

        // down
        if (row + 1 >= 0 && grid[row + 1][col] == word[1] && visited[row + 1][col] == false)
        {
            bool ans = dfs(grid, visited, word.substr(1), row + 1, col);
            if (ans == true)
            {
                return true;
            }
        }

        visited[row][col] = false;
    }

public:
    vector<string> wordSearch(vector<vector<char>> &grid, vector<string> words)
    {
        vector<vector<bool>> visited;
        int n = grid.size();
        int m = grid[0].size();
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            bool found = false;
            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < m; col++)
                {
                    if (grid[row][col] == word[0])
                    {
                        bool ans = dfs(grid, visited, word, row, col);
                        if (ans == true)
                        {
                            found = true;
                            result.push_back(word);
                        }
                    }

                    if (found == true)
                    {
                        break;
                    }
                }

                if (found == true)
                {
                    break;
                }
            }
        }

        return result;
    }
};

class solution
{
    class Trie
    {
    public:
        char val;
        vector<Trie *> children;
        bool isWord;
        Trie()
        {
            val = 0;
            children = vector<Trie *>(26, NULL);
            isWord = false;
        }
        Trie(char ch)
        {
            val = ch;
            children = vector<Trie *>(26, NULL);
            isWord = false;
        }

        void addWord(string word)
        {
            if (word.length() == 0)
            {
                this->isWord = true;
            }
            char x = word[0];
            int index = x - 'a';

            if (this->children[index] == NULL)
            {
                Trie *temp = new Trie(x);
                this->children[index] = temp;
                this->children[index]->addWord(word.substr(1));
            }
            else
            {
                this->children[index]->addWord(word.substr(1));
            }
        }
    };

    void dfs(vector<vector<char>> &grid, Trie *root, int row, int col, vector<vector<bool>> &visited, string word, vector<string> &result)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] == true)
        {
            return;
        }

        if (root->children[grid[row][col] - 'a'] == NULL)
        {
            return;
        }

        visited[row][col] = true;
        root = root->children[grid[row][col] - 'a'];
        word += grid[row][col];

        if (root->isWord)
        {
            result.push_back(word);
        }

        dfs(grid, root, row, col - 1, visited, word, result);
        dfs(grid, root, row, col + 1, visited, word, result);
        dfs(grid, root, row - 1, col, visited, word, result);
        dfs(grid, root, row + 1, col, visited, word, result);
        visited[row][col] = false;
    }

public:
    vector<string> wordSearch(vector<vector<char>> &grid, vector<string> words)
    {
        Trie *root = new Trie('\0');

        for (auto i : words)
        {
            root->addWord(i);
        }

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited;
        vector<string> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                string word = "";
                dfs(grid, root, i, j, visited, word, result);
            }
        }

        return result;
    }
};

class solution
{
    bool dfs(unordered_map<char, vector<char>> &adj, char node, unordered_map<char, bool> &visited, unordered_map<char, bool> &dinc, stack<char> &st)
    {
        visited[node] = true;
        dinc[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, i, visited, dinc, st);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (dinc[i] == false)
            {
                continue;
            }
            else if (dinc[i] == true)
            {
                st = {};
                return true;
            }
        }

        st.push(node);
        dinc[node] = false;
        return false;
    }

public:
    string alienDictionary(vector<string> words)
    {
        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i];
            string w2 = words[i + 1];
            int j;
            for (j = 0; j < min(w1.length(), w2.length()); j++)
            {
                if (w1[j] != w2[j])
                {
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
            if (j == min(w1.length(), w2.length()))
            {
                if (w1.length() > w2.length())
                {
                    return "";
                }
            }
        }

        // Now we need the topological sort
        unordered_map<char, bool> visited;
        unordered_map<char, bool> dinc;
        stack<char> st;
        int v = adj.size();

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool ans = dfs(adj, i, visited, dinc, st);
                if (ans == true)
                {
                    return "";
                }
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

class solution
{
public:
    int primsAlgorithm(vector<pair<int, int>> &points)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        int v = points.size();
        for (int i = 0; i < points.size() - 1; i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int d = fabs(points[j].first - points[i].first) + fabs(points[j].second - points[i].second);
                adj[i].push_back(make_pair(j, d));
                adj[j].push_back(make_pair(i, d));
            }
        }

        // prims algorithm.
        int minDist = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push(make_pair(0, 0));
        unordered_map<int, bool> mst;

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int d = top.first;
            int n = top.second;

            if (mst[n] == true)
            {
                continue;
            }
            mst[n] = true;
            minDist += d;

            for (auto i : adj[n])
            {
                if (!mst[i.first])
                {
                    minHeap.push(make_pair(i.second, i.first));
                }
            }
        }

        return minDist;
    }
};

class solution
{
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited, int row, int col, bool &ans, int n, int m)
    {
        if (row < 0 || row >= n || col < 0 || col >= m || grid2[row][col] == 0 || visited[row][col] == true)
        {
            return;
        }

        visited[row][col] = true;
        dfs(grid1, grid2, visited, row, col - 1, ans, n, m);
        dfs(grid1, grid2, visited, row, col + 1, ans, n, m);
        dfs(grid1, grid2, visited, row - 1, col, ans, n, m);
        dfs(grid1, grid2, visited, row + 1, col, ans, n, m);

        if (grid1[row][col] == 0)
        {
            ans = false;
        }
    }

public:
    int countSubislands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int n = grid2.size();
        int m = grid2[0].size();

        vector<vector<bool>> visited;
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] == 1 && visited[i][j] == false)
                {
                    bool ans = true;
                    dfs(grid1, grid2, visited, i, j, ans, n, m);
                    if (ans == true)
                    {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};

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

class solution
{
public:
    int CheapestFlightsWithinKStops(vector<pair<pair<int, int>, int>> edges, int s, int t, int k)
    {
        vector<int> distance(INT_MAX);
        vector<int> temp(INT_MAX);

        distance[s] = 0;
        temp[s] = 0;

        for (int i = 0; i < k + 1; i++)
        {
            for (auto i : edges)
            {
                int u = i.first.first;
                int v = i.first.second;
                int w = i.second;

                if (distance[u] == INT_MAX)
                {
                    continue;
                }
                else
                {
                    if (distance[u] + w < temp[v])
                    {
                        temp[v] = distance[u] + w;
                    }
                }
            }

            distance = temp;
        }

        if (distance[t] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return distance[t];
        }
    }
};

// Write a program to reconstruct an itinerary : Leet code 332.
class solution
{
    bool dfs(vector<string> &res, vector<pair<string, string>> &tickets, string source, unordered_map<string, vector<string>> &adj)
    {
        if (res.size() == tickets.size() + 1)
        {
            return true;
        }
        if (adj.find(source) == adj.end())
        {
            return false;
        }

        vector<string> temp = adj[source];
        vector<string>::iterator it = adj[source].begin();
        for (int i = 0; i < temp.size(); i++)
        {
            adj[source].erase(it + i);
            res.push_back(temp[i]);

            if (dfs(res, tickets, temp[i], adj))
            {
                return true;
            }

            adj[source].insert(it + i, temp[i]);
            res.pop_back();
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<pair<string, string>> &tickets)
    {
        unordered_map<string, vector<string>> adj;

        for (auto i : tickets)
        {
            adj[i.first].push_back(i.second);
        }

        for (auto i : adj)
        {
            sort(i.second.begin(), i.second.end());
        }

        vector<string> result;
        result.push_back("JFK");
        dfs(result, tickets, "JFK", adj);
        return result;
    }
};

// Write a program to solve the rotten orange problem. Multisource BFS
class solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        int count1 = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(make_pair(i, j), 0));
                }
                if (grid[i][j] == 1)
                {
                    count1++;
                }
            }
        }

        int time = 0;

        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;
            time = t;

            // traversals
            for (int i = 0; i < directions.size(); i++)
            {
                int nr = r + directions[i].first;
                int nc = c + directions[i].second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                {
                    count1--;
                    grid[nr][nc] = 2;
                    q.push(make_pair(make_pair(nr, nc), t + 1));
                }
            }
        }

        if (count1 > 0)
        {
            return -1;
        }
        else
        {
            return time;
        }
    }
};

// Write a program to find the longest path in a matrix:
class solution
{
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &lip, int row, int col, int prevVal)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] <= prevVal)
        {
            return 0;
        }

        if (lip[row][col] != -1)
        {
            return lip[row][col];
        }

        int length = 1;
        length = max(length, dfs(grid, lip, row, col - 1, grid[row][col]) + 1);
        length = max(length, dfs(grid, lip, row, col + 1, grid[row][col]) + 1);
        length = max(length, dfs(grid, lip, row - 1, col, grid[row][col]) + 1);
        length = max(length, dfs(grid, lip, row + 1, col, grid[row][col]) + 1);

        lip[row][col] = length;
        return length;
    }

public:
    int longestPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> LIP(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(grid, LIP, i, j, -1);
            }
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxi = max(maxi, LIP[i][j]);
            }
        }

        return maxi;
    }
};

int main()
{

    return 0;
}
// DFS : O(n) where n is the number of vertices. Recursively : Hashset , iteratively : += stacks
// BFS : O(n) where n is the number of vertices. Iteratively : Queue, Hashset.
// Union Find : O(nlogn). Data structure : Forest of trees. Disjoint.
// Topological Sort : O(n). Uses BFS or DFS. Hashset.
// Dijkstra's Shortest path algorithm : O(Elogv) . Priority queue (minHeap) or queue or set(ordered set).
// Prim's or kruskal's algorithm
// Floyd Warshall's algorithm.