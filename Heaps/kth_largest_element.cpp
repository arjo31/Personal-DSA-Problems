/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int> p;
    for (auto it : nums)
    {
        p.push(it);
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(p.top());
        p.pop();
    }
    return ans.back();
}

// Another Approach (O(nlogk))
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    return min_heap.top();
}

// Optimum Approach : Quickselect (O(n))
int partition(vector<int> &nums, int left, int right, int pivot_index)
{
    int pivot = nums[pivot_index];
    swap(nums[pivot_index], nums[right]);
    int stored_index = left;
    for (int i = left; i < right; i++)
    {
        if (nums[i] < pivot)
        {
            swap(nums[i], nums[stored_index]);
            stored_index++;
        }
    }
    swap(nums[right], nums[stored_index]);
    return stored_index;
}

int findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1;
    while (true)
    {
        int pivot_index = rand() % (right - left + 1) + left;
        int new_pivot_index = partition(nums, left, right, pivot_index);
        if (new_pivot_index == nums.size() - k)
        {
            return nums[new_pivot_index];
        }
        else if (new_pivot_index > nums.size() - k)
        {
            right = new_pivot_index - 1;
        }
        else
        {
            left = new_pivot_index + 1;
        }
    }
}