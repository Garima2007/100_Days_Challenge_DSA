/*
Articulation Point - I Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner. Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
Constraints:
1 ≤ V ≤ 105
*/
#include <stdio.h>
#define MAX 100

int V;
int adj[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX];
int ap[MAX];
int time_dfs = 0;

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++time_dfs;
    int children = 0;

    for(int v = 0; v < V; v++) {
        if(adj[u][v]) {
            if(!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v);

                if(low[v] < low[u])
                    low[u] = low[v];

                if(parent[u] == -1 && children > 1)
                    ap[u] = 1;

                if(parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }
            else if(v != parent[u]) {
                if(disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = 0;
    }

    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    int found = 0;
    for(int i = 0; i < V; i++) {
        if(ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found) printf("-1");

    return 0;
}
