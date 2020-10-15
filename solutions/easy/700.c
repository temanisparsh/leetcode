#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root)
        return NULL;

    if (root->val == val)
        return root;

    struct TreeNode *left = searchBST(root->left, val);
    if (left)
        return left;

    struct TreeNode *right = searchBST(root->right, val);
    if (right)
        return right;

    return NULL;
}