// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x - axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int maxArea(vector<int> height)
{
    int n = height.size();
    int i = 0, j = n - 1;
    int _max = INT_MIN;
    while (i < j)
    {
        int ans;
        if (height[i] < height[j])
        {
            ans = height[i] * (j - i);
            i++;
        }
        else if (height[i] >= height[j])
        {
            ans = height[j] * (j - i);
            j--;
        }
        _max = max(_max, ans);
    }
    return _max;
}