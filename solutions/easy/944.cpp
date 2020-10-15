#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {

        int len = A[0].length();
        int n = A.size();

        int del[len];
        fill_n(del, len, 0);

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < len; j++) {
                if (A[i][j] > A[i+1][j]) {
                    del[j] = 1;
                    
                }
            }
        }

        int count = 0;
        for(int i: del)
            count += i;

        return count;

    }
};