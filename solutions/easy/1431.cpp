#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        long int max = 0;
        for(int i  = 0; i < candies.size(); i++) {
            max = max > candies[i] ? max : candies[i];
        }
        for(int i: candies) {
            res.push_back(i + extraCandies >= max);
        }
        
        return res;
    }
};