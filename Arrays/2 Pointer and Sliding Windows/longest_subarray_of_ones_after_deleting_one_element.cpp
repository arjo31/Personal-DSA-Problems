
/*Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int l = 0;
    int r = 0;
    int count0 = 0;
    int n = nums.size();
    int maxLen = 0;
    for (r = 0; r < n; r++)
    {
        if (nums[r] == 0)
            count0++;
        while (count0 > 1)
        {
            if (nums[l] == 0)
                count0--;
            l++;
        }
        maxLen = max(maxLen, r - l);
    }
    return maxLen;
}