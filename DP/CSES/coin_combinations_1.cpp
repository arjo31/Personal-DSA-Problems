#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int>dp(x+1);
    dp[0] = 1;
    for (int weight = 0; weight<=x; weight++)
    {
        for (int i = 0; i<n; i++)
        {
            if (weight>=arr[i])
            {
                dp[weight] = dp[weight] + dp[weight - arr[i]];
                dp[weight]%= MOD;
            }
        }
    }
    cout<<dp[x]<<endl;

    return 0;
}