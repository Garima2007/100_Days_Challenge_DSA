/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int a;
    struct node *next;
    struct node *prev;
};

struct node* createNode(int value)
{
    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a = value;
    k->next = NULL;
    k->prev = NULL;
    return k;
}

void traverse(struct node *head)
{
    struct node *t = head;

    while(t != NULL)
    {
        printf("%d ", t->a);
        t = t->next;
    }
}

int main()
{
    int n, i, value;
    struct node *head = NULL, *t = NULL, *k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        k = createNode(value);

        if(head == NULL)
        {
            head = k;
            t = k;
        }
        else
        {
            t->next = k;
            k->prev = t;
            t = k;
        }
    }

    printf("Doubly Linked List (Forward Traversal): ");
    traverse(head);

    return 0;
}
