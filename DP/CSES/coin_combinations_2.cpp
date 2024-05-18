#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0; i < n ; i++) cin>>arr[i];
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int j = 1; j <= x; j++)
    {
        if (j%arr[0]==0) dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j<=x; j++)
        {
            int pick = 0;
            int notPick = dp[i-1][j];
            if (arr[i]<=j) pick = dp[i][j - arr[i]];
            dp[i][j] = (pick + notPick)%MOD;
        }
    }
    cout<<dp[n-1][x]<<endl;
    return 0;
}