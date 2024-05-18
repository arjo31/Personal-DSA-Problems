/*You are given an integer array nums.

Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

void seiveOfErastosthenes()
{
    isPrime.resize(101, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= 100; p++)
    {
        if (isPrime[p])
        {
            for (int k = p * p; k <= 100; k += p)
            {
                isPrime[k] = false;
            }
        }
    }
}

int maximumPrimeDifference(vector<int> &nums)
{
    seiveOfErastosthenes();
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        if (isPrime[nums[i]] && isPrime[nums[j]])
            return j - i;
        else if (isPrime[nums[i]] && !isPrime[nums[j]])
            j--;
        else if (!isPrime[nums[i]] && isPrime[nums[j]])
            i++;
        else
        {
            i++;
            j--;
        }
    }
    return -1;
}