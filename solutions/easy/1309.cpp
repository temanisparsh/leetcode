#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {

        stringstream res;

        int n = s.length();

        for(int i = 0; i < n; i++) {
            if (i+2 < n && s[i+2] == '#') {

                int a = (int)s[i] - 48;
                int b = (int)s[i+1] - 48;

                char r = (char)(106 + (a-1)*10 + b);
                res << r;
                i += 2;
            }
            else {
                char r = (char)((int)s[i] + 48);
                res << r;
            }
        }

        return res.str();
        
    }
};