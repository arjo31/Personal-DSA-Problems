// Link : https://codeforces.com/problemset/problem/1896/A

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (is_sorted(arr.begin(), arr.end()) || arr[0] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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