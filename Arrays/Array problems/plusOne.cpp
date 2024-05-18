/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    if (digits[n - 1] != 9)
    {
        digits[n - 1] += 1;
        return digits;
    }
    int sum;
    vector<int> ans;
    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            sum = digits[i] + 1 + carry;
            carry = sum / 10;
        }
        else
        {
            sum = digits[i] + carry;
            carry = sum / 10;
        }
        ans.push_back(sum % 10);
    }
    if (carry == 1)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}