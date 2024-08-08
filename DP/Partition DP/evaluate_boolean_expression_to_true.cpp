/*You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).
Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
As the answer can be very large, return the output modulo 1000000007.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MOD = 1e9 + 7;

// Memoization
ll solveMemoization(int i, int j, bool isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll noOfWays = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        ll leftTrue = solveMemoization(i, k - 1, 1, exp, dp);
        ll rightTrue = solveMemoization(k + 1, j, 1, exp, dp);
        ll leftFalse = solveMemoization(i, k - 1, 0, exp, dp);
        ll rightFalse = solveMemoization(k + 1, j, 0, exp, dp);

        if (exp[k] == '&')
        {
            if (isTrue)
                noOfWays = (noOfWays + (leftTrue * rightTrue) % MOD) % MOD;
            else
                noOfWays = (noOfWays + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
                noOfWays = (noOfWays + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
            else
                noOfWays = (noOfWays + (leftFalse * rightFalse) % MOD) % MOD;
        }
        else if (exp[k] == '^')
        {
            if (isTrue)
                noOfWays = (noOfWays + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD) % MOD;
            else
                noOfWays = (noOfWays + (leftTrue * rightTrue) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
        }
    }
    return dp[i][j][isTrue] = noOfWays;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
    return solveMemoization(0, n - 1, 1, exp, dp);
}

// Tabulation
int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j][1] = (exp[i] == 'T');
                dp[i][j][0] = (exp[i] == 'F');
            }
            else if (i > j)
                continue;
            else
            {
                ll noOfWays = 0;
                for (int k = i + 1; k <= j - 1; k += 2)
                {
                    ll leftTrue = dp[i][k - 1][1];
                    ll rightTrue = dp[k + 1][j][1];
                    ll leftFalse = dp[i][k - 1][0];
                    ll rightFalse = dp[k + 1][j][0];

                    if (exp[k] == '&')
                    {

                        dp[i][j][1] = (dp[i][j][1] + (leftTrue * rightTrue) % MOD) % MOD;
                        dp[i][j][0] = (dp[i][j][0] + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
                    }
                    else if (exp[k] == '|')
                    {
                        dp[i][j][1] = (dp[i][j][1] + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD + (leftTrue * rightTrue) % MOD) % MOD;
                        dp[i][j][0] = (dp[i][j][0] + (leftFalse * rightFalse) % MOD) % MOD;
                    }
                    else if (exp[k] == '^')
                    {
                        dp[i][j][1] = (dp[i][j][1] + (leftFalse * rightTrue) % MOD + (leftTrue * rightFalse) % MOD) % MOD;
                        dp[i][j][0] = (dp[i][j][0] + (leftTrue * rightTrue) % MOD + (leftFalse * rightFalse) % MOD) % MOD;
                    }
                }
            }
        }
    }
    return dp[0][n - 1][1];
}