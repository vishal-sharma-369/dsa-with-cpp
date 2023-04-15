#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int fib(int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1);
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i] = -1;
//     }
//     cout << fib(n, dp) << endl;
//     return 0;
// }
/*
Introduction to dynamic programming.
those who forget the past are condemned to repeat it.
Prerequisites : Recursion.

2 approaches :
top - down : recursion + memoization.
bottom - up : tabulation.

Fibonacci series :
using the top down approach.

*/

// int memoization[100] = {-1};

// int fibonacci(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }

//     if (memoization[n] != -1)
//     {
//         return memoization[n];
//     }

//     return memoization[n] = fibonacci(n - 1) + fibonacci(n - 2);
// }

// The time complexity of this solution is O(n).
// The space complexity of this solution is O(n).

// To perform the same task using tabulation.
// int fibon(int n)
// {
//     vector<int> dp(n);
//     dp[0] = 0;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[n];
// }
// The time complexity of this solution is O(n).
// The space complexity of this solution is O(n).
// int fibo(int n)
// {
//     int first = 0;
//     int second = 1;
//     if (n <= 1)
//     {
//         return n;
//     }
//     int ans;
//     for (int i = 2; i <= n; i++)
//     {
//         ans = first + second;
//         first = second;
//         second = ans;
//     }
//     return ans;
// }
// The time complexity of this solution is O(n).
// The space complexity of this solution is O(1).
// #define MOD 1000000007
// int solve(long long nStairs, int i)
// {
//     // base case
//     {
//         if (i == nStairs)
//         {
//             return 1;
//         }
//         if (i > nStairs)
//         {
//             return 0;
//         }
//         return solve(nStairs, i + 1) + solve(nStairs, i + 2) % MOD;
//     }
// }
// int main()
// {
//     return 0;
// }
// class solution
// {
// public:
//     int solve(vector<int> &cost, int n, vector<int> &dp)
//     {
//         if (n < 0)
//         {
//             return 0;
//         }
//         if (n == 0)
//         {
//             return cost[0];
//         }
//         if (n == 1)
//         {
//             return cost[1];
//         }
//         if (dp[n] != -1)
//         {
//             return dp[n];
//         }
//         return dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
//     }
//     int minCostClimbingStairs(vector<int> &cost)
//     {
//         // int n = cost.size();
//         // int ans = min(solve(cost, n - 1), solve(cost, n - 2));
//         // return ans;
//         int n = cost.size();
//         vector<int> dp(n + 1, -1);
//         int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
//         return ans;
//     }
// };
// Solving the same problem using tabulation method:
// int solve(vector<int> &cost, int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = cost[0];
//     dp[1] = cost[1];
//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//     }
//     return min(dp[n - 1], dp[n - 2]);
// }
// // Using space optimization method
// int solve(vector<int> &cost, int n)
// {
//     int first = cost[0];
//     int second = cost[1];
//     int curr;
//     for (int i = 2; i < n; i++)
//     {
//         int curr = cost[i] + min(first, second);
//         first = second;
//         second = curr;
//     }
//     return min(second, curr);
// }
// Minimum number of coins to make an amount.
// int solveRec(vector<int> &num, int x)
// {
//     if (x == 0)
//     {
//         return 0;
//     }
//     if (x < 0)
//     {
//         return INT_MAX;
//     }
//     int mini = INT_MAX;
//     for (int i = 0; i < num.size(); i++)
//     {
//         int ans = solveRec(num, x - num[i]);
//         if (ans != INT_MAX)
//         {
//             mini = min(mini, 1 + ans);
//         }
//     }
//     return mini;
// }

/*
Working with the knapsack problem.
*/