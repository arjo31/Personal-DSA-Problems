/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits == "")
        return ans;
    unordered_map<char, string> mpp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    solve(0, "", ans, digits, mpp);
    return ans;
}

void solve(int ind, string temp, vector<string> &ans, string digits, unordered_map<char, string> &mpp)
{
    if (ind >= digits.size())
    {
        ans.push_back(temp);
        return;
    }

    string letters = mpp[digits[ind]];
    for (char letter : letters)
    {
        solve(ind + 1, temp + letter, ans, digits, mpp);
    }
}