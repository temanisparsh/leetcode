#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        for(int i = left; i <= right; i++) {

            int isValid = 1;
            int num = i;
            while (num) {
                int rem = num % 10;
                if (rem == 0 || i % rem != 0) isValid = 0;
                num /= 10;
            }

            if (isValid) res.push_back(i);

        }

        return res;
        
    }
};