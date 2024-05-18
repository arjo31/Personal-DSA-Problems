// You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

//If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

#include <bits/stdc++.h>
using namespace std;

//Same function as lower bound

//Will implement using STL
int searchInsert(vector<int>&arr, int x)
{
    return lower_bound(arr.begin(), arr.end(),x) - arr.begin();
}