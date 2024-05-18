#include <bits/stdc++.h>
using namespace std;

//Memoization
int solveMemoization(int ind, int cap, vector<int>&weight, vector<int>&value,vector<vector<int>>&dp)
{
    if (ind==0)
    {
        if (cap%weight[ind]==0)
        {
            return dp[ind][cap] = (cap/weight[ind])*value[ind];
        }
        return 0;
    }
    if (cap==0)
    {
        return 0;
    }
    if (dp[ind][cap]!=-1) return dp[ind][cap];
    int pick = 0;
    int notPick = solveMemoization(ind-1,cap,weight,value,dp);
    if (weight[ind]<=cap)
    {
        pick = solveMemoization(ind,cap - weight[ind],weight,value,dp) + value[ind];
    }
    return dp[ind][cap] = max(pick,notPick);
}

int unboundedKnapsackMemoization(vector<int>&weight, vector<int>&value, int maxWeight)
{
    int n = weight.size();
    vector<vector<int>>dp(n,vector<int>(maxWeight + 1, -1));
    return solveMemoization(n-1,maxWeight,weight,value,dp);
}

//Tabulation
int unboundedKnapsackTabulation(vector<int>&weight,vector<int>&value,int maxWeight)
{
    int n = weight.size();
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    if (weight[0]<=maxWeight)
    {
        for(int i = weight[0]; i<= maxWeight; i++)
        {
            dp[0][i] = (i%weight[0]==0) ? (i/weight[0])*value[0] : 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0 ; w <= maxWeight; w++)
        {
            int pick = 0;
            int notPick = dp[i-1][w];
            if (weight[i]<=w)
            {
                pick = dp[i][w - weight[i]] + value[i];
            }
            dp[i][w] = max(pick,notPick);
        }
    }
    return dp[n-1][maxWeight];
}