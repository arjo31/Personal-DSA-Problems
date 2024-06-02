/*You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.*/

#include <bits/stdc++.h>
using namespace std;

int countDays(int days, vector<vector<int>> &meetings)
{
    vector<pair<int, int>> v;
    for (auto meeting : meetings)
    {
        int s = meeting[0], e = meeting[1];
        v.emplace_back(s, 1);
        v.emplace_back(e + 1, -1);
    }
    sort(v.begin(), v.end());

    int freeDays = 0;
    int prevDay = 1;
    int currMeetings = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int currDay = v[i].first;
        int currStatus = v[i].second;

        if (currMeetings == 0)
            freeDays += (currDay - prevDay);
        currMeetings += currStatus;
        prevDay = currDay;
    }
    if (currMeetings == 0)
        freeDays += (days - prevDay + 1);
    return freeDays;
}