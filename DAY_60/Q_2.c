968. Binary Tree Cameras
Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
int cameras;
int dfs(struct TreeNode* root) {
    if(root == NULL)
        return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if(left == 2 || right == 2) {
        cameras++;
        return 0;
    }

    if(left == 0 || right == 0)
        return 1;

    return 2;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if(dfs(root) == 2)
        cameras++;
    return cameras;
}
