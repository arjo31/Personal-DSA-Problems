/*You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.*/

#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxLength = 0;
    for (r = 0; r < n; r++)
    {
        sum += abs(s[r] - t[r]);
        while (sum > maxCost)
        {
            sum = sum - abs(s[l] - t[l]);
            l++;
        }
        maxLength = max(maxLength, r - l + 1);
    }
    return maxLength;
}