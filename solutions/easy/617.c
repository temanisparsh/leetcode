#include<stdio.h>
#include <stdlib.h>  

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2)
{

    if (!t1) return t2;
    if (!t2) return t1;

    t1->val = t1->val + t2->val;

    if (t1->left && t2->left)
        t1->left = mergeTrees(t1->left, t2->left);
    else if (t1->left)
        t1->left = t1->left;
    else if (t2->left)
        t1->left = t2->left;

    if (t1->right && t2->right)
        t1->right = mergeTrees(t1->right, t2->right);
    else if (t1->right)
        t1->right = t1->right;
    else if (t2->right)
        t1->right = t2->right;

    return t1;
}