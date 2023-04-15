// today we are going to study about Backtracking

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Write a program to solve rat in a maze problem

bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if (x < 0 || y < 0 || visited[x][y] == true || arr[x][y] == 0 || x >= n || y >= n)
    {
        return false;
    }
    return true;
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> ans, vector<vector<bool>> &visited, string path)
{
    if (x == n - 1 and y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movements
    visited[x][y] = 1;
    if (isSafe(x + 1, y, visited, arr, n))
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }
    if (isSafe(x, y - 1, visited, arr, n))
    {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }
    if (isSafe(x, y + 1, visited, arr, n))
    {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }
    if (isSafe(x - 1, y, visited, arr, n))
    {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }
    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
        return ans;
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

// The time complexity to solve this problem is O(4^(n*n)).
// The space complexity to solve this problem is O(n*m)

int main()
{
    return 0;
}