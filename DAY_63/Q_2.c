/* 733. Flood Fill
Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/
#include <stdio.h>
#include <stdlib.h>

int originalColor;

void dfs(int** image, int sr, int sc, int m, int n, int color)
{
    if(sr < 0 || sc < 0 || sr >= m || sc >= n)
        return;

    if(image[sr][sc] != originalColor)
        return;

    image[sr][sc] = color;

    dfs(image, sr + 1, sc, m, n, color);
    dfs(image, sr - 1, sc, m, n, color);
    dfs(image, sr, sc + 1, m, n, color);
    dfs(image, sr, sc - 1, m, n, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes)
{
    int m = imageSize;
    int n = imageColSize[0];

    originalColor = image[sr][sc];

    if(originalColor == color)
    {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, sr, sc, m, n, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
