106. Construct Binary Tree from Inorder and Postorder Traversal
Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree helper
struct TreeNode* build(int* inorder, int* postorder, int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, rootVal);

    // Build right first
    root->right = build(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = build(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Main function (LeetCode)
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}
