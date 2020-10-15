#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int cost = 0;
        int n = points.size();

        for(int i = 0; i < n - 1; i++) {

            vector<int> a = points[i];
            vector<int> b = points[i+1];

            cost += max(abs(a[0]-b[0]), abs(a[1]-b[1]));

            cout << cost << endl;

        }
        return cost;
        
    }
};