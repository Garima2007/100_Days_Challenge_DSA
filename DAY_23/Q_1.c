/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *lastnode = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = lastnode = newNode;
        } else {
            lastnode->next = newNode;
            lastnode = newNode;
        }
    }

    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node *result = NULL, *lastnode = NULL;

    while(l1 != NULL && l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if(l1->data <= l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }

        if(result == NULL) {
            result = lastnode = newNode;
        } else {
            lastnode->next = newNode;
            lastnode = newNode;
        }
    }

    while(l1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l1->data;
        newNode->next = NULL;

        lastnode->next = newNode;
        lastnode = newNode;
        l1 = l1->next;
    }

    while(l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l2->data;
        newNode->next = NULL;

        lastnode->next = newNode;
        lastnode = newNode;
        l2 = l2->next;
    }

    return result;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}
