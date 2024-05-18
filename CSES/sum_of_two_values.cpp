#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n ; i++)
    {
        int x;
        cin>>x;
        arr[i] = {x,i+1};
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = n-1;
    while (i < j)
    {
        int sum = arr[i].first + arr[j].first;
        if (sum==x)
        {
            cout<<arr[i].second<<" "<<arr[j].second;
            return;
        }
        else if(sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;    
}

int main()
{
    solve();
    return 0;
}