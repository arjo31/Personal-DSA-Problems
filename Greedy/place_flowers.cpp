// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no - adjacent - flowers rule and false otherwise.

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(int n, vector<int> flowerbed)
{
    int l = flowerbed.size();
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        if (flowerbed[i] == 0)
        {
            bool leftPlot = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightPlot = (i == l - 1) || (flowerbed[i + 1] == 0);

            if (leftPlot && rightPlot)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
}