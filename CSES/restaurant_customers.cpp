#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?*/

    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for (int i = 0; i < n; i++)
    {
        int s,e;
        cin>>s>>e;
        arr.push_back({s,+1});
        arr.push_back({e,-1});
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int maxCustomers = 0;
    for (auto it : arr)
    {
        ans+=it.second;
        maxCustomers = max(maxCustomers,ans);
    }
    cout<<maxCustomers<<endl;

    return 0;
}