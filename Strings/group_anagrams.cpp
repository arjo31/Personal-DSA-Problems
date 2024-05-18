/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    map<string, vector<string>> mpp;
    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        mpp[key].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto x : mpp)
    {
        ans.push_back(x.second);
    }
    return ans;
}