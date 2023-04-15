#include <bits/stdc++.h>

using namespace std;

// Write a program to solve the knapsack problem.
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
// {
//     if (index == 0)
//     {
//         if (weight[0] <= capacity)
//         {
//             return value[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     int include = 0;
//     if (weight[index] <= capacity)
//     {
//         include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
//     }

//     int exclude = 0 + solve(weight, value, index - 1, capacity);

//     return max(include, exclude);
// }

// int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
// {
//     if (index == 0)
//     {
//         if (weight[0] <= capacity)
//         {
//             return value[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     if (dp[index][capacity] != -1)
//     {
//         return dp[index][capacity];
//     }

//     int include = 0;
//     if (weight[index] <= capacity)
//     {
//         include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
//     }

//     int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

//     return dp[index][capacity] = max(include, exclude);
// }

// // Using tabulation:
// int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

//     // Initializing the 0th index
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             dp[0][w] = value[0];
//         }
//         else
//         {
//             dp[0][w] = 0;
//         }
//     }

//     // Initializing the remaining indexes
//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             if (w >= weight[index])
//             {
//                 int include = value[index] + dp[index - 1][w - weight[index]];
//                 int exclude = 0 + dp[index - 1][w];

//                 dp[index][w] = max(include, exclude);
//             }
//             else
//             {
//                 dp[index][w] = dp[index - 1][w];
//             }
//         }
//     }

//     return dp[n - 1][capacity];
// }

// // Using space optimization:
// int solveSO(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<int> first(capacity + 1, 0);
//     vector<int> second(capacity + 1, 0);
//     // initializing the first array
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] <= capacity)
//         {
//             first[w] = value[0];
//         }
//         else
//         {
//             first[w] = 0;
//         }
//     }
//     // Initializing the other indexes
//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             if (w >= weight[index])
//             {
//                 int include = value[index] + first[w - weight[index]];
//                 int exclude = 0 + first[w];
//                 second[w] = max(include, exclude);
//             }
//             else
//             {
//                 second[w] = first[w];
//             }
//         }
//         first = second;
//     }
//     return second[capacity];
// }

// // Using ultra space optimization
// int solveUSO(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<int> curr(capacity + 1, 0);
//     for (int w = weight[0]; w <= capacity; w++)
//     {
//         if (weight[0] >= capacity)
//         {
//             curr[w] = value[0];
//         }
//         else
//         {
//             curr[w] = 0;
//         }
//     }

//     for (int index = 1; index < n; index++)
//     {
//         for (int w = capacity; w >= 0; w++)
//         {
//             if (w >= weight[index])
//             {
//                 int include = value[0] + curr[w - weight[index]];
//                 int exclude = 0 + curr[w];

//                 curr[w] = max(include, exclude);
//             }
//             else
//             {
//                 curr[w] = curr[w];
//             }
//         }
//     }

//     return curr[capacity];
// }

// int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     // return solve(weight,value,n-1,capacity);

//     vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
//     return solveMem(weight, value, n - 1, capacity, dp);
// }

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to solve the combination sum problem.
// int solveRec(vector<int> &num, int tar)
// {
//     if (tar == 0)
//     {
//         return 1;
//     }
//     else if (tar < 0)
//     {
//         return 0;
//     }
//     int ans = 0;
//     for (int i = 0; i < num.size(); i++)
//     {
//         ans += solveRec(num, tar - num[i]);
//     }
//     return ans;
// }

// int solveMem(vector<int> &num, int tar, vector<int> &dp)
// {
//     if (tar == 0)
//     {
//         return 1;
//     }
//     else if (tar < 0)
//     {
//         return 0;
//     }
//     if (dp[tar] != -1)
//     {
//         return dp[tar];
//     }
//     int ans = 0;
//     for (int i = 0; i < num.size(); i++)
//     {
//         ans += solveMem(num, tar - num[i], dp);
//     }
//     dp[tar] = ans;
//     return ans;
// }

// // Using tabulation:
// int solveTab(vector<int> &num, int tar)
// {
//     vector<int> dp(tar + 1, 0);

//     dp[0] = 1;
//     for (int i = 1; i <= tar; i++)
//     {
//         int ans = 0;
//         for (int j = 0; j < num.size(); j++)
//         {
//             if(i - num[j] >= 0)
//              ans += dp[i - num[j]];
//         }
//         dp[i] = ans;
//     }

