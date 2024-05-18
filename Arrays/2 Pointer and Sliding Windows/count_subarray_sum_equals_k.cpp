/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[sum] = 1;
    for (auto it : nums)
    {
        sum += it;
        int find = sum - k;
        if (mp.find(find) != mp.end())
        {
            ans += mp[find];
        }
        mp[sum]++;
    }
    return ans;
}

// Another solution // Sliding window
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
int atMost(vector<int> &nums, int goal)
{
    int head, tail = 0, sum = 0, result = 0;
    for (head = 0; head < nums.size(); head++)
    {
        sum += nums[head];
        while (sum > goal && tail <= head)
        {
            sum -= nums[tail];
            tail++;
        }
        result += head - tail + 1;
    }
    return result;
}