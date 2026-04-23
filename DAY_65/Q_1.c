/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
Output:
- YES or NO
*/
#include <stdio.h>

int graph[10][10], visited[10];
int n;

int dfs(int v, int parent)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1)
        {
            if(!visited[i])
            {
                if(dfs(i, v))
                    return 1;
            }
            else if(i != parent)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int cycle = 0;

    for(i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
