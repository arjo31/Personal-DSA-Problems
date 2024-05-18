/*Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.*/

#include <bits/stdc++.h>
using namespace std;

int noOfPainters(vector<int>&boards, int timeLimit)
{
    int countPainters = 1;
    int n = boards.size();
    int prevTime = boards[0];
    for (int i = 1; i < n; i++)
    {
        if (prevTime + boards[i] > timeLimit)
        {
            prevTime = boards[i];
            countPainters++;
        }
        else
        {
            prevTime+=boards[i];
        }
    }
    return countPainters;
}

int minTime(vector<int>&boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (noOfPainters(boards,mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}