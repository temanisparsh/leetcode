#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int count = 0;

        for(vector<int> x: grid) {
            for(int a: x) {
                if (a < 0) ++count;
            }
        }
        return count;
        
    }
};