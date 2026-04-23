/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[10] = {NULL};

void addEdge(int u, int v)
{
    struct node* newnode;

   
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = adj[u];
    adj[u] = newnode;

    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = u;
    newnode->next = adj[v];
    adj[v] = newnode;
}


void display(int n)
{
    int i;
    struct node* temp;

    for(i = 0; i < n; i++)
    {
        printf("%d -> ", i);

        temp = adj[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int n, edges, i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("\nAdjacency List:\n");
    display(n);

    return 0;
}