//     return dp[tar];
// }

// // Using space optimization: space optimization is not possible for this problem.

// int combinationSum(vector<int> &num, int tar)
// {
//     // return solveRec(num,tar);
//     vector<int> dp(tar + 1, -1);
//     return solveMem(num, tar, dp);
// }

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to solve the perfect squares problem.
// class solution
// {
// public:
//     int solveRec(int n)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }

//         int ans = INT_MAX;
//         for (int j = 1; j * j <= n; j++)
//         {
//             ans = min(ans, 1 + solveRec(n - j * j));
//         }

//         return ans;
//     }

//     int solveMem(int n, vector<int> &dp)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }

//         if (dp[n] != -1)
//         {
//             return dp[n];
//         }

//         int ans = INT_MAX;
//         for (int j = 1; j * j <= n; j++)
//         {
//             ans = min(ans, 1 + solveMem(n - j * j, dp));
//         }
//         dp[n] = ans;
//         return ans;
//     }

//     // Using tabulation:
//     int solveTab(int n)
//     {
//         vector<int> dp(n + 1, -1);

//         dp[0] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int ans = INT_MAX;
//             for (int j = 1; j * j <= i; j++)
//             {
//                 ans = min(ans, 1 + dp[i - j * j]);
//             }

//             dp[i] = ans;
//         }

//         return dp[n];
//     }

//     // Using space optimization : space optimization is not possible for this problem.

//     int MinSquares(int n)
//     {
//         vector<int> dp(n + 1, -1);
//     }
// };

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________
// Write a program to solve the Minimum cost for tickets problem.
// int minimumCost(int n, vector<int> &days, vector<int> &cost)
// {
// }

// int main()
// {
//     return 0;
// }

// Write a program to find the largest square area in matrix.
// class solution
// {
// public:
//     int solveRec(int row, int col, vector<vector<int>> &mat, int n, int m, int &maxi)
//     {
//         if (row >= n || col >= m || row < 0 || col < 0)
//         {
//             return 0;
//         }

//         int right = solveRec(row, col + 1, mat, n, m, maxi);
//         int diagonal = solveRec(row + 1, col + 1, mat, n, m, maxi);
//         int down = solveRec(row + 1, col, mat, n, m, maxi);

//         if (mat[row][col] == 1)
//         {
//             maxi = max(maxi, 1 + min(right, min(diagonal, down)));
//             return 1 + min(right, min(diagonal, down));
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     // Using memoization:
//     int solveMem(int row, int col, vector<vector<int>> &mat, int n, int m, vector<vector<int>> &dp)
//     {
//         if (row >= n || col >= m || row < 0 || col < 0)
//         {
//             return 0;
//         }

//         if (dp[row][col] != -1)
//         {
//             return dp[row][col];
//         }

//         int right = solveMem(row, col + 1, mat, n, m, dp);
//         int diagonal = solveMem(row + 1, col + 1, mat, n, m, dp);
//         int down = solveMem(row + 1, col, mat, n, m, dp);

//         if (mat[row][col] == 1)
//         {
//             return dp[row][col] = 1 + min(right, min(diagonal, down));
//         }
//         else
//         {
//             return dp[row][col] = 0;
//         }
//     }

//     // Using tabulation:

//     int solveTab(vector<vector<int>> &mat, int n, int m)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         for (int row = n - 1; row >= 0; row--)
//         {
//             for (int col = m - 1; col >= 0; col--)
//             {
//                 int right = dp[row][col + 1];
//                 int diagonal = dp[row + 1][col + 1];
//                 int down = dp[row + 1][col];

//                 if (mat[row][col] == 1)
//                 {
//                     dp[row][col] = 1 + min(right, min(diagonal, down));
//                 }
//                 else
//                 {
//                     dp[row][col] = 0;
//                 }
//             }
//         }

//         return dp[0][0];
//     }

//     // Using space optimization:
//     int solveSO(vector<vector<int>> &mat, int n, int m)
//     {
//         vector<int> first(m + 1, 0);
//         vector<int> second(m + 1, 0);

//         for (int row = n - 1; row >= 0; row--)
//         {
//             for (int col = m - 1; col >= 0; col--)
//             {
//                 int right = second[col + 1];
//                 int diagonal = first[col + 1];
//                 int down = first[col];

