/*Given two integers a and b, return the sum of the two integers without using the operators + and -.*/

#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b)
{
    while (b)
    {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}