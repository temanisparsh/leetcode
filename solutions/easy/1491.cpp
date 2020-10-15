#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        int n = salary.size();
        int sum = 0;
        for (double i : salary)
            sum += i;
        sum -= salary[0];
        sum -= salary[n - 1];

        return (double)(sum / (double)(n - 2));
    }
};