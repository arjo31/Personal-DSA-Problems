/*Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
        }
        while (minHeap.size() > this->k)
        {
            minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};