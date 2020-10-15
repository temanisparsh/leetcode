#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {

        int n = nums.size();

        vector<int> res;

        for (int i = 0; i < n / 2; i ++) {
            for(int j = 0; j < nums[2*i]; j ++) {
                res.push_back(nums[2*i + 1]);
            }
        }

        return res;
        
    }
};