/*Given two strings s and t, your goal is to convert s into t in k moves or less.

During the ith (1 <= i <= k) move you can:

Choose any index j (1-indexed) from s, such that 1 <= j <= s.length and j has not been chosen in any previous move, and shift the character at that index i times.
Do nothing.
Shifting a character means replacing it by the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Shifting a character by i means applying the shift operations i times.

Remember that any index j can be picked at most once.

Return true if it's possible to convert s into t in no more than k moves, otherwise return false.*/

#include <bits/stdc++.h>
using namespace std;

bool canConvertString(string s, string t, int k)
{
    int n = s.size();
    int m = t.size();
    if (n != m)
        return false;
    vector<int> freq(26, 0);
    for (int i = 1; i <= k; i++)
    {
        freq[i % 26]++;
    }
    for (int i = 0; i < n; i++)
    {
        char old = s[i];
        char _new = t[i];
        if (old == _new)
            continue;
        else if (old < _new)
        {
            if (freq[(_new - 'a') - (old - 'a')] == 0)
                return false;
            freq[(_new - 'a') - (old - 'a')]--;
        }
        else
        {
            if (freq[26 - ((old - 'a') - (_new - 'a'))] == 0)
                return false;
            freq[26 - ((old - 'a') - (_new - 'a'))]--;
        }
    }
    return true;
}