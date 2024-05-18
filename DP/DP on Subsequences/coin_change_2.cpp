/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(int ind, int amt, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amt % arr[0] == 0)
        {
            return dp[ind][amt] = 1;
        }
        return dp[ind][amt] = 0;
    }
    if (amt == 0)
    {
        return dp[ind][amt] = 1;
    }
    if (dp[ind][amt] != -1)
        return dp[ind][amt];
    int notPick = solveMemoization(ind - 1, amt, arr, dp);
    int pick = 0;
    if (arr[ind] <= amt)
    {
        pick = solveMemoization(ind, amt - arr[ind], arr, dp);
    }
    return dp[ind][amt] = pick + notPick;
}

int coinChangeMemoization(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solveMemoization(n - 1, amount, coins, dp);
}

// Tabulation
int coinChangeTabulation(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (coins[0] <= amount)
    {
        for (int amt = coins[0]; amt <= amount; amt++)
        {
            if (amt % coins[0] == 0)
            {
                dp[0][amt] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int amt = 0; amt <= amount; amt++)
        {
            int notPick = dp[i - 1][amt];
            int pick = 0;
            if (coins[i] <= amt)
            {
                pick = dp[i][amt - coins[i]];
            }
            dp[i][amt] = notPick + pick;
        }
    }
    return dp[n - 1][amount];
}