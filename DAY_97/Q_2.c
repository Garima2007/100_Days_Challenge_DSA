/*
Meeting Rooms II
Constraints:
1 ≤ start.size() = end.size() ≤ 105
0 ≤ start[i] < end[i] ≤ 106
*/
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void heapifyDown(int heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int size = 0;

    heap[size++] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (heap[0] <= intervals[i][0]) {
            heap[0] = intervals[i][1];
            heapifyDown(heap, size, 0);
        } else {
            heap[size++] = intervals[i][1];
            heapifyUp(heap, size - 1);
        }
    }

    int result = size;
    free(heap);
    return result;
}
