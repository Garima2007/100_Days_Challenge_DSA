#include<stdio.h>
#include<stdlib.h>
struct node
{
int a;
struct node *next;
};
struct node *head = NULL;
void insert_end()
{
    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a=25;
    k->next=NULL;
 if(head == NULL)
 {
    printf("\nno node exist\n");
    head = k;
    return;
 }   
struct node*t = head;
while(t->next != NULL)
{
    t = t->next;
}
t->next = k;
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
    struct node *first = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));
    first->a =10;
    first-> next = second;
    second-> a = 20;
    second->next = third;
    third-> a = 30;
    third->next = fourth;
    fourth->a = 40;
    fourth-> next = NULL;
    head = first;
    display();
    insert_end();
    display();
    return 0;
}
