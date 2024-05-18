/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    map<int, int> mpp;
    for (int i : nums)
    {
        mpp[i]++;
    }
    priority_queue<pair<int, int>> p;
    for (auto it : mpp)
    {
        p.push({it.second, it.first});
    }
    while (k-- && !p.empty())
    {
        ans.push_back(p.top().second);
        p.pop();
    }
    return ans;
}