/*133. Clone Graph
Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/
#include <stdlib.h>
struct Node* dfs(struct Node* node, struct Node** map) {
    if (!node) return NULL;

    if (map[node->val] != NULL)
        return map[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    map[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], map);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;

    struct Node* map[101] = {NULL};
    return dfs(s, map);
}
