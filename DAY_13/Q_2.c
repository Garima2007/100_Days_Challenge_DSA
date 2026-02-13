54. Spiral Matrix
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    int *res = (int*)malloc(sizeof(int) * m * n);
    *returnSize = m * n;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int k = 0;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            res[k++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            res[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                res[k++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                res[k++] = matrix[i][left];
            left++;
        }
    }

    return res;
}
