#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Buy and sell stocks part 1
// class solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         int mini = prices[0];
//         int profit = 0;
//         for (int i = 1; i < n; i++)
//         {
//             int diff = prices[i] - mini;
//             profit = max(profit, diff);
//             mini = min(mini, prices[i]);
//         }
//         return profit;
//     }
// };
// int main()
// {
//     return 0;
// }

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Buy and sell stocks part 2:

// class solution
// {
//     // Using recursion:
//     int solveRec(int index, int buy, vector<int> &prices)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }

//         int profit = 0;
//         // buy logic:
//         if (buy)
//         {
//             int buyKaro = -1 * prices[index] + solveRec(index + 1, 0, prices);
//             int skipKaro = 0 + solveRec(index + 1, 1, prices);
//             profit = max(buyKaro, skipKaro);
//         }
//         else
//         {
//             int sellKaro = prices[index] + solveRec(index + 1, 1, prices);
//             int skipKaro = 0 + solveRec(index + 1, 0, prices);
//             profit = max(sellKaro, skipKaro);
//         }

//         return profit;
//     }

//     // Using memoization:
//     int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }

//         if (dp[index][buy] != -1)
//         {
//             return dp[index][buy];
//         }

//         int profit = 0;
//         // buy logic:
//         if (buy)
//         {
//             int buyKaro = -1 * prices[index] + solveMem(index + 1, 0, prices, dp);
//             int skipKaro = 0 + solveMem(index + 1, 1, prices, dp);
//             profit = max(buyKaro, skipKaro);
//         }
//         else
//         {
//             int sellKaro = prices[index] + solveMem(index + 1, 1, prices, dp);
//             int skipKaro = 0 + solveMem(index + 1, 0, prices, dp);
//             profit = max(sellKaro, skipKaro);
//         }

//         return dp[index][buy] = profit;
//     }

//     // Using tabulation:
//     int solveTab(vector<int> &prices)
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

//         for (int index = n - 1; index >= 0; index--)
//         {
//             for (int buy = 0; buy <= 1; buy++)
//             {
//                 int profit = 0;

//                 if (buy)
//                 {
//                     int buyKaro = -1 * prices[index] + dp[index + 1][0];
//                     int skipKaro = 0 + dp[index + 1][1];
//                     profit = max(buyKaro, skipKaro);
//                 }
//                 else
//                 {
//                     int sellKaro = prices[index] + dp[index + 1][1];
//                     int skipKaro = 0 + dp[index + 1][0];
//                     profit = max(sellKaro, skipKaro);
//                 }

//                 dp[index][buy] = profit;
//             }
//         }

//         return dp[0][1];
//     }

//     // Using space optimization:
//     int solveSO(vector<int> &prices)
//     {
//         int n = prices.size();
//         vector<int> next(2, 0);
//         vector<int> curr(2, 0);

//         for (int index = n - 1; index >= 0; index--)
//         {
//             for (int buy = 0; buy <= 1; buy++)
//             {
//                 int profit = 0;

//                 if (buy)
//                 {
//                     int buyKaro = -1 * prices[index] + next[0];
//                     int skipKaro = 0 + next[1];
//                     profit = max(buyKaro, skipKaro);
//                 }
//                 else
//                 {
//                     int sellKaro = prices[index] + next[1];
//                     int skipKaro = 0 + next[0];
//                     profit = max(sellKaro, skipKaro);
//                 }

//                 curr[buy] = profit;
//             }
//             next = curr;
//         }

//         return curr[1];
//     }

// public:
//     int maxProfit(vector<int> &prices)
//     {
//         vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
//     }
// };

// int main()
// {
//     return 0;
// }

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Buy and sell stock part 3:

