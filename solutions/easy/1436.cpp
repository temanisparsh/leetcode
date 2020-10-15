#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        

        set<string> all;
        for (vector<string> path: paths) {
            all.insert(path[0]);
            all.insert(path[1]);
        }

        set<string> outonly;
        for (vector<string> path: paths) {
            outonly.insert(path[0]);
        }

        string city;

        for(string c: all) {
            if (outonly.find(c) == outonly.end()) {
                city = c;
                break;
            }
        }

        return city;

    }
};