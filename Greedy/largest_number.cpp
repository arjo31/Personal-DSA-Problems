// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

#include <bits/stdc++.h>
using namespace std;

static bool comp(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), comp);
    string ans = "";
    for (auto it : nums)
    {
        ans += to_string(it);
    }
    if (ans[0] == '0')
        return "0";
    return ans;
}