/*You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.*/

#include <bits/stdc++.h>
using namespace std;

// Difference array method
string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    vector<long long> nums(n, 0);
    for (auto arr : shifts)
    {
        int l = arr[0];
        int r = arr[1];
        int sign = (arr[2] == 1) ? 1 : -1;
        nums[l] += sign;
        if (r + 1 < n)
            nums[r + 1] -= sign;
    }

    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        int shift = nums[i] % 26;
        if (shift < 0)
            shift += 26;
        ans += char('a' + (s[i] - 'a' + shift) % 26);
    }
    return ans;
}