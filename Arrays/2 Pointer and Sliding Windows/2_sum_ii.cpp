/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int low = 0;
    int high = numbers.size() - 1;
    vector<int> ans;
    while (low < high)
    {
        int sum = numbers[low] + numbers[high];
        if (sum == target)
        {
            ans.push_back(low + 1);
            ans.push_back(high + 1);
            return ans;
        }
        else if (sum < target)
            low++;
        else
            high--;
    }
    return ans;
}