// class solution
// {
//     int solveRec(int index, int buy, int transactions, int k, vector<int> &prices)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }
//         if (transactions >= k)
//         {
//             return 0;
//         }
//         // buy logic
//         int profit = 0;
//         if (buy)
//         {
//             int buyKaro = -prices[index] + solveRec(index + 1, 0, transactions, k, prices);
//             int skipKaro = 0 + solveRec(index + 1, 1, transactions, k, prices);
//             profit = max(buyKaro, skipKaro);
//         }
//         else
//         {
//             int sellKaro = +prices[index] + solveRec(index + 1, 1, transactions + 1, k, prices);
//             int skipKaro = 0 + solveRec(index + 1, 0, transactions, k, prices);
//             profit = max(sellKaro, skipKaro);
//         }
//         return profit;
//     }

//     // Using memoization:
//     int solveMem(int index, int buy, int transactions, int k, vector<int> &prices, vector<vector<vector<int>>> &dp)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }
//         if (transactions >= k)
//         {
//             return 0;
//         }

//         if (dp[index][buy][transactions] != -1)
//         {
//             return dp[index][buy][transactions];
//         }

//         // buy logic
//         int profit = 0;
//         if (buy)
//         {
//             int buyKaro = -prices[index] + solveMem(index + 1, 0, transactions, k, prices, dp);
//             int skipKaro = 0 + solveMem(index + 1, 1, transactions, k, prices, dp);
//             profit = max(buyKaro, skipKaro);
//         }
//         else
//         {
//             int sellKaro = +prices[index] + solveMem(index + 1, 1, transactions + 1, k, prices, dp);
//             int skipKaro = 0 + solveMem(index + 1, 0, transactions, k, prices, dp);
//             profit = max(sellKaro, skipKaro);
//         }
//         return dp[index][buy][transactions] = profit;
//     }

//     // Using tabulation:
//     int solveMem(int index, int buy, int transactions, int k, vector<int> &prices)
//     {
//         vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
//         int n = prices.size();

//         for (int index = n - 1; index >= 0; index--)
//         {
//             for (int buy = 0; buy <= 1; buy++)
//             {
//                 for (int transactions = k - 1; transactions >= 0; transactions--)
//                 {
//                     int profit = 0;
//                     if (buy)
//                     {
//                         int buyKaro = -prices[index] + dp[index + 1][0][transactions];
//                         int skipKaro = 0 + dp[index + 1][1][transactions];
//                         profit = max(buyKaro, skipKaro);
//                     }
//                     else
//                     {
//                         int sellKaro = +prices[index] + dp[index + 1][1][transactions + 1];
//                         int skipKaro = 0 + dp[index + 1][0][transactions];
//                         profit = max(sellKaro, skipKaro);
//                     }
//                     dp[index][buy][transactions] = profit;
//                 }
//             }
//         }

//         return dp[0][1][0];
//     }

//     // Using space optimization:
//     int solveSO(int index, int buy, int transactions, int k, vector<int> &prices)
//     {
//         vector<vector<int>> next(2, vector<int>(k +1, 0));
//         vector<vector<int>> curr(2, vector<int>(k+1, 0));

//         int n = prices.size();

//         for (int index = n - 1; index >= 0; index--)
//         {
//             for (int buy = 0; buy <= 1; buy++)
//             {
//                 for (int transactions = k - 1; transactions >= 0; transactions--)
//                 {
//                     int profit = 0;
//                     if (buy)
//                     {
//                         int buyKaro = -prices[index] + next[0][transactions];
//                         int skipKaro = 0 + next[1][transactions];
//                         profit = max(buyKaro, skipKaro);
//                     }
//                     else
//                     {
//                         int sellKaro = +prices[index] + next[1][transactions + 1];
//                         int skipKaro = 0 + next[0][transactions];
//                         profit = max(sellKaro, skipKaro);
//                     }
//                     curr[buy][transactions] = profit;
//                 }
//             }
//             next = curr;
//         }

//         return next[1][0];
//     }

// public:
//     int maxProfit(vector<int> &prices)
//     {
//     }
// };

// int main()
// {
//     return 0;
// }

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Buy and sell stocks part 4:
// class solution
// {
// public:
//     int solve(int index, int operationNo, int k, vector<int> &prices)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }
//         if (operationNo >= 2 * k)
//         {
//             return 0;
//         }

