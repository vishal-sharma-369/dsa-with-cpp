#include <iostream>
#include <bits/stdc++.h>

/*
pointers
recursion
dp
*/

using namespace std;

/*
Those who forget the past are condemned to repeat it.
*/
/*
top - down : recursion + memoisation
bottom - up : tabulation
spaceoptimization
*/

// int fibonacci(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }

//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int fibonacci(int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return dp[n];
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
// }

// int fibonacci(int n)
// {
//     int first = 0;
//     int second = 1;
//     int curr;

//     for (int i = 2; i <= n; i++)
//     {
//         curr = first + second;

//         first = second;
//         second = curr;
//     }

//     return curr;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> dp(n, -1);
//     dp[0] = 0;
//     dp[1] = 1;
//     fibonacci(10, dp);
//     return 0;
// }

/*
recursion follows the top to down approach .
tabulation follows the bottom to up approach.
*/

// int solve(long long nStairs, int i)
// {
//     if (i == nStairs)
//     {
//         return 1;
//     }
//     if (i > nStairs)
//     {
//         return 0;
//     }
//     return (solve(nStairs, i + 1) + solve(nStairs, i + 2));
// }

// int main()
// {
//     return 0;
// }

// int solve(vector<int> &cost, int n)
// {
//     // BASE case
//     if (n == 0)
//     {
//         return cost[0];
//     }
//     if (n == 1)
//     {
//         return cost[1];
//     }

//     int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
//     return ans;
// }

// int solve2(vector<int> &cost, int n, vector<int> &dp)
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

//     dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
//     return dp[n];
// }

// int minCostClimbingStairs(vector<int> &cost)
// {
//     int n = cost.size();

//     vector<int> dp(n + 1, -1);
//     int ans = min(solve(cost, n - 1), solve(cost, n - 2));
//     return ans;
// }

// // Solving the same problem using tabulation.
// int solve3(vector<int> &cost, int n)
// {
//     // step1 : creation of dp array
//     vector<int> dp(n + 1);

//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//     }

//     return min(dp[n - 1], dp[n - 2]);
// }
// // The time complexity of this solution is O(n).
// // The space complexity of this solution is O(n).

// // space optimization
// int solve3(vector<int> &cost, int n)
// {
//     int first = cost[0];
//     int second = cost[1];

//     int curr;
//     for (int i = 0; i < n; i++)
//     {
//         curr = min(first, second) + cost[i];

//         first = second;
//         second = curr;
//     }

//     return min(curr, second);
// }

// int main()
// {
//     return 0;
// }

// recursion -> memoization -> tabulation -> space optimization
// int solveRec(vector<int> &num, int x)
// {
//     if (x == 0)
//         return 0;

//     if (x < 0)
//         return INT_MAX;

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

// int solveMem(vector<int> &num, int x, vector<int> &dp)
// {
//     if (x == 0)
//         return 0;

//     if (x < 0)
//         return INT_MAX;

//     if (dp[x] != -1)
//     {
//         return dp[x];
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
//     dp[x] = mini;

//     return mini;
// }
// // Time complexity of this solution is O(x * n).

// int solveTab(vector<int> &num, int x, vector<int> &dp)
// {
//     vector<int> dp(x + 1, INT_MAX);
//     dp[0] = 0;

//     for (int i = 1; i <= x; i++)
//     {
//         for (int j = 0; j < num.size(); j++)
//         {
//             if (i - num[j] >= 0 && dp[i] - num[j] != INT_MAX)
//                 dp[i] = min(dp[i], 1 + dp[i - num[j]]);
//         }
//     }

//     if (dp[x] == INT_MAX)
//     {
//         return -1;
//     }
//     return dp[x];
// }
// // Time complexity of this solution is O(x * n).
// // Space complexity of this solution is O(x).

// int main()
// {
//     int x;
//     vector<int> num;
//     vector<int> dp(x + 1, -1);
//     int ans = solveMem(num, x, dp);

//     if (ans == INT_MAX)
//         return -1;
//     else
//         return ans;
//     return 0;
// }

// int solve(vector<int> &nums, int n)
// {
//     if (n < 0)
//         return 0;
//     if (n == 0)
//         return nums[0];

//     int incl = solve(nums, n - 2) + nums[n];
//     int excl = solve(nums, n - 1) + 0;

//     return max(incl, excl);
// }

// int solveMem(vector<int> &nums, int n, vector<int> &dp)
// {
//     if (n < 0)
//         return 0;
//     if (n == 0)
//         return nums[0];
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int incl = solve(nums, n - 2) + nums[n];
//     int excl = solve(nums, n - 1) + 0;

//     dp[n] = max(incl, excl);
//     return max(incl, excl);
// }

// int solveTab(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(nums.size() + 1, 0);
//     dp[0] = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = dp[i - 2] + nums[i];
//         int excl = dp[i - 1] + 0;

//         dp[i] = max(incl, excl);
//     }

//     return dp[n - 1];
// }
// // Time complexity of this solution is O(n).
// // Space complexity of this solution is O(n) + O(n).

// int maximumNonAdjacent(vector<int> &nums)
// {
//     // int n = nums.size();
//     // int ans = solve(nums, n - 1);
//     // return ans;

//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return solveMem(nums, n - 1, dp);
// }

// int main()
// {
//     return 0;
// }

// recursion -> memoization -> tabulation -> space optimization

// int fibonacci(int n)
// {
//     if (n == 1 || n == 0)
//     {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int fibonacci(int n)
// {
//     if (n == 1 || n == 0)
//     {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int fib(int n, vector<int> &dp)
// {
//     if (dp[n])
//     {
//         return dp[n];
//     }
//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }

// int fib(int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = 0;
//     dp[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[n];
// }

// int minStairs(int n, int i)
// {
//     if (i == n)
//     {
//         return 1;
//     }
//     else if (i > n)
//     {
//         return 0;
//     }
//     return minStairs(n, i + 1) + minStairs(n, i + 2);
// }

