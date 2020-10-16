#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {

        int *m1 = (int *)malloc(sizeof(int) * 1001);
        fill_n(m1, 1001, 0);

        for (int i : arr1)
            ++m1[i];

        int *m2 = (int *)malloc(sizeof(int) * 1001);
        fill_n(m2, 1001, 0);

        for (int i : arr2)
            ++m2[i];

        vector<int> out;
        vector<int> exc;

        for (int i : arr2)
        {
            if (m2[i])
            {
                int count = m1[i];
                for (int j = 0; j < count; ++j)
                {
                    out.push_back(i);
                }
            }
        }

        for (int i = 0; i <= 1000; ++i)
        {
            if (!m2[i])
            {
                int count = m1[i];
                for (int j = 0; j < count; ++j)
                {
                    exc.push_back(i);
                }
            }
        }

        sort(exc.begin(), exc.end());
        for (int i : exc)
            out.push_back(i);

        return out;
    }
};