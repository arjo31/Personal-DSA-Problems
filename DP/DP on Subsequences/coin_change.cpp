#include<bits/stdc++.h>
using namespace std;

//Here order does not matter
//Memoization
int solveMemoization(int ind, vector<int>&arr, int amount, vector<vector<int>>&dp)
{
    if (ind==0)
    {
        if (amount%arr[ind]==0)
        {
            return dp[ind][amount] = amount/arr[ind];
        }
        return 1e9;
    }
    if (dp[ind][amount]!=-1) return dp[ind][amount];

    int notPick = solveMemoization(ind-1,arr,amount,dp);
    int pick = 1e9;
    if (arr[ind]<=amount)
    {
        pick = solveMemoization(ind,arr,amount - arr[ind], dp) + 1;
    }
    return dp[ind][amount] = min(pick,notPick);
}
int coinChangeMemoization(vector<int>& arr, int amount)
{
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    int ans = solveMemoization(n-1,arr,amount,dp);
    if (ans >= 1e9) return -1;
    return ans;
}

//Tabulation
int coinChangeTabulation(vector<int>&arr, int amount)
{
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
    //Base Case
    for (int i = 0; i < n ;i++)
    {
        dp[i][0] = 0;
    }
    if (arr[0]<=amount)
    {
        for (int i = arr[0]; i<=amount; i++)
        {
            dp[0][i] = (i%arr[0]==0) ? i/arr[0] : 1e9;
        }
    }

    for (int i = 1; i < n ; i++)
    {
        for(int amt = 0 ;amt <= amount; amt++)
        {
            int notPick = dp[i-1][amt];
            int pick = 1e9;
            if (arr[i]<=amt)
            {
                pick = 1 + dp[i][amt-arr[i]];
            }
            dp[i][amt] = min(notPick,pick);
        }
    }
    return (dp[n-1][amount]>=1e9) ? -1 : dp[n-1][amount];
}