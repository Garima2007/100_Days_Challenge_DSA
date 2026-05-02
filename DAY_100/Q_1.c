/*
Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair* arr, int* res, Pair* temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            rightCount++;
            temp[k++] = arr[j++];
        } else {
            res[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        res[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int t = left; t <= right; t++) {
        arr[t] = temp[t];
    }
}

void mergeSort(Pair* arr, int* res, Pair* temp, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, res, temp, left, mid);
    mergeSort(arr, res, temp, mid + 1, right);
    merge(arr, res, temp, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    Pair* temp = (Pair*)malloc(numsSize * sizeof(Pair));
    int* res = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, res, temp, 0, numsSize - 1);

    free(arr);
    free(temp);

    *returnSize = numsSize;
    return res;
}
