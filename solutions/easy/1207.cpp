#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        vector<int> count;
        for(int i = 0; i < 2001; i++) {
            count.push_back(0);
        }

        for (int i: arr)
            ++count[i+1000];

        sort(count.begin(), count.end());
        int n = count.size();
        
        for(int i = 0; i < n - 1; i++) {
            if (count[i] > 0 && count[i] == count[i+1]) return false;
        }
        return true;
        
    }
};