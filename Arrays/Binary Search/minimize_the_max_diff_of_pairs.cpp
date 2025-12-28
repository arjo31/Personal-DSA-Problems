/*You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.*/

#include <bits/stdc++.h>
using namespace std;

int noOfPairs(vector<int> &nums, int diff)
{
    int n = nums.size();
    int pairs = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(nums[i] - nums[i - 1]) <= diff)
        {
            pairs++;
            i++;
        }
    }
    return pairs;
}

int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = *max_element(begin(nums), end(nums)) - *min_element(begin(nums), end(nums));
    int ans = r;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (noOfPairs(nums, mid) >= p)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}