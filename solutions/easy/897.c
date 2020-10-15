#include<stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *increasingBST(struct TreeNode *root)
{
    struct TreeNode *middle = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    middle->right = NULL;
    middle->left = NULL;
    middle->val = root->val;

    struct TreeNode *left;

    if (root->left)
    {
        left = increasingBST(root->left);
        struct TreeNode *temp = left;
        while (temp->right)
        {
            temp = temp->right;
        }
        temp->right = middle;
    }

    if (root->right)
    {
        middle->right = increasingBST(root->right);
    }
    return root->left ? left : middle;
}