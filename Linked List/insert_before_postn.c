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
    struct node *t;

    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->a = value;
    k->next = NULL;

    if (head == NULL)
    {
        head = k;
        return;
    }

    t = head;

    while (t->next != NULL)
    {
        t = t->next;
    }

    t->next = k;
}
void insert_before_data(int b, int c)
{
    struct node *t = head;

    if (head == NULL)
    {
        printf("No node exists");
        return;
    }

    if (head->next == NULL || head->a == b)
    {
        struct node *k = (struct node *)malloc(sizeof(struct node));
        k->a = c;
        k->next = head;
        head = k;
        return;
    }

    while (t != NULL && t->next != NULL)
    {
        if (t->next->a == b)
        {
            struct node *k = (struct node *)malloc(sizeof(struct node));
            k->a = c;
            struct node *p = t->next;
            t->next = k;
            k->next = p;
            return;
        }
        t = t->next;
    }

    printf("No node found");
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
    display();
    insert_before_data(20, 15);
    display();
    return 0;
}