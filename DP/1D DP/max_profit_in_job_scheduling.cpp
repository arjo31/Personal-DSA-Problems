/*We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.


Variation of this problem in CSES folder : Projects*/

#include <bits/stdc++.h>
using namespace std;

// O(n^2)
static bool comp(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }

int solve(vector<vector<int>> &cost, int ind, vector<int> &dp)
{
    if (ind >= cost.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int take = cost[ind][2];
    for (int k = ind + 1; k < cost.size(); k++)
    {
        if (cost[k][0] >= cost[ind][1])
        {
            take = max(take, cost[ind][2] + solve(cost, k, dp));
        }
    }
    int notTake = 0 + solve(cost, ind + 1, dp);
    return dp[ind] = max(take, notTake);
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> cost(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        cost[i][0] = startTime[i];
        cost[i][1] = endTime[i];
        cost[i][2] = profit[i];
    }
    sort(cost.begin(), cost.end(), comp);
    vector<int> dp(n + 1, -1);
    return solve(cost, 0, dp);
}

// DP with Binary Search
int searchIndex(vector<int> &startTime, int key)
{
    int n = startTime.size();
    int low = 0;
    int high = n - 1;
    int lowerBoundIndex = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (startTime[mid] >= key)
        {
            lowerBoundIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return lowerBoundIndex;
}

int solve(int i, vector<int> &startTime, vector<int> &endTime, vector<int> &profit, vector<int> &dp)
{
    if (i >= startTime.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int ind = searchIndex(startTime, endTime[i]);
    int take = profit[i] + solve(ind, startTime, endTime, profit, dp);
    int notTake = 0 + solve(i + 1, startTime, endTime, profit, dp);
    return dp[i] = max(take, notTake);
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> cost(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        cost[i][0] = startTime[i];
        cost[i][1] = endTime[i];
        cost[i][2] = profit[i];
    }
    sort(cost.begin(), cost.end(), comp);
    for (int i = 0; i < n; i++)
    {
        startTime[i] = cost[i][0];
        endTime[i] = cost[i][1];
        profit[i] = cost[i][2];
    }

    vector<int> dp(n + 1, -1);
    int ans = solve(0, startTime, endTime, profit, dp);
    // for (int i = 0; i<=n; i++) cout<<dp[i]<<" ";
    return ans;
}