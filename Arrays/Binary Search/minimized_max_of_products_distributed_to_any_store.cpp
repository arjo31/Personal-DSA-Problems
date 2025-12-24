/*You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.*/

#include <bits/stdc++.h>
using namespace std;

int noOfStores(vector<int> &quantities, int maxCapacity)
{
    int stores = 0;
    for (int quantity : quantities)
    {
        stores += (quantity < maxCapacity) ? 1 : ceil((double)quantity / maxCapacity);
    }
    return stores;
}

int minimizedMaximum(int n, vector<int> &quantities)
{
    int l = 1;
    int h = *max_element(begin(quantities), end(quantities));
    int ans = h;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (noOfStores(quantities, mid) <= n)
        {
            ans = h;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}