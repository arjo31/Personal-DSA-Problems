/*Given a string s, find the length of the longest
substring
 without repeating characters.*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int l = 0, r = 0, n = s.size(), ans = 0;
    unordered_map<char, int> mpp;
    for (r = 0; r < n; r++)
    {
        mpp[s[r]]++;
        while (mpp[s[r]] > 1)
        {
            mpp[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}
