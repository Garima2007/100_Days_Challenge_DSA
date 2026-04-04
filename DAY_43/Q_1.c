/*
Problem Statement:
Construct a Binary Tree from the given level-order traversal.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)
Output Format:
- Print inorder traversal of the constructed tree
Example:
Input:
7
1 2 3 4 5 -1 6
Output:
4 2 5 1 3 6
*/
#include<stdio.h>

#define MAX 100

int tree[MAX];

void init()
{
    for(int i = 0; i < MAX; i++)
        tree[i] = -1;
}

void insert(int index, int value)
{
    if(index >= MAX)
    {
        printf("Index out of range\n");
        return;
    }

    tree[index] = value;
}

void display()
{
    printf("Tree elements:\n");

    for(int i = 0; i < MAX; i++)
    {
        if(tree[i] != -1)
            printf("Index %d → %d\n", i, tree[i]);
    }
}

void getLeft(int index)
{
    int i = 2*index + 1;

    if(i < MAX && tree[i] != -1)
        printf("Left child of %d = %d\n", tree[index], tree[i]);
    else
        printf("No left child\n");
}

// get right child
void getRight(int index)
{
    int i = 2*index + 2;

    if(i < MAX && tree[i] != -1)
        printf("Right child of %d = %d\n", tree[index], tree[i]);
    else
        printf("No right child\n");
}

// get parent
void getParent(int index)
{
    if(index == 0)
    {
        printf("Root node has no parent\n");
        return;
    }

    int i = (index - 1) / 2;

    if(tree[i] != -1)
        printf("Parent of %d = %d\n", tree[index], tree[i]);
    else
        printf("No parent\n");
}

int main()
{
    init();

    insert(0, 10); // root
    insert(1, 20); // left child
    insert(2, 30); // right child
    insert(3, 40);
    insert(4, 50);
    insert(5, 60);

    display();

    printf("\n");
    getLeft(0);
    getRight(0);
    getParent(2);

    return 0;
}
