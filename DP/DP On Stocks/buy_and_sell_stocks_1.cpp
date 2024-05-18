/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

// Note..this is not DP...This is an intro to a series of problems to be done by DP

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(prices[i] - minPrice, maxProfit);
    }
    return maxProfit;
}