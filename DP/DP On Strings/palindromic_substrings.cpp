/*Given a string s, return the number of palindromic substrings in it.*/

#include <bits/stdc++.h>
using namespace std;

struct manacher
{
    vector<int> p;
    void build(string s)
    {
        string t = "";
        for (char c : s)
        {
            t += string("#") + c;
        }
        t += "#";
        run_manacher(t);
    }

    void run_manacher(string s)
    {
        int n = s.size();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
                p[i] = max(0, min(r - i, p[l + r - i]));
            while (((i + p[i]) < n) && ((i - p[i]) >= 0) && (s[i + p[i]] == s[i - p[i]]))
                p[i]++;
            if (i + p[i] > r)
            {
                r = i + p[i];
                l = i - p[i];
            }
        }
    }
};

int countSubstrings(string s)
{
    struct manacher m;
    m.build(s);
    vector<int> v = m.p;
    int ans = 0;
    for (int i : v)
        ans += i / 2;
    return ans;
}