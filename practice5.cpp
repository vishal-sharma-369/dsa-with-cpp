#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Those who forget the past are condemned to repeat it.

int solveRec(vector<int> &weight, vector<int> &value, int n, int capacity, int i)
{
    if (i == 0)
    {
        if (capacity >= weight[0])
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (capacity >= weight[i])
    {
        include = value[i] + solveRec(weight, value, n, capacity - weight[i], i - 1);
    }

    int exclude = 0 + solveRec(weight, value, n, capacity, i - 1);

    return max(include, exclude);
}

// Using memoization:
int solveMem(vector<int> &weight, vector<int> &value, int n, int capacity, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (capacity >= weight[0])
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[i][capacity] != -1)
    {
        return dp[i][capacity];
    }

    int include = 0;
    if (capacity >= weight[i])
    {
        include = value[i] + solveMem(weight, value, n, capacity - weight[i], i - 1, dp);
    }

    int exclude = 0 + solveMem(weight, value, n, capacity, i - 1, dp);

    return dp[i][capacity] = max(include, exclude);
}

// Using tabulation:
int solveTab(vector<int> &weight, vector<int> &value, int n, int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    for (int w = weight[0]; w <= maxweight; w++)
    {
        if (weight[0] <= maxweight)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int include = 0;
            if (w >= weight[i])
            {
                include = value[i] + dp[i - 1][w - weight[i]];
            }

            int exclude = 0 + dp[i - 1][w];

            dp[i][w] = max(include, exclude);
        }
    }

    return dp[n - 1][maxweight];
}

// Using space optimization:
int solveSO(vector<int> &weight, vector<int> &value, int n, int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));
    vector<int> prev(maxweight + 1, 0);
    vector<int> curr(maxweight + 1, 0);
    for (int w = weight[0]; w <= maxweight; w++)
    {
        if (weight[0] <= maxweight)
        {
            prev[w] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int include = 0;
            if (w >= weight[i])
            {
                include = value[i] + prev[w - weight[i]];
            }
            int exclude = 0 + prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[maxweight];
}

// Using ultra space optimization:
int solveUSO(vector<int> &weight, vector<int> &value, int n, int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));
    vector<int> curr(maxweight + 1, 0);
    for (int w = weight[0]; w <= maxweight; w++)
    {
        if (weight[0] <= maxweight)
        {
            curr[w] = value[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = maxweight; w >= 0; w--)
        {
            int include = 0;
            if (w >= weight[i])
            {
                include = value[i] + curr[w - weight[i]];
            }
            int exclude = 0 + curr[w];
            curr[w] = max(include, exclude);
        }
    }
    return curr[maxweight];
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // return solveRec(weight, value, n, maxWeight, n - 1);

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
}

int main()
{
    return 0;
}