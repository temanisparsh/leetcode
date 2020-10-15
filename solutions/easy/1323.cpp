#include<iostream>
#include<bits/stdc++.h>
#include <string.h>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {

        int temp = num;
        
        int mult = 1;
        int val = 0;

        while(num) {
            int rem = num%10;
            if (rem == 6) {
                val = 3*mult;
            }
            mult *= 10;
            num /= 10;
        }

        return temp + val;
    }
};