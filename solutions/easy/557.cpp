#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        vector<int> ind;
        ind.push_back(-1);
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                ind.push_back(i);
            }
        }

        ind.push_back(n);

        stringstream res;

        int nums = ind.size();
        for(int i = 0; i < nums - 1; i++) {
            for(int j = ind[i + 1] - 1; j > ind[i]; j--) {
                res << s[j];
            }
            if (i < nums - 2) {
                res << ' ';
            }
        }

        return res.str();
    }
};