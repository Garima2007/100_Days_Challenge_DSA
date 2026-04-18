/*114. Flatten Binary Tree to Linked List
Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/
void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    // Flatten left and right subtrees first
    flatten(root->left);
    flatten(root->right);

    // If left subtree exists
    if (root->left != NULL) {
        struct TreeNode* temp = root->left;

        // Find rightmost node of left subtree
        while (temp->right != NULL) {
            temp = temp->right;
        }

        // Attach original right subtree
        temp->right = root->right;

        // Move left subtree to right
        root->right = root->left;
        root->left = NULL;
    }
}
