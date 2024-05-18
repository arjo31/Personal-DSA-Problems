/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.*/

#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k)
{
    sort(nums.begin(),nums.end());
    long int l = 0, r = 0, n = nums.size(), ans = 0;
    long int sum = 0;
    for (r = 0; r < n; r++)
    {
        sum+=nums[r];
        while(nums[r]*(r-l+1) > sum+k)
        {
            sum-=nums[l];
            l++;
        }
        ans = max(ans,r-l+1);
    }
    return ans;
}