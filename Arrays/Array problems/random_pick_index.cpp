/*Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, vector<int>> mpp;

public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]].push_back(i);
        }
    }

    int pick(int target)
    {
        return (mpp[target][rand() % mpp[target].size()]);
    }
};