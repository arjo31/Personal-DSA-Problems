/*You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.*/

#include <bits/stdc++.h>
using namespace std;

//Method 1 : Difference array
string shiftingLetters(string s, vector<int> &shifts)
{
    int n = shifts.size();
    vector<long long int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        nums[0] += shifts[i];
        if (i + 1 < n)
            nums[i + 1] -= shifts[i];
    }
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans += char('a' + (s[i] - 'a' + nums[i]) % 26);
    }
    return ans;
}

//Method 2 : One pass solution
string shiftingLetters(string s, vector<int> &shifts)
{
    int n = shifts.size();
    long long int shift = 0;
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        shift = (shift + shifts[i]);
        ans += char('a' + (s[i] - 'a' + shift) % 26);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}