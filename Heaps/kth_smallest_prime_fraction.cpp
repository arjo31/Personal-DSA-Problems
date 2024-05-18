/*You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].*/

#include <bits/stdc++.h>
using namespace std;

//Method 1
vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> p;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            p.push({(double)arr[i] / (double)arr[j], {arr[i], arr[j]}});
        }
    }
    while (k--)
    {
        int a = p.top().second.first;
        int b = p.top().second.second;
        p.pop();
        if (k == 0)
            return {a, b};
    }
    return {};
}

//Method 2
vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    priority_queue<pair<double, pair<int, int>>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            double frac = arr[i] / (double)arr[j];
            if (pq.size() < k)
            {
                pq.push({frac, {arr[i], arr[j]}});
            }
            else if (pq.top().first > frac)
            {
                pq.pop();
                pq.push({frac, {arr[i], arr[j]}});
            }
        }
    }
    return {pq.top().second.first, pq.top().second.second};
}