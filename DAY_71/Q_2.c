/*
1584. Min Cost to Connect All Points
Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    if (n <= 1) return 0;
    
    int* key = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        key[i] = 1000000000;
    }
    
    key[0] = 0;
    int totalCost = 0;
    
    for (int count = 0; count < n; count++) {
        int u = -1;
        int minKey = 1000000000;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        
        visited[u] = 1;
        totalCost += key[u];
        
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + 
                          abs(points[u][1] - points[v][1]);
                if (dist < key[v]) {
                    key[v] = dist;
                }
            }
        }
    }
    
    free(key);
    free(visited);
    return totalCost;
}
