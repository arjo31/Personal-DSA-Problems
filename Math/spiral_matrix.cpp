/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans(n * m);
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;
    int k = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans[k] = mat[top][i];
            k++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans[k] = mat[i][right];
            k++;
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans[k] = mat[bottom][i];
                k++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[k] = mat[i][left];
                k++;
            }
            left++;
        }
    }
    return ans;
}