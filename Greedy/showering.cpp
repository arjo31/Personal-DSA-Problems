/*As a computer science student, Alex faces a hard challenge — showering. He tries to shower daily, but despite his best efforts there are always challenges. He takes s minutes to shower and a day only has m minutes!

He already has n tasks planned for the day. Task i is represented as an interval (li, ri), which means that Alex is busy and can not take a shower in that time interval (at any point in time strictly between li and ri). No two tasks overlap.

Given all n time intervals, will Alex be able to shower that day? In other words, will Alex have a free time interval of length at least s*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long double

const int MOD = 1e9 + 7;

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        intervals[i] = {start, end};
    }
    intervals.push_back({m, m});
    intervals.insert(intervals.begin(), {0, 0});

    int prevstartTime = intervals[0][0];
    int prevEndTime = intervals[0][1];
    for (int i = 1; i < n + 2; i++)
    {
        int currStartTime = intervals[i][0];
        int currEndTime = intervals[i][1];
        if (currStartTime - prevEndTime >= s)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            prevEndTime = currEndTime;
        }
    }
    cout << "NO" << endl;
    return;
}