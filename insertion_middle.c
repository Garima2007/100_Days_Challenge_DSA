#include<stdio.h>
#include<stdlib.h>
struct node
{
    int a;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void create(int b)
{
    struct node *a = (struct node*)malloc(sizeof(struct node));
    a->a=b;
    a->next=NULL;
    a->prev=NULL;
    if(head == NULL)
    {
        head = a;
        return;
    }
    struct node *t = head;
    while(t->next != NULL)
    {
        t = t-> next;
    }
        t->next = a;
        a->prev = t;
    
}
void insert_m(int b)
{
        struct node *t = head;
    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a=b;
    k->next=NULL;
    k->prev = NULL;
    if(head == NULL || head->next== NULL)
    {
        printf("no middle position exists\n");
        return;
    }
    int count = 0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    t = head;
    int mid = (count / 2);
    for(int i = 1; i < mid; i++)
    {
        t = t->next;
    }
    k->next = t->next;
    k->prev = t;
    if(t->next != NULL)
    {
    t->next->prev = k;
    }
    t->next = k;
}
void display()
{
    struct node*t = head;
    while(t!= NULL)
    {
        printf("%d ->", t->a);
        t = t->next;
    }
    printf("NULL\n");
}
int main()
{

    create(30);
    display();
    insert_m(34);
    display();
    return 0;
}