/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int ind = abs(nums[i]) - 1;
        if (nums[ind] > 0)
            nums[ind] = -nums[ind];
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}