// int minStairs(int n, vector<int> &dp)
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

//     return dp[n] = minStairs(n - 1, dp) + minStairs(n - 2, dp);
// }

// int minStaTab(int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// class solution
// {
// public:
//     int solve(vector<int> &cost, int n, vector<int> &dp)
//     {
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

//         dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
//         return dp[n];
//     }

//     int minCostClimbingStairs(vector<int> &cost)
//     {
//         int n = cost.size();

//         vector<int> dp(n + 1, -1);

//         // it can be simplified more -> homework
//         int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
//         return ans;
//     }
// };
// // time complexity : O(n).

// // Solving the same problem using tabulation method.
// int solve3(vector<int> &cost, int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//     }

//     return min(dp[n - 1], dp[n - 2]);
// }

// int solve4(vector<int> &cost, int n)
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

// // using the space optimization technique
// int solve5(vector<int> &cost, int n)
// {
//     int first = cost[0];
//     int second = cost[1];
//     int curr;

//     for (int i = 2; i < n; i++)
//     {
//         curr = min(first, second) + cost[i];
//         first = second;
//         second = curr;
//     }

//     return min(curr, second);
// }
// // Time complexity of this solution is O(n).
// // Space complexity of this solution is O(n).

// // Minimum number of coins to make a target.
// int minimumNumberOfCoins(int target, vector<int> &coins)
// {
//     if (target == 0)
//     {
//         return 0;
//     }
//     else if (target < 0)
//     {
//         return INT_MAX;
//     }

//     int mini = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         int ans = minimumNumberOfCoins(target - coins[i], coins) + 1;
//         if (ans != INT_MAX)
//             mini = min(mini, minimumNumberOfCoins(target - coins[i], coins) + 1);
//     }

//     return mini;
// }
// // Time complexity of this solution is exponential.
// // Space complexity of this solution is pata nahi.

// int solveMem(vector<int> &num, int x, vector<int> &dp)
// {
//     // base case
//     if (x == 0)
//     {
//         return 0;
//     }
//     if (x < 0)
//     {
//         return INT_MAX;
//     }
//     if (dp[x] != -1)
//     {
//         return dp[x];
//     }
//     int mini = INT_MAX;
//     for (int i = 0; i < num.size(); i++)
//     {
//         int ans = solveMem(num, x - num[i], dp);

//         if (ans != INT_MAX)
//             mini = min(mini, 1 + ans);
//     }
//     dp[x] = mini;
//     return mini;
// }

// int solveTab(vector<int> &num, int x)
// {
//     vector<int> dp(x + 1, INT_MAX);
//     dp[0] = 0;

//     for (int i = 1; i <= x; i++)
//     {
//         for (int j = 0; j < num.size(); j++)
//         {
//             if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
//                 dp[i] = min(dp[i], 1 + dp[i - num[j]]);
//         }
//     }

//     if (dp[x] == INT_MAX)
//     {
//         return -1;
//     }

//     return dp[x];
// }

// // There is no space optimized solution for this problem.

// int main()
// {
//     // int n;
//     // cin >> n;

//     // vector<int> dp(n + 1, -1);
//     // dp[0] = 0;
//     // dp[1] = 1;

//     // int n;
//     // cin >> n;

//     // vector<int> dp(n + 1, -1);

//     // dp[0] = 1;
//     // minStairs(n, dp);

//     int n;
//     cin >> n; // here n denotes the total amount to be made.

//     vector<int> dp(n + 1, -1);
//     vector<int> num;

//     int ans = solveMem(num, n, dp);

//     return 0;
// }

// Write a program to find the maximum sum of non adjacent elements.

// int solve(vector<int> &nums, int n)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     if (n == 0)
//     {
//         return nums[n];
//     }

//     int incl = solve(nums, n - 2) + nums[n];
//     int excl = solve(nums, n - 1) + 0;

//     return max(incl, excl);
// }
// int solveMem(vector<int> &nums, int n, vector<int> &dp)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     if (n == 0)
//     {
//         return nums[n];
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int incl = solve(nums, n - 2) + nums[n];
//     int excl = solve(nums, n - 1) + 0;

//     return dp[n] = max(incl, excl);
// }

// int maximumNonAdjacent(vector<int> &nums)
// {
//     // int n = nums.size();
//     // int ans = solve(nums, n - 1);
//     // return ans;

//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return solveMem(nums, n - 1, dp);
// }

// int solveTab(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, 0);

//     dp[0] = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = dp[i - 2] + nums[i];
//         int excl = dp[i - 1] + 0;
//         dp[i] = max(incl, excl);
//     }

//     return dp[n - 1];
// }

// int solveTab(vector<int> &nums)
// {
//     int n = nums.size();

//     int first = 0;
//     int second = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = first + nums[i];
//         int excl = second + 0;
//         int ans = max(incl, excl);
//         first = second;
//         second = ans;
//     }

//     return second;
// }

// long long int houseRobber(vector<int> &valueInHouse)
// {
//     int n = valueInHouse.size();
//     if (n == 1)
//     {
//         return valueInHouse[0];
//     }

//     vector<int> first, second;
//     for (int i = 0; i < n; i++)
//     {
//         if (i != n - 1)
//         {
//             first.push_back(valueInHouse[i]);
//         }
//         if (i != 0)
//         {
//             second.push_back(valueInHouse[i]);
//         }
//     }

//     return max(solveTab(first), solveTab(second));
// }
// Time complexity : O(n).
// Space complexity : O(n).

// int solve(int n, int x, int y, int z)
// {
//     if (n == 0)
//         return 0;
//     if (n < 0)
//     {
//         return INT_MIN;
//     }

//     int a = solve(n - x, x, y, z) + 1;
//     int b = solve(n - y, x, y, z) + 1;
//     int c = solve(n - z, x, y, z) + 1;

