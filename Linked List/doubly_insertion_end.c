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
void insertion_e(int b)
{
    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a=b;
    k->next=NULL;
    if(head == NULL)
    {
       head = k;
       return;
}
struct node *t = head;
while(t->next != NULL)
{
    t = t-> next;
}
k->prev = t;
t->next = k;
}
void display()
{
    struct node *t = head;
    while(t!= NULL)
    {
        printf("%d ->", t->a);
        t = t->next;
    }
    printf("NULL\n");
}
int main()
{
    create(10);
    create(20);
    create(30);
    display();
    insertion_e(100);
    display();
    return 0;
}