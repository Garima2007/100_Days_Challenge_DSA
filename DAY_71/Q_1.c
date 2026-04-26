/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Create array of adjacency lists
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge (for undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge from dest to src (for undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function - THIS IS CRITICAL
int main() {
    printf("Graph Implementation in C\n");
    printf("==========================\n\n");
    
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);
    
    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    
    // Display the graph
    displayGraph(graph);
    
    printf("\nProgram executed successfully!\n");
    return 0;  // Don't forget this
}
