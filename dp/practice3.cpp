#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Write a program to solve the pizza with 3n slices problem.
// class solution
// {
//     int solveRec(int index, vector<int> &slices, int endIndex, int n)
//     {
//         if (n == 0 || index > endIndex)
//         {
//             return 0;
//         }
//         int take = slices[index] + solveRec(index + 2, slices, endIndex, n - 1);
//         int notTake = 0 + solveRec(index + 1, slices, endIndex, n);
//         return max(take, notTake);
//     }
//     // Using memoization:
//     int solveMem(int index, vector<int> &slices, int endIndex, int n, vector<vector<int>> &dp)
//     {
//         if (n == 0 || index > endIndex)
//         {
//             return 0;
//         }
//         if (dp[index][n] != -1)
//         {
//             return dp[index][n];
//         }
//         int take = slices[index] + solveMem(index + 2, slices, endIndex, n - 1, dp);
//         int notTake = 0 + solveMem(index + 1, slices, endIndex, n, dp);
//         return dp[index][n] = max(take, notTake);
//     }
//     // Using tabulation:
//     int solveTab(int index, vector<int> &slices, int endIndex, int n)
//     {
//         int k = slices.size();
//         int n = k / 3;
//         vector<vector<int>> dp1(k + 1, vector<int>(n + 1, 0));
//         for (int index = k - 2; index >= 0; index--)
//         {
//             for (int n = 1; n <= k / 3; n++)
//             {
//                 int take = slices[index] + dp1[index + 2][n - 1];
//                 int notTake = 0 + dp1[index + 1][n];
//                 dp1[index][n] = max(take, notTake);
//             }
//         }
//        int case1 = dp1[0][k / 3];
//        vector<vector<int>> dp2(k + 2, vector<int>(n + 1, 0));
//         for (int index = k - 1; index >= 0; index--)
//         {
//             for (int n = 1; n <= k / 3; n++)
//             {
//                 int take = slices[index] + dp2[index + 2][n - 1];
//                 int notTake = 0 + dp2[index + 1][n];
//                 dp2[index][n] = max(take, notTake);
//             }
//         }
//         int case2 = dp2[1][k / 3];
//         return max(case1, case2);
//     }
//     // Using space optimization:
//     int solveSO(int index, vector<int> &slices, int endIndex, int n)
//     {
//         int k = slices.size();
//         int n = k / 3;
//         vector<int> prev(n + 1, 0);
//         vector<int> curr(n + 1, 0);
//         vector<int> next(n + 1, 0);
//         for (int index = k - 2; index >= 0; index--)
//         {
//             for (int n = 1; n <= k / 3; n++)
//             {
//                 int take = slices[index] + next[n - 1];
//                 int notTake = 0 + curr[n];
//                 prev[n] = max(take, notTake);
//             }
//             next = curr;
//             curr = prev;
//         }
//         int case1 = curr[k / 3];
//         vector<int> prev2(n + 1, 0);
//         vector<int> curr2(n + 1, 0);
//         vector<int> next2(n + 1, 0);
//         for (int index = k - 1; index >= 0; index--)
//         {
//             for (int n = 1; n <= k / 3; n++)
//             {
//                 int take = slices[index] + next[n - 1];
//                 int notTake = 0 + curr[n];
//                 prev[n] = max(take, notTake);
//             }
//         }
//         int case2 = curr2[k / 3];
//         return max(case1, case2);
//     }
// public:
//     int maxSizeSlices(vector<int> &slices)
//     {
//         // int k = slices.size();
//         // int case1 = solveRec(0, slices, k - 2, k / 3);
//         // int case2 = solveRec(1, slices, k - 1, k / 3);
//         // return max(case1, case2);
//         int k = slices.size();
//         vector<vector<int>> dp1(k, vector<int>(k / 3 + 1, -1));
//         int case1 = solveMem(0, slices, k - 2, k / 3, dp1);
//         vector<vector<int>> dp2(k, vector<int>(k / 3 + 1, -1));
//         int case2 = solveMem(1, slices, k - 1, k / 3, dp2);
//         return max(case1, case2);
//     }
// };
// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to find the number of dice rolls with target sum.
// class solution
// {
//     // Using recursion:
//     int solveRec(int n, int f, int t)
//     {
//         if (n == 0 && t != 0)
//         {
//             return 0;
//         }
//         if (n != 0 && t == 0)
//         {
//             return 0;
//         }
//         if (t < 0)
//         {
//             return 0;
//         }
//         if (n == 0 && t == 0)
//         {
//             return 1;
//         }
//         int ans = 0;
//         for (int j = 1; j <= f; j++)
//         {
//             ans += solveRec(n - 1, f, t - j);
//         }
//         return ans;
//     }

