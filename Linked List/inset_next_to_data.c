#include<stdio.h>
#include<stdlib.h>
struct node
{
    int a;
    struct node *next;
};
struct node *head = NULL;
void insert(int b, int c)
{
    if(head == NULL)
    {
        printf("No node Exists");
        return;
    }
    struct node *t = head;

    while(t != NULL)
    {
        if(t -> a == b)
        {
            printf("\nvalue found\n");
            struct node *k = (struct node*)malloc(sizeof(struct node));
            k -> a = c;
            k -> next = t -> next;
            t -> next = k;
            return;
        }
    t = t -> next;
}
printf("\n no value found\n");
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
head = first;
first -> a = 10;
first -> next = second;
second -> a = 20;
second -> next = third;
third -> a = 30;
third -> next = NULL;
display();
insert(20,40);
display();
}