/*Given a square matrix M[][] of size N X N, such that M[i][j] = 1 means ith person knows jth person, the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. Return the index of the celebrity, if there is no celebrity return -1.

Note: Follow 0 based indexing and M[i][i] will always be 0.*/

#include <bits/stdc++.h>
using namespace std;

// Graph Method : TC : O(n^2) and SC : O(n)
int celebrityProblem(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (outdegree[i] == 0 && indegree[i] == n - 1)
            return i;
    }
    return -1;
}

// Stack Method : TC : O(n) and SC : O(n)
int celebrityProblem(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    stack<int> s;
    int C;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (matrix[A][B])
            s.push(B);
        else
            s.push(A);
    }

    C = s.top();
    s.pop();

    for (int i = 0; i < n; i++)
    {
        if ((i != C) && (matrix[C][i] || !matrix[i][C]))
            return -1;
    }

    return C;
}

// 2 pointer : TC : O(2n) and SC : O(1)
int celebrityProblem(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int top = 0;
    int bottom = n - 1;
    while (top < bottom)
    {
        if (matrix[top][bottom])
            top++;
        else
            bottom--;
    }

    if (top > bottom)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (top == i)
            continue;
        if (matrix[i][top] == 0 || matrix[top][i] == 1)
            return -1;
    }
    return top;
}