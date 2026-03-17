#include<stdio.h>
#include<stdlib.h>
struct node
{
int a;
struct node *next;
};
struct node *head;
void insert(int value)
{
struct node *k = (struct  node*)malloc(sizeof(struct node));
k->a=value;
k->next=NULL;
if(head == NULL)
{
    head = k;
    return;
}
struct node *t = head;
while(t->next != NULL)
{
    t = t->next; 
} 
t -> next = k;
}
void delete_b()
{
    struct node *t = head;
    if(head == NULL)
    {
        printf("no node exists");
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    head = head->next;
    free(t);
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
    int value;
    scanf("%d", &value);
    insert(value);
    scanf("%d", &value);
    insert(value);
    scanf("%d", &value);
    insert(value);
    scanf("%d", &value);
    insert(value);
    scanf("%d", &value);
    insert(value);
    scanf("%d", &value);
    insert(value);
    scanf("%d", &value);
    insert(value);
    display();
    delete_b();
    display();
    return 0;
}