/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

void bt(vector<vector<int>> &ans, vector<int> &nums, vector<int> &p, vector<bool> &v)
{
    if (p.size() == nums.size())
    {
        ans.push_back(p);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!v[i])
        {
            v[i] = true;
            p.push_back(nums[i]);
            bt(ans, nums, p, v);
            v[i] = false;
            p.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> p;
    vector<bool> visited(nums.size(), false);
    bt(ans, nums, p, visited);
    return ans;
}