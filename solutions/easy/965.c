
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode *root)
{
    if(!root) return true;
    if(root->left) {
        if (root->left->val != root->val) return false;
        if (!isUnivalTree(root->left)) return false;
    }
    if(root->right) {
        if (root->right->val != root->val) return false;
        if (!isUnivalTree(root->right)) return false;
    }

    return true;

}