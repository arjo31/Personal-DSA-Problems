/*Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).*/

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
    }

    long num = labs(n);

    double pow = 1;

    while (num)
    { // equivalent to while(num != 0)
        if (num & 1)
        { // equivalent to if((num & 1) != 0)
            pow *= x;
        }

        x *= x;
        num >>= 1; //(num = num/2)
    }

    return pow;
}