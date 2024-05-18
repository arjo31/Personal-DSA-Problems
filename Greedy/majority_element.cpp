#include <bits/stdc++.h>
using namespace std;


//One method in O(N) time and O(1) space is the Bayer - Moore's Algorithm, but we are going to apply bits in this question
int majorityElement(vector<int>&arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0 ; i < 32 ; i++)
    {
        int noOfOnes = 0;
        for (auto num : arr)
        {
            if ((1<<i) & num)
            {
                noOfOnes+=1;
            }
        }
        if (noOfOnes > n/2)
        {
            ans+=(1<<i);
        }
    }
    return ans;
}