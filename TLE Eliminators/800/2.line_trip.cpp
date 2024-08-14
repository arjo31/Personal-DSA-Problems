// Link : https://codeforces.com/problemset/problem/1901/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long double
#define endl "\n"

const int MOD = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n >> x;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int gas_stations;
        cin >> gas_stations;
        s.insert(gas_stations);
    }
    int maxCost = 0;
    int cost = 0;
    for (int i = 1; i <= x; i++)
    {
        cost++;
        maxCost = max(cost, maxCost);
        if (s.count(i))
            cost = 0;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        cost++;
        maxCost = max(cost, maxCost);
        if (s.count(i))
            cost = 0;
    }
    cout << maxCost << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}