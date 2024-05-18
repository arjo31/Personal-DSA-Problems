#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0 ; i < n ; i++) cin>>arr[i];
    vector<bool>haveGondolaYet(n);
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] > x)
        {
            j--;
        }
        else
        {
            haveGondolaYet[i] = haveGondolaYet[j] = true;
            ans++;
            i++;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans+=(haveGondolaYet[i]==false);
    }
    cout<<ans<<endl;
    return 0;
}