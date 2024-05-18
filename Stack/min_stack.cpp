/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    vector<pair<int, int>> v;
    MinStack()
    {
    }

    void push(int val)
    {

        if (v.empty())
        {
            pair<int, int> p = make_pair(val, val);
            v.push_back(p);
        }

        else
        {

            int temp = min(val, v.back().second);
            pair<int, int> p = make_pair(val, temp);
            v.push_back(p);
        }
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back().first;
    }

    int getMin()
    {
        return v.back().second;
    }
};