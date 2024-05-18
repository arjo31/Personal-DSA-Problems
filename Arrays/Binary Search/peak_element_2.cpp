/*A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.*/

#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>>&mat, int n, int m, int col)
{
    int maxVal = -1;
    int ind = -1;
    for (int i = 0; i < n;i++)
    {
        if (mat[i][col] > maxVal)
        {
            maxVal = mat[i][col];
            ind = i;
        }
    }
    return ind;
}

vector<int>indicesOfPeakElement(vector<vector<int>>&mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        int maxRowIndex = findMaxIndex(mat,n,m,mid);
        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;
        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {
            return {maxRowIndex,mid};
        }
        else if(mat[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return {-1,-1};
}