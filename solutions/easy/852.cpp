#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int n = A.size();
        for (int i = 1; i < n-1; i++) {
            if (A[i] > A[i-1] && A[i] > A[i+1]) return i;
        }
        return  -1;
    }
};