//         int profit = 0;
//         if (operationNo & 1)
//         {
//             int sellKaro = prices[index] + solve(index + 1, operationNo + 1, k, prices);
//             int skipkaro = 0 + solve(index + 1, operationNo, k, prices);

//             profit = max(sellKaro, skipkaro);
//         }
//         else
//         {
//             int buyKaro = -prices[index] + solve(index + 1, operationNo + 1, k, prices);
//             int skipkaro = 0 + solve(index + 1, operationNo, k, prices);

//             profit = max(buyKaro, skipkaro);
//         }

//         return profit;
//     }

//     // Using memoization:
//     int solveMem(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }
//         if (operationNo >= 2 * k)
//         {
//             return 0;
//         }

//         if (dp[index][operationNo] != -1)
//         {
//             return dp[index][operationNo];
//         }

//         int profit = 0;
//         if (operationNo & 1)
//         {
//             int sellKaro = prices[index] + solveMem(index + 1, operationNo + 1, k, prices, dp);
//             int skipkaro = 0 + solveMem(index + 1, operationNo, k, prices, dp);

//             profit = max(sellKaro, skipkaro);
//         }
//         else
//         {
//             int buyKaro = -prices[index] + solveMem(index + 1, operationNo + 1, k, prices, dp);
//             int skipkaro = 0 + solveMem(index + 1, operationNo, k, prices, dp);

//             profit = max(buyKaro, skipkaro);
//         }

//         return dp[index][operationNo] = profit;
//     }

//     // Using tabulation:
//     int solveTab(int k, vector<int> &prices)
//     {
//         vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));

//         for (int index = prices.size() - 1; index >= 0; index--)
//         {
//             for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
//             {
//                 int profit = 0;
//                 if (operationNo & 1)
//                 {
//                     int sellKaro = prices[index] + dp[index + 1][operationNo + 1];
//                     int skipkaro = 0 + dp[index + 1][operationNo];

//                     profit = max(sellKaro, skipkaro);
//                 }
//                 else
//                 {
//                     int buyKaro = -prices[index] + dp[index + 1][operationNo + 1];
//                     int skipkaro = 0 + dp[index + 1][operationNo];

//                     profit = max(buyKaro, skipkaro);
//                 }

//                 dp[index][operationNo] = profit;
//             }
//         }

//         return dp[0][0];
//     }

//     // Using space optimization:
//     int solveSO(int k, vector<int> &prices)
//     {
//         vector<int> next(2 * k + 1, 0);
//         vector<int> curr(2 * k + 1, 0);

//         for (int index = prices.size() - 1; index >= 0; index--)
//         {
//             for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
//             {
//                 int profit = 0;
//                 if (operationNo & 1)
//                 {
//                     int sellKaro = prices[index] + next[operationNo + 1];
//                     int skipkaro = 0 + next[operationNo];

//                     profit = max(sellKaro, skipkaro);
//                 }
//                 else
//                 {
//                     int buyKaro = -prices[index] + next[operationNo + 1];
//                     int skipkaro = 0 + next[operationNo];

//                     profit = max(buyKaro, skipkaro);
//                 }

//                 curr[operationNo] = profit;
//             }
//             next = curr;
//         }

//         return next[0];
//     }

//     int maxProfit(int k, vector<int> &prices)
//     {
//         vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
//     }
// };

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Buy and Sell stocks part 5:

// class solution
// {
// public:
//     int solveRec(int index, int buy, vector<int> &prices, int fee)
//     {
//         if (index >= prices.size())
//         {
//             return 0;
//         }
//         int profit = 0;
//         // buy logic:
//         if (buy)
//         {
//             int buyKaro = -1 * prices[index] + solveRec(index + 1, 0, prices, fee);
//             int skipKaro = 0 + solveRec(index + 1, 1, prices, fee);
//             profit = max(buyKaro, skipKaro);
//         }
//         else
//         {
//             int sellKaro = prices[index] + solveRec(index + 1, 1, prices, fee) - fee;
//             int skipKaro = 0 + solveRec(index + 1, 0, prices, fee);
//             profit = max(sellKaro, skipKaro);
//         }
//         return profit;
//     }

