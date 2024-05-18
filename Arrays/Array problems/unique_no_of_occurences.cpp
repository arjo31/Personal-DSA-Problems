/*Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.*/

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    for (int i : arr)
    {
        mpp[i]++;
    }
    set<int> s;
    for (auto it : mpp)
    {
        s.insert(it.second);
    }
    return (s.size() == mpp.size());
}