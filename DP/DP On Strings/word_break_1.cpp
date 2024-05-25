/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.*/

#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second));
    }
};

bool solve(int ind, string temp, string &s, set<string> &st, unordered_map<pair<int, string>, bool, pair_hash> &dp)
{
    pair<int, string> key = {ind, temp};
    if (ind == s.size())
        return dp[key] = (st.find(temp) != st.end());

    if (dp.find(key) != dp.end())
        return dp[key];

    if (st.find(temp) != st.end())
    {
        if (solve(ind, "", s, st, dp))
            return dp[key] = true;
    }

    if (ind < s.size() && solve(ind + 1, temp + s[ind], s, st, dp))
        return dp[key] = true;

    return dp[key] = false;
}

// Another solve function
bool solve(int ind, string temp, string &s, set<string> &st, unordered_map<pair<int, string>, bool, pair_hash> &dp)
{
    pair<int, string> key = {ind, temp};
    if (ind == s.size())
        return dp[key] = (st.find(temp) != st.end());

    if (dp.find(key) != dp.end())
        return dp[key];

    bool take = solve(ind + 1, temp + s[ind], s, st, dp);

    bool notTake = false;
    if (st.find(temp) != st.end())
    {
        notTake = solve(ind, "", s, st, dp);
    }

    return dp[key] = take || notTake;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<pair<int, string>, bool, pair_hash> dp;
    set<string> st(wordDict.begin(), wordDict.end());
    return solve(0, "", s, st, dp);
}

// Tabular method
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    for (int i = n - 1; i >= 0; i--)
    {
        for (string word : wordDict)
        {
            int W = word.size();
            if (i + W <= n && s.substr(i, W) == word)
                dp[i] = dp[i + W];
            if (dp[i])
                break;
        }
    }
    return dp[0];
}