//     // Using memoization:
//     int solveMem(int n, int f, int t, vector<vector<int>> &dp)
//     {
//         if (n == 0 && t != 0)
//         {
//             return 0;
//         }
//         if (n != 0 && t == 0)
//         {
//             return 0;
//         }
//         if (t < 0)
//         {
//             return 0;
//         }
//         if (n == 0 && t == 0)
//         {
//             return 1;
//         }

//         if (dp[n][t] != -1)
//         {
//             return dp[n][t];
//         }

//         int ans = 0;
//         for (int j = 1; j <= f; j++)
//         {
//             ans += solveRec(n - 1, f, t - j);
//         }

//         return dp[n][t] = ans;
//     }

//     // Using tabulation:
//     int solveTab(int n, int f, int t)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
//         dp[0][0] = 1;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int x = 1; x <= t; x++)
//             {
//                 int ans = 0;
//                 for (int j = 1; j <= f; j++)
//                 {
//                     if (t - j >= 0)
//                         ans += dp[i - 1][x - j];
//                 }
//                 return dp[i][x] = ans;
//             }
//         }

//         return dp[n][t];
//     }

//     // Using space optimization:
//     int solveSO(int n, int f, int t)
//     {
//         vector<int> prev(t + 1, 0);
//         vector<int> curr(t + 1, 0);
//         prev[0] = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             for (int x = 1; x <= t; x++)
//             {
//                 int ans = 0;
//                 for (int j = 1; j <= f; j++)
//                 {
//                     if (t - j >= 0)
//                         ans += prev[x - j];
//                 }
//                 curr[x] = ans;
//             }
//             prev = curr;
//         }
//         return curr[t];
//     }

// public:
//     long long noOfWays(int M, int N, int X)
//     {
//         vector<vector<int>> dp(N + 1, vector<int>(X + 1, -1));
//     }
// };
// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to solve the partition equal sum problem.
// class solution
// {
//     // Using recursion:
//     bool solveRec(int index, int arr[], int n, int target)
//     {
//         if (target < 0)
//         {
//             return false;
//         }

//         if (index >= n && target != 0)
//         {
//             return false;
//         }

//         if (target == 0)
//         {
//             return true;
//         }

//         bool include = solveRec(index + 1, arr, n, target - arr[index]);
//         bool exclude = solveRec(index + 1, arr, n, target);

//         return include or exclude;
//     }

//     // Using memoization:
//     bool solveMem(int index, int arr[], int n, int target, vector<vector<int>> &dp)
//     {
//         if (target < 0)
//         {
//             return false;
//         }

//         if (index >= n && target != 0)
//         {
//             return false;
//         }

//         if (target == 0)
//         {
//             return true;
//         }

//         if (dp[index][target] != -1)
//         {
//             return dp[index][target];
//         }

//         bool include = solveMem(index + 1, arr, n, target - arr[index], dp);
//         bool exclude = solveMem(index + 1, arr, n, target, dp);

//         return dp[index][target] = include or exclude;
//     }

//     // Using tabulation:
//     bool solveTab(int index, int arr[], int n, int target)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

//         for (int i = 0; i < n; i++)
//         {
//             dp[i][0] = true;
//         }

//         for (int index = n - 1; index >= 0; index++)
//         {
//             for (int t = 1; t >= target; t++)
//             {
//                 bool include = 0;
//                 if (target - arr[index] >= 0)
//                     include = dp[index + 1][target - arr[index]];
//                 bool exclude = dp[index + 1][target];

//                 dp[index][target] = include or exclude;
//             }
//         }

//         return dp[0][target];
//     }

//     // Using space optimization:
//     bool solveSO(int index, int arr[], int n, int target)
//     {
//         vector<int> curr(target + 1, 0);
//         vector<int> next(target + 1, 0);

//         curr[0] = true;
//         next[0] = true;

//         for (int index = n - 1; index >= 0; index++)
//         {
//             for (int t = 1; t >= target; t++)
//             {
//                 bool include = 0;
//                 if (target - arr[index] >= 0)
//                     include = next[target - arr[index]];
//                 bool exclude = next[target];

//                 curr[target] = include or exclude;
//             }
//             next = curr;
//         }

