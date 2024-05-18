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

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    long long int queries(long long int ind, long long int low, long long int high, long long int l, long long int r)
    {
        if (r < low || high < l) return 0;
        if (low>=l && high<=r) return seg[ind];

        long long int mid = low + (high - low )/2;
        long long int left = queries(2*ind + 1, low, mid, l, r);
        long long int right = queries(2*ind + 2, mid + 1, high, l, r);

        return left + right;
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low==high)
        {
            seg[ind] += val;
            return;
        }

        int mid = low + (high - low)/2;

        if (i<=mid) update(2*ind + 1, low, mid, i, val);
        else update(2*ind + 2, mid+1, high, i, val);

        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
};

int main()
{
    long long int n;
    cin>>n;
    vector<long long int>arr(n);
    long long int mx = -1;
    for (long long int i = 0; i < n; i++) 
    {
        cin>>arr[i];
        mx = max(mx,arr[i]);
    }
    mx+=1;
    vector<long long int>freq(mx,0);
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    SGTree sg(4*mx);
    sg.build(0,0,mx-1,freq);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]--;
        sg.update(0,0,mx-1,arr[i], -1);
        
        cnt+=sg.queries(0,0,mx-1,1,arr[i]-1);
    }
    cout<<cnt<<endl;

    return 0;
}