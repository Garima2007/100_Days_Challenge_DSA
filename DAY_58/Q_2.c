/**
105. Construct Binary Tree from Preorder and Inorder Traversal

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
 */
int findIndex(int* inorder, int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[*preIndex];
    root->left = root->right = NULL;

    (*preIndex)++;

    if(inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
