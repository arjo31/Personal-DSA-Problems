/*You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).*/

#include <bits/stdc++.h>
using namespace std;

int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    vector<int> inDegree(n);
    vector<vector<int>> graph(n, vector<int>());
    for (auto &edge : relations)
    {
        int prev = edge[0] - 1, next = edge[1] - 1;
        graph[prev].push_back(next);
        inDegree[next]++;
    }

    vector<int> dist(n);
    queue<int> q;
    for (int u = 0; u < n; ++u)
    {
        if (inDegree[u] == 0)
        {
            q.push(u);
            dist[u] = time[u];
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            dist[v] = max(dist[v], dist[u] + time[v]); // Update `dist[v]` using the maximum dist of the predecessor nodes
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }
    return *max_element(dist.begin(), dist.end());
}