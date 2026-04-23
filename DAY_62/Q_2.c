/*841. Keys and Rooms
Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.
*/
int visited[1000];

void dfs(int** rooms, int* roomsColSize, int room)
{
    visited[room] = 1;

    for(int i = 0; i < roomsColSize[room]; i++)
    {
        int key = rooms[room][i];
        if(visited[key] == 0)
        {
            dfs(rooms, roomsColSize, key);
        }
    }
}

int canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
    int i;

    for(i = 0; i < roomsSize; i++)
    {
        visited[i] = 0;
    }

    dfs(rooms, roomsColSize, 0);

    for(i = 0; i < roomsSize; i++)
    {
        if(visited[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}