//                 if (mat[row][col] == 1)
//                 {
//                     second[col] = 1 + min(right, min(diagonal, down));
//                 }
//                 else
//                 {
//                     second[col] = 0;
//                 }
//             }

//             first = second;
//         }

//         return second[0];
//     }

//     int maxSquare(int n, int m, vector<vector<int>> &mat)
//     {
//         // return solveRec(0, 0, mat, n, m);
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//     }
// };

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to solve the min score triangulation of polygon problem.
// class solution
// {
// public:
//     int solveRec(vector<int> &v, int i, int j)
//     {
//         if (i + 1 == j)
//         {
//             return 0;
//         }

//         int ans = INT_MAX;
//         for (int k = i + 1; i < j; i++)
//         {
//             ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
//         }

//         return ans;
//     }

//     int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp)
//     {
//         if (i + 1 == j)
//         {
//             return 0;
//         }

//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }

//         int ans = INT_MAX;
//         for (int k = i + 1; k < j; k++)
//         {
//             ans = min(ans, v[i] *[j] * v[k] + solve(v, i, k, dp) + solve(v, k, j, dp));
//         }

//         dp[i][j] = ans;

//         return ans;
//     }

//     // Using tabulation
//     int solveTab(vector<int> &v)
//     {
//         vector<vector<int>> dp(v.size(), vector<int>(v.size(), 0));
//         int n = v.size();

//         for (int i = n - 1; i >= 0; j--)
//         {
//             for (int j = i + 2; j < n; j++)
//             {
//                 int ans = INT_MAX;
//                 for (int k = i + 1; k < j; k++)
//                 {
//                     ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
//                 }

//                 dp[i][j] = ans;
//             }
//         }

//         return dp[0][n - 1];
//     }

//     int minScoreTriangulation(vector<int> &values)
//     {
//         // return solveRec(values, 0, values.size() - 1);

//         vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
//     }
// };

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________
// Write a program to solve the min sideways jump problem.
// endPos = obstacles.size() - 1
// int solveRec(vector<int> &obstacles, int position, int endPos, int lane)
// {
//     if (position == endPos)
//     {
//         return 0;
//     }

//     if (obstacles[position + 1] == 0)
//     {
//         return solveRec(obstacles, position + 1, endPos, lane);
//     }
//     else if (obstacles[position + 1] != lane)
//     {
//         return solveRec(obstacles, position + 1, endPos, lane);
//     }
//     else
//     {
//         int ans = INT_MAX;
//         for (int i = 1; i <= 3; i++)
//         {
//             if (i == lane)
//             {
//                 continue;
//             }
//             else
//             {
//                 if (obstacles[position] != i)
//                     ans = min(ans, 1 + solveRec(obstacles, position, endPos, i));
//             }
//         }
//         return ans;
//     }
// }
// // This is the recursive solution for this problem.
// int solveMem(vector<int> &obstacles, int position, int endPos, int lane, vector<vector<int>> &dp)
// {
//     if (position == endPos)
//     {
//         return 0;
//     }

//     if (dp[position][lane] != -1)
//     {
//         return dp[position][lane];
//     }

//     if (obstacles[position + 1] == 0)
//     {
//         return dp[position][lane] = solveMem(obstacles, position + 1, endPos, lane, dp);
//     }
//     else if (obstacles[position + 1] != lane)
//     {
//         return dp[position][lane] = solveMem(obstacles, position + 1, endPos, lane, dp);
//     }

//     else
//     {
//         int ans = INT_MAX;
//         for (int i = 1; i <= 3; i++)
//         {
//             if (i == lane)
//             {
//                 continue;
//             }
//             else
//             {
//                 if (obstacles[position] != i)
//                     ans = min(ans, 1 + solveMem(obstacles, position, endPos, i, dp));
//             }
//         }
//         return dp[position][lane] = ans;
//     }
// }

// // Using tabulation:
// int solveTab(vector<int> &obstacles, int endPos)
// {
//     vector<vector<int>>(n, vector<int>(4, 0));

//     for (int position = endPos - 1; position >= 0; position--)
//     {
//         for (int lane = 1; lane <= 3; lane++)
//         {
//             if (obstacles[position + 1] == 0)
//             {
//                 dp[position][lane] = dp[position + 1][lane];
//             }
//             else if (obstacles[position + 1] != lane)
//             {
//                 dp[position][lane] = dp[position + 1][lane];
//             }

