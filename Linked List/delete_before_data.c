#include<stdio.h>
#include<stdlib.h>
struct node
{
int a;
struct node *next;
};
struct node *head = NULL;
void insert(int value)
{
    struct node *t;

    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a = value;
    k->next = NULL;

    if(head == NULL)
    {
        head = k;
        printf("Inserted at end\n");
        return;
    }

    t = head;

    while(t->next != NULL)
    {
        t = t->next;
    }

    t->next = k;
}
void  delete_before_to_data(int b)
{
    struct node *t = head;
    if(head == NULL)
    {
        printf("no node exists");
        return;
    }
    if(head->next == NULL)
    {
        return;
    }
    while(t != NULL && t->next != NULL && t->next->next != NULL)
    {
        if(head->next->a == b)
        {
            printf("\nvalue found\n");
            struct node *prev;
           prev = head;
           head = head ->next;
            free(prev);
            return;
        }
        if(t->next->next->a==b)
        {
            struct node *p = t-> next;
            t->next = t->next->next;
            free(p);
            return;
        }
        t = t-> next;
        if(t == NULL || t->next == NULL)
        {
            printf("no value found\n");
            return;
        }
    }
}
void display()
{
        struct node *t = head;
    while(t != NULL)
    {
        printf("%d -> ", t-> a);
        t = t-> next;
    }
    printf("NULL\n");
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    delete_before_to_data(30);
    display();
    return 0;
}