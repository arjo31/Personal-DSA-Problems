/*You are given a 0-indexed array nums of size n consisting of positive integers.

You are also given a 2D array queries of size m where queries[i] = [indexi, ki].

Initially all elements of the array are unmarked.

You need to apply m queries on the array in order, where on the ith query you do the following:

Mark the element at index index i if it is not already marked.
Then mark ki unmarked elements in the array with the smallest values. If multiple such elements exist, mark the ones with the smallest indices. And if less than ki unmarked elements exist, then mark all of them.
Return an array answer of size m where answer[i] is the sum of unmarked elements in the array after the ith query.*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<long long> ans;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> p;
    int n = nums.size();
    int m = queries.size();
    unordered_set<long long> s;
    for (int i = 0; i < n; i++)
    {
        p.push({nums[i], i});
    }
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    for (int i = 0; i < m; i++)
    {
        int ind = queries[i][0];
        int k = queries[i][1];
        if (s.find(ind) == s.end())
        {
            s.insert(ind);
            sum = sum - nums[ind];
        }
        while (k-- && !p.empty())
        {
            auto it = p.top();
            int val = it.first;
            int index = it.second;
            p.pop();
            if (s.find(index) == s.end())
            {
                s.insert(index);
                sum = sum - val;
            }
            else
                k++;
        }
        ans.push_back(sum);
    }
    return ans;
}