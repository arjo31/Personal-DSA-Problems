/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(vector<int> &prices, int ind, int buy, int cap, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
        return 0;
    if (ind == prices.size())
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    long long profit = 0;

    if (buy)
    {
        profit = max(-prices[ind] + solveMemoization(prices, ind + 1, 0, cap, dp), 0 + solveMemoization(prices, ind + 1, 1, cap, dp));
    }
    else
    {
        profit = max(prices[ind] + solveMemoization(prices, ind + 1, 1, cap - 1, dp), 0 + solveMemoization(prices, ind + 1, 0, cap, dp));
    }
    return dp[ind][buy][cap] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    if (n == 0)
        return 0;
    return solveMemoization(prices, 0, 1, k, dp);
}

// Tabulation
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // if cap==0, buy and ind can be anything
    for (int ind = 0; ind < n; ind++)
        for (int buy = 0; buy <= 1; buy++)
            dp[ind][buy][0] = 0;

    // If ind==n, buy and cap can be anything
    for (int buy = 0; buy <= 1; buy++)
        for (int cap = 0; cap <= k; cap++)
            dp[n][buy][cap] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy)
                {
                    dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], 0 + dp[i + 1][1][cap]);
                }
                else
                {
                    dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][k];
}