/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible  palindrome partitioning of s.*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    int low = start;
    int high = end;
    while (low <= high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void backtrack(string s, int ind, vector<string> &v, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = ind + 1; i <= s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            v.push_back(s.substr(ind, i - ind));
            backtrack(s, i, v, ans);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> v;
    backtrack(s, 0, v, result);
    return result;
}