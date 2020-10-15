#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {

        transform(str.begin(), str.end(), str.begin(), ::tolower);

        return str;
        
    }
};