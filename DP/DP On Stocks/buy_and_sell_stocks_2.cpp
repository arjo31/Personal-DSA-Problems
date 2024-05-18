#include <bits/stdc++.h>
using namespace std;

/*We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell a stock only once.
We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.
We need to tell the maximum profit one can get by buying and selling this stock.*/

// Greedy
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int buy = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (buy < prices[i])
            maxProfit += (prices[i] - buy);
        buy = prices[i];
    }
    return maxProfit;
}

// DP : Memoization
long getAns(vector<long> Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    if (ind == n)
    {
        return 0;
    }

    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 1)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }

    if (buy == 0)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(vector<long> Arr, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    if (n == 0)
    {
        return 0;
    }
    long ans = getAns(Arr, 0, 1, n, dp);
    return ans;
}

// DP : Tabulation
long getMaximumProfit(long *Arr, int n)
{
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;

    long profit;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
            { // We can buy the stock
                profit = max(0 + dp[ind + 1][1], -Arr[ind] + dp[ind + 1][0]);
            }

            if (buy == 0)
            { // We can sell the stock
                profit = max(0 + dp[ind + 1][0], Arr[ind] + dp[ind + 1][1]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][1] after all calculations
    return dp[0][1];
}