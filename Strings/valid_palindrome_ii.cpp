/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.*/

#include <bits/stdc++.h>
using namespace std;

bool palin(string s, int i, int j)
{
    while (j >= i)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (j >= i)
    {
        if (s[i] != s[j])
        {
            return palin(s, i + 1, j) || palin(s, i, j - 1);
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
