/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/

#include <bits/stdc++.h>
using namespace std;

// Method 1
unordered_map<int, int> mpp;
void nge(vector<int> &arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            st.push(i);
            continue;
        }

        while (!st.empty() && arr[st.top()] < arr[i])
        {
            mpp[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        mpp[st.top()] = -1;
        st.pop();
    }
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> arr;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        arr.push_back(nums[i]);
    for (int i = 0; i < n; i++)
        arr.push_back(nums[i]);
    nge(arr);
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(mpp[i]);
    }
    return ans;
}

// Method 2
vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            ans[st.top()] = nums[i];
            st.pop();
        }
    }
    return ans;
}