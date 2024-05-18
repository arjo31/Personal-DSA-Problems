#include <bits/stdc++.h>
using namespace std;

// O(n) palindrome substring checking

struct manacher
{
    vector<int> p;

    void run_manacher(string s)
    {
        cout << s << endl;
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
                p[i] = max(0, min(r - i, p[l + r - i]));
            while ((i + p[i] < n) && (i - p[i]) >= 0 && s[i + p[i]] == s[i - p[i]]) // l & r are exclusive
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
        for (auto it : p)
            cout << it << " ";
        cout << endl;
    }

    void build(string s)
    {
        string t;
        for (char c : s)
        {
            t += string("#") + c;
        }
        run_manacher(t + "#");
    }

    int getLongest(int center, bool odd)
    {
        int pos = 2 * center + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalin(int l, int r)
    {
        return ((r - l + 1) <= getLongest(((l + r) / 2), (l % 2 == r % 2)));
    }
} m;