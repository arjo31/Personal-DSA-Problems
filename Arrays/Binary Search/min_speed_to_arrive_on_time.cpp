/*You are given a floating-point number hour, representing the amount of time you have to reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and hour will have at most two digits after the decimal point.*/

#include <bits/stdc++.h>
using namespace std;

int n;

double timeTaken(vector<int> &dist, int speed)
{
    double hoursTaken = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            hoursTaken += ceil((double)dist[i] / speed);
        else
            hoursTaken += (double)dist[i] / speed;
    }
    return hoursTaken;
}

int minSpeedOnTime(vector<int> &dist, double hour)
{
    n = dist.size();
    int l = 1;
    int r = 1e7;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (timeTaken(dist, mid) <= hour)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}