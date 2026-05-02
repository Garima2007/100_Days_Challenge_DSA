/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int size = 0;

    heap[size++] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        int minIndex = 0;
        for (int j = 1; j < size; j++) {
            if (heap[j] < heap[minIndex])
                minIndex = j;
        }

        if (heap[minIndex] <= start) {
            heap[minIndex] = end;
        } else {
            heap[size++] = end;
        }
    }

    int result = size;
    free(heap);
    return result;
}
