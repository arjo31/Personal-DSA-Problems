/*Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.*/

#include <bits/stdc++.h>
using namespace std;

// Two pointer technique
string reverseVowels(string s)
{
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int n = s.size();
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (vowels.count(s[l]) && vowels.count(s[r]))
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
        else if (vowels.count(s[l]))
            r--;
        else if (vowels.count(s[r]))
            l++;
        else
        {
            l++;
            r--;
        }
    }
    return s;
}