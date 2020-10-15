
struct Node
{
    int val;
    int numChildren;
    struct Node **children;
};

int *maxDepth(struct Node *root)
{
    return calc_depth(root, 0);
}

int calc_depth(struct Node *root, int depth)
{
    if (!root)
        return depth;
    int old_depth = depth;
    depth += 1;
    for (int i = 0; i < root->numChildren; i++)
    {
        int newd = calc_depth(root->children[i], old_depth + 1);
        printf("%d\n", newd);
        depth = depth > newd ? depth : newd;
    }
    return depth;
}