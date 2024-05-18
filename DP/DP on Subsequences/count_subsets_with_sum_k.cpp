#include <bits/stdc++.h>
using namespace std;

//arr[i] does not include the number 0;

//Memoization
int solveMemoization(int n, int k, vector<int>&arr, vector<vector<int>>&dp)
{
    if (k==0) return 1;
    if (n < 0) return 0;
    if (dp[n][k]!=-1) return dp[n][k];
    int notTake = solveMemoization(n-1,k,arr,dp);
    int take = 0;
    if (arr[n]<=k)
    {
        take = solveMemoization(n-1,k-arr[n],arr,dp);
    }
    dp[n][k] = notTake + take;
    return dp[n][k];
}

int countSubsetsMemoization(int n, int k, vector<int>&arr)
{
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solveMemoization(n-1,k,arr,dp);
}

//Tabulation
int countSubsetsTabulation(int n, int k, vector<int>&arr)
{
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0]<=k)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for(int target = 0; target<=k; target++)
        {
            int take = 0;
            int notTake = dp[i-1][target];
            if (arr[i]<=target) take = dp[i-1][target - arr[i]];
            dp[i][target] = notTake + take;
        }
    }
    return dp[n-1][k];
}