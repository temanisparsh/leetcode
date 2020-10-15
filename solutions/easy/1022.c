#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumRootToLeaf(struct TreeNode *root)
{
    return findSum(root, 0);
}

int findSum(struct TreeNode *root, int prevSum) {

    int sum = 0;

    if (root->left)
        sum += findSum(root->left, 2*prevSum + root->val);
    if (root->right)
        sum += findSum(root->right, 2*prevSum + root->val);

    if (!root->left && !root->right)
        return prevSum*2 + root->val;
    return sum;

}