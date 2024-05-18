// You are given an array happiness of length n, and a positive integer k.

// There are n children standing in a queue, where the ith child has happiness value happiness[i].You want to select k children from these n children in k turns.

// In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

// Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    int n = happiness.size();
    sort(happiness.rbegin(), happiness.rend());
    long long sum = 0;
    int chance = 0;
    int i = 0;
    while (k--)
    {
        sum += (happiness[i] - chance > 0) ? (happiness[i] - (chance == 0 ? 0 : chance)) : 0;
        chance++;
        i++;
    }
    return sum;
}