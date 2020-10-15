#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        vector<int> res;
        int n = arr.size();
        for (int i: arr) {
            res.push_back(-1);
        }

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if (arr[j] > res[i]) {
                    res[i] = arr[j];
                }
            }
        }

        return res;
        
    }
};