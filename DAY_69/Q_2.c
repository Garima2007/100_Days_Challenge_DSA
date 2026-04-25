/*
743. Network Delay Time
Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
#define INF 0x3f3f3f3f

int min(int a, int b) {
    return a < b ? a : b;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int dist[101];
    int visited[101] = {0};
    int graph[101][101];
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;
    }
    dist[k] = 0;
    
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }
    
    for (int cnt = 0; cnt < n; cnt++) {
        int u = -1;
        int minDist = INF;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < INF) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > ans) ans = dist[i];
    }
    return ans;
}
