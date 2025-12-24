/*You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within ‘d’ days.
The weights of the packages are given in an array ‘of weights’. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.*/

#include <bits/stdc++.h>
using namespace std;
int n;

int daysTaken(vector<int> &weights, int capacity)
{
    int daysTaken = 0;
    int cap = 0;
    for (int i = 0; i < n; i++)
    {
        cap += weights[i];
        if (cap > capacity)
        {
            daysTaken += 1;
            cap = weights[i];
        }
    }
    daysTaken += 1;
    return daysTaken;
}

int shipWithinDays(vector<int> &weights, int days)
{
    n = weights.size();
    int minCap = *max_element(weights.begin(), weights.end());
    int maxCap = accumulate(weights.begin(), weights.end(), 0);
    int minDays = maxCap;
    while (minCap <= maxCap)
    {
        int midCap = minCap + (maxCap - minCap) / 2;

        if (daysTaken(weights, midCap) <= days)
        {
            minDays = midCap;
            maxCap = midCap - 1;
        }
        else
            minCap = midCap + 1;
    }
    return minDays;
}