#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {

        vector<string> codes;
        int n = words.size();

        string mapping[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        for (string word : words)
        {

            stringstream r;

            for (char c : word)
            {
                r << mapping[(int)(c)-97];
            }

            string res = r.str();
            codes.push_back(res);
        }

        sort(codes.begin(), codes.end());

        int count = n > 0 ? 1 : 0;

        for (int i = 1; i < n; i++)
        {
            if (codes[i].compare(codes[i - 1]))
                ++count;
        }

        return count;
    }
};