#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        vector<int> even;
        vector<int> odd;
        for(int i: A) if (i%2) odd.push_back(i); else even.push_back(i);
        for(int i: odd) even.push_back(i);
        return even;

    }
};