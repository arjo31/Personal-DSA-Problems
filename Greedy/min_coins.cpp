#include <bits/stdc++.h>
using namespace std;

/*Given a value of V Rs and an infinite supply of each of the denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, The task is to find the minimum number of coins and/or notes needed to make the change?*/

vector<int> MinimumCoins(int n)
{
    vector<int> currency = {1,2,5,10,20,50,100,500,1000}; 
    // Initialize result
    vector<int> ans;
 
    // Traverse through all currency
    for (int i = 8; i >= 0; i--) {
 
        // Find currencys
        while (n >= currency[i]) {
            n -= currency[i];
            ans.push_back(currency[i]);
        }
    }
    return ans;
}