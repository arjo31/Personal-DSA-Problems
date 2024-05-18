/*Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum K valid sum combinations from all the possible sum combinations.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int K)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();
    priority_queue<pair<int, pair<int, int>>> pq;

    set<pair<int, int>> s;

    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});

    s.insert({n - 1, n - 1});
    vector<int> ans;
    for (int count = 0; count < K; count++)
    {
        auto temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];
        pair<int, int> temp1 = {i - 1, j};
        if (s.find(temp1) == s.end())
        {
            pq.push({sum, temp1});
            s.insert(temp1);
        }
        sum = A[i] + B[j - 1];
        temp1 = {i, j - 1};
        if (s.find(temp1) == s.end())
        {
            pq.push({sum, temp1});
            s.insert(temp1);
        }
    }
    return ans;
}