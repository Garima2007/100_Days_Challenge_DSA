/*
853. Car Fleet
Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    res[idx] = (int*)malloc(2 * sizeof(int));
    res[idx][0] = intervals[0][0];
    res[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= res[idx][1]) {
            if (intervals[i][1] > res[idx][1])
                res[idx][1] = intervals[i][1];
        } else {
            idx++;
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return res;
}
