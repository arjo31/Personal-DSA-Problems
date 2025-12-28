/*You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.*/

#include <bits/stdc++.h>
using namespace std;

int n;

long long noOfCars(vector<int> &ranks, long long minutes)
{
    long long carCount = 0;
    for (int i = 0; i < n; i++)
    {
        carCount += sqrt(minutes / (long long)ranks[i]);
    }
    return carCount;
}

long long repairCars(vector<int> &ranks, int cars)
{
    long long l = 1;
    long long r = *max_element(ranks.begin(), ranks.end()) * (long long)cars * (long long)cars;
    long long ans = r;
    n = ranks.size();
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        if (noOfCars(ranks, mid) >= cars)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}