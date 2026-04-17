101. Symmetric Tree
Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
int isMirror(struct TreeNode* t1, struct TreeNode* t2)
{
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}
