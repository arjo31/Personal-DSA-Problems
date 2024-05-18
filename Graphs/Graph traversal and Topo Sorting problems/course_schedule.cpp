#include <bits/stdc++.h>
using namespace std;

/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    int V = numCourses;
    vector<int> indegree(V,0);
    vector<int>adj[V];
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it: adj[node])
        {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    if (ans.size()==V) return ans;
    return {};
}