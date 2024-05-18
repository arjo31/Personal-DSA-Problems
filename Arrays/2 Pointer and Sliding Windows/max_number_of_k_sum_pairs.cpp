/*You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.*/

#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int count = 0;
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum == k)
        {
            count++;
            i++;
            j--;
        }
        else if (sum < k)
        {
            i++;
        }
        else
            j--;
    }
    return count;
}