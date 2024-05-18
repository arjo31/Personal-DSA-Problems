/*You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.*/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    int l = 0;
    int r = 0;
    int n = fruits.size();
    int maxFruits = 0;
    unordered_map<int, int> mpp;
    for (r = 0; r < n; r++)
    {
        mpp[fruits[r]]++;
        while (mpp.size() > 2)
        {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);
            l++;
        }
        maxFruits = max(maxFruits, r - l + 1);
    }
    return maxFruits;
}