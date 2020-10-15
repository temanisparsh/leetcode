#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {

        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        int first_pos[101];
        fill_n(first_pos, 101, -1);

        int n = temp.size();

        for (int i = 0; i < n; i++) {
            if (first_pos[temp[i]] == -1) {
                first_pos[temp[i]] = i;
            }
        }

        vector<int> res;

        for (int i = 0; i < n; i++) {
            res.push_back(first_pos[nums[i]]);
        }

        return res;


    }
};