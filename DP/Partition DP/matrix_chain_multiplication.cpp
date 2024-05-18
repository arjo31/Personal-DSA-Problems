#include <bits/stdc++.h>
using namespace std;

//Memoization
int solveMemoization(int i, int j, vector<int>&arr, vector<vector<int>>&dp)
{
    if (i==j) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for (int k = i; k<j; k++)
    {
        int cost = arr[i-1]*arr[k]*arr[j] + solveMemoization(i,k,arr,dp) + solveMemoization(k+1,j,arr,dp);
        if (cost < mini) mini = cost;
    }
    return dp[i][j] = mini;
}

int mcmMemoization(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n,-1));
    return solveMemoization(1,n-1,arr,dp);
}

//Tabulation
int mcmTabulation(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = n-1; i>=0; i--)
    {
        for (int j = i+1; j<n; j++)
        {
            int mini = 1e9;
            for (int k = i ; k < j; k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                dp[i][j] = min(mini,steps);
            }
        }
    }
    return dp[1][n-1];
}