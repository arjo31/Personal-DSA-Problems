#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    set<int>s;
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < n)
    {
        while (j < n && !s.count(v[j]))
        {
            s.insert(v[j]);
            ans = max(ans, j - i + 1);
            j++;
        }
        while (j < n && s.count(v[j]))
        {
            s.erase(v[i]);
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}