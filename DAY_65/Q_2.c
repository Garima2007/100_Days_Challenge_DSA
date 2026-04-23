/*
Undirected Graph Cycle
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V
*/
#include <stdbool.h>

int parent[20005];
int rank[20005];

int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if(pa == pb)
        return;

    if(rank[pa] < rank[pb])
        parent[pa] = pb;
    else if(rank[pa] > rank[pb])
        parent[pb] = pa;
    else
    {
        parent[pb] = pa;
        rank[pa]++;
    }
}

bool isCycle(int edges[][2], int E, int V)
{
    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    for(int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return true;   // cycle found

        unionSet(pu, pv);
    }

    return false;
}
