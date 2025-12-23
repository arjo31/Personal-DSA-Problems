/*You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.*/

#include <bits/stdc++.h>
using namespace std;

//Difference array  - Linear search technique (TLE)
int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> prefix_sum(n, 0);
    int k = 0;
    if (zeroArray(nums, prefix_sum))
        return 0;
    for (auto arr : queries)
    {
        int l = arr[0];
        int r = arr[1];
        int shift = arr[2];
        prefix_sum[l] += shift;
        if (r + 1 < n)
            prefix_sum[r + 1] -= shift;
        if (zeroArray(nums, prefix_sum))
            return k + 1;
        else
            k++;
    }
    return -1;
}

bool zeroArray(vector<int> &nums, vector<int> &prefix_sum)
{
    int n = nums.size();
    vector<int> comp;
    copy(prefix_sum.begin(), prefix_sum.end(), back_inserter(comp));
    for (int i = 1; i < n; i++)
    {
        comp[i] += comp[i - 1];
    }
    for (int i = 0; i < n; i++)
        if (nums[i] - comp[i] > 0)
            return false;
    return true;
}

// Difference array  + Binary Search -> Optimal
int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int k = queries.size();
    int low = 0;
    int high = k;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (zeroArray(nums, queries, mid))
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

bool zeroArray(vector<int> &nums, vector<vector<int>> &queries, int k)
{
    int n = nums.size();
    vector<int> prefix(n);
    for (int i = 0; i < k; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        int shift = queries[i][2];
        prefix[l] += shift;
        if (r + 1 < n)
            prefix[r + 1] -= shift;
    }

    for (int i = 1; i < n; i++)
        prefix[i] += prefix[i - 1];

    for (int i = 0; i < n; i++)
    {
        if (nums[i] - prefix[i] > 0)
            return false;
    }
    return true;
}