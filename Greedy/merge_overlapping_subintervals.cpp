// Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingSubintervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    int prevEndTime = intervals[0][1];
    int prevStartTime = intervals[0][0];
    vector<vector<int>> ans;
    for (int i = 1; i < n; i++)
    {
        int currEndTime = intervals[i][1];
        int currStartTime = intervals[i][0];
        if (currStartTime <= prevEndTime)
        {
            prevEndTime = max(prevEndTime, currEndTime);
        }
        else
        {
            ans.push_back({prevStartTime, prevEndTime});
            prevStartTime = currStartTime;
            prevEndTime = currEndTime;
        }
    }
    ans.push_back({prevStartTime, prevEndTime});
    return ans;
}