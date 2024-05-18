/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(vector<int> &prices, int ind, int buy, vector<vector<int>> &dp)
{
    if (ind >= prices.size())
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long long maxProfit = 0;
    if (buy)
    {
        maxProfit = max(-prices[ind] + solveMemoization(prices, ind + 1, 0, dp), 0 + solveMemoization(prices, ind + 1, 1, dp));
    }
    else
    {
        maxProfit = max(prices[ind] + solveMemoization(prices, ind + 2, 1, dp), 0 + solveMemoization(prices, ind + 1, 0, dp));
    }
    return dp[ind][buy] = maxProfit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solveMemoization(prices, 0, 1, dp);
}

// Tabulation
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int buy = 0; buy < 2; buy++)
    {
        dp[n][buy] = 0;
        dp[n + 1][buy] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
            {
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else
            {
                dp[i][buy] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
            }
        }
    }
    return dp[0][1];
}