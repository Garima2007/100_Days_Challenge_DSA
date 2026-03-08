#include<stdio.h>
#include<stdlib.h>
struct node
{
int a;
struct node *next;
};
struct node *head = NULL;
void insert_b(int b)
{
    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a = b;
    k->next = head;
    head = k;
}
void display()
{
    struct node *t = head;
    while(t != NULL)
    {
        printf("%d -> ", t->a);
        t = t->next;
    }
        printf("NULL");
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
    int b;
    printf("\n enter new value ");
    scanf("%d", &b);
    insert_b(b);
    display();
}
