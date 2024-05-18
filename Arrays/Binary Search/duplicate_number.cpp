/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>&arr)
{
    int n = arr.size();
    int left = 1;
    int right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left)/2;
        int count = 0;

        for (int i : arr)
        {
            if (i <= mid)
            {
                count++;
            }
        }
        
        if (count > mid) //Duplicate lies on the left half
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

// 1 3 4 3 5 2
/*
left = 1, right = 5
mid = 3, count = 4
*/

//Tortoise and Hare Algorithm
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast)
        {
            break;
        }
    }

    int slow2 = nums[0];

    while (slow != slow2)
    {
        slow = nums[slow];
        slow2 = nums[slow2];
    }

    return slow;
}