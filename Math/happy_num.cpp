/*Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.*/

#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    unordered_set<int> set;
    int sum, d;
    while (n != 1)
    {
        set.insert(n);
        sum = 0;
        while (n != 0)
        {
            d = n % 10;
            sum += d * d;
            n = n / 10;
        }
        if (set.count(sum))
        {
            return false;
        }
        n = sum;
    }
    return true;
}