#include <bits/stdc++.h>
using namespace std;

struct manacher
{
    vector<int> p;

    void run_manacher(string s)
    {
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
                p[i] = max(0, min(r - i, p[l + r - i]));
            while (((i + p[i]) < n) && ((i - p[i]) >= 0) && (s[i + p[i]] == s[i - p[i]]))
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    void build(string s)
    {
        string t = "";
        for (char c : s)
        {
            t += string("#") + c;
        }
        run_manacher(t + "#");
    }
};

string longestPalindrome(string s)
{
    struct manacher m;
    m.build(s);
    vector<int> p = m.p;
    int maxPalindrome = INT_MIN;
    int center = 0;
    bool odd = true;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] > maxPalindrome)
        {
            maxPalindrome = p[i];
            center = i;
            if (center % 2 == 0)
                odd = false;
            else
                odd = true;
        }
    }
    maxPalindrome -= 1;
    int actualCenter = (center - 1 - (!odd)) / 2;
    int l = (2 * actualCenter - maxPalindrome + 1 + (!odd)) / 2;
    return s.substr(l, maxPalindrome);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
}