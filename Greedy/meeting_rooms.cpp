/*Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.
Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int minRooms(vector<vector<int>>&time)
{
    vector<pair<int,int>>v;
    for (auto period : time)
    {
        v.push_back({period[0], +1});
        v.push_back({period[1], -1});
    }
    sort(v.begin(), v.end());
    int rooms = 0;
    int minRooms = 0;
    for (auto it : v)
    {
        rooms+=it.second;
        minRooms = max(rooms,minRooms);
    }
    return minRooms;
}