//             else
//             {
//                 int ans = INT_MAX;
//                 for (int i = 1; i <= 3; i++)
//                 {
//                     if (i == lane)
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         if (obstacles[position] != i)
//                         {
//                             ans = min(ans, dp[position + 1][i]);
//                         }
//                     }
//                 }

//                 dp[position][lane] = ans;
//             }
//         }
//     }

//     int first = 1 + dp[0][1];
//     int second = dp[0][2];
//     int third = 1 + dp[0][3];

//     return min(first, min(second, third));
// }

// // Using space optimization:
// int solveSO(vector<int> &obstacles, int endPos)
// {
//     vector<int> first(4, 0);
//     vector<int> second(4, 0);

//     for (int position = endPos - 1; position >= 0; position--)
//     {
//         for (int lane = 1; lane <= 3; lane++)
//         {
//             if (obstacles[position + 1] == 0 || obstacles[position + 1] != lane)
//             {
//                 second[lane] = first[lane];
//             }
//             else
//             {
//                 int ans = INT_MAX;
//                 for (int i = 1; i <= 3; i++)
//                 {
//                     if (lane == i || obstacles[position] == i)
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         ans = min(ans, 1 + first[i]);
//                     }
//                 }
//                 second[lane] = ans;
//             }
//         }

//         first = second;
//     }

//     return min(second[2], min(1 + second[1], 1 + second[3]));
// }
// // Space Complexity : O(1).

// int minSidewaysJumps(vector<int> &obstacles)
// {
//     int endPos = obstacles.size() - 1;
//     int currPos = 0;
//     int lane = 2;

//     // return solveRec(obstacles, currPos, endPos, lane);
//     vector<vector<int>> dp(n, vector<int>(4, -1));
// }

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a problem to solve the reducing dishes problem.

// class solution
// {
// public:
//     int solveRec(vector<int> &satisfaction, int index, int time)
//     {
//         // base case
//         if (index >= satisfaction.size())
//         {
//             return 0;
//         }

//         int include = satisfaction[index] * (time + 1) + solveRec(satisfaction, index + 1, time + 1);
//         int exclude = 0 + solveRec(satisfaction, index + 1, time);

//         return max(include, exclude);
//     }

//     int solveMem(vector<int> &satisfaction, int index, int time, vector<vectr<int>> &dp)
//     {
//         if (index >= satisfaction.size())
//         {
//             return 0;
//         }
//         if (dp[index][time] != -1)
//         {
//             return dp[index][time];
//         }

//         int include = satisfaction[index] * (time + 1) + solveMem(satisfaction, index + 1, time + 1, dp);
//         int exclude = 0 + solveMem(satisfaction, index + 1, time, dp);

//         return dp[index][time] = max(include, exclude);
//     }

//     // Using tabulation:
//     int solveTab(vector<int> &satisfaction, int index, int time)
//     {
//         int n = satisfaction.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int index = n - 1; index >= 0; index--)
//         {
//             for (int time = index; time >= 0; time--)
//             {
//                 int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
//                 int exclude = 0 + dp[index + 1][time];

//                 dp[index][time] = max(include, exclude);
//             }
//         }

//         return dp[0][0];
//     }

//     // Using space optimization:
//     int solveSO(vector<int> &satisfaction, int index, int time)
//     {
//         int n = satisfaction.size();
//         vector<int> first(n + 1, 0);
//         vector<int> second(n + 1, 0);

//         for (int index = n - 1; index >= 0; index--)
//         {
//             for (int time = index; time >= 0; time--)
//             {
//                 int include = satisfaction[index] * (time + 1) + first[time + 1];
//                 int exclude = 0 + first[time];

//                 second[time] = max(include, exclude);
//             }
//             first = second;
//         }
//         return second[0];
//     }

//     int maxSatisfaction(vector<int> &satisfaction)
//     {
//         sort(satisfaction.begin(), satisfaction.end());
//         // return solveRec(satisfaction, 0, 0);

//         vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size(), -1));
//         return solveMem(satisfaction, 0, 0, dp);
//     }
// };

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________
// Write a program to find the longest increasing subsequence.

