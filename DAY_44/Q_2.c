144. Binary Tree Preorder Traversal
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
struct Stack {
    struct TreeNode **arr;
    int top;
    int capacity;
};

struct Stack* createStack(int cap) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * cap);
    s->top = -1;
    s->capacity = cap;
    return s;
}

void push(struct Stack* s, struct TreeNode* node) {
    if (s->top + 1 >= s->capacity) {
        s->capacity *= 2;
        s->arr = (struct TreeNode**)realloc(s->arr, sizeof(struct TreeNode*) * s->capacity);
    }
    s->arr[++s->top] = node;
}

struct TreeNode* pop(struct Stack* s) {
    return s->arr[s->top--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int capacity = 100;         
    int *res = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    if (!root) return res;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* node = pop(stack);

        if (*returnSize >= capacity) {
            capacity *= 2;
            res = (int*)realloc(res, sizeof(int) * capacity);
        }
        res[(*returnSize)++] = node->val;

        if (node->right) push(stack, node->right);
        if (node->left) push(stack, node->left);
    }

    free(stack->arr);
    free(stack);

    return res;
}
