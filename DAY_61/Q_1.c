/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    bool isDirected;
    
    cin >> isDirected;
    cin >> n;
    cin >> m;
    
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = 1;
            
            if (!isDirected) {
                adjMatrix[v][u] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
