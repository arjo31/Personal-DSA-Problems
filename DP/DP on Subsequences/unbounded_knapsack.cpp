/*Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(int ind, int cap, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (cap % weight[ind] == 0)
        {
            return dp[ind][cap] = (cap / weight[ind]) * value[ind];
        }
        return 0;
    }
    if (cap == 0)
    {
        return 0;
    }
    if (dp[ind][cap] != -1)
        return dp[ind][cap];
    int pick = 0;
    int notPick = solveMemoization(ind - 1, cap, weight, value, dp);
    if (weight[ind] <= cap)
    {
        pick = solveMemoization(ind, cap - weight[ind], weight, value, dp) + value[ind];
    }
    return dp[ind][cap] = max(pick, notPick);
}

int unboundedKnapsackMemoization(vector<int> &weight, vector<int> &value, int maxWeight)
{
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveMemoization(n - 1, maxWeight, weight, value, dp);
}

// Tabulation
int unboundedKnapsackTabulation(vector<int> &wt, vector<int> &val, int maxWeight)
{
    int N = wt.size();
    vector<vector<int>> dp(N + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 0; i <= N; i++)
        dp[i][0] = 0;
    if (maxWeight % wt[N - 1] == 0)
        dp[N - 1][maxWeight] = (maxWeight / wt[N - 1]) * val[N - 1];
    for (int i = N - 1; i >= 0; i--)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notPick = dp[i + 1][w];
            int pick = 0;
            if (wt[i] <= w)
                pick = val[i] + dp[i][w - wt[i]];
            dp[i][w] = max(pick, notPick);
        }
    }
    return dp[0][maxWeight];
}