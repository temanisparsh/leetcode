#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {

        string push = "Push";
        string pop = "Pop";

        vector<string> res;

        int index = 0;

        for (int num = 1; index < target.size() && num <= n; ++num)
        {
            res.push_back(push);
            if (num == target[index])
            {
                ++index;
            }
            else
            {
                res.push_back(pop);
            }
        }

        return res;
    }
};