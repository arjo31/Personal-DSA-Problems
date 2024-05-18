#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//This algorithm finds all occurrences of a pattern in a text in linear time. Let length of text be n and of pattern be m, then total time taken is O(m + n) with linear space complexity.

//Kind of like reverse KMP Algo... We need Z array

//z[i] is the length of the longest string that is, at the same time, a prefix of word, and a prefix of the suffix of word starting at i

vector<int> zFunction(string s)
{
    int n = s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}