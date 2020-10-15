#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int sum = 0;
        int totalsum = 0;
        vector<int> res;

        for(int i: nums)
            totalsum += i;

        for (int i: nums) {
            sum += i;
            res.push_back(i);
            if (sum > totalsum / 2) {
                break;
            }
        }

        return res;
        
    }
};