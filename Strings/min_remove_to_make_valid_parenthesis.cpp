/*Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.*/

#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    int openParenthesesCount = 0;
    vector<char> arr(s.begin(), s.end());
    // First pass: mark excess closing parentheses with '*'

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == '(')
            openParenthesesCount++;
        else if (arr[i] == ')')
        {
            if (openParenthesesCount == 0)
                arr[i] = '*';
            else
                openParenthesesCount--;
        }
    }

    // Second pass: mark excess opening parentheses from the end
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (openParenthesesCount > 0 && arr[i] == '(')
        {
            arr[i] = '*'; // Mark excess opening parentheses
            openParenthesesCount--;
        }
    }

    string result = "";
    for (char c : arr)
    {
        if (c != '*')
            result += c;
    }

    return result;
}

// Using stack

string minRemoveToMakeValid(string s)
{
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            if (!st.empty() && s[st.top()] == '(')
                st.pop();
            else
                st.push(i);
        }
    }
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (!st.empty() && st.top() == i)
        {
            st.pop();
            continue;
        }
        else
            ans = ans + s[i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
