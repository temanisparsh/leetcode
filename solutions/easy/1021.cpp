#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {

        int n = S.length();
        char res[n];

        fill_n(res, n, '\0');

        int pos = 0;
        int diff = 0;
        for (char i : S)
        {

            if (i == '(')
            {
                if (diff)
                {
                    res[pos] = '(';
                    ++pos;
                }
                ++diff;
            }
            else
            {
                --diff;
                if (diff)
                {
                    res[pos] = ')';
                    ++pos;
                }
            }
        }

        string r(res);

        return r;
    }
};