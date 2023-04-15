#include <iostream>
#include <vector>

using namespace std;

// bool isSafe(int row, int col, vector<vector<int>> &board, int value, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (board[row][i] == value)
//         {
//             return false;
//         }
//         if (board[i][col] == value)
//         {
//             return false;
//         }

//         if (board[3 * (row / 3) + i / 3][3 * (col / 3) * i % 3] == value)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// bool solve(vector<vector<int>> &board)
// {
//     int n = board[0].size();
//
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n; col++)
//         {
//             // cell empty
//             if (board[row][col] == 0)
//             {
//                 for (int val = 1; val <= 9; val++)
//                 {
//                     if (isSafe(row, col, board, val, n))
//                     {
//                         board[row][col] = val;
//
//                         // recursive call
//                         bool aageSolutionPossible = solve(board);
//                         if (aageSolutionPossible)
//                         {
//                             return true;
//                         }
//                         else
//                         {
//                             // backtrack
//                             board[row][col] = 0;
//                         }
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void solveSudoku(vector<vector<int>> &sudoku)
// {
//     solve(sudoku);
// }

// Write a program to solve sudoku

// bool isSafe(int row, int col, vector<vector<int>> &board, int val, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (board[row][i] == val)
//         {
//             return false;
//         }
//         if (board[i][col] == val)
//         {
//             return false;
//         }
//         if (board[3 * (row / 3) + i / 3][3 * (col / 3) * i % 3] == val)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// bool solve(vector<vector<int>> &board)
// {
//     int n = board[0].size();
//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < n; col++)
//         {
//             // case if empty
//             if (board[row][col] == 0)
//             {
//                 for (int val = 1; val <= 9; val++)
//                 {
//                     if (isSafe(row, col, board, val, n))
//                     {
//                         board[row][col] = val;
//                         bool ageWalaSafe = solve(board);

//                         if (ageWalaSafe)
//                         {
//                             return true;
//                         }
//                         else
//                         {
//                             // backtrack
//                             board[row][col] = 0;
//                         }
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void solveSudoku(vector<vector<int>> &sudoku)
// {
//     solve(sudoku);
// }

// Write a program to solve a sudoku

bool isSafe(int row, int col, vector<vector<int>> &board, int val, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
        if (board[i][col] == val)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) * i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val < 9; val++)
                {
                    if (isSafe(row, col, board, val, n))
                    {
                        board[row][col] = val;
                        bool ageWalaSafe = solve(board);

                        if (ageWalaSafe)
                        {
                            return true;
                        }
                        else
                        {
                            // backtracing
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    return 0;
}
// The time complexity of this solution is O(9^m).
// The space complexity of this solution is O(1).

// some of the cases where hashing are not important are:
/*
finding closest value
sorted data


Applications of hashing:
1. dictionaries
2. cryptography
3. caches
4. symbol table in compilers/interpretors
5. routers


Direct access table:
direct access table does not work fine because it can't handle large values

phone numbers are key
floating point numbers are key
keys are string



How hashing actually works:
Hash table

basic functionality:
universe of keys ----> hash function ------> index of bucket array

Then we have the concept of size of hash table.



How a hash function work
should always map a large key to same small key
should generate values from 0 to m-1
should be fast,O(1) for integers, and O(len) for string of length "len"
should uniformly distribute large key into hash table slots.


Example of hash function:

H{large_key} = large_key % n

ideally choose prime number chance of collision is less
bad value of m -> power of 2, 10


for strings, weighted sum
str[] = "abcd"
str[0] ^ x^0 + str[1] ^ x ^ 1 + ...
Where x is a prime number

Universally distributed the keys in table


Now comes the concept of collision handling

Collision Handling:
If we do not know keys in Advance then, we can use one of following:

- chaining              : Here the hash table is an array of linked list
                        performance of chaining
                        m = no. of slots in hash table
                        n = no. of keys to be inserted

                        load factor (alpha) = n/m
                        we want the load factor to be small(or less than 0.7).
                        expected chain length = we don't know,
                        worst case : every key is inserted in same chain
                        expected chain length = alpha
                        we can implement chaining by linkedlist , vector etc.

- open addressing
    - Linear probing
    - Quadratic probing
    - Double Hashing
*/

// Life is not about achieving things. It is more about process.
// Aim is not to get the officer post . The real aim is to become an officer.