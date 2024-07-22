/*You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int k, vector<vector<int>> &arr)
{
    vector<int> ans;
    vector<int> adj[k + 1];
    for (int i = 0; i < arr.size(); i++)
    {
        int u = arr[i][0];
        int v = arr[i][1];
        adj[u].push_back(v);
    }
    vector<int> indegree(k + 1);
    for (int i = 1; i <= k; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;

    for (int i = 1; i <= k; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return ans;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    vector<int> rowOrdering = topoSort(k, rowConditions);
    vector<int> colOrdering = topoSort(k, colConditions);

    // for (int row : rowOrdering)
    //     cout << row << " ";
    // cout << endl;
    // for (int col : colOrdering)
    //     cout << col << " ";
    // cout << endl;

    vector<vector<int>> ans(k, vector<int>(k));
    if (rowOrdering.size() != k || colOrdering.size() != k)
        return {};
    vector<int> row(k + 1, -1);
    vector<int> col(k + 1, -1);

    for (int i = 0; i < k; i++)
    {
        row[rowOrdering[i]] = i;
        col[colOrdering[i]] = i;
    }

    for (int i = 1; i <= k; i++)
    {
        ans[row[i]][col[i]] = i;
    }
    return ans;
}