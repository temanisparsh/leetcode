#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {

        stringstream out;
        vector<char> s;
        for (char ch : S)
            s.push_back(ch);

        int n = S.length();

        for (int i = 0; i < n - 1; i++)
        {
            
            if (s[i] == s[i + 1])
            {

                s.erase(s.begin() + i+1);
                s.erase(s.begin() + i);

                i -= 2;
                n -= 2;

                if (i < -1)
                    i = -1;

            }
        }

        for(char ch: s) out << ch;

        return out.str();
    }
};