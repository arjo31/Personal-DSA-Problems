#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<long long int>seg;
public:

    SGTree(long long int n)
    {
        seg.resize(4*n+1);
    }

    void build(long long int ind, long long int low, long long int high, vector<long long int>&arr)
    {
        if (low==high)
        {
            seg[ind] = arr[low];
            return ;
        }

        long long int mid = low + (high - low)/2;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid+1, high, arr);

        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }

    long long int queries(long long int ind, long long int low, long long int high, long long int l, long long int r)
    {
        if (r < low || high < l) return 0;
        if (low>=l && high<=r) return seg[ind];

        long long int mid = low + (high - low )/2;
        long long int left = queries(2*ind + 1, low, mid, l, r);
        long long int right = queries(2*ind + 2, mid + 1, high, l, r);

        return left ^ right;
    }
};

int main()
{
    long long int n,q;
    cin>>n>>q;
    vector<long long int>arr(n);
    for (long long int i = 0; i < n; i++) cin>>arr[i];
    SGTree sg(n);
    sg.build(0,0,n-1,arr);
    while (q--)
    {
        long long int l,r;
        cin>>l>>r;
        cout<<sg.queries(0,0,n-1,l-1,r-1)<<endl;
    }
    return 0;
}