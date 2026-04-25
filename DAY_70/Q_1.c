/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCL*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1e8

typedef struct {
    int u, v, w;
} Edge;

void bellman_ford(int V, int E, Edge* edges, int S) {
    int* dist = (int*)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[S] = 0;
    
    for (int i = 0; i < V - 1; i++) {
        int updated = 0;
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }
        if (!updated) break;
    }
    
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            free(dist);
            return;
        }
    }
    
    printf("Shortest distances from node %d:\n", S);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
    
    free(dist);
}

int main() {
    int V, E, S;
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    printf("Enter source node: ");
    scanf("%d", &S);
    
    bellman_ford(V, E, edges, S);
    
    free(edges);
    return 0;
}
