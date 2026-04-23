/*
994. Rotting Oranges

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2
*/
#include <stdio.h>
int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];

    int queue[10000][2];
    int front = 0, rear = 0;

    int fresh = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 2)
            {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if(grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    int time = 0;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(front < rear && fresh > 0)
    {
        int size = rear - front;
        int infected = 0;

        for(int k = 0; k < size; k++)
        {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for(int d = 0; d < 4; d++)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                    fresh--;
                    infected = 1;
                }
            }
        }

        if(infected)
            time++;
    }

    return fresh == 0 ? time : -1;
}
