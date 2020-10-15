#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        int n = A.size();

        vector<vector<int>> res;

        for (vector<int> a: A) {
            vector<int> temp;
            for(int x: a) {
                temp.push_back(1-x);
            }
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }

        return res;
        
    }
};