#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        vector<int> odd;
        vector<int> even;

        vector<int> res;

        for (int i: A) {
            if (i % 2) odd.push_back(i);
            else even.push_back(i);
        }

        int even_len = even.size();
        int odd_len = odd.size();

        for (int i = 0; i < odd_len; ++i) {
            res.push_back(even[i]);
            res.push_back(odd[i]);
        }

        if (even_len > odd_len) 
            res.push_back(even[even_len - 1]);

        return res;
        
    }
};