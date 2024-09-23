/*You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can take at most one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.*/

#include <bits/stdc++.h>
using namespace std;

int maximumCandies(vector<int> &candies, long long k)
{
    int low = 1;
    int high = *max_element(candies.begin(), candies.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, candies, k))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

bool isPossible(int mid, vector<int> &candies, long long k)
{
    long long child = 0;
    int n = candies.size();
    for (int i = 0; i < n; i++)
    {
        child += ((long long)candies[i] / mid);
    }
    return (child >= k);
}