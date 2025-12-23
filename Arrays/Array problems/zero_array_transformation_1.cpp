/*You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.*/

#include <bits/stdc++.h>
using namespace std;

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> prefix(n);

    for (auto arr : queries)
    {
        int l = arr[0];
        int r = arr[1];

        prefix[l] += -1;
        if (r + 1 < n)
            prefix[r + 1] -= -1;
    }

    for (int i = 1; i < n; i++)
        prefix[i] += prefix[i - 1];

    for (int i = 0; i < n; i++)
    {
        if (nums[i] + prefix[i] > 0)
            return false;
    }
    return true;
}