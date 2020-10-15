#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {

        int count = 0;
        int diff = 0;
        int n = s.length();

        for(char i: s) {
            if (i == 'L') diff--;
            else diff++;

            if (diff == 0){
                count ++;
            }
        }

        return count;
    }
};