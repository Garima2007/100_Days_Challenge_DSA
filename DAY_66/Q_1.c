/*
Problem: Detect cycle in directed graph using DFS and recursion stack.
Output:
- YES if cycle exists
*/
#include <iostream>
using namespace std;

bool dfsCheck(int node, int adj[][100], int vis[], int pathVis[], int V) {
    vis[node] = 1;
    pathVis[node] = 1;
    
    for(int i = 0; i < V; i++) {
        if(adj[node][i] == 1) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis, V))
                    return true;
            }
            else if(pathVis[i]) {
                return true;
            }
        }
    }
    
    pathVis[node] = 0;
    return false;
}

int main() {
    int V = 4;
    int adj[100][100] = {0};
    
    // Graph WITHOUT cycle (DAG - Directed Acyclic Graph)
    // 0 -> 1
    adj[0][1] = 1;
    // 0 -> 2
    adj[0][2] = 1;
    // 1 -> 3
    adj[1][3] = 1;
    // 2 -> 3
    adj[2][3] = 1;
    
    int vis[100] = {0};
    int pathVis[100] = {0};
    bool cycle = false;
    
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfsCheck(i, adj, vis, pathVis, V)) {
                cycle = true;
                break;
            }
        }
    }
    
    if(cycle)
        cout << "Cycle Detected!" << endl;
    else
        cout << "No Cycle Detected!" << endl;
    
    return 0;
}
