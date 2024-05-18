#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    int i = 0, j = 0;
    int ans = 0;
    int sum = 0;
    for (; j < n ; j++)
    {
        sum+=arr[j];
        while (sum > x)
        {
            sum = sum - arr[i];
            i++;
        }
        if (sum==x)
        {
            sum = sum - arr[i];
            i++;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}