#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {

        int max_depth = 0;
        int current_depth = 0;

        for (char ch : s)
        {
            if (ch == '(')
                ++current_depth;
            else if (ch == ')')
                --current_depth;
            max_depth = max_depth > current_depth ? max_depth : current_depth;
        }

        return max_depth;
    }
};