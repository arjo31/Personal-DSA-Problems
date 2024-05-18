// Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Using built in function : next_permutation(vector)
vector<int> nextPermutation(vector<int> &arr)
{
    int n = arr.size();

    int breakPointIndex = n - 1;

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i - 1] < arr[i])
        {
            breakPointIndex = i - 1;
            break;
        }
    }
    if (breakPointIndex == n - 1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for (int i = n - 1; i > breakPointIndex; i--)
    {
        if (arr[i] > arr[breakPointIndex])
        {
            swap(arr[breakPointIndex], arr[i]);
            break;
        }
    }
    reverse(arr.begin() + breakPointIndex + 1, arr.end());
    return arr;
}

int main()
{
    vector<int> arr = {2, 3, 1, 0, 0, 4};
    nextPermutation(arr);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}