#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {

        vector<int> res;

        res.push_back(nums[0]);

        int sum = res[0];

        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            res.push_back(sum);
        }

        return res;
    }
};