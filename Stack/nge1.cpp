#include <bits/stdc++.h>
using namespace std;

// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

unordered_map<int, int> mpp;
void nge(vector<int> &arr)
{
    stack<int> st;
    st.push(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }

        while (!st.empty() && st.top() < arr[i])
        {
            mpp[st.top()] = arr[i];
            st.pop();
        }

        st.push(arr[i]);
    }

    while (!st.empty())
    {
        mpp[st.top()] = -1;
        st.pop();
    }
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    nge(nums2);
    vector<int> ans;
    for (int q : nums1)
    {
        ans.push_back(mpp[q]);
    }
    return ans;
}