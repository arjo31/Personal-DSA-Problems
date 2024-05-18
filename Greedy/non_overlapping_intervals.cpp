/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.*/

#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), comp);
    int count = 0;
    int prevEndTime = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        int currStartTime = intervals[i][0];
        int currEndTime = intervals[i][1];
        if (currStartTime < prevEndTime)
        {
            count++;
        }
        else
        {
            prevEndTime = currEndTime;
        }
    }
    return count;
}