#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fib(int N)
    {
        int *arr = (int *)malloc(sizeof(int) * N + 1);

        int n = N;
        if (n == 0) return 0;
        if (n == 1) return 1;

        arr[0] = 0;
        arr[1] = 1;

        for(int i = 2; i <= N; i++)
            arr[i] = arr[i-1] + arr[i-2];

        return arr[N];

    }
};