#include<stdio.h>
#include<stdlib.h>
struct node
{
int a;
struct node *next;
};
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
    struct node *t = first;
    while(t != NULL)
    {
        printf("%d -> ", t-> a);
        t = t-> next;
    }
    printf("NULL");
    return 0;
}
