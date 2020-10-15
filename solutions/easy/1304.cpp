#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> res;

        for (int i = 1; i <= (n/2); i++) {
            res.push_back(i);
            res.push_back(i*-1);
        }

        if (n%2)
            res.push_back(0);

        return res;
        
    }
};