#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long int calc_even(string a)
{
    long int product = 1;
    int arr[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    int n = a.length();
    for(int i = 0; i < n; i+=2) {
        product *= arr[(int)(a[i]) - 97];
    }

    return product;
}

long int calc_odd(string a)
{
    long int product = 1;
    int arr[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    int n = a.length();
    for(int i = 1; i < n; i+=2) {
        product *= arr[(int)(a[i]) - 97];
    }

    return product;
}

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        vector<int> matches;
        vector<int> even_scores;
        vector<int> odd_scores;

        for(string temp: A) {
            even_scores.push_back(calc_even(temp));
            odd_scores.push_back(calc_odd(temp));
        }

        int len = A.size();

        for (int i = 0; i < len; i++)
        {
            matches.push_back(-1);
            for (int j = i + 1; j < len; j++)
            {
                if (even_scores[i] == even_scores[j] && odd_scores[i] == odd_scores[j])
                {
                    matches[i] = j;
                    j = len;
                }
            }
        }

        int *group_id = (int *)malloc(sizeof(int) * len);
        fill_n(group_id, len, 0);

        int group_number = 0;

        for (int i = 0; i < len; i++)
        {
            if (!group_id[i])
                group_id[i] = ++group_number;
            if (matches[i] != -1)
            {
                group_id[matches[i]] = group_id[i];
            }
        }

        return group_number;
    }
};