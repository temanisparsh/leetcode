#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prod = 1;

        while (n) {
            int rem = n % 10;
            sum += rem;
            prod *= rem;
            n /= 10;
        }

        if (sum > prod) {
            return sum - prod;
        }
        return prod - sum;
    }
};