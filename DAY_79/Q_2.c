/*
Count Strongly Connected
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;
int adj[MAX][MAX], rev[MAX][MAX];
int visited[MAX], stack[MAX], top = -1;

void dfs1(int u) {
    visited[u] = 1;
    for(int v = 0; v < V; v++) {
        if(adj[u][v] && !visited[v]) {
            dfs1(v);
        }
    }
    stack[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    for(int v = 0; v < V; v++) {
        if(rev[u][v] && !visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
            rev[i][j] = 0;
        }
        visited[i] = 0;
    }

    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        rev[v][u] = 1;
    }

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs1(i);
        }
    }

    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int count = 0;

    while(top != -1) {
        int u = stack[top--];
        if(!visited[u]) {
            dfs2(u);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
