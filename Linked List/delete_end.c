#include<stdio.h>
#include<stdlib.h>
struct node
{
    int a;
    struct node *next;
};
struct node *head = NULL;
void insert_end(int value)
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
void delete_b()
{
    if(head == NULL)
    {
        printf("no node exists");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head = NULL;
    }
    struct node *t = head;
    head = head->next;
    free(t);
};
    void display()
{
    struct node *t = head;
    while(t != NULL)
    {
        printf("%d ->", t->a);
        t = t-> next;
    }
    printf("NULL\n");
};
int main()
{
    insert_end(50);
    insert_end(30);
    insert_end(40);
    insert_end(20);
    display();
    delete_b();
    display();
}