#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class RecentCounter
{

public:
    vector<int> pings;
    int size;
    int lastIndex;

    RecentCounter()
    {
        this->lastIndex = 0;
        this->size = 0;
    }

    int ping(int t)
    {
        this->pings.push_back(t);
        ++this->size;
        for (; this->lastIndex < this->size && this->pings[this->lastIndex] < t - 3000; ++this->lastIndex)
            ;
        return this->size - this->lastIndex;
    }
};