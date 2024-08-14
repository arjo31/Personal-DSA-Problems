// Link : https://codeforces.com/problemset/problem/1900/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long double
#define endl "\n"

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int countEmptyCells = (s[0] == '.') ? 1 : 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '.')
            countEmptyCells++;

        if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.')
        {
            cout << 2 << endl;
            return;
        }
    }
    if (s[n - 1] == '.' && n != 1)
        countEmptyCells++;
    cout << countEmptyCells << endl;
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