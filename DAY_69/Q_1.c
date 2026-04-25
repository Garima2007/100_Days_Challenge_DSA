/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define INF INT_MAX

typedef struct {
    int node;
    int distance;
} HeapNode;

typedef struct {
    HeapNode* arr;
    int size;
    int capacity;
} MinHeap;

typedef struct Edge {
    int neighbor;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    Edge* head;
} AdjList;

typedef struct {
    AdjList* array;
    int num_nodes;
} Graph;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < heap->size && heap->arr[left].distance < heap->arr[smallest].distance)
        smallest = left;
    if (right < heap->size && heap->arr[right].distance < heap->arr[smallest].distance)
        smallest = right;
    
    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

HeapNode extractMin(MinHeap* heap) {
    HeapNode min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return min;
}

void decreaseKey(MinHeap* heap, int node, int distance) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i].node == node) {
            heap->arr[i].distance = distance;
            break;
        }
    }
    
    while (i > 0 && heap->arr[(i - 1) / 2].distance > heap->arr[i].distance) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

void insertMinHeap(MinHeap* heap, int node, int distance) {
    heap->arr[heap->size].node = node;
    heap->arr[heap->size].distance = distance;
    heap->size++;
    
    int i = heap->size - 1;
    while (i > 0 && heap->arr[(i - 1) / 2].distance > heap->arr[i].distance) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Graph* createGraph(int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->array = (AdjList*)malloc(num_nodes * sizeof(AdjList));
    
    for (int i = 0; i < num_nodes; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->neighbor = dest;
    new_edge->weight = weight;
    new_edge->next = graph->array[src].head;
    graph->array[src].head = new_edge;
}

void dijkstra(Graph* graph, int source) {
    int num_nodes = graph->num_nodes;
    int* dist = (int*)malloc(num_nodes * sizeof(int));
    bool* visited = (bool*)malloc(num_nodes * sizeof(bool));
    
    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    
    dist[source] = 0;
    
    MinHeap* heap = createMinHeap(num_nodes);
    insertMinHeap(heap, source, 0);
    
    while (!isEmpty(heap)) {
        HeapNode min_node = extractMin(heap);
        int u = min_node.node;
        
        if (visited[u])
            continue;
        
        visited[u] = true;
        
        Edge* edge = graph->array[u].head;
        while (edge != NULL) {
            int v = edge->neighbor;
            int weight = edge->weight;
            
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertMinHeap(heap, v, dist[v]);
            }
            edge = edge->next;
        }
    }
    
    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < num_nodes; i++) {
        if (dist[i] == INF)
            printf("  to %d: INFINITY\n", i);
        else
            printf("  to %d: %d\n", i, dist[i]);
    }
    
    free(dist);
    free(visited);
    free(heap->arr);
    free(heap);
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Edge* edge = graph->array[i].head;
        while (edge != NULL) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    int num_nodes = 4;
    Graph* graph = createGraph(num_nodes);
    
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 5);
    
    int source = 0;
    dijkstra(graph, source);
    
    freeGraph(graph);
    
    return 0;
}
