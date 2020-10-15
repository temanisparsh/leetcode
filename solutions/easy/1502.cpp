#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff;
        if (arr.size() > 1)
            diff = arr[1] - arr[0];
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (diff != arr[i + 1] - arr[i])
                return false;
        }
        return true;
    }
};