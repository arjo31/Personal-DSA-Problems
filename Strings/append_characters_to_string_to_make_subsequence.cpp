/*You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.*/

#include <bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t)
{
    int n = s.size();
    int m = t.size();
    ;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
            j++;
        i++;
    }
    return m - j;
}