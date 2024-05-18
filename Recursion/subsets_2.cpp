/*Given an integer array nums that may contain duplicates, return all possible
subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.*/

#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;
void solve(int ind, vector<int> &temp, set<vector<int>> &s, vector<int> &nums)
{
    if (ind >= nums.size())
    {
        s.insert(temp);
        return;
    }
    solve(ind + 1, temp, s, nums);
    temp.push_back(nums[ind]);
    solve(ind + 1, temp, s, nums);
    temp.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> temp;
    sort(nums.begin(), nums.end());
    solve(0, temp, s, nums);
    vector<vector<int>> v;
    for (auto it : s)
    {
        v.push_back(it);
    }
    return v;
}