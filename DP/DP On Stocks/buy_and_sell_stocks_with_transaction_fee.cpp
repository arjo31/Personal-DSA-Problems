/*You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(vector<int> &prices, int ind, int buy, int fee, vector<vector<int>> &dp)
{
    if (ind == prices.size())
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long long maxProfit = 0;

    if (buy)
    {
        maxProfit = max(-prices[ind] + solveMemoization(prices, ind + 1, 0, fee, dp), 0 + solveMemoization(prices, ind + 1, 1, fee, dp));
    }
    else
    {
        maxProfit = max(prices[ind] + solveMemoization(prices, ind + 1, 1, fee, dp) - fee, 0 + solveMemoization(prices, ind + 1, 0, fee, dp));
    }
    return dp[ind][buy] = maxProfit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solveMemoization(prices, 0, 1, fee, dp);
}

// Tabulation
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            else
                dp[i][buy] = max((prices[i] - fee) + dp[i + 1][1], 0 + dp[i + 1][0]);
        }
    }

    return dp[0][1];
}