#include<iostream>
#include<bits/stdc++.h>
#include <cmath> 

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int count = 0;
        for (int i: nums) {
            if ((int)ceil(log10(i+1)) % 2 == 0)
                count ++;
        }

        return count;
        
    }
};