#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long int ll;

ll solve(vector<ll>&arr, ll target)
{
    ll n = arr.size();
    vector<vector<ll>>dp(n, vector<ll>(target+1,0));
    for (ll i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][1] = 1;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j<=target; j++)
        {
            ll notTake = dp[i-1][j];
            ll take = 0;
            if (arr[i]<=j)
            {
                take = dp[i-1][j - arr[i]];
            }
            dp[i][j] = (take + notTake)%MOD;
        }
    }
    return dp[n-1][target];
}

int main()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for (ll i = 0; i < n; i++) arr[i] = i+1;
    ll sum = n*(n+1)/2;
    ll target = sum / 2;
    if (sum&1)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<(solve(arr,target) * 500000004) % MOD<<endl;
    return 0;
}