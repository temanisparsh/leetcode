#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {

        int n = nums.size();

        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            res.insert(res.begin() + index[i], nums[i]);
        }

        return res;
    }
};