/*Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MOD = 1e9 + 7;

ll countStrings(int n)
{
    vector<ll>dp(n+1,0);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i<=n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }
    return dp[n]%MOD;
}