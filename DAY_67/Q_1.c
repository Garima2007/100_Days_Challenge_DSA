/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <iostream>
using namespace std;
void dfs(int node, int adj[][100], int visited[], int V) {
    cout << "Visiting node " << node << endl;
    visited[node] = 1;
    
    for(int next = 0; next < V; next++) {
        if(adj[node][next] == 1 && !visited[next]) {
            cout << "  Going from " << node << " to " << next << endl;
            dfs(next, adj, visited, V);
        }
    }
    
    cout << "Finished node " << node << " - Adding to order" << endl;
}

int main() {
    int V = 4;
    int adj[100][100] = {0};
    adj[3][2] = 1;
    adj[2][1] = 1;
    adj[1][0] = 1;
    
    int visited[100] = {0};
    
    cout << "=== DFS Traversal ===" << endl;
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, V);
        }
    }
    
    return 0;
}
