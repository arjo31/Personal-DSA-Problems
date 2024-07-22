/*You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.*/

#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s)
{
    unordered_map<char, int> mpp;
    int count = 0;
    for (char c : s)
    {
        mpp[c]++;
    }

    for (auto it : mpp)
    {
        count += ((it.second % 2 == 0) ? (it.second / 2 - 1) * 2 : (it.second / 2) * 2);
    }

    return s.size() - count;
}