/*You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.*/

// Youtube link : https://www.youtube.com/watch?v=nJZ_Ob3VIQs

#include <bits/stdc++.h>
using namespace std;

int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int Q = queries.size();
    sort(queries.begin(), queries.end());
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>past;
    int j = 0;
    int usedQuery = 0;
    for (int i = 0; i < n; i++) {
        while (j < Q && queries[j][0]==i) {
            maxHeap.push(queries[j][1]);
            j++;
        }
        nums[i]-=past.size(); //Checking whether we can impact current i from any past queries endings

        while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
            past.push(maxHeap.top());
            usedQuery++;
            maxHeap.pop();
            nums[i]--;
        }
        
        if (nums[i] > 0) return -1;

        // Remove outdated past indices
        while (!past.empty() && past.top() <= i) past.pop();
    }
    return Q - usedQuery;
}