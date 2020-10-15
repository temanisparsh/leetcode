#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {

        int n = s.length();

        char arr[n+1];
        fill_n(arr, n+1, '\0');
        
        for (int i = 0; i < n; i++)
        {
            arr[indices[i]] = s[i];
        }        
        string res(arr);
        return res;
    }
};