Leet Code 867. Transpose Matrix
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int m = matrixSize;
    int n = matrixColSize[0];
    
    *returnSize = n;
    int** result = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++){
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
        for(int j = 0; j < m; j++){
            result[i][j] = matrix[j][i];
        }
    }
    
    return result;
}
