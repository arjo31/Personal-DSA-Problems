/*An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};
int n, m;
bool isValid(int row, int col)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void bfs(int row, int col, vector<vector<int>> &image, int initColor, int color)
{
    image[row][col] = color;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (isValid(nrow, ncol) && image[nrow][ncol] == initColor)
            {
                image[nrow][ncol] = color;
                q.push({nrow, ncol});
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    n = image.size();
    m = image[0].size();
    int initColor = image[sr][sc];
    if (initColor == color)
        return image;
    bfs(sr, sc, image, initColor, color);
    return image;
}