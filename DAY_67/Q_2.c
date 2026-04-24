/*
210. Course Schedule II
Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, 
               int* prerequisitesColSize, int* returnSize) {
    
    // Build adjacency list and indegree array
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphSize = (int*)calloc(numCourses, sizeof(int));
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    
    for(int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int));
    }
    
    // Build the graph
    for(int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphSize[prereq]++] = course;
        indegree[course]++;
    }
    
    // Queue for BFS
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    // Add courses with 0 indegree
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    // Result array
    int* result = (int*)malloc(numCourses * sizeof(int));
    int index = 0;
    
    // BFS processing
    while(front < rear) {
        int course = queue[front++];
        result[index++] = course;
        
        for(int i = 0; i < graphSize[course]; i++) {
            int next = graph[course][i];
            indegree[next]--;
            if(indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }
    
    // Clean up
    for(int i = 0; i < numCourses; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphSize);
    free(queue);
    
    // Check if all courses can be taken
    if(index != numCourses) {
        free(result);
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = numCourses;
    return result;
}
