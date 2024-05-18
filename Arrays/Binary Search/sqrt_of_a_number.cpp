//You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of ‘sqrt(n)’.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sqrtBS(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}