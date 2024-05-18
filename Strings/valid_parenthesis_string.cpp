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
    int s1 = 0;
    int a = 0;
    for (auto &x : s)
    {
        if (x == '(')
            s1 += 1;
        if (x == ')')
            s1 -= 1;
        else if (x == '*')
            a++;
        if (s1 < 0)
        {
            if (a == 0)
                return 0;
            a--;
            s1++;
        }
    }
    if (s1 == 0)
        return 1;
    if (a >= s1)
    {

        s1 = 0;
        a = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char x = s[i];
            if (x == '(')
                s1 += 1;
            if (x == ')')
                s1 -= 1;
            else if (x == '*')
                a++;
            if (s1 > 0)
            {
                if (a <= 0)
                    return 0;
                a--;
                s1--;
            }
        }
        return a >= (-1 * s1);
    }

    // if(s1 >= 0 && a >= s1) return 1;
    return a >= (s1);
}