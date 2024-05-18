// Given an array of integers heights representing the histogram’s bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Brute force
int maxAreaBrute(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, heights[j]);
            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
}

// Optimized
int maxAreaOpti(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftSmall[n], rightSmall[n];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            leftSmall[i] = 0;

        else
            leftSmall[i] = st.top() - 1;

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = st.top() - 1;

        st.push(i);
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
    }

    return maxArea;
}

// More Optimized
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && ((i == n) || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxArea = max(maxArea, width * height);
        }
        st.push(i);
    }
    return maxArea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << maxAreaBrute(heights) << endl;
    return 0;
}