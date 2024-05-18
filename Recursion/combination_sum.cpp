/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void solve(int i, vector<int> &arr, vector<int> &temp, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
        return;

    if (i == arr.size())
        return;
    solve(i + 1, arr, temp, target);

    temp.push_back(arr[i]);
    solve(i, arr, temp, target - arr[i]);
    temp.pop_back();
}
vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    ans.clear();

    vector<int> temp;
    solve(0, arr, temp, target);
    return ans;
}