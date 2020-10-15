#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int one_count(int a) {
    if (a == 0) return 0;
    return a % 2 + one_count(a / 2);
}

bool comp(int a, int b)
{
    int c = one_count(a);
    int d = one_count(b);
    if (c == d) {
        return a < b;
    }
    return c < d;
}

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};