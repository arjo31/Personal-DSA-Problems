#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> prefixFunc(string s)
{
    int n = s.size();
    int i = 1, prevLPS = 0;
    vector<int>pi(n,0);
    while (i < n)
    {
        if (s[i]==s[prevLPS])
        {
            pi[i] = prevLPS + 1;
            prevLPS++;
            i++;
        }
        else if (prevLPS==0)
        {
            pi[i] = 0;
            i++;
        }
        else
        {
            prevLPS = pi[prevLPS - 1];
        }
    }
    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word,pattern;
    cin>>word;
    cin>>pattern;

    string ans = pattern + '/' + word;
    vector<int>res = prefixFunc(ans);
    int count = 0;
    for (auto it : res)
    {
        if (it==pattern.size()) count++;
    }
    cout<<count<<endl;
    return 0;
}