/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.*/

#include <bits/stdc++.h>
using namespace std;

// TC : O(n) and SC : O(n)
vector<int> findDuplicates(vector<int> &nums)
{
    set<int> s;
    vector<int> ans;
    for (int i : nums)
    {
        if (s.find(i) != s.end())
        {
            ans.push_back(i);
            continue;
        }
        s.insert(i);
    }
    return ans;
}

// TC : O(n) and SC : O(1)
vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(0);
    vector<int> res;
    for (int i = 0; i <= n; ++i)
    {
        while (nums[i] != nums[nums[i]])
            swap(nums[i], nums[nums[i]]);
    }
    for (int i = 0; i <= n; ++i)
    {
        if (nums[i] != i)
            res.push_back(nums[i]);
    }
    return res;
}