#include<stdio.h>
#include<stdlib.h>

struct node
{
    int a;
    struct node *next;
};

struct node *head = NULL;

void insert(int b)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));

    if(node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    node->a = b;
    node->next = NULL;

    if(head == NULL)
    {
        head = node;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
}

void insert_pos(int value, int pos)
{
    if(pos <= 0)
    {
        printf("Position does not exist\n");
        return;
    }

    if(pos == 1)
    {
        struct node *k = (struct node*)malloc(sizeof(struct node));
        k->a = value;
        k->next = head;
        head = k;
        return;
    }

    if(head == NULL)
    {
        printf("No Node Exists \n");
        return;
    }

    struct node *temp = head;

    for(int i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position does not exist\n");
        return;
    }

    if(temp->next == NULL)
    {
        insert(value);
        return;
    }

    struct node *k = (struct node*)malloc(sizeof(struct node));
    k->a = value;

    k->next = temp->next;
    temp->next = k;
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *t = head;
    while(t != NULL)
    {
        printf("%d -> ", t->a);
        t = t->next;
    }
    printf("NULL\n");
}

int main()
{
    int value, pos;
    //insert(10);
    display();

    printf("Enter new value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    insert_pos(value, pos);

    display();

    return 0;
}
