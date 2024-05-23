/*You are given an array nums of inditive integers and a inditive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (indsibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.*/

#include <bits/stdc++.h>
using namespace std;

int c = 0;

bool checkCondition(vector<int> temp, int k)
{
    if (temp.size() == 0)
        return false;
    set<int> s;
    int n = temp.size();
    for (int i = 0; i < n; i++)
    {
        if (s.count(temp[i] - k) || s.count(temp[i] + k))
            return false;
        s.insert(temp[i]);
    }
    return true;
}

void solve(int ind, vector<int> &nums, vector<int> &temp, int k)
{
    if (ind >= nums.size())
    {
        if (checkCondition(temp, k))
        {
            c++;
        }
        return;
    }
    solve(ind + 1, nums, temp, k); // Exclude current element
    temp.push_back(nums[ind]);
    solve(ind + 1, nums, temp, k); // Include current element
    temp.pop_back();
}

int beautifulSubsets(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp;
    solve(0, nums, temp, k);
    return c;
}

// Another method:
int count = 0;

int ans;
unordered_map<int, int> rec;
int beautifulSubsets(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    ans = 0;
    vector<int> tmp;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        rec[nums[i]]++;
        recursion(i + 1, n, tmp, nums, k);
        rec[nums[i]]--;
    }
    return ans;
}

void recursion(int ind, int n, vector<int> &tmp, vector<int> &nums, int k)
{
    if (ind == n)
    {
        ans++;
        return;
    }
    if (rec[nums[ind] - k] == 0)
    {
        rec[nums[ind]]++;
        recursion(ind + 1, n, tmp, nums, k);
        rec[nums[ind]]--;
    }
    recursion(ind + 1, n, tmp, nums, k);
}