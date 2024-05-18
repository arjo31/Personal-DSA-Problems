/*Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.*/
#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    if (k<=1) return 0;
    long long int r = 0, l = 0, n = nums.size(), ans = 1;
    long long int count = 0;
    for (r = 0; r < n; r++)
    {
        ans*= nums[r];

        while (ans>=k)
        {
            ans/= nums[l];
            l++;
        }
        count+=r-l+1;
    }
    return count;
}