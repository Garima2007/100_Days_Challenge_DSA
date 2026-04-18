/*
  Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.
  */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create node
struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for level-order build
struct node* queue[1000];
int front = 0, rear = 0;

// Build tree from level order
struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* root = create(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct node* curr = queue[front++];

        // Left child
        if (arr[i] != -1) {
            curr->left = create(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = create(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Mirror function
void mirror(struct node* root) {
    if (root == NULL) return;

    // swap
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}
