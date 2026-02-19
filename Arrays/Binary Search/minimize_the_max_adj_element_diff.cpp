/*You are given an array of integers nums. Some values in nums are missing and are denoted by -1.

You must choose a pair of positive integers (x, y) exactly once and replace each missing element with either x or y.

You need to minimize the maximum absolute difference between adjacent elements of nums after replacements.

Return the minimum possible difference.*/

// Youtube link : https://www.youtube.com/watch?v=J_2DtfCHeSI

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums, int x, int y, int d)
{
    int count = 0; // Number of -1's
    int prev = 0;  // Previously seen non -1 element
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == -1)
        {
            if (prev != 0 && min(abs(prev - x), abs(prev - y)) > d)
            {
                return false;
            }
            count++;
        }
        else
        {
            if (count > 0)
            {
                int absDiffResult;
                if (prev != 0)
                { // case : {a, -1, -1, -1, b}
                    int all_x = max(abs(prev - x), abs(nums[i] - x));
                    int all_y = max(abs(prev - y), abs(nums[i] - y));
                    absDiffResult = min(all_x, all_y);
                }
                else
                { // case : {-1, -1, -1, b}
                    absDiffResult = min(abs(nums[i] - x), abs(nums[i] - y));
                }

                // Mix x and y values
                bool canMix = (count >= 2 && abs(x - y) <= d);

                if (absDiffResult > d && !canMix)
                {
                    return false;
                }
            }
            prev = nums[i];
            count = 0;
        }
    }
    return true;
}

int minDifference(vector<int> &nums)
{
    int n = nums.size();

    int min_val = INT_MAX; // Find the minimum value surrounding the -1's
    int max_val = 0;       // Find the maximum value surrounding the -1's
    int maxAbsDiff = 0;    // Between two adj elements not equal to -1

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] != -1 && nums[i + 1] != -1)
        {
            maxAbsDiff = max(maxAbsDiff, abs(nums[i] - nums[i + 1]));
        }
        else if (!(nums[i] == -1 && nums[i + 1] == -1))
        {                                        // All cases like {-1, a}, {a, -1}, {a, -1, b}, etc.. Not {-1,-1}
            int val = max(nums[i], nums[i + 1]); // val is the number except -1
            min_val = min(min_val, val);
            max_val = max(max_val, val);
        }
    }
    int l = maxAbsDiff;
    int r = max_val - min_val;

    int result = l;

    while (l <= r)
    {
        int d = l + (r - l) / 2;
        int x = min_val + d;
        int y = max_val - d;
        if (check(nums, x, y, d))
        {
            result = d;
            r = d - 1;
        }
        else
        {
            l = d + 1;
        }
    }
    return result;
}