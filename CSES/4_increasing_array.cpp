#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    long long int moves = 0;
    int prev = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] < prev)
        {
            moves+=(prev-v[i]);
            v[i] = prev;
        }
        prev = v[i];
    }
    cout<<moves<<endl;
    return 0;
}