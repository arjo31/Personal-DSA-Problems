/*Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force : O(n) time and O(n/2 + 2) space
vector<int> singleNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i : nums)
        mpp[i]++;
    for (auto it : mpp)
        if (it.second == 1)
            ans.push_back(it.first);
    return ans;
}

// Another method : O(n) time and O(1) space
vector<int> singleNumber(vector<int> &nums)
{
    int n = nums.size();
    long long int _xor = 0;
    for (int i : nums)
        _xor = _xor ^ i;
    int b1 = 0;
    int b2 = 0;
    int rightmostBit = (_xor & (_xor - 1)) ^ _xor;
    for (int i : nums)
    {
        if (i & rightmostBit)
            b1 = b1 ^ i;
        else
            b2 = b2 ^ i;
    }
    return {b1, b2};
}