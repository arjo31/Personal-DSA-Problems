#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

//Memoization
int solveMemoization(int row,int col,int n, vector<vector<int>>&points, unordered_map<pair<int,int>,int, pair_hash>&mpp)
{
    if (mpp.find({row,col})!=mpp.end())
    {
        return mpp[{row,col}];
    }
    if (row>=n)
    {
        return mpp[{row,col}] = 0;
    }
    if (row==n-1)
    {
        return mpp[{row,col}] = points[row][col];
    }
    if (col==0)
    {
        mpp[{row,col}] = max(solveMemoization(row+1,col+1,n,points,mpp),solveMemoization(row+1,col+2,n,points,mpp)) + points[row][col];
    }
    else if(col==1)
    {
        mpp[{row,col}] = max(solveMemoization(row+1,col-1,n,points,mpp),solveMemoization(row+1,col+1,n,points,mpp)) + points[row][col];
    }
    else if(col==2)
    {
        mpp[{row,col}] = max(solveMemoization(row+1,col-2,n,points,mpp),solveMemoization(row+1,col-1,n,points,mpp)) + points[row][col];
    }
    return mpp[{row,col}];
}

int ninjaTrainingMemoization(int n, vector<vector<int>>&points)
{
    unordered_map<pair<int,int>,int,pair_hash>mpp;
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(solveMemoization(0,i,n,points,mpp));
    }
    return *max_element(arr.begin(),arr.end());
}

//Tabulation
int ninjaTrainingTabulation(int n, vector<vector<int>>&points, vector<vector<int>>&dp)
{
    dp[n-1][0] = points[n-1][0];
    dp[n-1][1] = points[n-1][1];
    dp[n-1][2] = points[n-1][2];

    for (int i = n-2; i>=0; i--)
    {
        dp[i][0] = max(dp[i+1][1],dp[i+1][2]) + points[i][0];
        dp[i][1] = max(dp[i+1][0],dp[i+1][2]) + points[i][1];
        dp[i][2] = max(dp[i+1][0],dp[i+1][1]) + points[i][2];
    }
    return max({dp[0][0],dp[0][1],dp[0][2]});
}

//Space Optimization
int ninjaTrainingSO(int n, vector<vector<int>>& points)
{
    // Initialize a vector to store the maximum points for the previous day's activities
    vector<int> prev(4, 0);

    // Initialize the DP table for the first day (day 0)
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        // Create a temporary vector to store the maximum points for the current day's activities
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++)
            {
                if (task != last) {
                // Calculate the points for the current activity and add it to the
                // maximum points obtained on the previous day (stored in prev)
                temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        // Update prev with the maximum points for the current day
        prev = temp;
    }

    // The maximum points for the last day with any activity can be found in prev[3]
    return prev[3];
}