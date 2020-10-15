#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {

        int isJewel[126];

        fill_n(isJewel, 126, 0);

        for (char i : J)
        {
            isJewel[(int)i] = 1;
        }

        int count = 0;
        for (char i : S)
        {
            count += isJewel[(int)i];
        }

        return count;
    }
};