/*Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> dp;
int n;

vector<string> dfs(string &s, vector<string> &wordDict, int start)
{
    if (start == n)
        return {""};
    if (!dp[start].empty())
        return dp[start];

    vector<string> ans;

    for (string &w : wordDict)
    {
        int sz = w.size();
        if (start + sz <= n && s.substr(start, sz) == w)
        {
            vector<string> rest = dfs(s, wordDict, start + sz);
            for (string &r : rest)
                ans.push_back(w + (r.empty() ? "" : " ") + r);
        }
    }
    return dp[start] = ans;
}

vector<string> wordBreak(string &s, vector<string> &wordDict)
{
    n = s.size();
    dp.resize(n + 1);
    return dfs(s, wordDict, 0);
}