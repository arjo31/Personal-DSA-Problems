// In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has k amount of money initially, find out the maximum number of stocks a customer can buy. 

// For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

#include <bits/stdc++.h>
using namespace std;

struct stocks{
    int price;
    int day;
};

bool comp(struct stocks a, stocks b)
{
    return a.price < b.price;
}

int maxNumberOfStocks(vector<int>prices,int k)
{
    int n = prices.size();
    struct stocks stock[n];
    for (int i = 0; i < n; i++)
    {
        stock[i].price = prices[i];
        stock[i].day = i + 1;
    }
    sort(stock, stock + n, comp);

    int maxStocks = 0;

    for (int i = 0; i < n; i++)
    {
        maxStocks+=min(stock[i].day, k / stock[i].price);
        k = k - stock[i].price * min(stock[i].day, k / stock[i].price);
    }
    return maxStocks;
}