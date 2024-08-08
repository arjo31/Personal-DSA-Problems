/*A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.*/

#include <bits/stdc++.h>
using namespace std;

bool parseBoolExpr(string expression)
{
    stack<char> s;
    int i = 0;
    bool sol;
    int exp = 0;
    while (i < expression.size())
    {
        char c = expression[i];
        if (c == '(' || c == '!' || c == '|' || c == '&' || c == 'f' || c == 't')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            vector<bool> ans;
            while (s.top() != '(')
            {
                if (s.top() == 'f')
                {
                    ans.push_back(false);
                }
                else if (s.top() == 't')
                {
                    ans.push_back(true);
                }
                s.pop();
            }
            if (exp == 0)
            {
                sol = ans[0];
                exp++;
            }
            s.pop();
            if (s.empty())
                break;
            char op = s.top();
            s.pop();
            if (op == '&')
            {
                for (auto i : ans)
                {
                    sol &= i;
                }
            }
            else if (op == '!')
            {
                sol = !ans[0];
            }
            else if (op == '|')
            {
                for (auto i : ans)
                {
                    sol |= i;
                }
            }
            s.push(sol ? 't' : 'f');
        }
        i++;
    }
    return sol;
}