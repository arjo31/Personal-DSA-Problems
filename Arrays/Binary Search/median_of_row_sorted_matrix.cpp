/*Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.

Assume – r*c is odd*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>&arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>>&mat, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt+=upperBound(mat[i], x);
    }
    return cnt;
}

int median(vector<vector<int>>&mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low,mat[i][0]);
        high = max(high,mat[i][m-1]);
    }

    int req = (n * m)/2;
    while (low<=high)
    {
        int mid = (low + high)/2;
        int smallEqual = countSmallEqual(mat,n,mid);
        if (smallEqual <= req) low = mid+1;
        else high = mid - 1;
    }
    return low;
}