/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) exit(1);
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int length(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);
    int diff = abs(len1 - len2);
    struct Node *ptr1 = head1, *ptr2 = head2;
    if (len1 > len2) for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    else for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = createNode(val);
        if (!head1) head1 = tail1 = node;
        else { tail1->next = node; tail1 = node; }
    }
    scanf("%d", &m);
    struct Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = createNode(val);
        if (!head2) head2 = tail2 = node;
        else { tail2->next = node; tail2 = node; }
    }

    struct Node* temp1 = head1;
    while (temp1) {
        struct Node* t2 = head2;
        while (t2) {
            if (temp1->data == t2->data) { tail2->next = temp1; break; }
            t2 = t2->next;
        }
        temp1 = temp1->next;
    }

    struct Node* intersect = getIntersection(head1, head2);
    if (intersect) printf("%d\n", intersect->data);
    else printf("No Intersection\n");

    return 0;
}
