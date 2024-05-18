/*You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> drow = {0, 1, 0, -1};
vector<int> dcol = {1, 0, -1, 0};
int lx = -1;
int ly = -1;

bool isValid(int row, int n, int col, int m)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void bfs(int row, int col, int n, int m, vector<vector<int>> land, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        lx = r;
        ly = c;
        for (int i = 0; i < 4; i++)
        {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (isValid(nrow, n, ncol, m) && land[nrow][ncol] && !vis[nrow][ncol])
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}
vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] && !vis[i][j])
            {
                lx = i;
                ly = j;
                bfs(i, j, n, m, land, vis);
                ans.push_back({i, j, lx, ly});
            }
        }
    }
    return ans;
}