/*You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.*/

#include <bits/stdc++.h>
using namespace std;

int n;

int dp[100001][3];

int binary_search(vector<vector<int>>&events, int currentEndTime)
{
    int l = 0;
    int r = n - 1;
    int ans = n;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (events[mid][0] > currentEndTime)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int solve(vector<vector<int>> &events, int i, int count)
{
    if (count == 2 || i >= n)
        return 0;
    if (dp[i][count] != -1)
        return dp[i][count];
    int nextValidIndex = binary_search(events, events[i][1]);
    int take = events[i][2] + solve(events, nextValidIndex, count + 1);
    int not_take = solve(events, i + 1, count);
    return dp[i][count] = max(take, not_take);
}

int maxTwoEvents(vector<vector<int>> &events)
{
    n = events.size();
    sort(events.begin(), events.end());
    memset(dp, -1, sizeof(dp));
    int count = 0;
    return solve(events, 0, count);
}