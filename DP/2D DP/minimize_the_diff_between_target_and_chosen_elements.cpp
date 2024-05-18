/*You are given an m x n integer matrix mat and an integer target.

Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.

Return the minimum absolute difference.*/

#include <bits/stdc++.h>
using namespace std;

int solveMemoization(vector<vector<int>> &mat, int r, int sum, int target, vector<vector<int>> &dp)
{
    if (r == mat.size())
    {
        return abs(sum - target);
    }
    if (dp[r][sum] != -1)
        return dp[r][sum];

    int minPoints = INT_MAX;
    for (int j = 0; j < mat[0].size(); j++)
    {
        minPoints = min(minPoints, solveMemoization(mat, r + 1, sum + mat[r][j], target, dp));
    }
    return dp[r][sum] = minPoints;
}
int minimizeTheDifference(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(80, vector<int>(5000, -1));
    return solveMemoization(mat, 0, 0, target, dp);
}

// Tabulation
int minimizeTheDifference(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(80, vector<int>(5000, 0));
}