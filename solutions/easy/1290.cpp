#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {

        int res = 0;

        while(head) {
            res = res*2 + head->val;
            head = head->next;
        }

        return res;
        
    }
};