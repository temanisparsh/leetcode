#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {

        vector<int> res;
        if (!root) {
            return res;
        }

        reverse((root->children).begin(), (root->children).end());

        for (Node* node: root->children) {
            vector<int> temp = postorder(node);
            res.insert(res.begin(), temp.begin(), temp.end());
        }

        res.push_back(root->val);
        return res;
    }
};