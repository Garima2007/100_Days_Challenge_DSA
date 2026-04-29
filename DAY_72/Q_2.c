/*Travelling Salesman Problem */
#include <stdio.h>
#include <limits.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int pos, int count, int cost) {
    if (count == N && graph[pos][0]) {
        return cost + graph[pos][0];
    }

    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            ans = min(ans, tsp(i, count + 1, cost + graph[pos][i]));
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    visited[0] = 1;  // start from city 0

    int result = tsp(0, 1, 0);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
