/*
215. Kth Largest Element in an Array
Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int* heap, int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void buildHeap(int* heap, int size) {
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++)
        heap[i] = nums[i];

    buildHeap(heap, k);

    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapify(heap, k, 0);
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}
