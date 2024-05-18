/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.*/

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int m = s2.size();
    int i = 0;
    string str = s2.substr(i, m);
    sort(s1.begin(), s1.end());
    while (str.size() == m)
    {
        str = s2.substr(i, m);
        sort(str.begin(), str.end());
        if (str == s1)
            return true;
        i++;
    }
    return false;
}