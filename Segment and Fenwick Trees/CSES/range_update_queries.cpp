#include <bits/stdc++.h>
using namespace std;

#typedef long long int ll;

class SGTree
{
public:
    vector<ll>seg,lazy;

    SGTree(ll n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    
    void build(ll ind, ll low, ll high, vector<ll>&arr)
    {
        if (low==high)
        {
            seg[ind] = arr[low];
            return;
        }
        ll mid = low + (high - low)/2;
        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(ll ind, ll low, ll high, ll l, ll r, ll val)
    {
        if (lazy[ind]!=0)
        {
            seg[ind]+=(high - low + 1)*lazy[ind];
            if (low!=high)
            {
                lazy[2*ind + 1]+=lazy[ind];
                lazy[2*ind + 2]+=lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || r < low) return;
        if (low>=l && high<=r)
        {
            seg[ind]+=(high - low + 1)*val;
            if (low!=high) 
            {
                lazy[2*ind + 1]+=val;
                lazy[2*ind + 2]+=val;
            }
            return;
        }
        ll mid = low + (high - low)/2;
        update(2*ind+1, low, mid, l , r, val);
        update(2*ind+2, mid+1, high, l ,r, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    ll query(ll ind, ll low, ll high, ll i)
    {
        if (lazy[ind]!=0)
        {
            seg[ind]+=(high - low + 1)*lazy[ind]; 
            if (low!=high)
            {
                lazy[2*ind + 1]+=lazy[ind];
                lazy[2*ind + 2]+=lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high==low) return seg[ind];
        ll mid = low + (high - low)/2;
        if (i<=mid) return query(2*ind + 1, low, mid, i);
        return query(2*ind + 2, mid + 1,high, i);
    }
};

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    for (ll i = 0; i < n ; i++) cin>>arr[i];
    SGTree sg(n);
    sg.build(0,0,n-1,arr);
    while (q--)
    {
        ll type;
        cin>>type;
        if (type==1)
        {
            ll l,r,val;
            cin>>l>>r>>val;
            l--,r--;
            sg.update(0,0,n-1,l,r,val);   
        }
        else
        {
            ll k;
            cin>>k;
            k--;
            cout<<sg.query(0,0,n-1,k)<<endl;
        }
    }
    return 0;
}