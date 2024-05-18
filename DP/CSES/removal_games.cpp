#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define int long long

//Game Theory

int fun(int i,int j, vector<vector<int>>&dp, vector<int>&arr)
{
    if (i==j) return dp[i][j]=arr[i];

    if (j-i==1) return dp[i][j]=max(arr[i],arr[j]);

    if(dp[i][j] != -1)
    return dp[i][j];

    int op1 = arr[i] + min(fun(i+2,j, dp, arr), fun(i+1,j-1,dp,arr));
    int op2 = arr[j] + min(fun(i+1,j-1,dp,arr), fun(i,j-2,dp,arr));

    return dp[i][j] = max(op1,op2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n;i++) cin>>arr[i];

    vector<vector<int>>dp(n,vector<int>(n,-1));
    fun(0,n-1,dp,arr);
    cout<<dp[0][n-1]<<endl;

    return 0;
}