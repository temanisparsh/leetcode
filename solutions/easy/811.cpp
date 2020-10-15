#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        vector<string> res;

        unordered_map<string, int> count;
        for (string x: cpdomains) {

            int space_pos = x.find(' ');
            string num_string = x.substr(0, space_pos);
            int num = stoi(num_string);
            string domain = x.substr(space_pos + 1);

            if (count[domain]) count[domain] += num;
            else count[domain] = num;

            for (int i = 0; i < domain.length(); i++) {
                if (domain[i] == '.') {
                    if (count[domain.substr(i+1)]) count[domain.substr(i+1)] += num;
                    else count[domain.substr(i+1)] = num;
                }
            }

        }
        for (auto x: count) {
            stringstream r;
            r << x.second << " " << x.first;
            res.push_back(r.str());
        }
        return res;
    }
};