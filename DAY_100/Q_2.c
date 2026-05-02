/*
315. Count of Smaller Numbers After Self
Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node* arr, int* count, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Node* L = (Node*)malloc(n1 * sizeof(Node));
    Node* R = (Node*)malloc(n2 * sizeof(Node));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Node* arr, int* count, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(arr, count, l, m);
    mergeSort(arr, count, m + 1, r);
    merge(arr, count, l, m, r);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    Node* arr = (Node*)malloc(numsSize * sizeof(Node));
    int* count = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, count, 0, numsSize - 1);

    free(arr);
    return count;
}
