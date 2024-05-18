/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int l = 0, r = 0, n = nums.size(), ans = 0;
    int count_0 = 0;
    for (r = 0; r < n; r++)
    {
        if (nums[r] == 0)
            count_0++;
        while (count_0 > k)
        {
            if (nums[l] == 0)
                count_0--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}