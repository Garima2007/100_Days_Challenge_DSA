199. Binary Tree Right Side View
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

  int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(1000 * sizeof(int));
    struct TreeNode* q[1000];
    int front = 0, rear = 0;

    q[rear++] = root;
    *returnSize = 0;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct TreeNode* temp = q[front++];

            if(i == size - 1)
                result[(*returnSize)++] = temp->val;

            if(temp->left)
                q[rear++] = temp->left;
            if(temp->right)
                q[rear++] = temp->right;
        }
    }

    return result;
}
