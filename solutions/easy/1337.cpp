#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        int m = mat.size();
        int n = mat[0].size();

        int *arr = (int *)malloc(sizeof(int) * m);
        fill_n(arr, m, 0);

        vector<int> output;
        output.reserve(k);

        int done = 0;

        for (int i = 0; i < n && done < k; i++)
        {
            for (int j = 0; j < m && done < k; j++)
            {
                if (!(mat[j][i] || arr[j]))
                {
                    output.push_back(j);
                    arr[j] = 1;
                    ++done;
                }
            }
        }

        if (done != k) {
            for(int i = 0; i < m && done < k; i++) {
                if (!arr[i]) {
                    ++done;
                    output.push_back(i);
                }
            }
        }


        return output;
    }
};