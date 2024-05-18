/*You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given ‘mat’ or not.*/

#include <bits/stdc++.h>
using namespace std;

//O(n + m)
bool searchIn2DArray(vector<vector<int>>&mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m-1;
    while (i < n && j>=0)
    {
        if (mat[i][j]==target) return true;
        if (mat[i][j] > target)
        {
            j--;
        }
        else if (mat[i][j] < target)
        {
            i++;
        }
    }
    return false;
}