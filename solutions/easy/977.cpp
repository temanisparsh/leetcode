#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {

        vector<int> res;

        for(int i: A) res.push_back(i*i);

        sort(res.begin(), res.end());

        return res;
        
    }
};