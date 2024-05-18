//Segment trees are used in range queries, where you need to find out the minimum/sum etc. in an array in a given array or so
#include <bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int>seg; 
public:
    SGTree(int n)
    {
        seg.resize(4*n+1);
    }
    void build(int ind,int low, int high,vector<int>&arr)
    {
        if (low==high)
        {
            seg[ind] = arr[low];
            return ;
        }

        int mid = low + (high - low)/2;
        build(2*ind+1, low,mid,arr); //Build the left subtree
        build(2*ind+2,mid+1,high,arr); //Build the right subtree

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    int queries(int ind, int low, int high, int l, int r)
    {
        //No Overlap of range
        //[l r][low high] || [low high][l r]
        if (r < low || high < l) return INT_MAX;

        //Complete overlap
        //[l low high r]
        if (low>=l && high<=r) return seg[ind];

        int mid = low + (high - low)/2;
        int left = queries(2*ind+1,low,mid,l,r);
        int right = queries(2*ind+2,mid+1,high,l,r);

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
        if (i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind + 2, mid+1, high, i, val);

        seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n ;i++) cin>>arr[i];
    SGTree sg(n);
    sg.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1) //Only find the minimum
        {
            int l,r;
            cin>>l>>r;
            cout<<sg.queries(0,0,n-1,l,r)<<endl;
        }
        else
        {
            int i,val; //Update the segment tree and change the value at the index given
            cin>>i>>val;
            sg.update(0,0,n-1,i,val);
            arr[i] = val;
        }
    }
    return 0;
}