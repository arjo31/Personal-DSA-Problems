// Link : https://codeforces.com/contest/1903/problem/A

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (is_sorted(arr.begin(), arr.end()) || k > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}