#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>arr)
{
    int n = arr.size();
    long long int sum = accumulate(arr.begin(),arr.end(),0);
    vector<vector<bool>>dp(n, vector<bool>(sum+1,false));
    //Base cases : 
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j<=sum; j++)
        {
            bool notTake = dp[i-1][j];
            bool take = false;
            if (j >= arr[i])
            {
                take = dp[i-1][j - arr[i]];
            }
            dp[i][j] = take||notTake;
        }
    }
    for (int i = 1; i<= sum ; i++) if (dp[n-1][i]) count++;
    cout<<count<<endl;
    for (int i = 1; i<=sum; i++)
    {
        if (dp[n-1][i]) cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    solve(v);
    return 0;
}