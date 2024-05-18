// Let there be N workers and N jobs (N<=20). Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

#include <bits/stdc++.h>
using namespace std;

int cost[21][21];
int dp[21][(1 << 21)];

int solve(int i, int mask, int &n) // In main function : the function called will be solve(0, (1<<n) - 1, n)
{
    if (i == n)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
        {
            ans = min(ans, cost[j][i] + solve(i + 1, (mask ^ (1 << j)), n));
        }
    }
    return dp[i][mask] = ans;
}