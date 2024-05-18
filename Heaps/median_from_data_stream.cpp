/*Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);
        if (maxHeap.size() - minHeap.size() > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (!minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            if ((minHeap.size() - maxHeap.size()) > 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double findMedian()
    {
        return (maxHeap.size() == minHeap.size()) ? (maxHeap.top() + minHeap.top()) / 2.0 : ((minHeap.size() < maxHeap.size()) ? maxHeap.top() : minHeap.top());
    }
};