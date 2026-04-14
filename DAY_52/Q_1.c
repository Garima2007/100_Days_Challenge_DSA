/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
