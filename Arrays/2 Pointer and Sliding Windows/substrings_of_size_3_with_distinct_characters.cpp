/*A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.*/

#include <bits/stdc++.h>
using namespace std;

int countGoodSubstrings(string s)
{
    if (s.size() < 3)
        return 0;
    unordered_map<char, int> mpp;
    for (int i = 0; i < 3; i++)
        mpp[s[i]]++;
    int count = (mpp.size() == 3);
    cout << count << endl;
    int l = 0;
    int r = 3;
    while (r < s.size())
    {
        mpp[s[l]]--;
        if (mpp[s[l]] == 0)
            mpp.erase(s[l++]);
        else
            l++;
        mpp[s[r++]]++;
        count += (mpp.size() == 3);
        cout << count << endl;
    }
    return count;
}