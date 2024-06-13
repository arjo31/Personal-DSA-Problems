/*Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.*/

#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    map[0] = -1; // To handle the case where the sub-array starts from index 0
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int rem = sum % k;

        if (map.find(rem) != map.end())
        {
            if (i - map[rem] > 1)
            {
                return true;
            }
        }
        else
        {
            map[rem] = i;
        }
    }
    return false;
}