#include <bits/stdc++.h>
using namespace std;

//Memoization
int solve(int ind, vector<int>&weight, vector<int>&value, int cap,vector<vector<int>>&dp)
{
    if (ind==0)
    {
        if (weight[0]<=cap)
        {
            return dp[ind][cap] = value[0];
        }
        return 0;
    }
    if (cap==0)
    {
        return 0;
    }
    if (dp[ind][cap]!=-1) return dp[ind][cap];
    int notPick = solve(ind-1,weight,value,cap,dp);
    int pick = 0;
    if(weight[ind]<=cap)
    {
        pick = solve(ind-1,weight,value,cap - weight[ind],dp) + value[ind];
    }
    return dp[ind][cap]=max(pick,notPick);
}

int knapsackMemoization(int n, vector<int>&weight,vector<int>&value, int capacity)
{
    vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
    return solve(n-1,weight,value,capacity,dp);
}

//Tabulation
int knapsackTabulation(int n, vector<int>&weight, vector<int>&value, int capacity)
{
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    if (weight[0]<=capacity)
    {
        for (int i = weight[0]; i<=capacity; i++)
        {
            dp[0][i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt<=capacity ; wt++)
        {
            int notPick = dp[i-1][wt];
            int pick = 0;
            if (weight[i]<=wt)
            {
                pick = dp[i-1][wt - weight[i]] + value[i];
            }
            dp[i][wt] = max(pick,notPick);
        }
    }
    return dp[n-1][capacity];
}

//Space Optimization
int knapsackSO1(int n, vector<int>&weight, vector<int>&value, int capacity)
{
    vector<int>prev(capacity+1,0),current(capacity+1,0);
    //For this type of SO, instead of dp[ind-1] write prev. Just follow the below code
    if (weight[0]<=capacity)
    {
        for (int i = weight[0]; i<=capacity; i++)
        {
            prev[i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt<=capacity ; wt++)
        {
            int notPick = prev[wt];
            int pick = 0;
            if (weight[i]<=wt)
            {
                pick = prev[wt - weight[i]] + value[i];
            }
            current[wt] = max(pick,notPick);
        }
        prev = current;
    }
    return prev[capacity];
}

//Space Optimization2
int knapsackSO2(int n, vector<int>&weight, vector<int>&value, int capacity)
{
    vector<int>prev(capacity+1,0);
    if (weight[0]<=capacity)
    {
        for (int i = weight[0]; i<=capacity; i++)
        {
            prev[i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt<=capacity ; wt++)
        {
            int notPick = prev[wt];
            int pick = 0;
            if (weight[i]<=wt)
            {
                pick = prev[wt - weight[i]] + value[i];
            }
            prev[wt] = max(pick,notPick);
        }
    }
    return prev[capacity];
}