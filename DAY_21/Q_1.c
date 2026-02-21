/*
Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
int a;
struct node *next;
};
struct node *head = NULL;
void display()
{
    struct node *t = head;
    while(t != NULL)
    {
        printf("%d -> ", t -> a);
        t = t -> next;
    }
    printf("NULL");
}
int main()
{
    struct node *t = head;
    int n;
    printf("enter number of nodes to create: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
    int value;
    printf("enter data in node: ");
    scanf("%d", &value);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new -> a = value;
    new -> next = NULL;
    if(head == NULL)
    {
        head = new;
        t = new;
    }
    else
    {
        t -> next = new;
        t = new;
    }
}
display();
}