//     return max(a, max(b, c));
// }

// int cutSegments(int n, int x, int y, int z)
// {
//     int ans = solve(n, x, y, z);
//     if (ans < 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return ans;
//     }
// }

// int solveTab(int n, int x, int y, int z)
// {
//     vector<int> dp(n + 1, INT_MIN);
//     dp[0] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         if (i - x >= 0)
//             dp[i] = max(dp[i], dp[i - x] + 1);
//         if (i - y >= 0)
//             dp[i] = max(dp[i], dp[i - y] + 1);
//         if (i - z >= 0)
//             dp[i] = max(dp[i], dp[i - z] + 1);
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

// // Write a program to solve the count derangements problem.
// long long int countDerangements(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }

//     int ans = (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));

//     return ans;
// }

// long long int solveMem(int n, vector<long long int> &dp)
// {
//     if (n == 1)
//     {
//         return 0;
//     }

//     if (n == 2)
//     {
//         return 1;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     dp[n] = (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));

//     return dp[n];
// }

// long long int solveTab(int n)
// {
//     vector<long long int> dp(n + 1, 0);
//     dp[1] = 0;
//     dp[2] = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         long long int first = dp[n - 1];
//         long long int second = dp[n - 2];
//         long long int sum = (first + second);
//         long long int ans = (i - 1) * sum;
//         dp[i] = ans;
//     }

//     return dp[n];
// }

// // using the space optimized solution
// long long int solveSp(int n)
// {
//     long long int first = 0;
//     long long int second = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         long long int sum = first + second;
//         long long int ans = (i - 1) * sum;

//         first = second;
//         second = ans;
//     }

//     return second;
// }
// // Time complexity : O(n).
// // Space complexity : O(1).

// long long int countDerangements(int n)
// {
//     vector<long long int> dp(n + 1, -1);
//     return solveMem(n, dp);
// }

// #define MOD 1000000007

// int add(int a, int b)
// {
//     return (a % MOD + b % MOD) % MOD;
// }

// int mul(int a, int b)
// {
//     return ((a % MOD) * (b % MOD)) % MOD;
// }

// int solve(int n, int k, vector<int> &dp)
// {
//     if (n == 1)
//     {
//         return k;
//     }
//     if (n == 2)
//     {
//         return add(k, mul(k, k - 1));
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     dp[n] = add(mul(solve(n - 1, k, dp), k), mul(solve(n - 1, k, dp), k - 1));
//     return dp[n];
// }

// int solveTab(int n, int k)
// {
//     vector<int> dp(n + 1, 0);
//     dp[1] = k;
//     dp[2] = add(k, mul(k, k - 1));
//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
//     }
//     return dp[n];
// }
// // Time complexity of this solution is O(n).
// // Space complexity of this solution is O(n).

// // using space optimized technique
// int solveTab(int n, int k)
// {
//     int first = k;
//     int second = k * (k - 1);
//     for (int i = 3; i <= n; i++)
//     {
//         int curr = (first * (k - 1)) + (second * (k - 1));
//         first = second;
//         second = curr;
//     }
//     return second;
// }

// int numberOfWays(int n, int k)
// {
//     // Write your code here.
//     vector<int> dp(n + 1, -1);
//     return solve(n, k, dp);
// }

// // Write a program to solve the knapsack problem.
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
// {
//     // base case
//     // if only 1 item to steal , then just compare with the knapsack capacity.
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

//     int include;
//     if (weight[index] <= capacity)
//     {
//         include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
//     }

//     int exclude = 0 + solve(weight, value, index - 1, capacity);

//     int ans = max(include, exclude);
//     return ans;
// }
// int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
// {
//     // base case
//     // if only 1 item to steal , then just compare with the knapsack capacity.
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

//     int include;
//     if (weight[index] <= capacity)
//     {
//         include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
//     }

//     int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

//     dp[index][capacity] = max(include, exclude);
//     return dp[index][capacity];
// }

// int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

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

//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             int include = 0;
//             if (weight[index] <= w)
//             {
//                 include = value[index] + dp[index - 1][w - weight[index]];
//             }

//             int exclude = 0 + dp[index - 1][w];

//             dp[index][w] = max(exclude, include);
//         }
//     }

//     return dp[n - 1][capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
// {
//     vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
//     return solveMem(weight, value, n - 1, maxWeight, dp);
// }

// Write a program to solve the combination sum problem.
// int solve(vector<int> &num, int tar)
// {
//     if (tar < 0)
//     {
//         return 0;
//     }
//     if (tar == 0)
//     {
//         return 1;
//     }

//     int ans = 0;

//     for (int i = 0; i < num.size(); i++)
//     {
//         ans += solve(num, tar - num[i]);
//     }

//     return ans;
// }
// int solveMem(vector<int> &num, int tar, vector<int> &dp)
// {
//     if (tar < 0)
//     {
//         return 0;
//     }
//     if (tar == 0)
//     {
//         return 1;
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

// int solveTab(vector<int> &num, int tar)
// {
//     vector<int> dp(tar + 1, 0);
//     dp[0] = 1;

//     for (int i = 1; i <= tar; i++)
//     {
//         for (int j = 0; j < num.size(); j++)
//         {
//             if (i - num[j] >= 0)
//                 dp[i] += dp[i - num[j]];
//         }
//     }

//     return dp[tar];
// }

// int findWays(vector<int> &num, int tar)
// {
//     vector<int> dp(tar + 1, -1);
//     return solveMem(num, tar, dp);
// }

// class solution
// {
// public:
//     int solve(int n)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         int ans = n;
//         for (int i = 1; i * i <= n; i++)
//         {
//             ans = min(ans, 1 + solve(n - i * i));
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
//         int ans = n;
//         for (int i = 1; i * i <= n; i++)
//         {
//             ans = min(ans, 1 + solve(n - i * i));
//         }
//         dp[n] = ans;
//         return ans;
//     }