// class solution
// {
// public:
//     int solveRec(int n, int a[], int curr, int prev)
//     {
//         if (curr == n)
//         {
//             return 0;
//         }

//         int include = 0;
//         if (prev == -1 || a[curr] > a[prev])
//         {
//             include = 1 + solveRec(n, a, curr + 1, curr);
//         }

//         int exclude = solveRec(n, a, , curr + 1, prev);

//         return max(include, exclude);
//     }

//     // Using memoization
//     int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
//     {
//         if (curr == n)
//         {
//             return 0;
//         }
//         if (dp[curr][prev + 1] != -1)
//         {
//             return dp[curr][prev + 1];
//         }

//         int include = 0;
//         if (prev == -1 || a[curr] > a[prev])
//         {
//             include = 1 + solveMem(n, a, curr + 1, curr, dp);
//         }

//         int exclude = 0 + solveMem(n, a, curr + 1, prev, dp);

//         return dp[curr][prev + 1] = max(include, exclude);
//     }

//     // Using tabulation:
//     int solveTab(int n, int a[], int curr, int prev)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int curr = n - 1; curr >= 0; curr--)
//         {
//             for (int prev = curr - 1; prev >= -1; prev--)
//             {
//                 int take = 0;
//                 if (prev == -1 || a[curr] > a[prev])
//                 {
//                     take = 1 + dp[curr + 1][curr + 1];
//                 }

//                 int notTake = 0 + dp[curr + 1][prev + 1];

//                 dp[curr][prev + 1] = max(take, notTake);
//             }
//         }

//         return dp[0][-1 + 1];
//     }

//     // Using dp with binary search
//     int solveBS(int n, int a[])
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         vector<vector<int>> bs;
//         bs.push_back({a[0]});
//         for (int i = 1; i < n; i++)
//         {
//             bool inc = false;
//             for (int j = 0; j < bs.size(); j++)
//             {
//                 if (bs[j][bs[j].size() - 1] < a[i])
//                 {
//                     inc = true;
//                     bs[j].puush_back(a[i]);
//                 }
//             }
//             if (inc == false)
//             {
//                 bs.push_back({a[i]});
//             }
//         }
//         int maxi = 0;
//         for (int i = 0; i < bs.size(); i++)
//         {
//             maxi = max(maxi, bs[i].size());
//         }
//         return maxi;
//     }

//     int solveUBS(int n, int a[])
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         vector<pair<int, int>> bs;
//         bs.push_back({a[0], 1});
//         for (int i = 1; i < n; i++)
//         {
//             bool inc = false;
//             for (int j = 0; j < bs.size(); j++)
//             {
//                 if (bs[j].first < a[i])
//                 {
//                     inc = true;
//                     bs[j].first = a[i];
//                     bs[j].second++;
//                 }
//             }
//             if (inc == false)
//             {
//                 bs.push_back({a[i], 1});
//             }
//         }

//         int maxi = 0;
//         for (int i = 0; i < bs.size(); i++)
//         {
//             maxi = max(maxi, bs[i].second);
//         }
//         return maxi;
//     }

//     // Using the lower bound method.
//     int solveOptimal(int n, int a[])
//     {
//         vector<int> o;

//         o.push_back(a[0]);

//         for (int i = 1; i < n; i++)
//         {
//             if (o[o.size() - 1] < a[i])
//             {
//                 o.push_back(a[i]);
//             }
//             else
//             {
//                 int lowerbound = lower_bound(o.begin(), o.end(), a[i]) - o.begin();
//                 o[lowerbound] = a[i];
//             }
//         }

//         return o.size();
//     }
//     // The time complexity of this solution is O(nlogn).
//     // The Space complexity of this solution is O(n).

//     int longestSubsequence(int n, int a[])
//     {
//         // return solveRec(n, a, 0, -1);

//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solveMem(n, a, 0, -1, dp);
//     }
// };

// int main()
// {
//     return 0;
// }

// Write a program to solve the russian dolls problem.
// class solution
// {
//     bool compare(vector<int> a, vector<int> b)
//     {
//         if (a[0] == b[0])
//         {
//             return a[1] > b[1];
//         }
//         else
//         {
//             return a[0] < b[0];
//         }
//     }

