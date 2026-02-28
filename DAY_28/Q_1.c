/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the circular linked list elements starting from head, space-separated
Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50
Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
  */
#include <stdio.h>
#include <stdlib.h>
struct node {
    int a;
    struct node *next;
};
int main() 
{
    int n, i;
    struct node *head = NULL, *t = NULL;
    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }
    for (i = 0; i < n; i++) 
    {
        struct node *k = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &k->a);
        k->next = NULL;

        if (head == NULL) {
            head = k;
            t = k;
        } else {
            t->next = k;
            t = k;
        }
    }
    t->next = head;
    t = head;
    do {
        printf("%d ", t->a);
        t = t->next;
    } while (t != head);

    return 0;
}
