/*You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>> &queries)
{
    vector<int> ans;
    unordered_map<int, int> mpp;
    unordered_map<int, int> colors;
    for (auto query : queries)
    {
        int ballNo = query[0];
        int color = query[1];
        if (mpp.find(ballNo) != mpp.end())
        {
            int tempColor = mpp[ballNo];
            colors[tempColor]--;
            if (colors[tempColor] == 0)
                colors.erase(tempColor);
            mpp[ballNo] = color;
            colors[color]++;
        }
        else
        {
            mpp[ballNo] = color;
            colors[color]++;
        }
        ans.push_back(min(mpp.size(), colors.size()));
    }
    return ans;
}
