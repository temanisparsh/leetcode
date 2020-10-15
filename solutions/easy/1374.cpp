#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string generateTheString(int n)
    {

        stringstream ss;

        if (n % 2)
        {
            for (int i = 0; i < n; i++)
            {
                ss << 'a';
            }
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                ss << 'a';
            }
                ss << 'b';
        }

        return ss.str();
    }
};