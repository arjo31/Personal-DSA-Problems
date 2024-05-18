/*Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> mpp;
    int n = s.size();
    int m = t.size();
    for (char c : t)
    {
        mpp[c]++;
    }
    int l = 0;
    int r = 0;
    int minLen = 1e9;
    int count = 0;
    int ind = -1;
    for (r = 0; r < n; r++)
    {
        if (mpp[s[r]] > 0)
            count++;
        mpp[s[r]]--;
        while (count == m)
        {
            if ((r - l + 1) < minLen)
            {
                minLen = r - l + 1;
                ind = l;
            }
            mpp[s[l]]++;
            if (mpp[s[l]] > 0)
                count = count - 1;
            l++;
        }
    }
    return (ind == -1) ? "" : s.substr(ind, minLen);
}