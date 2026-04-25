/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList;

typedef struct {
    AdjList* array;
    int num_nodes;
} Graph;

typedef struct {
    int* items;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0) return -1;
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void freeQueue(Queue* q) {
    free(q->items);
    free(q);
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

void addEdge(Graph* graph, int src, int dest) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;
}

void topologicalSort(Graph* graph) {
    int num_nodes = graph->num_nodes;
    int* in_degree = (int*)calloc(num_nodes, sizeof(int));
    
    for (int i = 0; i < num_nodes; i++) {
        Node* temp = graph->array[i].head;
        while (temp) {
            in_degree[temp->vertex]++;
            temp = temp->next;
        }
    }
    
    Queue* q = createQueue(num_nodes);
    
    for (int i = 0; i < num_nodes; i++) {
        if (in_degree[i] == 0) {
            enqueue(q, i);
        }
    }
    
    int* top_order = (int*)malloc(num_nodes * sizeof(int));
    int index = 0;
    
    while (!isEmpty(q)) {
        int u = dequeue(q);
        top_order[index++] = u;
        
        Node* temp = graph->array[u].head;
        while (temp) {
            int v = temp->vertex;
            in_degree[v]--;
            
            if (in_degree[v] == 0) {
                enqueue(q, v);
            }
            temp = temp->next;
        }
    }
    
    if (index != num_nodes) {
        printf("Graph has a cycle! Topological sorting not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < num_nodes; i++) {
            printf("%d ", top_order[i]);
        }
        printf("\n");
    }
    
    free(in_degree);
    free(top_order);
    freeQueue(q);
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node* temp = graph->array[i].head;
        while (temp) {
            Node* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    int num_nodes = 6;
    Graph* graph = createGraph(num_nodes);
    
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    
    printf("Kahn's Algorithm - Topological Sorting\n");
    topologicalSort(graph);
    
    freeGraph(graph);
    
    printf("\nAnother example:\n");
    Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    addEdge(graph2, 3, 1);
    
    topologicalSort(graph2);
    freeGraph(graph2);
    
    return 0;
}
