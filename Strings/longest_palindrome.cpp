/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> mpp;
    for (char c : s)
    {
        mpp[c]++;
    }
    int count = 0;
    bool hasOddFreq = false;
    for (auto it : mpp)
    {
        count = count + 2 * (it.second / 2);
        if (it.second % 2 != 0)
        {
            hasOddFreq = true;
        }
    }
    return hasOddFreq ? count + 1 : count;
}