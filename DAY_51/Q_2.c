235. Lowest Common Ancestor of a Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    return root; 
}