//     int solveMem(int n)
//     {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;

//         for (int i = 2; i <= n; i++)
//         {
//             for (int j = 1; j * j <= n; j++)
//             {
//                 int temp = j * j;
//                 if (i - temp >= 0)
//                     dp[i] = min(dp[i], 1 + dp[i - temp]);
//             }
//         }

//         return dp[n];
//     }

//     int MinSquares(int n)
//     {
//         vector<int> dp;
//     }
// };

// int solve(int n, vector<int> &days, vector<int> &cost, int index)
// {
//     if (index >= n)
//     {
//         return 0;
//     }

//     int option1 = cost[0] + solve(n, days, cost, index + 1);

//     // 7 day pass
//     int i;
//     for (i = index; i < n && days[i] < days[index] + 7; i++)
//         ;

//     int option2 = cost[1] + solve(n, days, cost, i);

//     // 30 days pass
//     for (i = index; i < n && days[i] < days[index] + 30; i++)
//         ;

//     int option3 = cost[2] + solve(n, days, cost, i);

//     return min_element(option1, option2, option3);
// }

// int solv//////eMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
// {
//     if (index >= n)
//     {
//         return 0;
//     }

//     if (dp[index] != -1)
//     {
//         return dp[index];
//     }

//     int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp);

//     // 7 day pass
//     int i;
//     for (i = index; i < n && days[i] < days[index] + 7; i++)
//         ;

//     int option2 = cost[1] + solveMem(n, days, cost, i, dp);

//     // 30 days pass
//     for (i = index; i < n && days[i] < days[index] + 30; i++)
//         ;

//     int option3 = cost[2] + solveMem(n, days, cost, i, dp);

//     dp[index] = min_element(option1, option2, option3);
//     return dp[index];
// }
// int solveTab(int n, vector<int> &days, vector<int> &cost, int index)
// {
//     vector<int> dp(n + 1, INT_MAX);
//     dp[n] = 0;

//     for (int k = n - 1; k >= 0; k--)
//     {
//     }
// }

// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     vector<int> dp(n + 1, -1);

//     return solve(n, days, cost, 0);
// }

// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     int ans = 0;

//     queue<pair<int, int>> month;
//     queue<pair<int, int>> week;

//     for (int day : days)
//     {
//         // step1 : remove expired days
//         while (!month.empty() && month.front().first + 30 <= day)
//         {
//             month.pop();
//         }

//         while (!week.empty() && week.front().first + 7 <= day)
//         {
//             week.pop();
//         }

//         week.push(make_pair(day, ans + cost[1]));
//         month.push(make_pair(day, ans + cost[2]));

//         ans = min(ans + cost[0], min(week.front().second, month.front().second));
//     }

//     return ans;
// }

// Write a program to solve the maximal square problem.
// class solution
// {
// public:
//     int solve(vector<vector<int>> mat, int i, int j, int &maxi)
//     {
//         if (i >= mat.size() || j >= mat[0].size())
//         {
//             return 0;
//         }
//         int right = solve(mat, i, j + 1, maxi);
//         int diagonal = solve(mat, i + 1, j + 1, maxi);
//         int down = solve(mat, i + 1, j, maxi);

//         if (mat[i][j] == '1')
//         {
//             int ans = 1 + min(right, min(down, diagonal));
//             maxi = max(maxi, ans);
//             return ans;
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     // This solution uses 2Dp because it has two variables that are changing in the recursie calls.
//     int solveMem(vector<vector<int>> mat, int i, int j, int &maxi, vector<vector<int>> &dp)
//     {
//         if (i >= mat.size() || j >= mat[0].size())
//         {
//             return 0;
//         }

//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         int right = solveMem(mat, i, j + 1, maxi, dp);
//         int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
//         int down = solveMem(mat, i + 1, j, maxi, dp);

//         if (mat[i][j] == 1)
//         {
//             dp[i][j] = 1 + min(right, min(diagonal, down));

//             maxi = max(maxi, dp[i][j]);
//             return dp[i][j];
//         }
//         else
//         {
//             return dp[i][j] = 0;
//         }
//     }

//     int solveTab(vector<vector<int>> &mat, int &maxi)
//     {
//         int row = mat.size();
//         int col = mat[0].size();
//         vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

//         for (int i = row - 1; i >= 0; i--)
//         {
//             for (int j = col - 1; j >= 0; j--)
//             {
//                 int right = dp[i][j + 1];
//                 int diagonal = dp[i + 1][j + 1];
//                 int down = dp[i + 1][j];

//                 if (mat[i][j] == 1)
//                 {
//                     dp[i][j] = 1 + min(right, min(diagonal, down));

//                     maxi = max(maxi, dp[i][j]);
//                 }
//                 else
//                 {
//                     dp[i][j] = 0;
//                 }
//             }
//         }

//         return dp[row][col];
//     }

//     // Time complexity of this solution is O(m * n)

//     // The space optimized solution of this problem would be:

//     int maxSquare(int n, int m, vector<vector<int>> mat)
//     {
//         int maxi = 0;
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         solveMem(mat, 0, 0, maxi, dp);

//         return maxi;
//     }
// };

// Write a program to find the Minimum Score Triangulation of Polygon.
// class solution
// {
// public:
//     int solve(vector<int> &v, int i, int j)
//     {
//         if (i + 1 == j)
//         {
//             return 0;
//         }

//         int ans = INT_MAX;
//         for (int k = i + 1; k < j; k++)
//         {
//             ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
//         }

//         return ans;
//     }

//     int minScoreTriangle(vector<int> &values)
//     {
//         int n = values.size();
//         return solve(values, 0, n - 1);
//     }
// };

// // Starting again:
// /*
// pointers
// recursion

// top - down : recursion + memoization
// bottom - up : tabulation
// */

// int fibonacci(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

// // This is the top to down approach to solve this problem.
// int fibonacci(int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
// }

