102. Binary Tree Level Order Traversal
Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

int height(struct TreeNode* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

void fill(struct TreeNode* root, int level, int* arr, int* colSize) {
    if (!root) return;

    if (level == 0) {
        arr[(*colSize)++] = root->val;
    } else {
        fill(root->left, level - 1, arr, colSize);
        fill(root->right, level - 1, arr, colSize);
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int h = height(root);
    *returnSize = h;

    int** result = (int**)malloc(sizeof(int*) * h);
    *returnColumnSizes = (int*)malloc(sizeof(int) * h);

    for (int i = 0; i < h; i++) {
        result[i] = (int*)malloc(sizeof(int) * 1000);
        int colSize = 0;
        fill(root, i, result[i], &colSize);
        (*returnColumnSizes)[i] = colSize;
    }

    return result;
}
