#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ParkingSystem
{
public:
    int b, s, m;
    int c_big, c_small, c_medium;

    ParkingSystem(int big, int medium, int small)
    {
        b = 0;
        s = 0;
        m = 0;
        c_big = big;
        c_medium = medium;
        c_small = small;
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 3:
            if (s < c_small)
            {
                ++s;
                cout << s;
                return true;
            }
            return false;
            break;
        case 2:
            if (m < c_medium)
            {
                ++m;
                cout << m;
                return true;
            }
            return false;
            break;
        case 1:
            if (b < c_big)
            {
                cout << b;
                ++b;
                return true;
            }
            return false;
            break;
        default:
            break;
        }
        return false;
    }
};