// // This is the bottom to up approach to solve this problem.
// int fibonacci(int n)
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

// int fibonacci(int n)
// {
//     int first = 0;
//     int second = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         int curr = first + second;
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// // This is the space optimized solution of this problem.

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> dp(n, -1);

//     fibonacci(n, dp);
//     return 0;
// }

// // The number of ways to reach the top
// int nHeight(int n, vector<int> &dp)
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

//     return dp[n] = nHeight(n - 1) + nHeight(n - 2);
// }

// // soling the same problem using the tabulation method:
// int solveTab(int n)
// {
//     vector<int> dp(n + 1, 0);
//     dp[0] = 1;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// int solveTab(int n)
// {
//     int first = 0;
//     int second = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         int curr = first + second;
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// int nHeight(int n)
// {
//     vector<int> dp(n + 1, -1);

//     nHeight(n, dp);
// }

// // Write a program to find the minimum cost of climbing the stairs
// int solve(int n, vector<int> &cost)
// {
//     if (n == 0)
//     {
//         return cost[0];
//     }
//     else if (n == 1)
//     {
//         return cost[1];
//     }

//     int ans = min(solve(n - 1, cost), solve(n - 2, cost)) + cost[n];

//     return ans;
// }

// int minimumCost(vector<int> &cost, int n)
// {
//     if (n <= 1)
//     {
//         return 0;
//     }

//     return min(solve(n - 1, cost), solve(n - 2, cost));
// }

// // Solving the same problem using tabulation:
// int solve(vector<int> &cost, int n)
// {
//     vector<int> dp(n + 1, 0);
//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//     }

//     return min(dp[n - 1], dp[n - 2]);
// }

// // solving the same problem using the space optimization technique
// int solve(vector<int> &cost, int n)
// {
//     int first = cost[0];
//     int second = cost[1];

//     for (int i = 2; i <= n; i++)
//     {
//         int curr = min(first, second) + cost[i];
//         first = second;
//         second = curr;
//     }

//     return second;
// }

// Minimum number of coins to make an amount.

// int minimumElements(vector<int> &num, int x)
// {

//     if (x < 0)
//     {
//         return INT_MAX;
//     }
//     if (x == 0)
//     {
//         return 0;
//     }

//     int ans = INT_MAX;
//     for (int i = 0; i < num.size(); i++)
//     {
//         ans = min(ans, minimumElements(num, x - num[i]) + 1);
//     }

//     return ans;
// }

// int solveMem(vector<int> &dp, vector<int> &num, int x)
// {
//     if (x < 0)
//     {
//         return INT_MAX;
//     }

//     if (x == 0)
//     {
//         return 0;
//     }
//     if (dp[x] != -1)
//     {
//         return dp[x];
//     }

//     int ans = INT_MAX;
//     for (int i = 0; i < num.size(); i++)
//     {
//         if (solveMem(dp, num, x - num[i]) != INT_MAX)
//             ans = min(ans, solveMem(dp, num, x - num[i] + 1));
//     }
//     dp[x] = ans;
//     return ans;
// }

// // solving the same problem using tabulation.
// int solveTab(vector<int> &num, int x)
// {
//     vector<int> dp(x + 1, INT_MAX);
//     dp[0] = 0;

//     for (int i = 1; i <= x; i++)
//     {
//         int ans = INT_MAX;
//         for (int j = 0; j < num.size(); j++)
//         {
//             if (x - num[j] >= 0 && dp[x - num[j]] != INT_MAX)
//                 ans = min(ans, dp[x - num[j]] + 1);
//         }
//         dp[i] = ans;
//     }

//     if (dp[x] == INT_MAX)
//     {
//         return -1;
//     }
//     return dp[x];
// }

// // The space optimized solution is not possible for this problem.

// int minimumElements(vector<int> &num, int x)
// {
// }

// // Write a program to find the maximum sum of non adjacent elements
// int maxSum(vector<int> elements, int i)
// {
//     if (i < 0)
//     {
//         return 0;
//     }
//     if (i == 0)
//     {
//         return elements[i];
//     }

//     int incl = maxSum(elements, i - 2) + elements[i];

//     int excl = maxSum(elements, i - 1) + 0;

//     return max(incl, excl);
// }

// int solveMem(vector<int> elements, int i, vector<int> &dp)
// {
//     if (i < 0)
//     {
//         return 0;
//     }
//     if (i == 0)
//     {
//         return elements[i];
//     }

//     if (dp[i] != -1)
//     {
//         return dp[i];
//     }

//     int incl = maxSum(elements, i - 2) + elements[i];

//     int excl = maxSum(elements, i - 1) + 0;

//     return dp[i] = max(incl, excl);
// }

// int solveTab(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, 0);

//     dp[0] = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = dp[i - 2] + nums[i];
//         int excl = dp[i - 1] + 0;
//         dp[i] = max(incl, excl);
//     }

//     return dp[n - 1];
// }

// // Using the space optimized solution
// int solveTab(vector<int> &nums)
// {
//     int n = nums.size();
//     int first = 0;
//     int second = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = nums[i] + max(first, second);
//         int excl = 0 + max(first, second);
//         int curr = max(incl, excl);

//         first = second;
//         second = curr;
//     }
//     return second;
// }
// // The time complexity of this solution is O(n).
// // The space complexity of this solution is O(1).

// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     solveMem(nums, n - 1, dp);
// }

// Those who forget the past are condemned to repeat it.
// int fibonacci(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int solve(int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return n;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
// }

// int calculateFib(int n)
// {
//     vector<int> dp(n + 1, -1);
//     return solve(n, dp);
// }

// // Using tabulation
// int solveTab(int n)
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
// // The time complexity of this solution is O(n).
// // The space complexity of this solution is O(n).

// int solveTab(int n)
// {
//     int first = 0;
//     int second = 1;

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

// Write a program to find all number of distinct steps required to reach the nth stair
// int solve(int n)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     if (n == 0)
//     {
//         return 1;
//     }

