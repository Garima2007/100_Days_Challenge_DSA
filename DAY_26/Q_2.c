707. Design Linked List
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* t = obj->head;
    for (int i = 0; i < index; i++)
        t = t->next;

    return t->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* k = (Node*)malloc(sizeof(Node));
    k->val = val;
    k->next = obj->head;
    obj->head = k;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* k = (Node*)malloc(sizeof(Node));
    k->val = val;
    k->next = NULL;

    if (obj->head == NULL) {
        obj->head = k;
    } else {
        Node* t = obj->head;
        while (t->next != NULL)
            t = t->next;
        t->next = k;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* k = (Node*)malloc(sizeof(Node));
    k->val = val;

    Node* t = obj->head;
    for (int i = 0; i < index - 1; i++)
        t = t->next;

    k->next = t->next;
    t->next = k;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* t = obj->head;
        for (int i = 0; i < index - 1; i++)
            t = t->next;

        temp = t->next;
        t->next = temp->next;
        free(temp);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* t = obj->head;
    while (t != NULL) {
        Node* temp = t;
        t = t->next;
        free(temp);
    }
    free(obj);
}
