#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>>dp(n,vector<int>(x+1,1e9));
    for (int i = 0; i < n; i++) dp[i][0] = 0;
    for (int j = 1; j<=x; j++)
    {
        if (j%arr[0]==0) dp[0][j] = j/arr[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <=x; j++)
        {
            int pick = 1e9;
            int notPick = 0 + dp[i-1][j];
            if (arr[i]<=j) pick = 1 + dp[i][j - arr[i]];
            dp[i][j] = min(pick,notPick);
        }
    }

    cout<<((dp[n-1][x]!=1e9) ? dp[n-1][x] : -1)<<endl;
    return 0;
}