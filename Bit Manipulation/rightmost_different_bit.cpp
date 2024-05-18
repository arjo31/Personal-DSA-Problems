//Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.

#include<bits/stdc++.h>
using namespace std;

int rightMostBit(int m, int n)
{
    int count = 0;
    if(m==n) return -1;
    while(true)
    {
        int d1 = m&1;
        int d2 = n&1;
        if (d1!=d2) return count + 1;
        else
        {
            count++;
            n = n>>1;
            m = m>>1;
        }
    }
    return -1;
}
