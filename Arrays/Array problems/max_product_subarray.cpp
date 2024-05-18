/*Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxLeft = nums[0];
    int maxRight = nums[0];

    int prod = 1;

    bool zeroPresent = false;

    for (auto i : nums)
    {
        prod *= i;
        if (i == 0)
        {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxLeft = max(maxLeft, prod);
    }

    prod = 1;

    for (int j = nums.size() - 1; j >= 0; j--)
    {
        prod *= nums[j];
        if (nums[j] == 0)
        {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxRight = max(maxRight, prod);
    }

    if (zeroPresent)
        return max(max(maxLeft, maxRight), 0);
    return max(maxLeft, maxRight);
}