/*
785. Is Graph Bipartite?
*/
#include <stdbool.h>

bool dfs(int** graph, int graphSize, int* graphColSize, int* color, int node, int c) {
    color[node] = c;

    for (int i = 0; i < graphColSize[node]; i++) {
        int nei = graph[node][i];

        if (color[nei] == -1) {
            if (!dfs(graph, graphSize, graphColSize, color, nei, 1 - c))
                return false;
        } else if (color[nei] == c) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];

    for (int i = 0; i < graphSize; i++)
        color[i] = -1;

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            if (!dfs(graph, graphSize, graphColSize, color, i, 0))
                return false;
        }
    }

    return true;
}
