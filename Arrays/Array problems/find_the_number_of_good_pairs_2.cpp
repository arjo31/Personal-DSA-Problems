/*You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.

A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).

Return the total number of good pairs.

Constraints:

1 <= n, m <= 10^5
1 <= nums1[i], nums2[j] <= 10^6
1 <= k <= 10^3

*/

#include <bits/stdc++.h>
using namespace std;

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    int m = nums2.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < m; i++)
        mpp[nums2[i] * k]++;
    long long ans = 0;
    for (int num : nums1)
    {
        for (int i = 1; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                int div = num / i;
                if (mpp.find(i) != mpp.end())
                    ans += mpp[i];
                if (div != i && mpp.find(div) != mpp.end())
                    ans += mpp[div];
            }
        }
    }
    return ans;
}