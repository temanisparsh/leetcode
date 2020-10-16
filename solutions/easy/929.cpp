#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {

        set<string> track;
        for (string email : emails)
        {
            stringstream processed;
            int plusenc = 0;
            int atenc = 0;
            for(char ch: email) {
                if (ch == '.' && !atenc) continue;
                if (ch == '+') plusenc = 1;
                if (ch == '@') atenc = 1;
                if (plusenc && !atenc) continue;
                processed << ch;
            }

            track.insert(processed.str());
        }

        return track.size();
    }
};