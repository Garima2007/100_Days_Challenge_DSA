/*
787. Cheapest Flights Within K Stops
Constraints:

2 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int* dist = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        dist[i] = 1000000000;
        temp[i] = 1000000000;
    }
    
    dist[src] = 0;
    
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }
        
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];
            
            if (dist[u] < 1000000000 && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        
        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }
    
    int result = dist[dst];
    free(dist);
    free(temp);
    
    return result == 1000000000 ? -1 : result;
}
