/*Slavic has a very tough exam and needs your help in order to pass it. Here is the question he is struggling with:

There exists a string s, which consists of lowercase English letters and possibly zero or more "?".

Slavic is asked to change each "?" to a lowercase English letter such that string t becomes a subsequence (not necessarily continuous) of the string s.

Output any such string, or say that it is impossible in case no string that respects the conditions exists.*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long double
#define endl "\n"

const int MOD = 1e9 + 7;

void solve()
{
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (s[i] == '?')
        {
            if (j < m)
                s[i] = t[j++];
            else
                s[i] = 'a';
            i++;
        }
        else if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    if (j >= m)
    {
        cout << "YES" << endl;
        cout << s << endl;
    }
    else
        cout << "NO" << endl;
}