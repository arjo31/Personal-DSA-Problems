#include <bits/stdc++.h>
using namespace std;

/*Given an array arr of distinct elements of size N, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 

arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. */

void zigZagArray(vector<int>&arr)
{
    int n = arr.size();
    bool flag = 1;
    int i = 0;  
    while (i < n)
    {
        if (flag==1 && arr[i+1] > arr[i])
        {
            flag = 0;
        }
        else if (flag==1 && arr[i+1] < arr[i])
        {
            flag = 0;
            swap(arr[i],arr[i+1]);
        }
        else if (flag==0 && arr[i+1] > arr[i])
        {
            flag = 1;
            swap(arr[i],arr[i+1]);
        }
        else if (flag==0 && arr[i+1]<arr[i])
        {
            flag = 1;
        }
        i++;
    }
}