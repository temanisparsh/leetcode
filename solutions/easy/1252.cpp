#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int oddCells(int n, int m, vector<vector<int>> &indices)
    {

        int arr[n][m];

        for (int i = 0; i < n; i++)
        {
            fill_n(arr[i], m, 0);
        }

        for (vector<int> i : indices)
        {
            int r = i[0];
            int c = i[1];

            for (int k = 0; k < m; k++)
            {
                ++arr[r][k];
            }

            for (int k = 0; k < n; k++)
            {
                ++arr[k][c];
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j: arr[i]) {
                count += j%2;
            }
        }

        return count;
    }
};