//     return solve(n - 1) + solve(n - 2);
// }
// int solveMem(int n, vector<int> &dp)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     if (n == 0)
//     {
//         return 1;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp);
// }

// // Using tabulation : i.e. bottom up approach
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

//     return second;
// }

// int distinctSteps(int n)
// {
//     vector<int> dp(n + 1, -1);
// }

// // Write the same code the another way
// int solve(long long int nstairs, int i)
// {
//     if (i == nstairs)
//     {
//         return 1;
//     }
//     if (i > nstairs)
//     {
//         return 0;
//     }

//     return solve(nstairs, i + 1) + solve(nstairs, i + 2);
// }

// int main()
// {
//     return 0;
// }

// Write a program to find the minimum cost to climb the stairs
// int solve(vector<int> &cost, int n)
// {
//     if (n == 0)
//     {
//         return cost[0];
//     }
//     if (n == 1)
//     {
//         return cost[1];
//     }

//     return min(solve(cost, n - 2), solve(cost, n - 1)) + cost[n];
// }

// int solve(vector<int> &cost, int n, vector<int> &dp)
// {
//     if (n <= 1)
//     {
//         return cost[n];
//     }

//     if (dp[n] != 0)
//     {
//         return dp[n];
//     }

//     return dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
// }

// int minCostClimbingStairs(vector<int> &cost)
// {
//     // int n = cost.size();
//     // return min(solve(cost, n - 1), solve(cost, n - 2));
//     int n = cost.size();
//     vector<int> dp(n + 1, 0);
//     return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
// }

// // Using tabulation
// int solve(vector<int> &cost, int n)
// {
//     vector<int> dp(n + 1, -1);

//     dp[0] = cost[0];
//     dp[1] = cost[1];

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//     }

//     return dp[n];
// }

// // Using space optimization
// int solveTab(vector<int> &cost, int n)
// {
//     int first = cost[0];
//     int second = cost[1];

//     for (int i = 2; i <= n; i++)
//     {
//         int curr = min(first, second) + cost[i];

//         first = second;
//         second = curr;
//     }

//     return second;
// }

// int main()
// {
//     return 0;
// }

// Write a program to solve the coin change problem.
// int solve(vector<int> &coins, int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n < 0)
//     {
//         return INT_MAX;
//     }

//     int ans = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         if (solve(coins, n - coins[i]) != INT_MAX)
//             ans = min(ans, solve(coins, n - coins[i]) + 1);
//     }

//     return ans;
// }

// int solveMem(vector<int> &coins, int n, vector<int> &dp)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n < 0)
//     {
//         return INT_MAX;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int ans = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         if (solve(coins, n - coins[i]) != INT_MAX)
//             ans = min(ans, solve(coins, n - coins[i]) + 1);
//     }

//     dp[n] = ans;
//     return ans;
// }

// // Using tabulation
// int solveTab(vector<int> &coins, int n)
// {
//     vector<int> dp(n + 1, -1);

//     dp[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int ans = INT_MAX;
//         for (int j = 0; j < coins.size(); j++)
//         {
//             if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
//                 ans = min(ans, dp[i - coins[j]] + 1);
//         }

//         dp[i] = ans;
//     }

//     return dp[n];
// }

// // Using space optimization is not applicable to this problem.

// int minimumCoins(vector<int> &coins, int target)
// {
//     vector<int> dp(target + 1, -1);
//     return solveMem(coins, target, dp);
// }

// Write a program to find the maximum sum of non adjacent elements
// int solve(vector<int> &nums, int n)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     else if (n == 0)
//     {
//         return nums[0];
//     }

//     int incl = nums[n] + solve(nums, n - 2);
//     int excl = 0 + solve(nums, n - 1);

//     return max(incl, excl);
// }

// int solveMem(vector<int> &nums, int n, vector<int> &dp)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     else if (n == 0)
//     {
//         return nums[0];
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int incl = nums[n] + solveMem(nums, n - 2, dp);
//     int excl = 0 + solveMem(nums, n - 1, dp);

//     return dp[n] = max(incl, excl);
// }

// // Using tabulation
// int solveTab(vector<int> &nums, int n, vector<int> &dp)
// {
//     vector<int> dp(nums.size(), 0);
//     dp[0] = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = nums[i] + dp[i - 2];
//         int excl = 0 + dp[i - 1];
//         int ans = max(incl, excl);
//         dp[i] = ans;
//     }

//     return dp[nums.size() - 1];
// }

// // Using space optimization
// int solveSO(vector<int> &nums, int n)
// {
//     int first = 0;
//     int second = nums[0];

//     for (int i = 1; i < n; i++)
//     {
//         int incl = nums[i] + first;
//         int excl = 0 + second;

//         int curr = max(incl, excl);

//         first = second;
//         second = curr;
//     }

//     return second;
// }

// // int maximuNonAdjacentSum(vector<int> &nums)
// // {
// //     vector<int> dp(nums.size(), -1);
// //     return solveMem(nums, nums.size() - 1, dp);
// // }

// // int main()
// // {
// //     return 0;
// // }

// // Write a program to solve the house robbery problem.
// long long int houseRobber(vector<int> &valueInHouse)
// {
//     vector<int> first;
//     vector<int> second;
//     if (valueInHouse.size() == 1)
//     {
//         return valueInHouse[0];
//     }

//     for (int i = 0; i < valueInHouse.size(); i++)
//     {
//         if (i != 0)
//         {
//             second.push_back(valueInHouse[i]);
//         }
//         if (i != valueInHouse.size() - 1)
//         {
//             first.push_back(valueInHouse[i]);
//         }
//     }

//     return max(solveSO(first, first.size() - 1), solveSO(second, second.size() - 1));
// }

// int main()
// {
//     return 0;
// }

// Write a program to cut a rod into n segments.
// int solve(int n, int x, int y, int z)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n < 0)
//     {
//         return INT_MIN;
//     }

