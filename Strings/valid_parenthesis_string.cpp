/*Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".*/

#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    int n = s.size();
    int min = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            min = min + 1;
            max = max + 1;
        }
        else if (s[i] == ')')
        {
            min = min - 1;
            max = max - 1;
        }
        else
        {
            min = min - 1;
            max = max + 1;
        }
        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }
    return (min == 0);
}