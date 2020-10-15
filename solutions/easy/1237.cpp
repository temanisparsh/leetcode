#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class CustomFunction
{
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {

        vector<vector<int>> res;
        for (int x = 1; x <= 1000; x++)
        {
            for (int y = 1; y <= 1000; y++)
            {
                int val = customfunction.f(x, y);
                if (val == z)
                {
                    vector<int> r = {x, y};
                    res.push_back(r);
                    break;
                }
                if (val > z)
                {
                    break;
                }
            }
        }

        return res;
    }
};