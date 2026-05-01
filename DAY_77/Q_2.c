/*
1192. Critical Connections in a Network
Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/
#include <stdlib.h>

int timer = 0;

void dfs(int u, int parent, int* disc, int* low, int** graph, int* graphColSize, int** res, int* returnSize) {
    disc[u] = low[u] = ++timer;

    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, graph, graphColSize, res, returnSize);
            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                res[*returnSize][0] = u;
                res[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        graph[i] = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        disc[i] = -1;

    int** res = (int**)malloc(connectionsSize * sizeof(int*));
    for (int i = 0; i < connectionsSize; i++)
        res[i] = (int*)malloc(2 * sizeof(int));

    *returnSize = 0;

    dfs(0, -1, disc, low, graph, graphColSize, res, returnSize);

    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;

    return res;
}
