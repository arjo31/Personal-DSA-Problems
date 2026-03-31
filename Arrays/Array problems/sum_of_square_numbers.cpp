/*Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.*/

#include <bits/stdc++.h>
using namespace std;

bool judgeSquareSum(int c)
{
    int i = 0;
    int j = sqrt(c);
    while (i <= j)
    {
        if (1LL * i * i + 1LL * j * j == c)
            return true;
        else if (1LL * i * i + 1LL * j * j > c)
            j--;
        else
            i++;
    }
    return false;
}