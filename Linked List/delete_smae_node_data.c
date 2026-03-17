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
void delete_data_node(int b)
{
    struct node *t = head;

    if(head == NULL)
    {
        printf("No node exists");
        return;
    }

    if(head->next == NULL && head->a == b)
    {
        free(head);
        head = NULL;
        return;
    }
     if(head->a == b)
        {
            struct node *p = head;
            head = head->next;
            free(p);
            return;
        }
    while(t != NULL && t->next != NULL)
    {
        if(t->next->a == b)
        {
            struct node *p = t->next;
            t->next = t->next->next;
            free(p);
            return;
        }

        t = t->next;
    }
    printf("No value found");
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
delete_data_node(30);
    display();
    return 0;
}