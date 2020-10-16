#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int top = 0;
        for (vector<int> temp : grid)
        {
            for (int i : temp)
            {
                if (i)
                    ++top;
            }
        }

        vector<int> front;
        vector<int> right;
        for (int i = 0; i < n; i++)
        {
            front.push_back(0);
            right.push_back(0);
            for (int j = 0; j < n; j++)
            {
                front[i] = max(front[i], grid[i][j]);
                right[i] = max(right[i], grid[j][i]);
            }
        }

        return top + accumulate(front.begin(), front.end(), 0) + accumulate(right.begin(), right.end(), 0);
    }
};