/*Reverse bits of a given 32 bits unsigned integer.*/

#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i)
        res |= ((n >> i) & 1) << (31 - i);
    return res;
}