#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int main()
{
    int n;
    cin>>n;
    vector<int> arr = {1,2,3,4,5,6};
    vector<int>dp(n+1,0);
    dp[0] = 1; // Initialize base case

    for (int i = 1; i <= n; i++)
    {
        for (int dice = 1; dice<=6; dice++)
        {
            if (dice<=i) dp[i] = (dp[i] + dp[i-dice])%MOD;
        }
    }

    cout << dp[n] << endl;
    return 0;
}