//         return curr[target];
//     }

// public:
//     int equalPartition(int N, int arr[])
//     {
//         int total = 0;
//         for (int i = 0; i < N; i++)
//         {
//             total += arr[i];
//         }

//         if (total & 1)
//         {
//             return 0;
//         }

//         else
//         {
//             // return solveRec()
//             vector<vector<int>> dp(N, vector<int>(total / 2 + 1, -1));
//         }
//     }
// };

// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to find the minimum number of swaps to make subsequences increasing.

// class solution
// {
//     int solveRec(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
//     {
//         if (index == nums1.size())
//             return 0;

//         int ans = INT_MAX;
//         int prev1 = nums1[index - 1];
//         int prev2 = nums2[index - 1];

//         if (swapped)
//         {
//             swap(prev1, prev2);
//         }

//         // no swap condition
//         if (nums1[index] > prev1 && nums2[index] > prev2)
//         {
//             ans = solveRec(nums1, nums2, index + 1, 0);
//         }

//         // swapped condition
//         if (nums1[index] > prev2 && nums2[index] > prev1)
//         {
//             ans = min(ans, 1 + solveRec(nums1, nums2, index + 1, 1));
//         }

//         return ans;
//     }

//     // Using memoization:
//     int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
//     {
//         if (index == nums1.size())
//             return 0;

//         int ans = INT_MAX;
//         int prev1 = nums1[index - 1];
//         int prev2 = nums2[index - 1];

//         if (swapped)
//         {
//             swap(prev1, prev2);
//         }
//         if (dp[index][swapped] != -1)
//         {
//             return dp[index][swapped];
//         }

//         // no swap condition
//         if (nums1[index] > prev1 && nums2[index] > prev2)
//         {
//             ans = solveMem(nums1, nums2, index + 1, 0, dp);
//         }

//         // swapped condition
//         if (nums1[index] > prev2 && nums2[index] > prev1)
//         {
//             ans = min(ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp));
//         }

//         return dp[index][swapped] = ans;
//     }

//     // Using tabulation:
//     int solveTab(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
//     {
//         int n = nums1.size();
//         vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
//         for (int index = n - 1; index >= 1; index--)
//         {
//             for (int swapped = 1; swapped >= 0; swapped--)
//             {
//                 int ans = INT_MAX;
//                 int prev1 = nums1[index - 1];
//                 int prev2 = nums2[index - 1];
//                 if (swapped)
//                 {
//                     swap(prev1, prev2);
//                 }
//                 // no swap condition
//                 if (nums1[index] > prev1 && nums2[index] > prev2)
//                 {
//                     ans = dp[index + 1][0];
//                 }
//                 // swapped condition
//                 if (nums1[index] > prev2 && nums2[index] > prev1)
//                 {
//                     ans = min(ans, 1 + dp[index + 1][1]);
//                 }
//                 dp[index][swapped] = ans;
//             }
//         }
//         return dp[1][0];
//     }

//     // Using space optimization:
//     int solveSO(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
//     {
//         int n = nums1.size();
//         vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
//         vector<int> curr(2, 0);
//         vector<int> next(2, 0);
//         for (int index = n - 1; index >= 1; index--)
//         {
//             for (int swapped = 1; swapped >= 0; swapped--)
//             {
//                 int ans = INT_MAX;
//                 int prev1 = nums1[index - 1];
//                 int prev2 = nums2[index - 1];
//                 if (swapped)
//                 {
//                     swap(prev1, prev2);
//                 }
//                 // no swap condition
//                 if (nums1[index] > prev1 && nums2[index] > prev2)
//                 {
//                     ans = next[0];
//                 }
//                 // swapped condition
//                 if (nums1[index] > prev2 && nums2[index] > prev1)
//                 {
//                     ans = min(ans, 1 + next[1]);
//                 }
//                 curr[swapped] = ans;
//             }
//             next = curr;
//         }
//         return curr[0];
//     }

// public:
//     int minSwap(vector<int> &nums1, vector<int> &nums2)
//     {
//         // bool swapped = 0;
//         // return solveRec(nums1, nums2, 1, swapped);

//         bool swapped = 0;
//         vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
//     }
// };

// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to find the longest arithmetic subsequence.
// class solution
// {
//     int solveRec(int index, int diff, int a[])
//     {
//         if (index <= 0)
//         {
//             return 0;
//         }

