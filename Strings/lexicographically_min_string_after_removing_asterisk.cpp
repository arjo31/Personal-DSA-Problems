/*You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    char ch;
    int idx;
};

struct compare
{
    bool operator()(const node &a, const node &b)
    {
        if (a.ch == b.ch)
            return a.idx < b.idx;
        return a.ch > b.ch;
    }
};

string clearStars(string s)
{
    int n = s.length();

    priority_queue<node, vector<node>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '*')
        {
            if (pq.size() > 0)
                pq.pop();
        }
        else
        {
            pq.push({ch, i});
        }
    }

    vector<pair<int, char>> v;
    while (pq.size() > 0)
    {
        node cur = pq.top();
        pq.pop();

        v.push_back({cur.idx, cur.ch});
    }

    sort(v.begin(), v.end());
    string ans = "";
    for (pair<int, char> p : v)
        ans += p.second;

    return ans;
}
