/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>&arr, int target) //array not sorted
{
    unordered_map <int,int> mpp;
    vector <int> ans;
    for (int i = 0; i < arr.size();i++)
    {
        int x = target - arr[i];
        if (mpp.find(x)!=mpp.end())
        {
            ans.push_back(mpp[x]);
            ans.push_back(i);
            return ans;
        }
        mpp[arr[i]] = i;
    }
    ans = {-1,-1};
    return ans;
}

//two pointer method : only if array is sorted
vector<int> twoSum(vector<int>&arr, int target) //Array sorted
{
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum==target)
        {
            return {arr[i],arr[j]};
        }
        else if (sum > target) j--;
        else i++;
    }
    return {-1};
}