/*You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.*/

#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int r = 0;
    int l = 0;
    int maxLen = 0;
    unordered_map<char, int> mpp;
    for (r = 0; r < n; r++)
    {
        mpp[str[r]]++;
        while (mpp.size() > k)
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}