//     int solveOptimal(int n, vector<int> a)
//     {
//         vector<int> o;
//         o.push_back(a[0]);
//         for (int i = 1; i < n; i++)
//         {
//             if (o[o.size() - 1] < a[i])
//             {
//                 o.push_back(a[i]);
//             }
//             else
//             {
//                 int lowerbound = lower_bound(o.begin(), o.end(), a[i]) - o.begin();
//                 o[lowerbound] = a[i];
//             }
//         }
//         return o.size();
//     }

// public:
//     int maxEnvelopes(vector<vector<int>> &envelopes)
//     {
//         sort(envelopes.begin(), envelopes.end(), compare);
//         vector<int> aux;
//         for (auto i : envelopes)
//         {
//             aux.push_back(i[1]);
//         }

//         return solveOptimal(envelopes.size(), aux);
//     }
// };

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to find the maximum height by stacking cuboid.
// class solution
// {
//     bool check(vector<int> a, vector<int> b)
//     {
//         if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     int solveTab(int n, vector<vector<int>> &a, int curr, int prev)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         for (int curr = n - 1; curr >= 0; curr--)
//         {
//             for (int prev = curr - 1; prev >= -1; prev--)
//             {
//                 int take = 0;
//                 if (prev == -1 || check(a[curr], a[prev]))
//                 {
//                     take = a[curr][2] + dp[curr + 1][curr + 1];
//                 }
//                 int notTake = 0 + dp[curr + 1][prev + 1];
//                 dp[curr][prev + 1] = max(take, notTake);
//             }
//         }
//         return dp[0][-1 + 1];
//     }
// public:
//     int maxHeight(vector<vector<int>> &cuboids)
//     {
//         for (auto &i : cuboids)
//         {
//             sort(i.begin(), i.end());
//         }
//         sort(cuboids.begin(), cuboids.end());
//         return solveTab(cuboids.size(), cuboids);
//     }
// };

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to find the factorial of a number using dynamic programming.
// Those who forget the past are condemned to repeat it.
// The process of storing the result of a computation so that it can be used in future references is called memoization.

// int factorial(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }

//     return factorial(n - 1) + factorial(n - 2);
// }

// // Using memoization:
// int factorial(int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return n;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = factorial(n - 1) + factorial(n - 2);
// }

// // Using tabulation:
// int factorial(int n)
// {
//     vector<int> dp(n + 1, -1);
//     dp[0] = 0;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// // Using space optimization:
// int factorial(int n)
// {
//     int first = 0;
//     int second = 1;

//     if (n == 0)
//     {
//         return n;
//     }

//     for (int i = 2; i <= n; i++)
//     {
//         int curr = first + second;
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to find the minimum cost of climbing the nth stair.
// No of ways to reach the  nth stair.
// int solveRec(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     else if (n < 0)
//     {
//         return 0;
//     }

//     return solveRec(n - 1) + solveRec(n - 2);
// }

// // Using memoization:
// int solveMem(int n, vector<int> &dp)
// {
//     if (n == 0)
//     {
//         return 1;
//     }

//     else if (n < 0)
//     {
//         return 0;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp);
// }

// // Using tabulation:
// int solveTab(int n)
// {
//     vector<int> dp(n + 1, 0);
//     dp[0] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// // Using space optimization:
// int solveSO(int n)
// {
//     int first = 0;
//     int second = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         int curr = first + second;
//         first = second;
//         second = curr;
//     }

//     return curr;
// }

// Write a program to find the minimum cost of climbing the nth stair.
// int solveRec(vector<int> &cost, int n)
// {
//     if (n == 0)
//     {
//         return cost[0];
//     }
//     if (n == 1)
//     {
//         return cost[1];
//     }

//     return cost[n] + min(solveRec(cost, n - 1), solveRec(cost, n - 2));
// }

// // Using memoization:
// int solveMem(vector<int> &cost, int n, vector<int> &dp)
// {
//     if (n == 0)
//     {
//         return cost[0];
//     }

//     if (n == 1)
//     {
//         return cost[1];
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = cost[n] + min(solveMem(cost, n - 1, dp), solveMem(cost, n - 2, dp));
// }

// // Using Tabulation:
// int solveTab(vector<int> &cost, int n, vector<int> &dp)
// {
//     vector<int> dp(n + 1, 0);
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//     }

//     return dp[n];
// }

// // Using space optimization:
// int solveSO(vector<int> &cost, int n)
// {
//     int first = cost[0];
//     int second = cost[1];

