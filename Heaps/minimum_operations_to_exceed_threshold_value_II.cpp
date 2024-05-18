/*You are given a 0 - indexed integer array nums, and an integer k.

In one operation, you will :
.Take the two smallest integers x and y in nums.Remove x and y from nums.
.Add min(x, y) * 2 + max(x, y) anywhere in the array.
.Note that you can only apply the described operation if nums contains at least two elements.
Return the minimum number of operations needed so that all elements of the array are greater than
or equal to k.*/

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

    for (long long int it : nums)
    {
        pq.push(it);
    }
    long long ans = 0;
    while (pq.top() < k)
    {
        long long int a = pq.top();
        pq.pop();
        long long int b = pq.top();
        pq.pop();
        ans++;

        long long int c = min(a, b) * 2 + max(a, b);
        pq.push(c);
    }
    return ans;
}