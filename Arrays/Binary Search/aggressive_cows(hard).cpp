/*You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool canWePlaceCows(vector<int>&stalls, int dist, int cows)
{
    int countCows = 1;
    int lastPlacedCow = stalls[0];
    int n = stalls.size();
    for (int i = 1; i < n ; i++)
    {
        if (stalls[i] - lastPlacedCow >= dist)
        {
            lastPlacedCow = stalls[i];
            countCows++;
        }
    }
    if (countCows>=cows) return true;
    return false;
}

int aggresiveCows(vector<int>&stalls, int cows)
{
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int n = stalls.size();
    int high = stalls[n-1] - stalls[0];
    while (low<=high)
    {
        int mid = low + (high - low) / 2;
        if (canWePlaceCows(stalls,mid,cows))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}