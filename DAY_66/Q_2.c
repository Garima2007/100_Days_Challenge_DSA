/*
207. Course Schedule
Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    int* adjCap = (int*)calloc(numCourses, sizeof(int));
    
    for(int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(4 * sizeof(int));
        adjCap[i] = 4;
    }
    
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    for(int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        
        if(adjSize[prereq] >= adjCap[prereq]) {
            adjCap[prereq] *= 2;
            adj[prereq] = (int*)realloc(adj[prereq], adjCap[prereq] * sizeof(int));
        }
        adj[prereq][adjSize[prereq]++] = course;
        indegree[course]++;
    }
    
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }
    
    int completed = 0;
    while(front < rear) {
        int course = queue[front++];
        completed++;
        
        for(int i = 0; i < adjSize[course]; i++) {
            int next = adj[course][i];
            indegree[next]--;
            if(indegree[next] == 0)
                queue[rear++] = next;
        }
    }
    
    for(int i = 0; i < numCourses; i++)
        free(adj[i]);
    free(adj);
    free(adjSize);
    free(adjCap);
    free(indegree);
    free(queue);
    
    return completed == numCourses;
}
