/*Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.*/

#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    int n = s.size();
    unordered_map<char, int> mpp;
    int l = 0;
    int r = 0;
    int maxLen = 0;
    for (r = 0; r < n; r++)
    {
        mpp[s[r]]++;
        while (mpp.size() > k)
        {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}