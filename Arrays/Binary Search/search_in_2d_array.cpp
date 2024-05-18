/*You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given ‘mat’ or not.*/

#include <bits/stdc++.h>
using namespace std;

//O(n + m)
int searchIn2DArray(vector<vector<int>>&mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m-1;
    while (i < n)
    {
        if (mat[i][j] < target)
        {
            i++;
            continue;
        }
        if (mat[i][j] >= target)
        {
            auto arr = mat[i];
            while (j >=0)
            {
                if (arr[j]==target) return true;
                j--;
            }
        }
        return false;
    }
    return false;
}

//Another method
//O(log(n*m))
int searchIn2DArray(vector<vector<int>>&mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = n*m - 1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col]==target) return true;
        else if (mat[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}