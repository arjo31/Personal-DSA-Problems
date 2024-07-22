/*You are given two positive integers n and k.

You can choose any bit in the binary representation of n that is equal to 1 and change it to 0.

Return the number of changes needed to make n equal to k. If it is impossible, return -1.*/

#include <bits/stdc++.h>
using namespace std;

int minChanges(int n, int k)
{
    int count = 0;
    if (n < k)
        return -1;
    while (n)
    {
        int a = n & 1;
        int b = k & 1;
        if (a == 0 && ((a ^ b) == 1))
        {
            count = -1;
            break;
        }
        a = a & 1;
        if (a)
            a = a ^ b;

        if (a)
            count++;
        n = n >> 1;
        k = k >> 1;
    }
    return count;
}