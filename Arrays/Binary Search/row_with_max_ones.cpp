/*You have been given a non-empty grid ‘mat’ with ‘n’ rows and ‘m’ columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there’s no row with at least 1 zero, return -1.*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int maxOnes(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int prevInd = 1e9;
    int rowNumber = 0;
    int ans = -1;
    for  (auto arr : grid)
    {
        int low = 0;
        int high = m-1;
        int ind = -1;
        while (low <= high)
        {
            int mid = low + (high - low)/2;
            if (arr[mid]==0)
            {
                low = mid + 1;
            }
            else
            {
                ind = mid;
                high = mid - 1;
            }
        }
        if (prevInd > ind && ind!=-1)
        {
            prevInd = ind;
            ans = rowNumber;
        }
        rowNumber++;
    }
    return ans;
}