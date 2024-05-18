/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.*/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0};
    bool thash[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && thash[t[i]] == 0)
        {                       // check whetere the element was already mapped
            hash[s[i]] = t[i];  // map the element of s with t
            thash[t[i]] = true; // check wheter mapped
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (char(hash[s[i]] != t[i]))
        {                 // if not mapped
            return false; // return false
        }
    }

    return true;
}

// Another method

bool isIsomorphic(string &s, string &t)
{
    int n = s.size();
    // Using size 256  for ASCII characters
    bitset<256> s_char = 0, t_char = 0;
    char st[256] = {0};
    char ts[256] = {0};

    for (int i = 0; i < n; i++)
    {
        char cs = s[i], ct = t[i];
        if (s_char[cs] == 0 && t_char[ct] == 0)
        {
            st[cs] = ct;
            ts[ct] = cs;
            s_char[cs] = 1;
            t_char[ct] = 1;
        }
        else
        {
            if (st[cs] != ct || ts[ct] != cs)
            {
                return 0;
            }
        }
    }
    return 1;
}
