#include <bits/stdc++.h>
using namespace std;

/*The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.*/
struct things
{
    int weight;
    int value;
    double vw;
};

bool comp(struct things i1,things i2)
{
    if (i1.vw > i2.vw) return true;
    return false;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    struct things item[n];
    for (int i = 0; i<n; i++)
    {
        item[i].weight = items[i].first;
        item[i].value = items[i].second;
        item[i].vw = (double)items[i].second/(double)items[i].first;
    }
    sort(item,item + n,comp);
    int rem = w;
    double value = 0;
    int i = 0;
    while(rem>0 && i < n)
    {
        if (rem < item[i].weight)
        {
            value+=(double)(rem*item[i].vw);
            rem = rem - item[i].weight;
        } else {
            value += item[i].vw * item[i].weight;
            rem = rem - item[i].weight;
            i++;
        }
    }
    return value;
}