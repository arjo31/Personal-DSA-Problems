/*You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.*/

#include <bits/stdc++.h>
using namespace std;

int arithmeticTriplets(vector<int> &nums, int diff)
{
    set<int> numSet(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (numSet.count(nums[i] + diff) and numSet.count(nums[i] + 2 * diff))
        {
            count++;
        }
    }

    return count;
}