#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    struct node *next;
};

struct node *head = NULL;

void insert(int value)
{
    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->a = value;
    k->next = NULL;
    if (head == NULL)
    {
        head = k;
        return;
    }
    struct node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = k;
}

void deleteMiddle()
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    int count = 0;
    struct node *t = head;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }

    int middle = (count + 1) / 2;
    t = head;
    struct node *p = NULL;
    for (int i = 1; i < middle; i++)
    {
        p = t;
        t = t->next;
    }

    p->next = t->next;
    free(t);
}

void display()
{
    struct node *t = head;
    while (t != NULL)
    {
        printf("%d -> ", t->a);
        t = t->next;
    }
    printf("NULL\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();
    deleteMiddle();
    display();
    return 0;
}