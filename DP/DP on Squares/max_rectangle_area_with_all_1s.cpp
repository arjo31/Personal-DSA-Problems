// Given a row X cols binary matrix filled with 0’s and 1’s, find the largest rectangle containing only 1’s and return its area.

#include <bits/stdc++.h>
using namespace std;

// Prerequisite :
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

int maximalAreaOfSubMatrixOfAll(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    cout << n << endl;
    cout << m << endl;
    int maxArea = 0;
    vector<int> heights(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
        }

        int currArea = largestRectangleArea(heights);
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};
    cout << maximalAreaOfSubMatrixOfAll(mat)
         << endl;
    return 0;
}