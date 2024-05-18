#include <bits/stdc++.h>
using namespace std;

//Given an array of N strings, find the longest common prefix among all strings present in the array.

string longestCommonPrefix(vector<string>arr)
{
    int n = arr.size();
    if (n==1) return arr[0];
    string s1 = arr[0];
    string s2 = arr[1];
    string ans = "";
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i]==s2[j])
        {
            ans+=s1[i];
            i++;
            j++;
        }
        else break;
    }
    for (int i = 2; i < n; i++)
    {
        s1 = arr[i];
        s2 = ans;
        string common = "";
        int a = 0, b = 0;
        int p = s1.size();
        int q = s2.size();

        while (a < p && b < q)
        {
            if (s1[a]==s2[b])
            {
                common+=s1[a];
                a++;
                b++;
            }
            else break;
        }
        ans = common;
    }
    return (ans!="") ? ans : "-1";
}