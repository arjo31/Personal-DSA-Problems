/*There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.*/

#include <bits/stdc++.h>
using namespace std;

int minCapability(vector<int> &nums, int k)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

bool isPossible(vector<int> &nums, int mid, int k)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= mid)
        {
            count++;
            i++;
        }
    }
    return count >= k;
}