//         int ans = 0;
//         for (int j = index - 1; j >= 0; j--)
//         {
//             if (a[index] - a[j] == diff)
//             {
//                 ans = max(ans, 1 + solveRec(j, diff, a));
//             }
//         }
//         return ans;
//     }

//     // Using memoization:
//     int solveMem(int index, int diff, int a[], unordered_map<int, unordered_map<int, int>> &dp)
//     {
//         int ans = 0;
//         if (dp[index].count(diff))
//         {
//             return dp[index][diff];
//         }
//         for (int j = index - 1; j >= 0; j--)
//         {
//             if (a[index] - a[j] == diff)
//             {
//                 ans = max(ans, 1 + solveMem(j, diff, a, dp));
//             }
//         }
//         return dp[index][diff] = ans;
//     }

//     // Using tabulation:
//     int solveTab(int n, int a[])
//     {
//         int ans = 0;
//         unordered_map<int, unordered_map<int, int>> dp(n);

//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 int diff = a[i] - a[j];
//                 int cnt = 1;

//                 if (dp[j].count(diff))
//                 {
//                     cnt = dp[j][diff];
//                 }

//                 dp[i][diff] = 1 + cnt;
//                 ans = max(ans, dp[i][diff]);
//             }
//         }
//         return ans;
//     }

//     // Using space optimization: space optimized solution is not possible for this problem.

// public:
//     int lengthOfLongestAP(int A[], int n)
//     {
//         int longest = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 int diff = A[j] - A[i];
//                 longest = max(longest, 2 + solveRec(i, diff, A));
//             }
//         }

//         return longest;
//     }
// };

// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to find the longest AP with given difference "d".

// class solution
// {
// public:
//     int longestSubsequence(vector<int> &arr, int difference)
//     {
//         unordered_map<int, int> dp;
//         int ans = 0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             int cnt = 1;
//             int temp = arr[i] - difference;
//             if (dp.count(temp))
//             {
//                 cnt = dp[temp] + 1;
//             }
//             dp[i] = cnt;
//             ans = max(ans, dp[i]);
//         }
//         return ans;
//     }
//     // this is known as the array with prefix sum problem solution.
// };

// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to find the number of unique binary search trees.

// class solution
// {
//     // Using recursion:
//     int solveRec(int n)
//     {
//         if (n <= 1)
//         {
//             return 1;
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             ans += solveRec(i - 1) * solveRec(n - i);
//         }
//         return ans;
//     }

//     int solveMem(int n, vector<int> &dp)
//     {
//         if (n <= 1)
//         {
//             return 1;
//         }

//         if (dp[n] != -1)
//         {
//             return dp[n];
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
//         }
//         return dp[n] = ans;
//     }

//     // Using tabulation:
//     int solveTab(int n)
//     {
//         vector<int> dp(n + 1, 0);
//         dp[0] = 1;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++)
//         {
//             int ans = 0;
//             for (int j = 1; j <= i; j++)
//             {
//                 ans += dp[j - 1] * dp[i - j];
//             }
//             dp[i] = ans;
//         }

//         return dp[n];
//     }

//     // Using space optimization: space optimized solution is not possible for this problem.

//     // This can be solved using the catlan number :
//     long long int factorial(int n)
//     {
//         if (n <= 1)
//         {
//             return 1;
//         }

//         return n * factorial(n - 1);
//     }

//     long long int solveCatlan(int n)
//     {
//         return (factorial(2 * n) / (factorial(n + 1) + factorial(n)));
//     }

// public:
//     int numTrees(int n)
//     {
//         vector<int> dp(n + 1, -1);
//     }
// };

// int main()
// {
//     return 0;
// }

// ________________________________________________________________________________________________________________________
// ________________________________________________________________________________________________________________________
// Write a program to solve the guess number higher or lower problem.
class solution
{
    int solve(int start, int end)
    {
        if (start >= end)
        {
            return 0;
        }

        int maxi = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            maxi = min(maxi, i + max(solve(start, i - 1), solve(i + 1, end)));
        }

        return maxi;
    }

    // Using memoization:
    int solveMem(int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
        {
            return 0;
        }
        if (dp[start][end])
        {
            return dp[start][end];
        }
        int maxi = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            maxi = min(maxi, max(solveMem(start, i - 1, dp), solveMem(i + 1, end, dp)));
        }
        return dp[start][end] = maxi;
    }

    // Using tabulation:
    int solveTab(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int start = n; start >= 1; start--)
        {
        }
    }

public:
    int getMoneyAmount(int n)
    {
        return solve(1, n);
    }
};