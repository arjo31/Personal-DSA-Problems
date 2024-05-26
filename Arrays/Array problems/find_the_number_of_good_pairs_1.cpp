/*You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.

A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).

Return the total number of good pairs.

Constraints:

1 <= n, m <= 50
1 <= nums1[i], nums2[j] <= 50
1 <= k <= 50

*/

#include <bits/stdc++.h>
using namespace std;

int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] % (nums2[j] * k) == 0)
                count++;
        }
    }
    return count;
}