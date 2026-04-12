/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left, *right;
};


struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}


struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}


struct node* deleteNode(struct node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right); // inorder successor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);

    int key = 40;
    if (search(root, key))
        printf("\n%d found in BST", key);
    else
        printf("\n%d not found", key);

    root = deleteNode(root, 50);

    printf("\nAfter deletion (Inorder): ");
    inorder(root);

    return 0;
}
