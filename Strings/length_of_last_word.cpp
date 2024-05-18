/*Given a string s consisting of words and spaces, return the length of the last word in the string.*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int count = 0;
    int n = s.size();
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
            break;
    }
    for (int j = i; j >= 0; j--)
    {
        if (s[j] == ' ')
            break;
        count++;
    }
    return count;
}