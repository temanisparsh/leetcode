#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {

        int a, b, c, d;

        char arr[address.length() + 1];

        strcpy(arr, address.c_str());

        sscanf(arr, "%d.%d.%d.%d", &a, &b, &c, &d);

        char res_arr[address.length() + 1 + 10];

        sprintf(res_arr, "%d[.]%d[.]%d[.]%d", a, b, c, d);

        string res(res_arr);

        return res;
    }
};