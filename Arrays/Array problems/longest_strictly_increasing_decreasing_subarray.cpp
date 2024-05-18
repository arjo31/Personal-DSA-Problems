/*You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.*/

#include <bits/stdc++.h>
using namespace std;

int lenOfLongDecSubArr(vector<int> &a)
{
    int mx = 1, cur = 1, n = a.size();
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            cur++;
        else
        {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    return max(cur, mx);
}
int lenOfLongIncSubArr(vector<int> &a)
{
    int mx = 1, cur = 1, n = a.size();
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            cur++;
        else
        {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    return max(cur, mx);
}
int longestMonotonicSubarray(vector<int> &nums)
{
    return max(lenOfLongIncSubArr(nums), lenOfLongDecSubArr(nums));
}