// backtracking day 2
// solving the n-queen problem
#include <iostream>
#include <vector>

using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // checking for diagonal
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    while (x < n and y >= n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

// void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
// {
//     if (col == n)
//     {
//         addSolution(board, ans, n);
//         return;
//     }
//     else
//     {
//         for (int row = 0; row < n; row++)
//         {
//             if (isSafe(row, col, board, n))
//             {
//                 // if placing queen is safe
//                 board[row][col] = 1;
//                 solve(col + 1, ans, board, n);
//                 // backtrack
//                 board[row][col] = 0;
//             }
//         }
//     }
// }

// // vector<vector<int>> nQueens(int n)
// {
//     vector<vector<int>> board(n, vector<int>(n, 0));
//     vector<vector<int>> ans;

//     solve(0, ans, board, n);
//     return ans;
// }

// The time complexity to solve this question is O(n!)
// The space complexity to solve this question is O(n*n)

// even if you use a map to solve this problem the time complexity will still be O(n).

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(ans, board, n);
    }

    else
    {
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 1;
                solve(col + 1, ans, board, n);
                board[row][col] = 0;
            }
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}
// the time complexity of solving this problem is O(n!). why?

int main()
{
    return 0;
}