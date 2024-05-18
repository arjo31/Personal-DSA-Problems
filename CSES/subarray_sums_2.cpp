#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    map<long long int, int>mpp;
    long long int ans = 0;
    long long int prefix_sum = 0;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefix_sum+=arr[i];
        ans+=mpp[prefix_sum - x];
        mpp[prefix_sum]++;
    }
    cout<<ans<<endl;
    return 0;
}