/*
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root, int arr[], int *i){
    if(root==NULL){
        arr[(*i)++] = -1;
        return;
    }
    inorder(root->left, arr, i);
    arr[(*i)++] = root->val;
    inorder(root->right, arr, i);
}

int isSymmetric(struct TreeNode* root){
    int arr[2000], n=0, i;
    inorder(root, arr, &n);
    for(i=0;i<n/2;i++){
        if(arr[i]!=arr[n-i-1]) return 0;
    }
    return 1;
}

int main(){
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    if(isSymmetric(root))
        printf("Symmetric\n");
    else
        printf("Not Symmetric\n");

    return 0;
}
