// Remove cycle from linked list:
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int a;
    struct Node* next;
};
void removeLoop(struct Node* head) 
{
    if (head == NULL || head->next == NULL) return;
    
    struct Node* prev = head;
    struct Node* t = head;
        while (t != NULL && t->next != NULL)
        {
        prev = prev->next;
        t = t->next->next;
        if (prev == t) break;
    }
    
    if (prev != t) return; 
    prev = head;
    while (prev->next != t->next) 
    {
        prev = prev->next;
        t = t->next;
    }
        t->next = NULL;
}
