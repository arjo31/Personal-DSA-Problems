/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).*/

#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    long long int sum = 0;
    long long int len = -1;
    long long int p = abs(x);
    while (p > 0)
    {
        p = p / 10;
        len++;
    }
    p = abs(x);
    while (p > 0)
    {
        int q = p % 10;
        sum = sum + q * pow(10, len);
        --len;
        p = p / 10;
    }
    if (x < 0)
    {
        sum = sum * (-1);
    }
    if (sum < INT_MIN or sum > INT_MAX - 1)
    {
        return 0;
    }
    else
        return sum;
}