//     for (int i = 2; i <= n; i++)
//     {
//         int curr = cost[i] + min(first, second);

//         first = second;
//         second = curr;
//     }

//     return second;
// }

// int minCost(vector<int> &cost, int n)
// {
//     return min(solveRec(cost, n - 1), solveRec(cost, n - 2));
// }

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________
// Write a program to find the minimum number of coins:
// int solveRec(vector<int> &num, int tar)
// {
//     if (tar == 0)
//     {
//         return 0;
//     }

//     int ans = INT_MAX;

//     for (int i = 0; i < num.size(); i++)
//     {
//         if (tar - num[i] >= 0)
//             ans = min(ans, 1 + solveRec(num, tar - num[i]));
//     }

//     return ans;
// }

// // Using memoization:
// int solveMem(vector<int> &num, int tar, vector<int> &dp)
// {
//     if (tar == 0)
//     {
//         return 0;
//     }

//     if (dp[tar] != -1)
//     {
//         return dp[tar];
//     }

//     int ans = INT_MAX;

//     for (int i = 0; i < num.size(); i++)
//     {
//         if (tar - num[i] >= 0)
//         {
//             ans = min(ans, 1 + solveMem(num, tar - num[i], dp));
//         }
//     }

//     return dp[tar] = ans;
// }

// // Using tabulation:
// int solveTab(vector<int> &num, int tar)
// {
//     vector<int> dp(tar + 1, INT_MAX);

//     dp[0] = 0;
//     for (int i = 1; i <= tar; i++)
//     {
//         int ans = INT_MAX;
//         for (int j = 0; j < num.size(); j++)
//         {
//             if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
//                 ans = min(ans, 1 + dp[i - num[j]]);
//         }
//     }

//     if (dp[tar] == INT_MAX)
//     {
//         return -1;
//     }
//     else
//     {
//         return dp[tar];
//     }
// }

// int main()
// {
//     return 0;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________
// Write a program to find the maximum sum of two non adjacent elements.

// int solveRec(vector<int> &nums, int i)
// {
//     if (i >= nums.size())
//     {
//         return 0;
//     }

//     int include = nums[i] + solveRec(nums, i + 2);
//     int exclude = 0 + solveRec(nums, i + 1);
//     return max(include, exclude);
// }

// int solve(vector<int> &nums, int i)
// {
//     if (i == 0)
//     {
//         return nums[0];
//     }

//     if (i < 0)
//     {
//         return 0;
//     }

//     int include = nums[i] + solve(nums, i - 2);
//     int exclude = 0 + solve(nums, i - 1);
//     return max(include, exclude);
// }

// // Using memoization:
// int solveMem(vector<int> &nums, int i, vector<int> &dp)
// {
//     if (i == 0)
//     {
//         return nums[0];
//     }
//     if (i < 0)
//     {
//         return 0;
//     }
//     if (dp[i] != -1)
//     {
//         return dp[i];
//     }

//     int include = nums[i] + solveMem(nums, i - 2, dp);
//     int exclude = 0 + solveMem(nums, i - 1, dp);

//     return dp[i] = max(include, exclude);
// }

// // Using tabulation:
// int solveTab(vector<int> &nums, int n)
// {
//     vector<int> dp(n, 0);

//     dp[0] = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int include = nums[i] + dp[i - 2];
//         int exclude = 0 + dp[i - 1];

//         dp[i] = max(include, exclude);
//     }

//     return dp[n - 1];
// }

// // Using space optimization:
// int solveSO(vector<int> &nums, int n)
// {
//     int first = 0;
//     int second = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int include = nums[i] + first;
//         int exclude = 0 + second;

//         int curr = max(include, exclude);
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     // int n = nums.size();
//     // int ans = solve(nums, n - 1);
//     // return ans;

//     vector<int> dp(nums.size(), -1);
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________
// Write a program to solve the house robbery problem.

// Using space optimization:
// long long int solveSO(vector<long long int> &nums, long long int n)
// {
//     long long int first = 0;
//     long long int second = nums[0];

//     for (long long int i = 1; i < n; i++)
//     {
//         long long int include = nums[i] + first;
//         long long int exclude = 0 + second;

