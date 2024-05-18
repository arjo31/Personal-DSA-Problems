/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.*/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{
    return atMost(nums, k) - atMost(nums, k - 1);
}
int atMost(vector<int> &nums, int k)
{
    int n = nums.size();
    int r = 0;
    int l = 0;
    int count = 0;
    for (r = 0; r < n; r++)
    {
        k -= (nums[r] % 2);
        while (k < 0)
        {
            k += (nums[l] % 2);
            l++;
        }
        count += r - l + 1;
    }
    return count;
}