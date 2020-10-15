#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int min_row[m];
        int max_col[n];

        fill_n(min_row, m, 1000000);
        fill_n(max_col, n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                min_row[i] = min_row[i] < matrix[i][j] ? min_row[i] : matrix[i][j];
                max_col[j] = max_col[j] > matrix[i][j] ? max_col[j] : matrix[i][j];
            }

        vector<int> res;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (min_row[i] == matrix[i][j] && max_col[j] == matrix[i][j])
                    res.push_back(matrix[i][j]);
        
        return res;
    }
};