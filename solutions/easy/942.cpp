#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {

        vector<int> res;

        int n = S.length();

        if (S[0] == 'I') res.push_back(0);
        else res.push_back(n);

        int ICount = count(S.begin(), S.end(), 'I');
        int DCount = n - ICount;

        int I, D;
        if (S[0] == 'I') {
            D = DCount;
            I = D+1;
        }
        else {
            D = DCount - 1;
            I = D+1;
        }

        for(char i: S) {
            if (i == 'I') res.push_back(I++);
            else res.push_back(D--);
        }

        return res;

    }
};