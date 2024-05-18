#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<long long int> &a, vector<long long int> &b)
{
    return a[0] < b[0];
}

int searchIndex(vector<long long int> &startTime, long long int endTime)
{
    int n = startTime.size();
    int low = 0;
    int high = n - 1;
    int upperBoundIndex = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((long long int)startTime[mid] > (long long int)endTime)
        {
            upperBoundIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return upperBoundIndex;
}

long long int solve(int i, vector<long long int> &startTime, vector<long long int> &endTime, vector<long long int> &profit, vector<long long int> &dp)
{
    if (i >= startTime.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ind = searchIndex(startTime, endTime[i]);
    long long int take = profit[i] + solve(ind, startTime, endTime, profit, dp);
    long long int notTake = 0 + solve(i + 1, startTime, endTime, profit, dp);
    return dp[i] = max(take, notTake);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<long long int>> cost(n, vector<long long int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        long long int s, e, c;
        cin >> s >> e >> c;
        cost[i][0] = s;
        cost[i][1] = e;
        cost[i][2] = c;
    }

    sort(cost.begin(), cost.end(), comp);
    vector<long long int> startTime(n);
    vector<long long int> endTime(n);
    vector<long long int> profit(n);

    for (int i = 0; i < n; i++)
    {
        startTime[i] = cost[i][0];
        endTime[i] = cost[i][1];
        profit[i] = cost[i][2];
    }
    vector<long long int> dp(n + 1, -1);
    cout << solve(0, startTime, endTime, profit, dp) << endl;
    return 0;
}