//         long long int curr = max(include, exclude);
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// long long int houseRobber(vector<long long int> &valueInHouse)
// {
//     if (valueInHouse.size() == 1)
//     {
//         return valueInHouse[0];
//     }

//     vector<long long int> first;
//     vector<long long int> second;

//     for (long long int i = 0; i < valueInHouse.size(); i++)
//     {
//         if (i != 0)
//         {
//             second.push_back(valueInHouse[i]);
//         }
//         else if (i != valueInHouse.size() - 1)
//         {
//             first.push_back(valueInHouse[i]);
//         }
//     }

//     return max(solveSO(first, first.size()), solveSO(second, second.size()));
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to solve the rod cutting problem.
// int solveRec(int n, int x, int y, int z)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     if (n < 0)
//     {
//         return INT_MIN;
//     }

//     int a = 1 + solveRec(n - x, x, y, z);
//     int b = 1 + solveRec(n - y, x, y, z);
//     int c = 1 + solveRec(n - z, x, y, z);

//     return max(a, max(b, c));
// }
// int solveMem(int n, int x, int y, int z, vector<int> &dp)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     if (n < 0)
//     {
//         return INT_MIN;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int a = 1 + solveMem(n - x, x, y, z, dp);
//     int b = 1 + solveMem(n - y, x, y, z, dp);
//     int c = 1 + solveMem(n - z, x, y, z, dp);

//     return dp[n] = max(a, max(b, c));
// }
// int solveTab(int n, int x, int y, int z)
// {
//     vector<int> dp(n + 1, INT_MIN);
//     dp[0] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         if (i - x >= 0)
//         {
//             dp[i] = max(dp[i], dp[i - x] + 1);
//         }
//         if (i - y >= 0)
//         {
//             dp[i] = max(dp[i], dp[i - y] + 1);
//         }
//         if (i - z >= 0)
//         {
//             dp[i] = max(dp[i], dp[i - z] + 1);
//         }
//     }

//     if (dp[n] < 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return dp[n];
//     }
// }

// int cutSegments(int n, int x, int y, int z)
// {
//     int ans = solveRec(n, x, y, z);
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to count the total number of derangements

// long long int countDerangements(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     else if (n == 1)
//     {
//         return 0;
//     }
//     else if (n == 2)
//     {
//         return 1;
//     }

//     return (n - 1) * (countDerangements(n - 2) + countDerangements(n - 1));
// }

// long long int solveMem(int n, vector<long long int> &dp)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     else if (n == 2)
//     {
//         return 1;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = (n - 1) * (solveMem(n - 1, dp) + solveMem(n - 2, dp));
// }

// // Using tabulation:
// long long int solveMem(int n)
// {
//     vector<long long int> dp(n + 1, 0);
//     dp[0] = 0;
//     dp[1] = 0;
//     dp[2] = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
//     }

//     return dp[n];
// }

// // Using space optimization:
// long long int solveSO(int n)
// {
//     int first = 0;
//     int second = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         int curr = (i - 1) * (first + second);
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// __________________________________________________________________________________________________________________
// __________________________________________________________________________________________________________________

// Write a program to solve the painting fence algorithm.
// int solveRec(int n, int k)
// {
//     if (n == 1)
//     {
//         return k;
//     }
//     if (n == 2)
//     {
//         return k * (k - 1);
//     }

//     return ((k - 1) * solveRec(n - 2, k) + (k - 1) * solveRec(n - 1, k));
// }

// int solveMem(int n, int k, vector<int> &dp)
// {
//     if (n == 1)
//     {
//         return k;
//     }
//     if (n == 2)
//     {
//         return k * (k - 1);
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = ((k - 1) * solveRec(n - 2, k) + (k - 1) * solveRec(n - 1, k));
// }

// // Using tabulation
// int solveTab(int n, int k)
// {
//     vector<int> dp(n + 1, 0);
//     dp[1] = k;
//     dp[2] = k * (k - 1);

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (k - 1) * dp[i - 2] + (k - 1) * dp[i - 1];
//     }

//     return dp[n];
// }

// // Using space optimization:
// int solveSO(int n, int k)
// {
//     int first = k;
//     int second = k * (k - 1);

//     for (int i = 3; i <= n; i++)
//     {
//         int curr = (k - 1) * first + (k - 2) * second;

//         first = second;
//         second = curr;
//     }

//     return second;
// }