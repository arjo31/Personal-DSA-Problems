/*An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n;

long long int solve(int ind, int absent, int late, vector<vector<vector<long long int>>> &dp)
{
    if (ind == 0)
        return 1;

    if (dp[ind][absent][late] != -1)
        return dp[ind][absent][late];

    long long int ans = solve(ind - 1, absent, 0, dp) % MOD;
    ans = (ans + ((absent < 1) ? solve(ind - 1, absent + 1, 0, dp) : 0)) % MOD;
    ans = (ans + ((late < 2) ? solve(ind - 1, absent, late + 1, dp) : 0)) % MOD;

    return dp[ind][absent][late] = ans % MOD;
}

int checkRecord(int n)
{
    n = n;
    vector<vector<vector<long long int>>> dp(n + 1, vector<vector<long long int>>(2, vector<long long int>(3, -1)));
    return solve(n, 0, 0, dp);
}

// Tabulation
int checkRecord(int n)
{
    int dp[100001][2][3] = {0};
    fill(&dp[0][0][0], &dp[0][0][0] + 6, 1); // dp[0][j][k]=1 for all j, k
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        { // absent
            for (int k = 0; k <= 2; k++)
            {                                              // late
                long long ans = dp[i - 1][j][0];           // P
                ans += (k < 2 ? dp[i - 1][j][k + 1] : 0);  // L
                ans += (j == 0 ? dp[i - 1][j + 1][0] : 0); // A
                dp[i][j][k] = ans % MOD;
            }
        }
    }

    return dp[n][0][0];
}