//     int maxProfit(vector<int> &prices, int fee)
//     {
//         return solveRec(0, 1, prices, fee);
//     }
// };

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Write a program to find the longest common subsequence.

// class solution
// {
//     int solve(string a, string b, int i1, int i2)
//     {
//         if (i1 >= a.length())
//         {
//             return 0;
//         }
//         if (i2 >= b.length())
//         {
//             return 0;
//         }
//         int ans = 0;
//         if (a[i1] == b[i2])
//         {
//             ans = 1 + solve(a, b, i1 + 1, i2 + 1);
//         }
//         else
//         {
//             ans = max(solve(a, b, i1 + 1, i2), solve(a, b, i1, i2 + 1));
//         }
//         return ans;
//     }

//     // Using memoization:
//     int solveMem(string a, string b, int i1, int i2, vector<vector<int>> &dp)
//     {
//         if (i1 >= a.length())
//         {
//             return 0;
//         }
//         if (i2 >= b.length())
//         {
//             return 0;
//         }
//         if (dp[i1][i2] != -1)
//         {
//             return dp[i1][i2];
//         }

//         int ans = 0;
//         if (a[i1] == b[i2])
//         {
//             ans = 1 + solveMem(a, b, i1 + 1, i2 + 1, dp);
//         }
//         else
//         {
//             ans = max(solveMem(a, b, i1 + 1, i2, dp), solveMem(a, b, i1, i2 + 1, dp));
//         }
//         return dp[i1][i2] = ans;
//     }

//     // Using tabulation:
//     int solveTab(string a, string b, int i1, int i2)
//     {
//         vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

//         for (int i = a.length() - 1; i >= 0; i--)
//         {
//             for (int j = b.length() - 1; j >= 0; j--)
//             {
//                 int ans = 0;
//                 if (a[i] == b[j])
//                 {
//                     ans = 1 + dp[i + 1][j + 1];
//                 }
//                 else
//                 {
//                     ans = max(dp[i + 1][j], dp[i][j + 1]);
//                 }
//                 dp[i][j] = ans;
//             }
//         }

//         return dp[0][0];
//     }

//     // Using space optimization:
//     int solveSO(string a, string b, int i1, int i2)
//     {
//         vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
//         vector<int> next(b.length() + 1, 0);
//         vector<int> curr(b.length() + 1, 0);
//         for (int i = a.length() - 1; i >= 0; i--)
//         {
//             for (int j = b.length() - 1; j >= 0; j--)
//             {
//                 int ans = 0;
//                 if (a[i] == b[j])
//                 {
//                     ans = 1 + next[j + 1];
//                 }
//                 else
//                 {
//                     ans = max(next[j], curr[j + 1]);
//                 }
//                 curr[j] = ans;
//             }
//             next = curr;
//         }
//         return next[0];
//     }

// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         return solve(text1, text2, 0, 0);
//     }
// };
// int main()
// {
//     return 0;
// }

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Write a program to find the longest palindromic subsequence.

// class solution
// {
//     int solve(string a, string b, int i1, int i2)
//     {
//         if (i1 >= a.length())
//         {
//             return 0;
//         }
//         if (i2 >= b.length())
//         {
//             return 0;
//         }
//         int ans = 0;
//         if (a[i1] == b[i2])
//         {
//             ans = 1 + solve(a, b, i1 + 1, i2 + 1);
//         }
//         else
//         {
//             ans = max(solve(a, b, i1 + 1, i2), solve(a, b, i1, i2 + 1));
//         }
//         return ans;
//     }

// public:
//     int longestPalindromicSubsequence(string str)
//     {
//         string str2 = str;
//         reverse(str2.begin(), str2.end());
//         return solve(str, str2, 0, 0);
//     }
// };

// int main()
// {
//     return 0;
// }

// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Write a program to solve the edit distance problem.
// class solution
// {
//     int solve(string &a, string &b, int i, int j)
//     {
//         if (i == a.length())
//         {
//             return b.length() - j;
//         }
//         if (j == b.length())
//         {
//             return a.length() - i;
//         }
//         int ans = 0;
//         if (a[i] == b[j])
//         {
//             ans = solve(a, b, i + 1, j + 1);
//         }
//         else
//         {
//             int insert = 1 + solve(a, b, i, j + 1);
//             int del = 1 + solve(a, b, i + 1, j);
//             int replace = 1 + solve(a, b, i + 1, j + 1);
//             ans = min(insert, min(del, replace));
//         }
//         return ans;
//     }
//     // Using memoization:int solve(string &a, string &b, int i, int j)
//     int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
//     {
//         if (i == a.length())
//         {
//             return b.length() - j;
//         }
//         if (j == b.length())
//         {
//             return a.length() - i;
//         }
//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         int ans = 0;
//         if (a[i] == b[j])
//         {
//             ans = solveMem(a, b, i + 1, j + 1, dp);
//         }
//         else
//         {
//             int insert = 1 + solveMem(a, b, i, j + 1, dp);
//             int del = 1 + solveMem(a, b, i + 1, j, dp);
//             int replace = 1 + solveMem(a, b, i + 1, j + 1, dp);
//             ans = min(insert, min(del, replace));
//         }
//         return dp[i][j] = ans;
//     }
//     // Using tabulation:
//     int solveTab(string &a, string &b, int i, int j)
//     {
//         vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
//         for (int j = 0; j <= b.length(); j++)
//         {
//             dp[a.length()][j] = b.length() - j;
//         }
//         for (int i = 0; i <= a.length(); i++)
//         {
//             dp[i][b.length()] = a.length() - i;
//         }
//         for (int i = a.length() - 1; i >= 0; i--)
//         {
//             for (int j = b.length() - 1; j >= 0; j--)
//             {
//                 int ans = 0;
//                 if (a[i] == b[j])
//                 {
//                     ans = dp[i + 1][j + 1];
//                 }
//                 else
//                 {
//                     int insert = 1 + dp[i][j + 1];
//                     int del = 1 + dp[i + 1][j];
//                     int replace = 1 + dp[i + 1][j + 1];
//                     ans = min(insert, min(del, replace));
//                }
//                 dp[i][j] = ans;
//             }
//         }
//         return dp[0][0];
//     }
//     // Using space optimization:
//     int solveSO(string &a, string &b)
//     {
//         vector<int> next(b.length() + 1, 0);
//         vector<int> curr(b.length() + 1, 0);
//         for (int j = 0; j <= b.length(); j++)
//         {
//             next[j] = b.length() - j;
//         }
//         for (int i = a.length() - 1; i >= 0; i--)
//         {
//             for (int j = b.length() - 1; j >= 0; j--)
//             {
//                 curr[b.length()] = a.length() - i;
//                 int ans = 0;
//                 if (a[i] == b[j])
//                 {
//                     ans = next[j + 1];
//                 }
//                 else
//                 {
//                     int insert = 1 + curr[j + 1];
//                     int del = 1 + next[j];
//                     int replace = 1 + next[j + 1];
//                     ans = min(insert, min(del, replace));
//                 }
//                 curr[j] = ans;
//             }
//             next = curr;
//         }
//         return next[0];
//     }
// public:
//     int minDistance(string word1, string word2)
//     {
//         // return solve(word1, word2, 0, 0);
//         // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
//         if (word1.length() == 0)
//         {
//             return word2.length();
//         }
//         if (word2.length() == 0)
//         {
//             return word1.length();
//         }
//         return solveSO(word1, word2);
//     }
// };
// int main()
// {
//     return 0;
// }
// ______________________________________________________________________________________
// ______________________________________________________________________________________
// Write a program to find the maximal rectangle with all 1's
// class solution
// {
//     int largestAreaHistogram(vector<int> &a)
//     {
//         int lefts[a.size()];
//         int rights[a.size()];
//         queue<int> q;
//         q.push(-1);
//         for (int i = a.size() - 1; i >= 0; i--)
//         {
//             if (q.front() < a[i])
//             {
//                 rights[i] = q.front();
//             }
//             else
//             {
//                 while (q.front() >= a[i] && q.front() != -1)
//                 {
//                     q.pop();
//                 }
//                 rights[i] = q.front();
//             }
//             q.push(a[i]);
//         }
//         q = {};
//         q.push(-1);
//         for (int i = 0; i <= a.size(); i--)
//         {
//             if (q.front() < a[i])
//             {
//                 lefts[i] = q.front();
//             }
//             else
//             {
//                 while (q.front() >= a[i] && q.front() != -1)
//                 {
//                     q.pop();
//                 }
//                 rights[i] = q.front();
//             }
//             q.push(a[i]);
//         }
//     }
// public:
//     int maximalRectangle(vector<vector<char>> &matrix)
//     {
//         vector<int> temp(matrix[0].size(), 0);
//         int ans = 0;
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[i].size(); j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     temp[i] = 0;
//                 }
//                 else
//                 {
//                     temp[i] = 1 + temp[i];
//                 }
//             }
//             ans = max(ans, largestAreaHistogram(temp));
//         }
//         return ans;
//     }
// };
// int main()
// {
//     return 0;
// }
// ______________________________________________________________________________________
// ______________________________________________________________________________________
// class solution
// {
//     bool solve(string str, string pattern, int i, int j)
//     {
//         if (i < 0 && j < 0)
//         {
//             return true;
//         }
//         if (i >= 0 && j < 0)
//         {
//             return false;
//         }
//         if (i < 0 && j >= 0)
//         {
//             for (int k = 0; k <= j; k++)
//             {
//                 if (pattern[k] != '*')
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }
//         if (str[i] == pattern[j] || pattern[j] == '?')
//         {
//             return solve(str, pattern, i - 1, j - 1);
//         }
//         else if (pattern[j] == '*')
//         {
//             return (solve(str, pattern, i - 1, j), solve(str, pattern, i, j - 1));
//         }
//         else
//         {
//             return false;
//         }
//     }
//     // Using memoization:
//     bool solveMem(string str, string pattern, int i, int j, vector<vector<int>> &dp)
//     {
//         if (i == 0 && j == 0)
//         {
//             return true;
//         }
//         if (i > 0 && j == 0)
//         {
//             return false;
//         }
//         if (i == 0 && j > 0)
//         {
//             for (int k = 1; k <= j; k++)
//             {
//                 if (pattern[k - 1] != '*')
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }
//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
//         {
//             return dp[i][j] = solveMem(str, pattern, i - 1, j - 1, dp);
//         }
//         else if (pattern[j - 1] == '*')
//         {
//             return dp[i][j] = (solveMem(str, pattern, i - 1, j, dp), solveMem(str, pattern, i, j - 1, dp));
//         }
//         else
//         {
//             return dp[i][j] = false;
//         }
//     }
//     // Using tabulation:
// bool solveTab(string s1, string s2)
// {
//     vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
//     dp[0][0] = true;
//     for (int j = 1; j <= s2.length(); j++)
//     {
//         bool flag = true;
//         for (int k = 1; k <= j; k++)
//         {
//             if (s2[k - 1] != '*')
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         dp[0][j] = flag;
//     }
//     for (int i = 1; i <= s1.length(); i++)
//     {
//         for (int j = 1; j <= s2.length(); j++)
//         {
//             if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
//             {
//                 dp[i][j] = dp[i - 1][j - 1];
//             }
//             else if (s2[j - 1] == '*')
//             {
//                 dp[i][j] = (dp[i - 1][j], dp[i][j - 1]);
//             }
//             else
//             {
//                 dp[i][j] = false;
//             }
//         }
//     }
//     return dp[s1.length()][s2.length()];
// }
// public:
// bool isMatch(string s, string p)
// {
//     return solve(s, p, s.length() - 1, p.length() - 1);
// }
// };
// int main()
// {
//     return 0;
// }
