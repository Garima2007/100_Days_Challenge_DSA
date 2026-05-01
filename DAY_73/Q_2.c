/* 684. Redundant Connection
Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
  */
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    static int result[2];
    int parent[1001];

    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        if (pu == pv) {
            result[0] = u;
            result[1] = v;
            *returnSize = 2;
            return result;
        }

        parent[pu] = pv;
    }

    *returnSize = 2;
    return result;
}
