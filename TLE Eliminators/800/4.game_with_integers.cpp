// Link : https://codeforces.com/problemset/problem/1899/A

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
    if (n % 3 == 0)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
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