/*Given a string s, you need to partition it into one or more balanced substrings. For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.

Return the minimum number of substrings that you can partition s into.

Note: A balanced string is a string where each character in the string occurs the same number of times.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int i, string &s)
{
    if (i < 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int freq[26] = {0};
    int ans = 5005;
    for (int j = i; j >= 0; j--)
    {
        freq[s[j] - 'a']++;
        int mini = 5005, maxi = 0;
        for (int k = 0; k < 26; k++)
        {
            if (freq[k])
            {
                mini = min(mini, freq[k]);
                maxi = max(maxi, freq[k]);
            }
        }
        if (mini == maxi)
            ans = min(ans, 1 + solve(j - 1, s));
    }
    return dp[i] = ans;
}

int minimumSubstringsInPartition(string s)
{
    dp.assign(1002, -1);
    int n = s.size();
    return solve(n - 1, s);
}