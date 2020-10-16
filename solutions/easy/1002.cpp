#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {

        int len = A.size();
        vector<vector<int>> m;
        for (int i = 0; i < 26; i++)
        {
            vector<int> t;
            for (string temp : A)
                t.push_back(0);
            m.push_back(t);
        }

        for (int i = 0; i < len; ++i)
        {
            for (char ch : A[i])
            {
                ++m[(int)(ch)-97][i];
            }
        }

        vector<string> out;

        for (int i = 0; i < 26; i++)
        {
            vector<int> counts = m[i];
            int min_count = *min_element(counts.begin(), counts.end());
            stringstream s;
            s << (char)(i + 97);
            for (int j = 0; j < min_count; ++j)
            {
                out.push_back(s.str());
            }
        }

        return out;
    }
};