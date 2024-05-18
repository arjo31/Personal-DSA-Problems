/*You are given two integer arrays nums1 and nums2 of length n.

The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).

For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
Rearrange the elements of nums2 such that the resulting XOR sum is minimized.

Return the XOR sum after the rearrangement.*/

#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int bitset, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
{
    if (ind >= nums1.size())
        return 0;

    if (dp[ind][bitset] != -1)
        return dp[ind][bitset];

    int sum = INT_MAX;
    for (int i = 0; i < nums2.size(); i++)
    {
        if (bitset & (1 << i))
        {
            int newbitset = bitset ^ (1 << i);
            sum = min(sum, (nums1[ind] ^ nums2[i]) + solve(ind + 1, newbitset, nums1, nums2, dp));
        }
    }
    return dp[ind][bitset] = sum;
}

int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>((1 << n) + 5, -1));
    return solve(0, (1 << n) - 1, nums1, nums2, dp);
}