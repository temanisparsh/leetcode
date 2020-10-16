#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {

        int sum = 0;
        int *count = (int *)malloc(sizeof(int) * 26);
        fill_n(count, 26, 0);

        for (char ch : chars)
        {
            ++count[(int)(ch)-97];
        }

        for (string s : words)
        {
            int *count_t = (int *)malloc(sizeof(int) * 26);
            fill_n(count_t, 26, 0);

            for (char ch : s)
            {
                ++count_t[(int)(ch)-97];
            }

            int check = 1;

            for(int i = 0;  i < 26; i++) {
                if (count_t[i] > count[i]) {
                    check = 0;
                    break;
                }
            }

            if (check) sum += s.length();
        }
        return sum;
    }
};