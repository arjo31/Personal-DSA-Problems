/*There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group must be paid at least their minimum wage expectation.
In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.*/

#include <bits/stdc++.h>
using namespace std;

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
{
    int n = quality.size();
    vector<pair<double, int>> ratio;
    for (int i = 0; i < n; i++)
    {
        ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
    }
    sort(ratio.begin(), ratio.end());
    priority_queue<int> maxHeap;
    int qualitySum = 0;
    double maxRate = 0.0;

    for (int i = 0; i < k; i++)
    {
        qualitySum += quality[ratio[i].second];
        maxRate = max(maxRate, ratio[i].first);
        maxHeap.push(quality[ratio[i].second]);
    }

    double ans = maxRate * qualitySum;
    for (int i = k; i < n; i++)
    {
        maxRate = max(maxRate, ratio[i].first);
        qualitySum -= maxHeap.top();
        maxHeap.pop();

        qualitySum += quality[ratio[i].second];
        maxHeap.push(quality[ratio[i].second]);
        ans = min(ans, maxRate * qualitySum);
    }
    return ans;
}