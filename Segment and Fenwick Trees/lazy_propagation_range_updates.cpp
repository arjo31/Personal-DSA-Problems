//Given range [L...R] update all values in range by some val
#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int>seg,lazy;
public:
    SGTree(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }

    void build(int ind, int low, int high, vector<int>&arr)
    {
        if (low==high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low)/2;

        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2]; //For min :  min(seg(2*i+1),seg(2*i+2))
    }

    void update(int ind, int low, int high, int l, int r, int val)
    {
        //Update the previous remaining updates and propagate downwards
        if (lazy[ind]!=0)
        {
            seg[ind]+=(high - low + 1)*lazy[ind]; //For min : seg[ind]+=lazy[ind]
            //propagate the lazy update downwards for the remaining nodes to get updated
            if (low!=high)
            {
                lazy[2*ind + 1]+=lazy[ind];
                lazy[2*ind + 2]+=lazy[ind];
            }

            lazy[ind] = 0;
        }

        //No overlap
        if (high < l || r < low) return;

        //Complete overlap
        if (low>=l && high<=r)
        {
            seg[ind]+=(high - low + 1)*val; ////For min : seg[ind]+=val
            if (low!=high) //Not a leaf node..Propagate
            {
                lazy[2*ind + 1]+=val;
                lazy[2*ind + 2]+=val;
            }
            return;
        }

        //Partial
        int mid = low + (high - low)/2;

        update(2*ind+1, low, mid, l , r, val);
        update(2*ind+2, mid+1, high, l ,r, val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r)
    {
        //Update if any updates are remaing as the nide will stay freah and updated
        if (lazy[ind]!=0)
        {
            seg[ind]+=(high - low + 1)*lazy[ind]; ////For min : seg[ind]+=lazy[ind]
            //propagate the lazy update downwards for the remaining nodes to get updated
            if (low!=high)
            {
                lazy[2*ind + 1]+=lazy[ind];
                lazy[2*ind + 2]+=lazy[ind];
            }

            lazy[ind] = 0;
        }

        if (high < l || r < low)
        {
            return 0;
        }

        if (low>=l && high <=r) return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2*ind + 1, low, mid, l , r);
        int right = query(2*ind + 2, mid + 1, high, l , r);

        return (left + right);
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n ; i++) cin>>arr[i];
    SGTree sg(n);
    sg.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<sg.query(0,0,n-1,l,r)<<endl;
        }
        else
        {
            int l,r,val;
            cin>>l>>r>>val;
            sg.update(0,0,n-1,l,r,val);            
        }
    }
    return 0;
}