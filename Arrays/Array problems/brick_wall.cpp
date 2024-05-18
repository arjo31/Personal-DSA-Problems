/*There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.*/

#include <bits/stdc++.h>
using namespace std;

int leastBricks(vector<vector<int>> &wall)
{
    int rows = wall.size();
    map<int, int> edgeFrequency;
    int maxFreq = 0;
    for (int i = 0; i < rows; i++)
    {
        int edgePos = 0;
        for (int brickNo = 0; brickNo < wall[i].size() - 1; brickNo++)
        {
            int currBrickLen = wall[i][brickNo];
            edgePos = edgePos + currBrickLen;
            edgeFrequency[edgePos]++;
            maxFreq = max(edgeFrequency[edgePos], maxFreq);
        }
    }
    return rows - maxFreq;
}