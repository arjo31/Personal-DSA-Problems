/*Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.*/

#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;
    int ans = -1;
    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            ans = nums1[i];
            break;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return ans;
}