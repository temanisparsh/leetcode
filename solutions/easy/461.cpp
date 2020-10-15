#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {

        int count  = 0;
        while (x || y) {
            if (x % 2 != y % 2) count ++;
            x /= 2; y/= 2;
        }

        return count;
        
    }
};