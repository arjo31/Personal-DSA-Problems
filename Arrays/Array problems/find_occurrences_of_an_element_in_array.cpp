/*You are given an integer array nums, an integer array queries, and an integer x.

For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

Return an integer array answer containing the answers to all queries.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
{
    int n = nums.size();
    vector<int> ind;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
            ind.push_back(i);
    }
    int j = 0;
    while (j < queries.size())
    {
        int q = queries[j];
        if (q - 1 < ind.size())
        {
            ans.push_back(ind[q - 1]);
        }
        else
            ans.push_back(-1);
        j++;
    }
    return ans;
}