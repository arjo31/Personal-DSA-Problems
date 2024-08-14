/*A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.*/

#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return n;
    int i = 0;
    while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
    if (i == n - 1)
        return 1;
    bool diff = nums[i + 1] > nums[i];
    int ans = 2;
    for (; i < n - 1; i++)
    {
        if (diff && nums[i + 1] < nums[i])
        {
            ans++;
            diff = !diff;
        }
        else if (!diff && nums[i + 1] > nums[i])
        {
            diff = !diff;
            ans++;
        }
    }
    return ans;
}