#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {

        vector<int> dup = heights;
        sort(dup.begin(), dup.end());
        int count = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            if (dup[i] != heights[i])
                ++count;
        }

        return count;
    }
};