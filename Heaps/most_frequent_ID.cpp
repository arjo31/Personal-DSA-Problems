/*The problem involves tracking the frequency of IDs in a collection that changes over time. You have two integer arrays, nums and freq, of equal length n. Each element in nums represents an ID, and the corresponding element in freq indicates how many times that ID should be added to or removed from the collection at each step.

Addition of IDs: If freq[i] is positive, it means freq[i] IDs with the value nums[i] are added to the collection at step i.
Removal of IDs: If freq[i] is negative, it means -freq[i] IDs with the value nums[i] are removed from the collection at step i.
Return an array ans of length n, where ans[i] represents the count of the most frequent ID in the collection after the ith step. If the collection is empty at any step, ans[i] should be 0 for that step.*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
{
    int n = nums.size();
    vector<long long> v;
    priority_queue<pair<long long, int>> p;
    unordered_map<int, long long> arr;
    for (int i = 0; i < n; i++)
    {
        int val = nums[i];
        long long fre = freq[i];
        arr[val] += fre;
        if (fre < 0)
        {
            if (p.top().second == val)
            {
                while (p.top().first != arr[p.top().second])
                {
                    long long currVal = p.top().second;
                    p.pop();
                    p.push({arr[currVal], currVal});
                }
            }
            if (p.empty())
            {
                v.push_back(0);
                continue;
            }
            v.push_back(p.top().first);
        }
        else
        {
            p.push({arr[val], val});
            v.push_back(p.top().first);
        }
    }
    return v;
}