//     int a = solve(n - x, x, y, z) + 1;
//     int b = solve(n - y, x, y, z) + 1;
//     int c = solve(n - z, x, y, z) + 1;

//     int ans = max(a, max(b, c));
//     return ans;
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

//     int a = solve(n - x, x, y, z) + 1;
//     int b = solve(n - y, x, y, z) + 1;
//     int c = solve(n - z, x, y, z) + 1;

//     dp[n] = max(a, max(b, c));
//     return dp[n];
// }

// // Using tabulation:
// int solveTab(int n, int x, int y, int z)
// {
//     vector<int> dp(n + 1, INT_MIN);
//     dp[0] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         int a = INT_MIN;
//         if (i - x >= 0)
//         {
//             a = max(a, dp[i - x] + 1);
//         }
//         if (i - y >= 0)
//         {
//             a = max(a, dp[i - y] + 1);
//         }
//         if (i - z >= 0)
//         {
//             a = max(a, dp[i - z] + 1);
//         }

//         dp[i] = a;
//     }

//     return dp[n] >= 0 ? dp[n] : 0;
// }

// int cutSegments(int n, int x, int y, int z)
// {
//     // int ans = solve(n, x, y, z);
//     // if (ans < 0)
//     // {
//     //     return 0;
//     // }
//     // else
//     // {
//     //     return ans;
//     // }

//     vector<int> dp(n + 1, -1);
//     return solveMem(n, x, y, z, dp);
// }

// Write a program to count the total number of derangements.
/*
base cases:
f(1) -> 0
f(2) -> 1
*/
// #define MOD 1000000007
// long long int countDerangements(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }

//     return (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));
// }

// long long int solveMem(int n, vector<int> &dp)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = (n - 1) * (solveMem(n - 1, dp) + solveMem(n - 2, dp));
// }

// long long solveTab(int n)
// {
//     vector<int> dp(n + 1, 0);

//     dp[1] = 0;
//     dp[2] = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
//     }
//     return dp[n];
// }

// // Using so
// long long solveSO(int n)
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

// // Space complexity : O(1).

// Write a program to find the number of ways to paint the fence.

// int solve(int n, int k)
// {
//     if (n == 1)
//     {
//         return k;
//     }
//     if (n == 2)
//     {
//         return k * (k - 1);
//     }

//     return (solve(n - 1, k) * (k - 1) + solve(n - 2, k) * (k - 1));
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

//     return dp[n] = (solve(n - 1, k) * (k - 1) + solve(n - 2, k) * (k - 1));
// }

// // Using tabulation:
// int solveTab(int n, int k)
// {
//     vector<int> dp(n + 1, -1);
//     dp[1] = k;
//     dp[2] = k * (k - 1);

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (dp[i - 1] * (k - 1)) + (dp[i - 2] * (k - 1));
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
//         int curr = (first * (k - 1)) + (second * (k - 1));
//         first = second;
//         second = curr;
//     }
//     return second;
// }

// int numberOfWays(int n, int k)
// {
// }

// Write a program to solve the knapsack problem.
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
// {
//     if (index == 0)
//     {
//         if (weight[index] <= capacity)
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

//     int ans = max(exclude, include);
//     return ans;
// }

// int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
// {
//     if (index == 0)
//     {
//         if (weight[index] <= capacity)
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

//     int ans = max(exclude, include);
//     dp[index][capacity] = ans;
//     return ans;
// }

// // Using tabulation:
// int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

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

//     for (int i = 1; i < n; i++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             int include = 0;

//             if (weight[i] <= w)
//             {
//                 include = value[i] + dp[i - 1][capacity - weight[i]];
//             }

//             int exclude = 0 + dp[i - 1][w];

//             dp[i][w] = max(exclude, include);
//         }
//     }

//     return dp[n - 1][capacity];
// }

// // Using space optimization:
// long long int solveSO(vector<int> &weight, vector<int> &value, int n, int capacity)
// {
//     vector<int> first(capacity + 1, 0);
//     vector<int> second(capacity + 1, 0);

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

//     for (int index = 1; index < n; index++)
//     {
//         for (int w = 0; w <= capacity; w++)
//         {
//             int include = 0;
//             if (weight[index] <= w)
//             {
//                 include = value[index] + first[w - weight[index]];
//             }

//             int exclude = 0 + first[w];

//             int ans = max(exclude, include);
//             second[w] = ans;

//             first = second;
//             second = {0};
//         }
//     }

//     return first[capacity];
// }

// int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
// {
//     vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

//     return solveMem(weight, value, n - 1, maxWeight, dp);
// }

// Write a program to find the combination sum problem.
// int solve(vector<int> &num, int tar)
// {
//     if (tar < 0)
//     {
//         return 0;
//     }
//     else if (tar == 0)
//     {
//         return 1;
//     }

//     int ans = 0;
//     for (int i = 0; i < num.size(); i++)
//     {
//         ans += solve(num, tar - num[i]);
//     }

//     return ans;
// }

// int solveMem(vector<int> &num, int tar, vector<int> &dp)
// {
//     if (tar < 0)
//     {
//         return 0;
//     }
//     else if (tar == 0)
//     {
//         return 1;
//     }
//     if (dp[tar] != -1)
//     {
//         return dp[tar];
//     }

