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

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    long long int queries(long long int ind, long long int low, long long int high, long long int l, long long int r)
    {
        if (r < low || high < l) return LONG_LONG_MAX;
        if (low>=l && high<=r) return seg[ind];

        long long int mid = low + (high - low )/2;
        long long int left = queries(2*ind + 1, low, mid, l, r);
        long long int right = queries(2*ind + 2, mid + 1, high, l, r);

        return min(left,right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low==high)
        {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low)/2;

        if (i<=mid) update(2*ind + 1, low, mid, i, val);
        else update(2*ind + 2, mid+1, high, i, val);

        seg[ind] = min(seg[2*ind + 1],seg[2*ind + 2]);
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
        int type;
        cin>>type;
        if (type==2)
        {
            long long int l,r;
            cin>>l>>r;
            cout<<sg.queries(0,0,n-1,l-1,r-1)<<endl;
        }
        else
        {
            long long int i, val;
            cin>>i>>val;
            sg.update(0,0,n-1,i-1,val);
            arr[i-1] = val;
        }
    }
    return 0;
}