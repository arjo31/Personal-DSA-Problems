/*An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.*/

#include <bits/stdc++.h>
using namespace std;


class SegmentTree
{
    vector<int>seg;
    int n;
    public:
        SegmentTree(int n)
        {
            this->n = n;
            seg.resize(4*n + 1);
        }

        int build(int low, int high, int ind, vector<int>&nums)
        {
            if (low==high)
            {
                seg[ind] = true;
                return seg[ind];
            }
            int mid = low + (high - low)/2;
            int leftTree = build(low, mid, 2*ind + 1, nums);
            int rightTree = build(mid+1, high, 2*ind + 2, nums);
            seg[ind] = (leftTree && rightTree && ((nums[mid]%2)!=(nums[mid+1]%2)));

            return seg[ind];
        }

        int query(int l, int r, int low, int high, int ind, vector<int>&nums)
        {
            if (r < low || l > high) return true;

            if (l<=low && high<=r) return seg[ind];

            int mid = low + (high - low)/2;
            int leftAns = query(l, r, low, mid, 2*ind + 1, nums);
            int rightAns = query(l, r, mid + 1, high, 2*ind + 2, nums);

            if (mid < n - 1 && l <= mid && mid < r) return (leftAns && rightAns && ((nums[mid]%2)!=(nums[mid+1]%2)));

            return leftAns && rightAns;
        }

        void printArray()
        {
            for (int i = 0; i <= 4*n; i++) cout<<seg[i]<<" ";
            cout<<endl;
        }
};

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();
    SegmentTree sg(n);
    vector<bool>res;
    sg.build(0, n - 1, 0, nums);
    for (auto q : queries)
    {
        int l = q[0];
        int r = q[1];
        res.push_back(sg.query(l, r, 0, n - 1, 0, nums));
    }
    return res;
}

int main()
{
    vector<int>nums = {3,4,1,2,6};
    vector<vector<int>>queries = {
        {0,3},
        {0,4},
        {1,3},
        {0,2}
    };
    vector<bool>ans = isArraySpecial(nums, queries);
    for (bool i : ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}