/*Given a wooden stick of length n units. The stick is labelled from 0 to n.

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solveMemoization(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minCost = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solveMemoization(i, k - 1, cuts, dp) + solveMemoization(k + 1, j, cuts, dp);
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return solveMemoization(1, c, cuts, dp);
}

// Tabulation
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            int minCost = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                minCost = min(minCost, cost);
            }
            dp[i][j] = minCost;
        }
    }
    return dp[1][c];
}