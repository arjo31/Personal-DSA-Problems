/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;

bool isOperator(string s)
{
    return (s == "+" || s == "-" || s == "*" || s == "/");
}
int evalRPN(vector<string> &tokens)
{
    stack<string> st;
    int result = 0;
    for (string s : tokens)
    {
        if (!isOperator(s))
            st.push(s);
        else
        {
            if (s == "+")
            {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                result = (y + x);
                st.push(to_string(result));
            }
            else if (s == "-")
            {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                result = (y - x);
                st.push(to_string(result));
            }
            else if (s == "*")
            {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                result = y * x;
                st.push(to_string(result));
            }
            else if (s == "/")
            {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                result = y / x;
                st.push(to_string(result));
            }
        }
    }
    return stoi(st.top());
}