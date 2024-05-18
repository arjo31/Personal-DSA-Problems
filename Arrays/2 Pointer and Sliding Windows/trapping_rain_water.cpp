/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.*/

#include <bits/stdc++.h>
using namespace std;

// TC = O(3N) SC = O(2N)
int totalTrappedRainwater(vector<int> &heights)
{
    int n = heights.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    int sum = 0;
    prefix[0] = heights[0];
    suffix[n - 1] = heights[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(heights[i], prefix[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(heights[i], suffix[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += (min(prefix[i], suffix[i]) - heights[i]);
    }
    return sum;
}

// 2 pointer solution
int totalTrappedRainwater(vector<int> &heights)
{
    int n = heights.size();
    int i = 0;
    int j = n - 1;
    int sum = 0;
    int leftMaxHeight = 0, rightMaxHeight = 0;
    while (i < j)
    {
        if (heights[i] <= heights[j])
        {
            if (heights[i] >= leftMaxHeight)
                leftMaxHeight = heights[i];
            else
                sum += (leftMaxHeight - heights[i]);
            i++;
        }
        else
        {
            if (heights[j] >= rightMaxHeight)
                rightMaxHeight = heights[j];
            else
                sum += (rightMaxHeight - heights[j]);
            j--;
        }
    }
    return sum;
}