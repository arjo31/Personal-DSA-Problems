/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = -1, last = -1;
    int si = 0, ei = nums.size() - 1;
    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            ei = mid - 1;
        }
        else if (nums[mid] < target)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    si = 0, ei = nums.size() - 1;
    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            si = mid + 1;
        }
        else if (nums[mid] < target)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return vector<int>{first, last};
}