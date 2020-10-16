#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> poss;
        int n = S.length();
        for (int i = 0; i < n; i++)
        {
            if (S[i] == C)
            {
                poss.push_back(i);
            }
        }

        vector<int> out;

        int occ = poss.size();

        if (occ)
        {
            for (int i = 0; i <= poss[0]; ++i)
                out.push_back(poss[0] - i);
        }
        for (int i = 0; i < occ - 1; i++)
        {
            for (int j = poss[i] + 1; j <= poss[i + 1]; ++j)
            {
                out.push_back(min((j - poss[i]), (poss[i + 1] - j)));
            }
        }

        if (occ)
        {
            for (int i = poss[occ - 1] + 1; i < n; ++i)
                out.push_back(i - poss[occ - 1]);
        }

        return out;
    }
};