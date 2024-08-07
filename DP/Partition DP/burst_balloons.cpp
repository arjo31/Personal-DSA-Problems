/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int maxCoins = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int cost = nums[i - 1] * nums[k] * nums[j + 1] + solveMemoization(i, k - 1, nums, dp) + solveMemoization(k + 1, j, nums, dp);
        maxCoins = max(maxCoins, cost);
    }
    return dp[i][j] = maxCoins;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveMemoization(1, n, nums, dp);
}

// Tabulation
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxCoins = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                maxCoins = max(maxCoins, cost);
            }
            dp[i][j] = maxCoins;
        }
    }
    return dp[1][n];
}