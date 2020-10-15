#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int visited[101];
        fill_n(visited, 101, 0);

        int count = 0;

        for (int i: nums) {
            visited[i] += 1;
        }

        for (int i: visited) {
            count += (i * (i-1)) / 2;
        }

        return count;
    }
};