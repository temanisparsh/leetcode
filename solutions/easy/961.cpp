#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        int v[100001];
        fill_n(v, 100001, 0);
        for(int i: A) if (v[i]++) return i;

    }
};