//     int ans = 0;
//     for (int i = 0; i < num.size(); i++)
//     {
//         ans += solve(num, tar - num[i]);
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
//             if (i - num[j] >= 0)
//                 ans += dp[i - num[j]];
//         }
//         dp[i] = ans;
//     }
//     return dp[tar];
// }
// int findWays(vector<int> &num, int tar)
// {
//     // return solve(num, tar);
//     vector<int> dp(tar + 1, -1);
//     return solveMem(num, tar, dp);
// }
// Write a program to find the minimum number of squares.
// class solution
// {
// public:
//     int solve(int n)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         int ans = n;
//         for (int i = 1; i * i <= n; i++)
//         {
//             ans = min(ans, 1 + solve(n - i * i));
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
//         int ans = n;
//         for (int i = 1; i * i <= n; i++)
//         {
//             ans = min(ans, solveMem(n - i * i, dp));
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
//             int ans = i;
//             for (int j = 1; j * j <= i; j++)
//             {
//                 ans = min(ans, dp[i - j * j]);
//             }
//             dp[i] = ans;
//         }
//         return dp[n];
//     }
//     int MinSquares(int n)
//     {
//     }
// };
// Write a program to find the minimum cost for tickets.
// int solve(vector<int> &days, vector<int> &cost, int index)
// {
//     if (index >= days.size())
//     {
//         return 0;
//     }
//     // One day
//     int one = cost[0] + solve(days, cost, index + 1);
//     // seven days
//     int i;
//     for (i = index; i < days.size() && days[i] - 7 < days[index]; i++)
//         ;
//     int seven = cost[1] + solve(days, cost, i);
//     for (i = index; i < days.size() && days[i] - 30 < days[index]; i++)
//         ;
//     int thirty = cost[2] + solve(days, cost, i);
//     return min(one, min(seven, thirty));
//
// int solveMem(vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
// {
//     if (index >= days.size())
//     {
//         return 0;
//     }
//     if (dp[index] != -1)
//     {
//         return dp[index];
//     }
//     // One day
//     int one = cost[0] + solveMem(days, cost, index + 1, dp);
//     // seven days
//     int i;
//     for (i = index; i < days.size() && days[i] - 7 < days[index]; i++)
//         ;
//     int seven = cost[1] + solveMem(days, cost, i, dp);
//     for (i = index; i < days.size() && days[i] - 30 < days[index]; i++)
//         ;
//     int thirty = cost[2] + solveMem(days, cost, i, dp);
//     return dp[index] = min(one, min(seven, thirty));
// }
// int solveTab(vector<int> &days, vector<int> &cost, int index)
// {
//     int n = days.size();
//     vector<int> dp(days.size() + 1, INT_MAX);
//     dp[n] = 0;
//     for (int k = n - 1; k >= 0; k--)
//     {
//         int one = cost[0] + dp[k + 1];
//         // 7 days
//         int i;
//         for (i = k; i < n && days[i] < days[k] + 7; i++)
//             ;
//         int two = cost[1] + dp[i];
//         for (i = k; i < n && days[i] < days[k] + 30; i++)
//             ;
//         int three = cost[2] + dp[i];
//         dp[k] = min(one, min(two, three));
//     }
//     return dp[0];
// }
// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     vector<int> dp(n + 1, -1);
//     return solveMem(days, cost, 0, dp);
// }
// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     int ans = INT_MAX;
//     queue<pair<int, int>> month;
//     queue<pair<int, int>> week;
//     for (int day : days)
//     {
//         while (!month.empty() && month.front().first + 30 <= day)
//         {
//             month.pop();
//         }
//         while (!week.empty() && week.front().first + 7 <= day)
//         {
//             week.pop();
//         }
//         week.push(make_pair(day, ans + cost[1]));
//         month.push(make_pair(day, ans + cost[2]));
//         ans = min(ans + cost[0], min(week.front().second, month.front().second));
//     }
//     return ans;
// }
// Write a program to find the largest square matrix in a matrix.
// class solution
// {
// public:
//     int solve(vector<vector<int>> mat, int i, int j, int &maxi)
//     {
//         if (i >= mat.size() || j >= mat.size())
//         {
//             return 0;
//         }
//         int right = solve(mat, i, j + 1, maxi);
//         int diagonal = solve(mat, i + 1, j + 1, maxi);
//         int down = solve(mat, i + 1, j, maxi);
//         if (mat[i][j] == 1)
//         {
//             int ans = min(right, min(diagonal, down)) + 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
//     {
//         if (i >= mat.size() || j >= mat[0].size())
//         {
//             return 0;
//         }
//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         int right = solveMem(mat, i, j + 1, maxi, dp);
//         int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
//         int down = solveMem(mat, i + 1, j, maxi, dp);
//         if (mat[i][j] == 1)
//         {
//             int ans = 1 + min(right, min(down, diagonal));
//             maxi = max(maxi, ans);
//             return dp[i][j] = ans;
//         }
//         else
//         {
//             return dp[i][j] = 0;
//         }
//     }
//     // Using tabulation
//     int solveTab(vector<vector<int>> &mat, int n, int m, int &maxi)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int j = m - 1; j >= 0; j--)
//             {
//                 int right = dp[i][j + 1];
//                 int diagonal = dp[i + 1][j + 1];
//                 int down = dp[i + 1][j];
//                 if (mat[i][j] == 1)
//                 {
//                     dp[i][j] = 1 + min(right, min(diagonal, down));
//                     maxi = max(maxi, dp[i][j]);
//                 }
//                 else
//                 {
//                     dp[i][j] = 0;
//                 }
//             }
//         }
//         return dp[0][0];
//     }
//     int maxSquare(int n, int m, vector<vector<int>> mat)
//     {
//         // int maxi = 0;
//         // solve(mat, 0, 0, maxi);
//         // return maxi;
//         int maxi = 0;
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         solveMem(mat, 0, 0, maxi, dp);
//         return maxi;
//     }
// };
// class solution
// {
// public:
//     int solve(vector<int> &v, int i, int j)
//     {
//         if (i + 1 == j)
//         {
//             return 0;
//         }
//         int ans = INT_MAX;
//         for (int k = i + 1; k < j; k++)
//         {
//             ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
//         }
//         return ans;
//     }
// };
// Write a program to find the length of the longest increasing subsequence.
class solution
{
public:
    int longestIncreasing(vector<int> &arr)
    {
    }
};
// In this way i  solved this problem.
// space optimizatioh is also possible in this problem.