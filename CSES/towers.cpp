#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n);
    multiset<int>temp;
    for (int i = 0; i < n; i++) cin>>arr[i];
    for (int i = 0; i < n; i++)
    {
        auto it = temp.upper_bound(arr[i]);
        if (it==temp.end())
        {
            temp.insert(arr[i]);
        }
        else
        {
            temp.erase(it);
            temp.insert(arr[i]);
        }
    }
    cout<<temp.size()<<endl;
    return 0;
}