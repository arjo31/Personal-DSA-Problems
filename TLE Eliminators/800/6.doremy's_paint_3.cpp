// Link : https://codeforces.com/problemset/problem/1890/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long double
#define endl "\n"

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mpp[x]++;
    }
    if (mpp.size() >= 3)
        cout << "NO" << endl;
    else
    {
        if (abs(mpp.begin()->second - mpp.rbegin()->second) <= 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}