#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortString(string s) {

        int n = s.length();

        int count[26];
        fill_n(count, 26, 0);

        stringstream ss;

        for(char i: s) {
            ++count[(int)(i) - 97];
        }

        int max_count = -1;
        for(int i: count) {
            max_count = max_count > i ? max_count : i;
        }

        for (int step = 1; step <= max_count; ++step ) {

            for (int i = 0; i < 26; i++) {
                if (count[i] >= step) {
                    ss << (char)(i + 97);
                }
            }

            ++step;

            for (int i = 25; i >= 0; i--) {
                if (count[i] >= step) {
                    ss << (char)(i + 97);
                }
            }

        }

        return ss.str();

    }
};