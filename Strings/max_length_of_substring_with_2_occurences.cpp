/*Given a string s, return the maximum length of a
substring such that it contains at most two occurrences of each character.*/

#include <bits/stdc++.h>
using namespace std;

int maximumLengthSubstring(string s)
{
    int l = 0;
    int r = 0;
    int n = s.size();
    unordered_map<char, int> mpp;
    int maxLen = 0;
    for (r = 0; r < n; r++)
    {
        mpp[s[r]]++;
        while (mpp[s[r]] > 2)
        {
            --mpp[s[l++]];
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}